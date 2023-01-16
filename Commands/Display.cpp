#include "Display.h"

/**
 * constructor
 * @param df the IO to write from or read to
 */
Display::Display(DefaultIO *df) : Command("display results", df){}

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