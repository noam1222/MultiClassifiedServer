#include "Upload.h"

/**
 * constructor
 * @param df the IO to write from or read to
 */
Upload::Upload(DefaultIO *df) : Command("upload an unclassified csv data file", df){}

/**
 * crate file in received path and with received content
 * @param path path to create the file in. if already exist, will override it.
 * @param content content to write to the file/
 */
void Upload::createFile(string path, string content){
    ofstream file(path);
    file << content;
    file.close();
}

/**
 * receive and save the uploaded files from the client.
 */
void Upload::execute() {
    m_df->write("Please upload your local train CSV file.");
    string content = m_df->read();
    string path = PATH + "classified";
    createFile(path, content);
    m_data.setClassifiedFilePath(path);

    m_df->write("Please upload your local test CSV file.");
    content = m_df->read();
    path = PATH + "unclassified";
    createFile(path, content);
    m_data.setUnclassifiedFilePath(path);

    m_df->write("Upload complete.");
}