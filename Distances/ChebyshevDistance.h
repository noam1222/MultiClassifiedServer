#ifndef CHEBYSHEV_DISTANCE_H
#define CHEBYSHEV_DISTANCE_H

#include "Distance.h"
#include <vector>
#include<cmath>

/**
 * class for calculate Chebyshev distance between 2 vectors
*/
class ChebyshevDistance : public Distance {
public:
    double getDistance(vector<double> v1, vector<double> v2);
};

#endif