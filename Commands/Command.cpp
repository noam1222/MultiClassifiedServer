#include "Command.h"

/**
 * constructor
 * @param description the description of the command
 * @param df the IO to write from or read to
 * @param data the shared data of the commands
 */
Command::Command(string description, DefaultIO *df, CommandsData &data) : m_data(data) {
    m_description = description;
    m_df = df;
}

/**
 * get the string description of the command
 * @return the string description of the command
 */
string Command::getDescription() { return m_description; }