#ifndef MULTICLASSIFIEDSERVER_CLI_H
#define MULTICLASSIFIEDSERVER_CLI_H

#include "Commands/Command.h"
#include "Commands/Upload.h"
#include "Commands/settings.h"
#include "Commands/Classify.h"
#include "Commands/Display.h"
#include "Commands/Download.h"
#include "DefaultIO.h"

/**
 * Class for control the m_commands flow in the server.
 */
class CLI {
private:
    DefaultIO *m_df;
    Command *m_commands[5];
    CommandsData m_data;
    void menu();
public:
    CLI(DefaultIO *df, int threadNum);
    void run();
    ~CLI();
};


#endif //MULTICLASSIFIEDSERVER_CLI_H
