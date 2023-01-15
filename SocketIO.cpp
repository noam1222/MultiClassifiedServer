#include "SocketIO.h"

/**
 * constructor
 * @param sockNum socket number to use in the sending and receiving data.
 */
SocketIO::SocketIO(int sockNum) {
    m_sockNum = sockNum;
    m_bufferSize = sizeof(m_buffer);
    clearBuffer();
}

/**
 * clear the buffer of this connection.
 */
void SocketIO::clearBuffer() {
    memset(&m_buffer, 0, m_bufferSize);
}

/**
 * receive data from the client.
 * @return the data the client sent.
 */
string SocketIO::read() {
    string result;
    size_t delim;
    bool connectionClose = false;
    while ((delim = result.find(MSG_END)) == string::npos) {
        ssize_t recv_bytes = recv(m_sockNum, &m_buffer, m_bufferSize, 0);
        if (recv_bytes == 0) {
            connectionClose = true;
            continue;
        }
        if (recv_bytes < 0) {
            perror("Error in receiving data");
            exit(1);
        }
        result += m_buffer;
        clearBuffer();
    }
    if (!connectionClose) {
        result = result.substr(0, delim);
    }
    return result;
}

/**
 * send data to client. data size <b>have to</b> be less or equal to BUFFER_SIZE.
 * @param s data to send to client. s.length() <= BUFFER_SIZE
 */
void SocketIO::sendBufferSizeOrLess(string s) {
    ssize_t sent_bytes = send(m_sockNum, &m_buffer, s.length(), 0);
    if (sent_bytes < 0) {
        perror("error in sending");
        exit(1);
    }
}

/**
 * send data to the client.
 * @param s data to send to client.
 */
void SocketIO::write(string s) {
    s += EOF;
    while (s.length() > 4096) {
        string toSend = s.substr(0, 4096);
        s = s.substr(4096);
        sendBufferSizeOrLess(toSend);
    }
    sendBufferSizeOrLess(s);
}

