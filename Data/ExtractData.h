#ifndef KNN_EXTRACTDATA_H
#define KNN_EXTRACTDATA_H

#include <string>
#include <map>
#include <vector>
#include "../Algorithm/Neighbor.h"
#include "../Distances/Distance.h"
#include "../Distances/CanberraDistance.h"
#include "../Distances/ChebyshevDistance.h"
#include "../Distances/EuclideanDistance.h"
#include "../Distances/ManhattanDistance.h"
#include "../Distances/MinkowskiDistance.h"

using namespace std;

/**
 * Class for extracting and manipulate data
*/
class ExtractData {
public:
    static string readFromFile(string filepath);
    static void writeToFile(string outputPath, string content);
    static int parseStringToInt(const string &s);
    static Distance* getDistanceByStr(const string &str);
    static vector<double> strVectorToDouble(vector<string> vStr);
    static  vector<string> splitString(string str, string delim);
    static vector<Neighbor> fileToVec(string fileAddress);
};


#endif //KNN_EXTRACTDATA_H