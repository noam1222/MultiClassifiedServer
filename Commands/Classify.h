#ifndef MULTICLASSIFIEDSERVER_CLASSIFY_H
#define MULTICLASSIFIEDSERVER_CLASSIFY_H

#include "Command.h"
#include "../Algorithm/KnnAlgorithm.h"
#include "../Algorithm/Neighbor.h"
#include "../Data/ExtractData.h"
#include "../Distances/Distance.h"
#include "fstream"
#include <vector>

/**
 * class for classify the unclassified file that the client sent.
 */
class Classify : public Command {
public:
    Classify(DefaultIO *, CommandsData &data);
    void execute() override;
};


#endif //MULTICLASSIFIEDSERVER_CLASSIFY_H
