#ifndef MULTICLASSIFIEDSERVER_SOCKETIO_H
#define MULTICLASSIFIEDSERVER_SOCKETIO_H

#include "DefaultIO.h"
#include <string.h>
#include <sys/socket.h>
#include <mutex>

#define BUFFER_SIZE 4096
#define MSG_END "EOF"

using namespace std;

/**
 * class for sending and receiving data using sockets.
 */
class SocketIO : public DefaultIO{
private:
    int m_sockNum;
    char m_buffer[BUFFER_SIZE];
    size_t m_bufferSize;
    mutex m_mutex;
    void clearBuffer();
    void sendBufferSizeOrLess(string s);
public:
    SocketIO(int sockNum);
    string read() override;
    void write(string s) override;
};


#endif //MULTICLASSIFIEDSERVER_SOCKETIO_H
