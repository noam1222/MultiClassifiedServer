#ifndef MULTICLASSIFIEDSERVER_COMMANDSDATA_H
#define MULTICLASSIFIEDSERVER_COMMANDSDATA_H

#include <string>

using namespace std;

/**
 * class for the shared date of the m_commands
 */
class CommandsData {
private:
    int m_threadNum;
    bool m_uploaded;
    bool m_classified;
    unsigned int m_k;
    string m_distanceMethodStr;
    string m_classifiedFilePath;
    string m_unclassifiedFilePath;
    string m_resultFileName;
public:
    CommandsData(int threadNum);
    int getThreadNumber() const;
    bool hasUploadedFiles() const;
    bool hasClasiifiedFile() const;
    unsigned int getK() const;
    string getDistanceMethod() const;
    string getClassifiedFileName() const;
    string getUnclassifiedFileName() const;
    string getResultFileName() const;
    void Uploaded(bool b);
    void Classified(bool b);
    void setK(unsigned int k);
    void setDistanceMethod(string distanceMethod);
    void setClassifiedFilePath(string classifiedFilePath);
    void setUnclassifiedFilePath(string unclassifiedFilePath);
    void setResultFileName(string resultFile);
};


#endif //MULTICLASSIFIEDSERVER_COMMANDSDATA_H
