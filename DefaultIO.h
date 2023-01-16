#ifndef MULTICLASSIFIEDSERVER_DEFAULTIO_H
#define MULTICLASSIFIEDSERVER_DEFAULTIO_H

#include "string"

using namespace std;

/**
 * abstract class for read and write in IO.
 */
class DefaultIO {
public:
    virtual string read() = 0;
    virtual void write(string s) = 0;
};


#endif //MULTICLASSIFIEDSERVER_DEFAULTIO_H
