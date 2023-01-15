#include "settings.h"
#include "SocketIO.h"

/**
 * constructor
 * @param df
 */
Settings::Settings(DefaultIO *df) : Command("algorithm setting", df) {
}

/**
 * execute the command -
 * first write the current settings and if the client want, change it.
 */
void Settings::execute() {
    m_df->write("The current KNN parameters are K = " + to_string(m_data.getK()) + ", distance metric = " + m_data.getDistanceMethod());
    string response = m_df->read();
    //as agreed in protocol, if the client return empty message it means - don't change anything.
    if (response.length()) {
        //assume correct input, check in client side.
        size_t nextLoc;
        int k = stoi(response, &nextLoc);
        string newDistance = response.substr(nextLoc + 1);
        m_data.setK(k);
        m_data.setDistanceMethod(newDistance);
    }
}