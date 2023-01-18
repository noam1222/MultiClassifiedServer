#include <iostream>
#include <fstream>
#include <sys/socket.h>
#include <stdio.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>
#include "Data/ExtractData.h"
#include "SocketIO.h"
#include <thread>

#define END_MSG "EOF"
#define INVALID_INPUT "invalid input"

using namespace std;

void uploadFile(SocketIO *socketIo) {
    string uploadFin;
    //receive from server to print train/test CSV
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
        cout << INVALID_INPUT << endl;
        socketIo->write("");
        return;
    }
    socketIo->write(fileToUpload);
    //waiting for response from server that upload is complete
    uploadFin = socketIo->read();
    cout << uploadFin << endl;

    //receive path from user
    getline(cin, path);
    //checks if path is valid
    try {
        fileToUpload = ExtractData::readFromFile(path);
    } catch (invalid_argument) {
        cout << INVALID_INPUT << endl;
        socketIo->write("");
        return;
    }
    socketIo->write(fileToUpload);
    //waiting for response from server that upload is complete
    uploadFin = socketIo->read();
    cout << uploadFin << endl;
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
    cout << display;
    if (display != "please upload data" && display != "please classify the data") {
        getline(cin, waitForEnter);
    } else {
        cout << endl;
    }
}

void downloadFile(string path, string fileToDownload) {
    //checks if able to write to path
    try{
        ExtractData::writeToFile(path, fileToDownload);
    }catch (invalid_argument) {
        cout << INVALID_INPUT << endl;
        return;
    }
}

void recDownloadPath(SocketIO *socketIo) {
    string fileToDownload = socketIo->read();
    if (fileToDownload == "please upload data" || fileToDownload == "please classify the data") {
        cout << fileToDownload << endl;
        return;
    }
    //receive path from user
    string path;
    getline(cin, path);
    //checks if path exists
    ofstream outfile;
    outfile.open(path, ios::out);
    if(!outfile) {
        cout << INVALID_INPUT << endl;
        return;
    }
    //creating separate thread for the downloading process
    std::thread downloadThread(downloadFile,path, fileToDownload);
    downloadThread.detach();
}



int main(int argc, char **argv) {
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
    cout << mainMenu;
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
            cout << mainMenu;
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
                recDownloadPath(socketIo);
                break;
            case 8:
                free(socketIo);
                close(sock);
                toRun = false;
                break;
            default:
                cout << INVALID_INPUT << endl;
        }
        //if user wants to close connection
        if (!toRun) {
            break;
        }
        //printing main menu in loop
        cout << mainMenu;
    }

    return 0;
}
