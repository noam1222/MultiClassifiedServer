#ifndef MANHATTAN_DISTANCE_H
#define MANHATTAN_DISTANCE_H

#include "Distance.h"
#include <vector>
#include <cmath>

/**
 * class for calculate Manhattan distance between 2 vectors
*/
class ManhattanDistance : public Distance {
public:
    double getDistance(vector<double> v1, vector<double> v2);
};

#endif