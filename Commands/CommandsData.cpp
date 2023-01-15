#include "CommandsData.h"

/**
 * constructor. as request, initialize k to 5 and distance method to euclidean.
 */
CommandsData::CommandsData() {
    m_uploaded = false;
    m_classified = false;
    m_k = 5;
    m_distanceMethodStr = "AUC";
}

/**
 * check if the client already upload files.
 * @return true if the client already upload files, false otherwise
 */
bool CommandsData::hasUploadedFiles() const {return m_uploaded;}

/**
 * check if the files already classified
 * @return true if the files already classified, false otherwise
 */
bool CommandsData::hasClasiifiedFile() const {return m_classified;}

/**
 * get the K of the algorithm
 * @return the K of the algorithm
 */
int CommandsData::getK() const {return m_k;}

/**
 * get the distance method of the algorithm
 * @return the distance method of the algorithm
 */
string CommandsData::getDistanceMethod() const {return m_distanceMethodStr;}

/**
 * mark that the client uploaded the requested files
 */
void CommandsData::Uploaded() {m_uploaded = true;}

/**
 * mark that the requested files classified
 */
void CommandsData::Classified() {m_classified = true;}

/**
 * set the K of the algorithm
 * @param k the K of the algorithm
 */
void CommandsData::setK(unsigned int k) {m_k = k;}

/**
 * set the distance method of the algorithm
 * @param distanceMethod the distance method of the algorithm
 */
void CommandsData::setDistanceMethod(string distanceMethod) {m_distanceMethodStr = distanceMethod;}