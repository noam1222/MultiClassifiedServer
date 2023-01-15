//
// Created by noam on 08/12/2022.
//

#ifndef KNN_NEIGHBOR_H
#define KNN_NEIGHBOR_H

#include <vector>
#include <string>
#include "Neighbor.h"

using namespace std;

/**
 * class for representing neighbor of vector.
 */
class Neighbor {
private:
    vector<double> m_v;
    string m_defnition;
    double m_distance;
public:
    vector<double> getVector();
    string getDefinition();
    double getDistance() const;
    void setDistance(double distance);
    Neighbor(vector<double> v, string definition);
};


#endif //KNN_NEIGHBOR_H
