#ifndef MINKOWSKI_DISTANCE_H
#define MINKOWSKI_DISTANCE_H

#include "Distance.h"
#include <vector>
#include <cmath>

/**
 * class for calculate Minkowski distance between 2 vectors
*/
class MinkowskiDistance : public Distance {
private:
    static const int P = 2;
public:
    double getDistance(vector<double> v1, vector<double> v2);
};

#endif