/**
 * @file analytics.h
 * @author Aiden Manansala
 * @brief header file
 * @version 0.1
 * @date 2023-09-05
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#ifndef ANALYTICS_H
#define ANALYTICS_H

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std;

struct GradEmploymentData
{
    int demographicsTotal;     // The estimated total of people awarded degrees in this major during 2005
    string educationMajor;     // The name of the major for these graduated students
    float meanSalary;          // The average (mean) recorded salary reported for employed people with this degree
    float medianSalary;        // The median recorded salary reported for employed people with this degree
    int demographicsAsian;     // The estimated number of people identifying as Asian that were awarded degrees in this major
    int demographicsMinority;  // The estimated number of people identifying as minority 
                               // (e.g., Black, African American, Native American) that were awarded degrees in this major
    int demographicsWhite;     // The estimated number of people identifying as White that were awarded degrees in this major
    int demographicsFemales;   // The estimate number of women awarded degrees in this major
    int demographicsMales;     // The estimate number of men awarded degrees in this major
    int educationBachelor;     // The estimated number of bachelor degrees awarded in this for major
    int educationDoctorate;    // The estimated number of doctoral degrees awarded in this for major
    int educationMasters;      // The estimated number of Masters awarded in this for major
};

void fileToVector(ifstream &fileToRead, vector<GradEmploymentData> &vectorToWrite);
void showPrompt();
void dataServer(int selection);
void getSelection();
void highMean(vector<GradEmploymentData> vectorToRead);
void lowMean(vector<GradEmploymentData> vectorToRead);
void highMedian(vector<GradEmploymentData> vectorToRead);
void lowMedian(vector<GradEmploymentData> vectorToRead);
void highAsians(vector<GradEmploymentData> vectorToRead); // top 5 majors w highest asians
void lowAsians(vector<GradEmploymentData> vectorToRead);
void highMinorities(vector<GradEmploymentData> vectorToRead); // top5 majors w highest minorities
void lowMinorities(vector<GradEmploymentData> vectorToRead);
void highestTotal(vector<GradEmploymentData> vectorToRead); // top 5 majors w/ most total amount of people
void lowestTotal(vector<GradEmploymentData> vectorToRead);
void majorSpecific(vector<GradEmploymentData> vectorToRead);

#endif