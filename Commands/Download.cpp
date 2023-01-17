#include "Download.h"

/**
 * constructor
 * @param df the IO to write from or read to
 * @param data the shared data of the commands
 */
Download::Download(DefaultIO *df, CommandsData &data) : Command("download results", df, data){}

/**
 * sent the client the results
 */
void Download::execute() {
    if (!m_data.hasUploadedFiles()) {
        m_df->write("please upload data");
        return;
    }
    if (!m_data.hasClasiifiedFile()) {
        m_df->write("please classify the data");
        return;
    }
    string result = ExtractData::readFromFile(m_data.getResultFileName());
    m_df->write(result + "\nDone.");
}