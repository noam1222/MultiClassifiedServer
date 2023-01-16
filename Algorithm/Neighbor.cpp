//
// Created by noam on 08/12/2022.
//

#include "Neighbor.h"

/**
 * constructor
 * pay attention: in first, the distance of this vector is 0! need to set it separately!
 * @param v vector
 * @param definition definition of v
 */
Neighbor::Neighbor(vector<double> v, string definition) {
    m_v = v;
    m_defnition = definition;
    m_distance = 0;
}

/**
 * get the vector of this neighbor
 * @return the vector of this neighbor
 */
vector<double> Neighbor::getVector() { return m_v;}

/**
 * get the definition of this neighbor
 * @return the definition of this neighbor
 */
string Neighbor::getDefinition() {return m_defnition;}

/**
 * get the distance of this neighbor from predetermined vector.
 * @return the distance of this neighbor from predetermined vector.
 */
double Neighbor::getDistance() const {return m_distance;}

/**
 * set the distance of this neighbor from some vector.
 * @param distance the distance of this neighbor from some vector.
 */
void Neighbor::setDistance(double distance) {m_distance = distance;}