#include "ManhattanDistance.h"

/**
 * this method calculates the distance between two vectors according to the euclidean algorithm
 * @param v1 first vector
 * @param v2 second vector
 * @return distance between v1 and v2 according to euclidean
 */
double ManhattanDistance::getDistance(vector<double> v1, vector<double> v2) {
    double manhattDis = 0;
    for (int i = 0; i < v1.size(); ++i) {
        manhattDis += abs(v1.at(i) - v2.at(i));
    }
    return manhattDis;
}