#include "CanberraDistance.h"
#include <cmath>


/**
 * this method calculates the distance between two vectors according to the canberra algorithm
 * @param v1 first vector
 * @param v2 second vector
 * @return distance between v1 and v2 according to canberra
 */
double CanberraDistance::getDistance(vector<double> v1, vector<double> v2) {
    double canDist = 0;
    for (int i = 0; i < v1.size(); ++i) {
        if ((v1.at(i) == 0) && (v2.at(i) == 0)) {
            continue;
        }
        canDist += (abs(v1.at(i) - v2.at(i))) / (abs(v1.at(i)) + abs(v2.at(i)));
    }
    return canDist;
}