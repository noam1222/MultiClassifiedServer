#ifndef MULTICLASSIFIEDSERVER_UPLOAD_H
#define MULTICLASSIFIEDSERVER_UPLOAD_H

#include "Command.h"
#include "string"

/**
 * class for upload command.
 */
class Upload : public Command {
private:
    const string PATH = "clients_data/";
    static void createFile(string &name, string &content);
public:
    Upload(DefaultIO *df, CommandsData &data);
    void execute() override;
};


#endif //MULTICLASSIFIEDSERVER_UPLOAD_H
