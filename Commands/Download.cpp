#include "Download.h"

/**
 * constructor
 * @param df the IO to write from or read to
 */
Download::Download(DefaultIO *df) : Command("download results", df){}

/**
 * sent the client the results
 */
void Download::execute() {
    ifstream resultFile(m_data.getResultFileName());
    string result, line;
    while(getline(resultFile, line)) {
        result += line;
    }
    m_df->write(result + "Done.");
}