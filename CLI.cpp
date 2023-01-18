#include "CLI.h"

/**
 * constructor. initialize this m_commands - Upload, Setting, Classify, Display and Download.
 * @param df the IO to write from or read to.
 */
CLI::CLI(DefaultIO *df, int threadNum) : m_data(threadNum) {
    m_df = df;
    m_commands[0] = new Upload(m_df, m_data);
    m_commands[1] = new Settings(m_df, m_data);
    m_commands[2] = new Classify(m_df, m_data);
    m_commands[3] = new Display(m_df, m_data);
    m_commands[4] = new Download(m_df, m_data);
}

/**
 * write the menu to the Default IO
 */
void CLI::menu() {
    string result = "Welcome to the KNN Classifier Server. Please choose an option:\n";
    for (int i = 0; i < 5; i++) {
        result += to_string(i + 1) + ". " + m_commands[i]->getDescription() + "\n";
    }
    result += "8. exit\n";
    m_df->write(result);
}

/**
 * Run the command flow of the program
 */
void CLI::run() {
    menu();
    do {
        string c = m_df->read();
        if (c == "") {
            break;
        }
        int choose = ExtractData::parseStringToInt(c);
        choose--;
        m_commands[choose]->execute();
    } while (true);
}

CLI::~CLI() {
    for (int i = 0; i < 5; i++) {
        free (m_commands[i]);
    }
    free(m_df);
}