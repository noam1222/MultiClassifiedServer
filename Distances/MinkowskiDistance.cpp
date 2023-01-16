#include "MinkowskiDistance.h"

/**
 * this method calculates the distance between two vectors according to the minkowski algorithm
 * @param v1 first vector
 * @param v2 second vector
 * @return distance between v1 and v2 according to minkowski
 */
double MinkowskiDistance::getDistance(vector<double> v1, vector<double> v2) {
    double minkowDis = 0;
    for (int i = 0; i < v1.size(); ++i) {
        minkowDis += pow((abs(v1.at(i) - v2.at(i))), P);
    }
    double result = pow(minkowDis, (1 / (double) P));
    return result;
}