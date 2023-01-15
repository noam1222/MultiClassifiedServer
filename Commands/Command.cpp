#include "Command.h"

/**
 * constructor
 * @param description the description of the command
 * @param df the IO to write from or read to
 */
Command::Command(string description, DefaultIO *df) {
    m_description = description;
    m_df = df;
    m_data = CommandsData();
}