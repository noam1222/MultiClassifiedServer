#ifndef MULTICLASSIFIEDSERVER_SETTINGS_H
#define MULTICLASSIFIEDSERVER_SETTINGS_H

#include "Command.h"

/**
 * class for the KNN algorithm setting handle command
 */
class Settings : public Command{
public:
    Settings(DefaultIO *df, CommandsData &data);
    void execute() override;
};


#endif //MULTICLASSIFIEDSERVER_SETTINGS_H
