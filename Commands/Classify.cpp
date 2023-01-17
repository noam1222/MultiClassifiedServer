#include "Classify.h"

/**
 * constructor
 * @param df the IO to write from or read to
 * @param data the shared data of the commands
 */
Classify::Classify(DefaultIO *df, CommandsData &data) : Command("classify data", df, data){}

/**
 * execute the command - classify al the vector in the unclassified file based on the classified file.
 */
void Classify::execute() {
    if (!m_data.hasUploadedFiles()) {
        m_df->write("please upload data");
        return;
    }
    unsigned int k = m_data.getK();
    vector<Neighbor> neighbors = ExtractData::fileToVec(m_data.getClassifiedFileName());
    Distance *d = ExtractData::getDistanceByStr(m_data.getDistanceMethod());
    KnnAlgorithm knn(k, neighbors, d);

    string unclassifiedName = m_data.getUnclassifiedFileName();
    ifstream sourceFile(unclassifiedName);
    size_t delim = unclassifiedName.find(".csv");
    string resultFileName = unclassifiedName.substr(0, delim) + "_result.csv";
    ofstream resultFile(resultFileName);
    string line;
    try {
        int lineNum = 1;
        while (getline(sourceFile, line)) {
            vector<string> vecToCompStr = ExtractData::splitString(line, ",");
            vector<double> vecToComp = ExtractData::strVectorToDouble(vecToCompStr);
            string result = knn.getDefinition(vecToComp);
            resultFile << lineNum << " " << result << "\n";
            lineNum++;
        }
        m_df->write("classifying data complete");
        m_data.Classified();
        m_data.setResultFileName(resultFileName);
    } catch (invalid_argument &e) {
        m_df->write("invalid input");
    }
    sourceFile.close();
    resultFile.close();
}