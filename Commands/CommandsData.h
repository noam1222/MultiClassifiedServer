#ifndef MULTICLASSIFIEDSERVER_COMMANDSDATA_H
#define MULTICLASSIFIEDSERVER_COMMANDSDATA_H

#include <string>

using namespace std;

/**
 * class for the shared date of the commands
 */
class CommandsData {
private:
    bool m_uploaded;
    bool m_classified;
    unsigned int m_k;
    string m_distanceMethodStr;
public:
    CommandsData();
    bool hasUploadedFiles() const;
    bool hasClasiifiedFile() const;
    int getK() const;
    string getDistanceMethod() const;
    void Uploaded();
    void Classified();
    void setK(unsigned int k);
    void setDistanceMethod(string distanceMethod);
};


#endif //MULTICLASSIFIEDSERVER_COMMANDSDATA_H
