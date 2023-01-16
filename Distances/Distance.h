#ifndef VECTORS_H
#define VECTORS_H

#include <vector>
#include <string>

using namespace std;

/**
 * Interface for 2 vectors distance calculating methods
*/
class Distance {
    public:
        /**
         * abstract method for calculating distance between 2 vectors
        */
        virtual double getDistance(vector<double> v1, vector<double> v2) = 0;
};

#endif