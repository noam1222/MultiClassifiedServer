#include "ExtractData.h"

#include <fstream>
#include "ExtractData.h"

string ExtractData::readFromFile(string filepath) {
    string content;
    string line;
    //open a file in read mode
    ifstream infile;
    infile.open(filepath, ios::in);
    if (!infile) {
        throw invalid_argument(filepath + " Not Found");
    }
    while (getline(infile, line)){
        content += line + "\n";
    }

    content = content.substr(0, content.size()-1); //remove last '\n'

    infile.close();
    return content;
}

void ExtractData::writeToFile(string outputPath, string content) {
//open a file in write mode
    ofstream outfile;
    outfile.open(outputPath, ios::out);
    if(!outfile) {
        throw invalid_argument(outputPath + " Not created");
    }
    outfile << content << endl;
}

/**
 * Parse string to int.
 * <p><b>pay attention:</b> unlike stoi, this function get only string who complete integer number as valid argument.
 * stoi, in other hand will return for example 12 from "12a".</p>
 * @param s string to parse to int
 * @return the int parse of s
 * @throw invalid_argument if s isn't complete integer number
 */
int ExtractData::parseStringToInt(const string &s) {
    size_t next_loc;
    int k = stoi(s, &next_loc);
    /**
     * stoi parse string that start with number and end with non-number as the starting number.
     * We don't want it, so we check where the parse stop in s, and if it dosn't end in the end of s - throw error.
     */
    if (next_loc < s.length()) {
        throw invalid_argument("invalid string int representation");
    }
    return k;
}

/**
 * Get Distance object by his string representation.
 * @param str the string representation of the distance.
 * @return the distance object
 */
Distance *ExtractData::getDistanceByStr(const string &str) {
    Distance *d;
    if (str == "AUC") {
        d = new EuclideanDistance();
    } else if (str == "MAN") {
        d = new ManhattanDistance();
    } else if (str == "CHB") {
        d = new ChebyshevDistance();
    } else if (str == "CAN") {
        d = new CanberraDistance();
    } else if (str == "MIN") {
        d = new MinkowskiDistance();
    } else {
        throw invalid_argument("Unknown distance");
    }
    return d;
}

/**
 * this method turns a long string into smaller separate strings according
 * to a certain delimiter
 * @param str the string
 * @param delim the separation character (delimiter)
 * @return vector with string arguments
 * @throws invalid_argument when string lenth is 0
 */
vector<string> ExtractData::splitString(string str, string delim) {
    vector<string> v;

    size_t pos = str.find(delim);
    while (pos != string::npos) {
        v.push_back(str.substr(0, pos));
        str.erase(0, pos + delim.length());
        pos = str.find(delim);
    }
    //push last element
    v.push_back(str);
    return v;
}

/**
 * this method turns a vector of strings into a vector of doubles
 * @param vStr vector with string arguments
 * @return vector with double arguments
 * @throws invalid_argument when there is an argument which isn't a valid number
 */
vector<double> ExtractData::strVectorToDouble(vector<string> vStr) {
    vector<double> vDouble;
    for (int i = 0; i < vStr.size(); i++) {
        string strDouble = vStr.at(i);
        /**
        next_loc used for checking if the user inserted a.b.c (where a, b are
        decimal numbers and c is any string).
        In that case stod will return a.b and not throw invalid_argument exception.
        To solve this, next_loc will get from stod the position of the first\
        character in strDouble after the double number. we except that this value
        is the end of the string and if not so, we will throw invalid_argument exception.
        */
        size_t next_loc;
        vDouble.push_back(stod(strDouble, &next_loc));
        if (next_loc < strDouble.length()) {
            throw invalid_argument("vector isn't in the right pattern");
        }
    }
    return vDouble;
}

/**
 * this method is in charge of creating a dictionary of vectors as keys and their group as values
 * from the file located at the address given to the program via the command line.
 * @param fileAddress the file path that the vectors are stored.
 * @return returns a dictionary created from the extracted data of the file of keys that are
 * vectors with "double" elements and values which are the vectors group that they are associated with.
 */
vector<Neighbor> ExtractData::fileToVec(string fileAddress) {
    vector<Neighbor> neighbors;
    //open a file in read mode
    ifstream infile;
    infile.open(fileAddress,
                ios::in); // try open relative path (relative to our environment - classifiedServer)
    if (!infile) {
        infile.open(fileAddress, ios::in); // try open absolute path
        if (!infile) {
            throw invalid_argument(fileAddress + " Not Found");
        }
    }
    string line;
    unsigned int vectorsSize = 0;
    while (getline(infile, line)) {
        //these variables contain the vector, and it's class that has last been
        // retrieved from the file
        vector<double> measurementsVector;
        string vectorClass;
        //turn long string into vector with elements according to comma separation
        vector<string> specificVector = splitString(line, ",");
        int size = specificVector.size();
        vectorClass = specificVector.at(size - 1);
        specificVector.resize(size - 1);
        //check for unifurm size in file
        if (vectorsSize == 0) {
            vectorsSize = specificVector.size();
        } else {
            if (vectorsSize != specificVector.size()) {
                throw invalid_argument("not all vector in " + fileAddress + " are in the same size!");
            }
        }
        if (vectorsSize)
            measurementsVector = strVectorToDouble(specificVector);
        neighbors.push_back(Neighbor(measurementsVector, vectorClass));
    }
    infile.close();
    return neighbors;
}