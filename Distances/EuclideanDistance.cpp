#include "EuclideanDistance.h"

/**
 * this method calculates the distance between two vectors according to the euclidean algorithm
 * @param v1
 * @param v2
 * @return distance between v1 and v2 according to euclidean
 */
double EuclideanDistance::getDistance(vector<double> v1, vector<double> v2) {
    double powSum = 0;
    auto iter1 = v1.begin();
    auto iter2 = v2.begin();

    while (iter1 != v1.end()) {
        double currentElementsSum = *iter1++ - *iter2++;
        powSum += currentElementsSum * currentElementsSum;
    }

    return sqrt(powSum);
}