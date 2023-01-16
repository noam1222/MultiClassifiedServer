#ifndef MULTICLASSIFIEDSERVER_DISPLAY_H
#define MULTICLASSIFIEDSERVER_DISPLAY_H

#include "Command.h"
#include <fstream>

/**
 * class for display result command
 */
class Display : public Command {
public:
    Display(DefaultIO *df, CommandsData &data);
    void execute() override;
};


#endif //MULTICLASSIFIEDSERVER_DISPLAY_H
