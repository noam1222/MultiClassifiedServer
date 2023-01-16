#include "Display.h"

/**
 * constructor
 * @param df the IO to write from or read to
 * @param data the shared data of the commands
 */
Display::Display(DefaultIO *df, CommandsData &data) : Command("display results", df, data){}

/**
 * sent the client the results
 */
void Display::execute() {
    ifstream resultFile(m_data.getResultFileName());
    string result, line;
    while(getline(resultFile, line)) {
        result += line;
    }
    m_df->write(result + "Done.");
}