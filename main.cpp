/**
 * @file main.cpp
 * @author Aiden Manansala
 * @brief Reads, writes, and manipulates data from a csv file
 * @version 0.1
 * @date 2023-09-05
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#include <iostream>
#include <vector>
#include "analytics.h"

using namespace std;

int main() {
    ifstream dataFile;
    dataFile.open("graduates2015.csv");

    vector<GradEmploymentData> data;

    fileToVector(dataFile, data); 
    dataFile.close();

    while(true){
        showPrompt();
        getSelection(data);
    }

    return 0;
}