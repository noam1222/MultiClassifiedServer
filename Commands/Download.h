#ifndef MULTICLASSIFIEDSERVER_DOWNLOAD_H
#define MULTICLASSIFIEDSERVER_DOWNLOAD_H

#include "Command.h"
#include <fstream>
#include "../Data/ExtractData.h"

/**
 * class for download result command
 */
class Download : public Command{
public:
    Download(DefaultIO *, CommandsData &data);
    void execute() override;
};


#endif //MULTICLASSIFIEDSERVER_DOWNLOAD_H
