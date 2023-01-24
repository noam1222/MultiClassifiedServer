#include "KnnAlgorithm.h"

/**
 * constructor
 * @param k the k of K-Nearest Neighbors
 * @param neighbors neighbors to find from them the k nearest
 * @param d distance method to define "nearest"
 */
KnnAlgorithm::KnnAlgorithm(unsigned int k, vector<Neighbor> neighbors, Distance *d) {
    m_k = k;
    m_neighbors = neighbors;
    m_d = d;
}

/**
 * compare tow neighbors distance.
 * pay attention: they both should contain the distance field compare to the same vector!
 * @param n1 first vector to compare
 * @param n2 second vector to compare
 * @return true if n1 closer than n2, false otherwise.
 */
bool sortByVec(Neighbor n1, Neighbor n2) {
    return n1.getDistance() < n2.getDistance();
}

/**
 * set distance between all neighbors and vecToComp
 * @param vecToComp check all neighbors distance compare to him.
 */
void KnnAlgorithm::setDistanceToNeighbors(vector<double> vecToComp) {
    for (int i = 0; i < m_neighbors.size(); i++) {
        vector<double> neighborVec = m_neighbors.at(i).getVector();
        double neighborDistance = m_d->getDistance(vecToComp, neighborVec);
        m_neighbors.at(i).setDistance(neighborDistance);
    }
}

/**
 * find most common definition in the k first neighbors.
 * pay attention: for this function to work right, the neighbors should be sorted!
 * @return most common definition in the k first neighbors.
 */
string KnnAlgorithm::findMostCommonString() {
    map<string, int> mostCommon;
    //if k > neighbors size, find the nearest from all the neighbors
    unsigned int k = m_k;
    if (k > m_neighbors.size()) {
        throw invalid_argument("K bigger than number of neighbors");
    }
    string mostCommonString = "";
    int mostCommonStringRepeat = 0;
    for (int i = 0; i < k; i++) {
        int repeats;
        string definition = m_neighbors.at(i).getDefinition();
        map<string, int>::iterator iter = mostCommon.find(definition);
        // check if first occurrence of definition
        if (iter == mostCommon.end()) {
            repeats = 1;
            mostCommon[definition] = repeats;
        } else {
            iter->second++;
            repeats = iter->second;
        }
        if (mostCommonStringRepeat < repeats) {
            mostCommonString = definition;
            mostCommonStringRepeat = mostCommonStringRepeat;
        }
    }
    return mostCommonString;
}

/**
 * get the definition of received vector base of k nearest neighbors.
 * @param vecToComp vec to return definition of.
 * @return definition of vecToComp base of k nearest neighbors.
 */
string KnnAlgorithm::getDefinition(vector<double> vecToComp) {
    if (vecToComp.size() != m_neighbors.at(0).getVector().size()) {
        throw invalid_argument("wrong size");
    }
    setDistanceToNeighbors(vecToComp);
    sort(m_neighbors.begin(), m_neighbors.end(), sortByVec);
    return findMostCommonString();
}

/**
 * set the k of the algorithm.
 * @param k the new k of the algorithm
 */
void KnnAlgorithm::setK(unsigned int k) { m_k = k; }

/**
 * set the distance method of the algorithm.
 * @param d new distance method of the algorithm
 */
void KnnAlgorithm::setDistance(Distance *d) {
    //free former distance object
    if (m_d != nullptr) {
        free(m_d);
    }
    m_d = d;
}

/**
 * destructor - free the distance object this algorithm use
 */
KnnAlgorithm::~KnnAlgorithm() { free(m_d); }