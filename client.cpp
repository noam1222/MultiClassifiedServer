
#include <iostream>
#include <sys/socket.h>
#include <stdio.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>
#include "Data/ExtractData.h"
#include "SocketIO.h"

#define END_MSG "EOF"
#define INVALID_INPUT "invalid input"

using namespace std;

void uploadFile(SocketIO *socketIo) {
    string uploadFin;
    //receive from server to print train/test CSV
    for (int i = 1; i < 3; ++i) {
        string ret = socketIo->read();
        cout << ret << endl;
        //receive path from user
        string path;
        getline(cin, path);
        //checks if path is valid
        string fileToUpload;
        try {
            fileToUpload = ExtractData::readFromFile(path);
        } catch (invalid_argument) {
            cout << path + " Not Found" << endl;
            socketIo->write("");
            return;
        }
        socketIo->write(fileToUpload);
        //waiting for response from server that upload is complete
        uploadFin = socketIo->read();
        cout << uploadFin << endl;
    }

}

void editSettings(SocketIO *socketIo) {
    bool validDistance = true;
    string newSettings;
    //present to user current settings
    string currentSettings = socketIo->read();
    cout << currentSettings << endl;
    getline(cin, newSettings);
    if (!(newSettings.length())) {
        socketIo->write("");
        return;
    }
    vector<string> settings = ExtractData::splitString(newSettings, " ");
    if (settings.size() != 2) {
        cout << INVALID_INPUT << endl;
        socketIo->write("");
        return;
    }
    //checks if K is valid
    bool k = true;
    try {
        if (ExtractData::parseStringToInt(settings.at(0)) <= 0) {
            throw invalid_argument("k must be positive");
        }
    } catch (invalid_argument) {
        k = false;
        cout << "invalid value for K" << endl;
    }
    //checks if distance is valid
    try {
        ExtractData::getDistanceByStr(settings.at(1));
    } catch (invalid_argument) {
        validDistance = false;
        cout << "invalid value for metric " << endl;
    }

    if (validDistance && k) {
        socketIo->write(settings.at(0) + " " + settings.at(1));
    } else {
        socketIo->write("");
    }
}

void classData(SocketIO *socketIo) {
    string forPrint = socketIo->read();
    cout << forPrint << endl;
}

void displayResults(SocketIO *socketIo) {
    string waitForEnter;
    string display = socketIo->read();
    cout << display << endl;
    getline(cin, waitForEnter);
}

void downResults(SocketIO *socketIo) {
    string waitForEnter;
    string pathToDownload;
    string fileToDownload = socketIo->read();
    //receive path from user
    string path;
    getline(cin, path);
    //checks if path is valid
    try{
        ExtractData::writeToFile(path, fileToDownload);
    }catch (invalid_argument) {
        cout << path + "Not Found" << endl;
        return;
    }
    getline(cin, waitForEnter);
}

int main(int argc, char **argv) {
    //Connection to server socket
    cout << argv[0] << endl;
    if (argc != 3) {
        cout << INVALID_INPUT << endl;
    }
    const char *ip_address = argv[1];
    int port_no;
    //checking that port input is valid, if not it clos
    try {
        port_no = ExtractData::parseStringToInt(argv[2]);
        if (port_no <= 0 || port_no > 65535) {
            cout << "Port not in range" << endl;
            exit(0);
        }
    } catch (exception &exception) {
        cout << "Port input not number" << endl;
        exit(0);
    }
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("error creating socket");
        exit(0);
    }
    struct sockaddr_in sin{};
    memset(&sin, 0, sizeof(sin));
    sin.sin_family = AF_INET;
    //checking id IP address is valid
    try {
        sin.sin_addr.s_addr = inet_addr(ip_address);
    } catch (exception &e) {
        cout << "Invalid IP address" << endl;
        exit(0);
    }

    sin.sin_port = htons(port_no);
    if (connect(sock, (struct sockaddr *) &sin, sizeof(sin)) < 0) {
        perror("error connecting to server");
        exit(0);
    }

    SocketIO *socketIo = new SocketIO(sock);
    string mainMenu = socketIo->read();
    cout << mainMenu << endl;
    bool toRun = true;
    //loop with user
    while (true) {
        //receiving input from user
        string input;
        getline(cin, input);
        int option;
        try {
            option = ExtractData::parseStringToInt(input);
        } catch (invalid_argument) {
            cout << INVALID_INPUT << endl;
            continue;
        }
        switch (option) {
            case 1:
                socketIo->write(input);
                uploadFile(socketIo);
                break;
            case 2:
                socketIo->write(input);
                editSettings(socketIo);
                break;
            case 3:
                socketIo->write(input);
                classData(socketIo);
                break;
            case 4:
                socketIo->write(input);
                displayResults(socketIo);
                break;
            case 5:
                socketIo->write(input);
                downResults(socketIo);
                break;
            case 8:
                socketIo->write(input);
                toRun = false;
                break;
            default:
                cout << "Invalid Option" << endl;
        }
        //if user wants to close connection
        if (!(toRun)) {
            break;
        }
        //printing main menu in loop
        cout << mainMenu << endl;
    }

    close(sock);
    return 0;
}
