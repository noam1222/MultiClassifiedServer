#ifndef MULTICLASSIFIEDSERVER_DOWNLOAD_H
#define MULTICLASSIFIEDSERVER_DOWNLOAD_H

#include "Command.h"
#include <fstream>

/**
 * class for download result command
 */
class Download : public Command{
public:
    Download(DefaultIO *df);
    void execute() override;
};


#endif //MULTICLASSIFIEDSERVER_DOWNLOAD_H
