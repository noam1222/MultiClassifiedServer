#ifndef MULTICLASSIFIEDSERVER_UPLOAD_H
#define MULTICLASSIFIEDSERVER_UPLOAD_H

#include "Command.h"
#include "string"

class Upload : public Command {
private:
    const string PATH = "clients_data/";
    void createFile(string name, string content);
public:
    Upload(DefaultIO *df);
    void execute() override;
};


#endif //MULTICLASSIFIEDSERVER_UPLOAD_H
