#ifndef MULTICLASSIFIEDSERVER_UPLOAD_H
#define MULTICLASSIFIEDSERVER_UPLOAD_H

#include "Command.h"
#include "string"
#include "../Data/ExtractData.h"

/**
 * class for upload command.
 */
class Upload : public Command {
private:
    const string PATH = "clients_data/";
public:
    Upload(DefaultIO *df, CommandsData &data);
    void execute() override;
};


#endif //MULTICLASSIFIEDSERVER_UPLOAD_H
