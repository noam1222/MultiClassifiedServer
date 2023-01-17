#include <iostream>
#include <string>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <atomic>
#include <thread>
#include "Data/ExtractData.h"
#include "SocketIO.h"
#include "CLI.h"

using namespace std;

void startChat(int sockNum, int threadID) {
    SocketIO sio(sockNum);
    CLI cli(&sio, threadID);
    cli.run();
}

void fatalError(const string &msg) {
    cout << msg << endl;
    exit(1);
}

int main(int argc, char **argv) {
    //check for correct amount of arguments
    if (argc != 2) {
        fatalError("Wrong amount of argument");
    }
    //create socket
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        fatalError("Error in creating socket");
    }

    // bind socket to received port
    struct sockaddr_in sin{};
    sin.sin_family = AF_INET;
    sin.sin_addr.s_addr = INADDR_ANY;
    int port;
    try {
        port = ExtractData::parseStringToInt(argv[1]);
        if (port < 1 or port > 65535) {
            throw invalid_argument("out of port range");
        }
    } catch (invalid_argument &e) {
        fatalError("Invalid port");
    }
    sin.sin_port = htons(port);
    if (bind(sock, (struct sockaddr *) &sin, sizeof(sin)) < 0) {
        fatalError("Error in bind to port");
    }

    //make the server listen
    if (listen(sock, 5) < 0) {
        fatalError("Error in listening");
    }
    atomic_int threadNum;
    threadNum = 0;
    while (true) {
        //accept client
        struct sockaddr_in client_sin{};
        unsigned int client_sin_len = sizeof(client_sin);
        int client_sock = accept(sock, (struct sockaddr *) &client_sin, &client_sin_len);
        if (client_sock < 0) {
            fatalError("Error in accept client");
        }
        threadNum++;
        thread c(&startChat, client_sock, (int)threadNum);
        c.detach();
    }

    close(sock);
    return 0;
}