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

    string result = ExtractData::readFromFile(m_data.getResultFileName());
    m_df->write(result + "Done.");
}