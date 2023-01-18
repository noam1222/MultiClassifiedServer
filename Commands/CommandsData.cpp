#include "CommandsData.h"

/**
 * constructor. as request, initialize k to 5 and distance method to euclidean.
 */
CommandsData::CommandsData(int threadNum) {
    m_threadNum = threadNum;
    m_uploaded = false;
    m_classified = false;
    m_k = 5;
    m_distanceMethodStr = "AUC";
}

/**
 * get the thread number of this chat.
 * @return the thread number of this chat.
 */
int CommandsData::getThreadNumber() const { return m_threadNum; }

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
unsigned int CommandsData::getK() const {return m_k;}

/**
 * get the distance method of the algorithm
 * @return the distance method of the algorithm
 */
string CommandsData::getDistanceMethod() const {return m_distanceMethodStr;}

/**
 * get classified file name
 * @return classified file name
 */
string CommandsData::getClassifiedFileName() const {return  m_classifiedFilePath; }

/**
 * get unclassified file name
 * @return unclassified file name
 */
string CommandsData::getUnclassifiedFileName() const {return  m_unclassifiedFilePath; }

/**
 * get result file name (after classification)
 * @return result file name
 */
string CommandsData::getResultFileName() const {return m_resultFileName;}

/**
 * mark that the client uploaded the requested files
 */
void CommandsData::Uploaded(bool b) {m_uploaded = b;}

/**
 * mark that the requested files classified
 */
void CommandsData::Classified(bool b) {m_classified = b;}

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

/**
 * set the classified file name
 * @param classifiedFileName the classified file name to set
 */
void CommandsData::setClassifiedFilePath(string classifiedFilePath) {
    m_classifiedFilePath = classifiedFilePath;
}

/**
 * set the unclassified file name
 * @param classifiedFileName the unclassified file name to set
 */
void CommandsData::setUnclassifiedFilePath(string unclassifiedFilePath) {
    m_unclassifiedFilePath = unclassifiedFilePath;
}

/**
 * set result file (after classification) name
 * @param resultFileName result file (after classification) name
 * @return
 */
void CommandsData::setResultFileName(string resultFileName) { m_resultFileName = resultFileName;}