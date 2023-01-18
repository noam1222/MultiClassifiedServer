#include "Upload.h"

/**
 * constructor
 * @param df the IO to write from or read to
 * @param data the shared data of the commands
 */
Upload::Upload(DefaultIO *df, CommandsData &data) : Command("upload an unclassified csv data file", df, data){}


/**
 * receive and save the uploaded files from the client.
 */
void Upload::execute() {
    m_df->write("Please upload your local train CSV file.");
    string content = m_df->read();
    if (!content.length()) {
        m_data.Uploaded(false);
        return;
    }
    string path = PATH + to_string(m_data.getThreadNumber()) + "classified.csv";
    ExtractData::writeToFile(path, content);
    m_data.setClassifiedFilePath(path);
    m_df->write("Upload complete.\nPlease upload your local test CSV file.");
    content = m_df->read();
    if (!content.length()) {
        m_data.Uploaded(false);
        return;
    }
    path = PATH + "unclassified" + to_string(m_data.getThreadNumber()) + ".csv";
    ExtractData::writeToFile(path, content);
    m_data.setUnclassifiedFilePath(path);
    m_df->write("Upload complete.");

    m_data.Uploaded(true); //notice that the user upload the files
}