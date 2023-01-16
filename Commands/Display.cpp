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
    string result = ExtractData::readFromFile(m_data.getResultFileName());
    m_df->write(result + "Done.");
}