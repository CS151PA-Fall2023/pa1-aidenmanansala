/**
 * @file analytics.cpp
 * @author Aiden Manansala
 * @brief All the functions to read, write, and manipulate data from a csv file
 * @version 0.1
 * @date 2023-09-05
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include "analytics.h"

/**
 * @brief Reads the data from a csv file into a vector with GradEmploymentData elements
 * 
 * @param fileToRead 
 * @param vectorToWrite 
 */
void fileToVector(ifstream &fileToRead, vector<GradEmploymentData> &vectorToWrite){
    string holder;

    char delim=',';

    getline(fileToRead, holder); // grab the column names and put the in the holder, we dont care about them
    while(fileToRead.peek()!=EOF){ // loop until the end of the file
        GradEmploymentData sectionData;

        fileToRead >> sectionData.demographicsTotal >> delim;

        // handling names with the quotes in them, we want to ignore the commas bc they arent the deliminator in this case
        if(fileToRead.peek()=='"'){
            fileToRead >> delim; // "eat" the quote, since it is next in the stream
            getline(fileToRead, sectionData.educationMajor, '"'); // read until endquote
            fileToRead >> delim; // for the comma
        } else{
            getline(fileToRead, sectionData.educationMajor, ','); // get major string from file, put it in object major member
        }
        
        fileToRead >> sectionData.meanSalary >> delim; // read number until delim, store it in the structure
        fileToRead >> sectionData.medianSalary >> delim;
        fileToRead >> sectionData.demographicsAsian >> delim;
        fileToRead >> sectionData.demographicsMinority >> delim;
        fileToRead >> sectionData.demographicsWhite >> delim;
        fileToRead >> sectionData.demographicsFemales >> delim;
        fileToRead >> sectionData.demographicsMales >> delim;
        fileToRead >> sectionData.educationBachelor >> delim;
        fileToRead >> sectionData.educationDoctorate >> delim;
        fileToRead >> sectionData.educationMasters; 

        if(sectionData.educationMajor!=""){ // need to include this because for some reason the last line was getting included again with an empty major string
            vectorToWrite.push_back(sectionData); // push the object to the end of the vector... each iteration, the respective object is pushed to its own index
        }
    }
}

/**
 * @brief Prompts the user for a menu, asks for an input
 * 
 */
void showPrompt(){
    cout << "\n2015 National Survey of Recent College Graduate" << endl;
    cout << "1. Top 10 Majors with the Highest Mean Salary" << endl;
    cout << "2. Top 10 Majors with the Lowest Mean Salary" << endl;
    cout << "3. Top 10 Majors with the Highest Median Salary" << endl;
    cout << "4. Top 10 Majors with the Lowest Median Salary" << endl;
    cout << "5. What are the Top 5 Majors with the Highest Number of Asians" << endl;
    cout << "6. What are the Top 5 Majors with the Lowest Number of Asians" << endl;
    cout << "7. What are the Top 5 Majors with the Highest Number of Minorities" << endl;
    cout << "8. What are the Top 5 Majors with the Lowest Number of Minorities" << endl;
    cout << "9. <Design and implement a menu item that provides information through the data>" << endl;
    cout << "10. <Design and implement a menu item that provides information through the data>" << endl;
    cout << "11. Display Information for a Specific Major" << endl;
    cout << "12. Exit" << endl << endl;
}

/**
 * @brief Gets the selection of the user from the menu and feeds it into dataServer()
 * 
 */
void getSelection(){
    int selection;

    do {
        cout << "Select a Menu: ";
        cin >> selection;
        if(selection>0 && selection<13){ // input must be between 1-12
            cout << "Your input is out of bounds (1-12). Please input a correct selection." << endl << endl;
        }
    } while(selection<1 && selection>12);


    // write code to call the sort / manip function based on input number
    // if selection is 12, exit


}

void highMean(vector<GradEmploymentData> vectorToRead){
    GradEmploymentData holder;
    bool switched = true;
    while(switched==true){
        switched = false;
        for(int i=0; i<vectorToRead.size()-1; i++){
            if(vectorToRead[i+1].meanSalary > vectorToRead[i].meanSalary){
                holder = vectorToRead[i];
                vectorToRead[i] = vectorToRead[i+1];
                vectorToRead[i+1] = holder;
                switched = true;
            }
        }
    }

    cout << "Education Major                    Mean Salary" << endl;
    cout << "------------------------------------------------" << endl;
    for(int i=0; i<10; i++){
        cout << setw(35) << left << vectorToRead[i].educationMajor << right << "$" << setw(11) << fixed << setprecision(2) << vectorToRead[i].meanSalary << endl;
    }
}

void lowMean(vector<GradEmploymentData> vectorToRead){
    GradEmploymentData holder;
    bool switched = true;
    while(switched==true){
        switched = false;
        for(int i=0; i<vectorToRead.size()-1; i++){
            if(vectorToRead[i+1].meanSalary < vectorToRead[i].meanSalary){
                holder = vectorToRead[i];
                vectorToRead[i] = vectorToRead[i+1];
                vectorToRead[i+1] = holder;
                switched = true;
            }
        }
    }

    cout << "Education Major                    Mean Salary" << endl;
    cout << "------------------------------------------------" << endl;
    for(int i=0; i<10; i++){
        cout << setw(35) << left << vectorToRead[i].educationMajor << right << "$" << setw(11) << fixed << setprecision(2) << vectorToRead[i].meanSalary << endl;
    }
}

void highMedian(vector<GradEmploymentData> vectorToRead){
    GradEmploymentData holder;
    bool switched = true;
    while(switched==true){
        switched = false;
        for(int i=0; i<vectorToRead.size()-1; i++){
            if(vectorToRead[i+1].medianSalary > vectorToRead[i].medianSalary){
                holder = vectorToRead[i];
                vectorToRead[i] = vectorToRead[i+1];
                vectorToRead[i+1] = holder;
                switched = true;
            }
        }
    }

    cout << "Education Major                  Meadian Salary" << endl;
    cout << "------------------------------------------------" << endl;
    for(int i=0; i<10; i++){
        cout << setw(35) << left << vectorToRead[i].educationMajor << right << "$" << setw(11) << fixed << setprecision(2) << vectorToRead[i].medianSalary << endl;
    }
}

void lowMedian(vector<GradEmploymentData> vectorToRead){
    GradEmploymentData holder;
    bool switched = true;
    while(switched==true){
        switched = false;
        for(int i=0; i<vectorToRead.size()-1; i++){
            if(vectorToRead[i+1].medianSalary < vectorToRead[i].medianSalary){
                holder = vectorToRead[i];
                vectorToRead[i] = vectorToRead[i+1];
                vectorToRead[i+1] = holder;
                switched = true;
            }
        }
    }

    cout << "Education Major                  Meadian Salary" << endl;
    cout << "------------------------------------------------" << endl;
    for(int i=0; i<10; i++){
        cout << setw(35) << left << vectorToRead[i].educationMajor << right << "$" << setw(11) << fixed << setprecision(2) << vectorToRead[i].medianSalary << endl;
    }
}

void highAsians(vector<GradEmploymentData> vectorToRead){ // top 5 majors w highest asians  
    GradEmploymentData holder;
    bool switched = true;
    while(switched==true){
        switched = false;
        for(int i=0; i<vectorToRead.size()-1; i++){
            if(vectorToRead[i+1].demographicsAsian > vectorToRead[i].demographicsAsian){
                holder = vectorToRead[i];
                vectorToRead[i] = vectorToRead[i+1];
                vectorToRead[i+1] = holder;
                switched = true;
            }
        }
    }

    cout << "Education Major              Demographic Asians" << endl;
    cout << "------------------------------------------------" << endl;
    for(int i=0; i<5; i++){
        cout << setw(35) << left << vectorToRead[i].educationMajor << right << setw(11) << fixed << setprecision(2) << vectorToRead[i].demographicsAsian << endl;
    }
}

void lowAsians(vector<GradEmploymentData> vectorToRead){ // top 5 majors w highest asians  
    GradEmploymentData holder;
    bool switched = true;
    while(switched==true){
        switched = false;
        for(int i=0; i<vectorToRead.size()-1; i++){
            if(vectorToRead[i+1].demographicsAsian < vectorToRead[i].demographicsAsian){
                holder = vectorToRead[i];
                vectorToRead[i] = vectorToRead[i+1];
                vectorToRead[i+1] = holder;
                switched = true;
            }
        }
    }

    cout << "Education Major              Demographic Asians" << endl;
    cout << "------------------------------------------------" << endl;
    for(int i=0; i<5; i++){
        cout << setw(35) << left << vectorToRead[i].educationMajor << right << setw(11) << fixed << setprecision(2) << vectorToRead[i].demographicsAsian << endl;
    }
}

void highMinorities(vector<GradEmploymentData> vectorToRead){ // top5 majors w highest minorities
    GradEmploymentData holder;
    bool switched = true;
    while(switched==true){
        switched = false;
        for(int i=0; i<vectorToRead.size()-1; i++){
            if(vectorToRead[i+1].demographicsMinority > vectorToRead[i].demographicsMinority){
                holder = vectorToRead[i];
                vectorToRead[i] = vectorToRead[i+1];
                vectorToRead[i+1] = holder;
                switched = true;
            }
        }
    }

    cout << "Education Major          Demographic Minorities" << endl;
    cout << "------------------------------------------------" << endl;
    for(int i=0; i<5; i++){
        cout << setw(35) << left << vectorToRead[i].educationMajor << right << setw(11) << fixed << setprecision(2) << vectorToRead[i].demographicsMinority << endl;
    }
}

void lowMinorities(vector<GradEmploymentData> vectorToRead){
    GradEmploymentData holder;
    bool switched = true;
    while(switched==true){
        switched = false;
        for(int i=0; i<vectorToRead.size()-1; i++){
            if(vectorToRead[i+1].demographicsMinority < vectorToRead[i].demographicsMinority){
                holder = vectorToRead[i];
                vectorToRead[i] = vectorToRead[i+1];
                vectorToRead[i+1] = holder;
                switched = true;
            }
        }
    }

    cout << "Education Major          Demographic Minorities" << endl;
    cout << "------------------------------------------------" << endl;
    for(int i=0; i<5; i++){
        cout << setw(35) << left << vectorToRead[i].educationMajor << right << setw(11) << fixed << setprecision(2) << vectorToRead[i].demographicsMinority << endl;
    }
}

void highestTotal(vector<GradEmploymentData> vectorToRead){ // top 5 majors w/ most total amount of people
    GradEmploymentData holder;
    bool switched = true;
    while(switched==true){
        switched = false;
        for(int i=0; i<vectorToRead.size()-1; i++){
            if(vectorToRead[i+1].demographicsTotal > vectorToRead[i].demographicsTotal){
                holder = vectorToRead[i];
                vectorToRead[i] = vectorToRead[i+1];
                vectorToRead[i+1] = holder;
                switched = true;
            }
        }
    }

    cout << "Education Major               Demographic Total" << endl;
    cout << "------------------------------------------------" << endl;
    for(int i=0; i<5; i++){
        cout << setw(35) << left << vectorToRead[i].educationMajor << right << setw(11) << fixed << setprecision(2) << vectorToRead[i].demographicsTotal << endl;
    }
}

void lowestTotal(vector<GradEmploymentData> vectorToRead){
    GradEmploymentData holder;
    bool switched = true;
    while(switched==true){
        switched = false;
        for(int i=0; i<vectorToRead.size()-1; i++){
            if(vectorToRead[i+1].demographicsTotal < vectorToRead[i].demographicsTotal){
                holder = vectorToRead[i];
                vectorToRead[i] = vectorToRead[i+1];
                vectorToRead[i+1] = holder;
                switched = true;
            }
        }
    }

    cout << "Education Major               Demographic Total" << endl;
    cout << "------------------------------------------------" << endl;
    for(int i=0; i<5; i++){
        cout << setw(35) << left << vectorToRead[i].educationMajor << right << setw(11) << fixed << setprecision(2) << vectorToRead[i].demographicsTotal << endl;
    }
}

void majorSpecific(vector<GradEmploymentData> vectorToRead){
    
}