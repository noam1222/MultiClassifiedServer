#include "Upload.h"

Upload::Upload(DefaultIO *df) : Command("upload an unclassified csv data file", df){}

void Upload::createFile(string name, string content){
    string path = PATH + name;
    ofstream file(path);
    file << content;
    file.close();
}

void Upload::execute() {
    m_df->write("Please upload your local train CSV file.");
    string content = m_df->read();
    createFile("classified", content);

    m_df->write("Please upload your local test CSV file.");
    content = m_df->read();
    createFile("unclassified", content);

    m_df->write("Upload complete.");
}