
#ifndef KNN_KNNALGORITHM_H
#define KNN_KNNALGORITHM_H

#include <string>
#include <vector>
#include <map>
#include <stdexcept>
#include <algorithm>
#include "../Distances/Distance.h"
#include "Neighbor.h"

using namespace std;

/**
 * class for KNN Algorithm - find K-Nearest Neighbors.
 */
class KnnAlgorithm {
private:
    unsigned int m_k;
    vector<Neighbor> m_neighbors;
    Distance *m_d;
    vector<double> m_vecToComp;
    void setDistanceToNeighbors(vector<double> vecToComp);
    string findMostCommonString();
public:
    void setK(unsigned int k);
    void setDistance(Distance *d);
    KnnAlgorithm(unsigned int k, vector<Neighbor> neighbors, Distance *d);
    string getDefinition(vector<double> vecToComp);
    ~KnnAlgorithm();
};

#endif //KNN_KNNALGORITHM_H
