#ifndef EUCLIDEAN_DISTANCE_H
#define EUCLIDEAN_DISTANCE_H

#include "Distance.h"
#include <vector>
#include <cmath>

/**
 * class for calculate Euclidean distance between 2 vectors
*/
class EuclideanDistance : public Distance {
public:
    double getDistance(vector<double> v1, vector<double> v2);
};

#endif