#ifndef CANBERRA_DISTANCE_H
#define CANBERRA_DISTANCE_H

#include "Distance.h"
#include <vector>
#include <cmath>

/**
 * class for calculate Canberra distance between 2 vectors
*/
class CanberraDistance : public Distance {
public:
    double getDistance(vector<double> v1, vector<double> v2) override;
};

#endif