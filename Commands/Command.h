
#ifndef MULTICLASSIFIEDSERVER_COMMAND_H
#define MULTICLASSIFIEDSERVER_COMMAND_H

#include <string>
#include <fstream>
#include "../DefaultIO.h"
#include "CommandsData.h"

using namespace std;

/**
 * Class that represent command of the server.
 */
class Command {
protected:
    string m_description;
    DefaultIO *m_df;
    CommandsData &m_data;
    Command(string description, DefaultIO *df, CommandsData &data);
public:
    virtual void execute() = 0;
    string getDescription();
};


#endif //MULTICLASSIFIEDSERVER_COMMAND_H
