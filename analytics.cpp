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
    cout << endl << endl;
    cout << "2015 National Survey of Recent College Graduate" << endl;
    cout << "1. Top 10 Majors with the Highest Mean Salary" << endl;
    cout << "2. Top 10 Majors with the Lowest Mean Salary" << endl;
    cout << "3. Top 10 Majors with the Highest Median Salary" << endl;
    cout << "4. Top 10 Majors with the Lowest Median Salary" << endl;
    cout << "5. What are the Top 5 Majors with the Highest Number of Asians" << endl;
    cout << "6. What are the Top 5 Majors with the Lowest Number of Asians" << endl;
    cout << "7. What are the Top 5 Majors with the Highest Number of Minorities" << endl;
    cout << "8. What are the Top 5 Majors with the Lowest Number of Minorities" << endl;
    cout << "9. What are the Top 5 Majors with the Highest Numer of People" << endl;
    cout << "10. What are the Top 5 Majors with the Lowest Numer of People" << endl;
    cout << "11. Display Information for a Specific Major" << endl;
    cout << "12. Exit" << endl << endl;
}

/**
 * @brief Gets the selection of the user from the menu and feeds it into dataServer()
 * 
 */
void getSelection(vector<GradEmploymentData> vectorToRead){
    int selection;

    do {
        cout << "Select a Menu: ";
        cin >> selection;
        if(selection<1 && selection>12){ // input must be between 1-12
            cout << "Your input is out of bounds (1-12). Please input a correct selection." << endl << endl;
        }
    } while(selection<1 && selection>12);


    if(selection==1){
        highMean(vectorToRead);
    } else if(selection==2){
        lowMean(vectorToRead);
    } else if(selection==3){
        highMedian(vectorToRead);
    } else if(selection==4){
        lowMedian(vectorToRead);
    } else if(selection==5){
        highAsians(vectorToRead);
    } else if(selection==6){
        lowAsians(vectorToRead);
    } else if(selection==7){
        highMinorities(vectorToRead);
    } else if(selection==8){
        lowMinorities(vectorToRead);
    } else if(selection==9){
        highestTotal(vectorToRead);
    } else if(selection==10){
        lowestTotal(vectorToRead);
    } else if(selection==11){
        majorSpecific(vectorToRead);
    } else if(selection==12){
        cout << endl << "Exiting..." << endl;
        exit(0);
    }


/**
 * @brief Finds the highest mean salaries from the data
 * 
 */
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

    cout << "\nEducation Major                    Mean Salary" << endl;
    cout << "------------------------------------------------" << endl;
    for(int i=0; i<10; i++){
        cout << setw(35) << left << vectorToRead[i].educationMajor << right << "$" << setw(11) << fixed << setprecision(2) << vectorToRead[i].meanSalary << endl;
    }

    cout << "\nPress enter to continue...";
    char temp;
    cin.get(temp);
}

/**
 * @brief Finds the lowest mean salaries from the data
 * 
 * @param vectorToRead 
 */
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

    cout << "\nEducation Major                    Mean Salary" << endl;
    cout << "------------------------------------------------" << endl;
    for(int i=0; i<10; i++){
        cout << setw(35) << left << vectorToRead[i].educationMajor << right << "$" << setw(11) << fixed << setprecision(2) << vectorToRead[i].meanSalary << endl;
    }
    cout << "\nPress enter to continue...";
    char temp;
    cin.get(temp);
}

/**
 * @brief finds the highest median salaries from the data
 * 
 * @param vectorToRead 
 */
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

    cout << "\nEducation Major                  Meadian Salary" << endl;
    cout << "------------------------------------------------" << endl;
    for(int i=0; i<10; i++){
        cout << setw(35) << left << vectorToRead[i].educationMajor << right << "$" << setw(11) << fixed << setprecision(2) << vectorToRead[i].medianSalary << endl;
    }
    cout << "\nPress enter to continue...";
    char temp;
    cin.get(temp);
}

/**
 * @brief finds the lowest median salaries from the data
 * 
 * @param vectorToRead 
 */
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

    cout << "\nEducation Major                  Meadian Salary" << endl;
    cout << "------------------------------------------------" << endl;
    for(int i=0; i<10; i++){
        cout << setw(35) << left << vectorToRead[i].educationMajor << right << "$" << setw(11) << fixed << setprecision(2) << vectorToRead[i].medianSalary << endl;
    }
    cout << "\nPress enter to continue...";
    char temp;
    cin.get(temp);
}

/**
 * @brief Ranks top 5 majors with most asians
 * 
 * @param vectorToRead 
 */
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

    cout << "\nEducation Major              Demographic Asians" << endl;
    cout << "------------------------------------------------" << endl;
    for(int i=0; i<5; i++){
        cout << setw(35) << left << vectorToRead[i].educationMajor << right << setw(11) << fixed << setprecision(2) << vectorToRead[i].demographicsAsian << endl;
    }
    cout << "\nPress enter to continue...";
    char temp;
    cin.get(temp);
}

/**
 * @brief ranks top 5 majors with lowest Asians
 * 
 * @param vectorToRead 
 */
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

    cout << "\nEducation Major              Demographic Asians" << endl;
    cout << "------------------------------------------------" << endl;
    for(int i=0; i<5; i++){
        cout << setw(35) << left << vectorToRead[i].educationMajor << right << setw(11) << fixed << setprecision(2) << vectorToRead[i].demographicsAsian << endl;
    }
    cout << "\nPress enter to continue...";
    char temp;
    cin.get(temp);
}

/**
 * @brief ranks top 5 majors w highest miniorities
 * 
 * @param vectorToRead 
 */
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

    cout << "\nEducation Major          Demographic Minorities" << endl;
    cout << "------------------------------------------------" << endl;
    for(int i=0; i<5; i++){
        cout << setw(35) << left << vectorToRead[i].educationMajor << right << setw(11) << fixed << setprecision(2) << vectorToRead[i].demographicsMinority << endl;
    }
    cout << "\nPress enter to continue...";
    char temp;
    cin.get(temp);
}

/**
 * @brief ranks top 5 majors w lowest minorities
 * 
 * @param vectorToRead 
 */
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

    cout << "\nEducation Major          Demographic Minorities" << endl;
    cout << "------------------------------------------------" << endl;
    for(int i=0; i<5; i++){
        cout << setw(35) << left << vectorToRead[i].educationMajor << right << setw(11) << fixed << setprecision(2) << vectorToRead[i].demographicsMinority << endl;
    }
    cout << "\nPress enter to continue...";
    char temp;
    cin.get(temp);
}

/**
 * @brief ranks top 5 majors w highest number of people
 * 
 * @param vectorToRead 
 */
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

    cout << "\nEducation Major               Demographic Total" << endl;
    cout << "------------------------------------------------" << endl;
    for(int i=0; i<5; i++){
        cout << setw(35) << left << vectorToRead[i].educationMajor << right << setw(11) << fixed << setprecision(2) << vectorToRead[i].demographicsTotal << endl;
    }
    cout << "\nPress enter to continue...";
    char temp;
    cin.get(temp);
}

/**
 * @brief ranks top 5 majors with lowest number of people
 * 
 * @param vectorToRead 
 */
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

    cout << "\nEducation Major               Demographic Total" << endl;
    cout << "------------------------------------------------" << endl;
    for(int i=0; i<5; i++){
        cout << setw(35) << left << vectorToRead[i].educationMajor << right << setw(11) << fixed << setprecision(2) << vectorToRead[i].demographicsTotal << endl;
    }
    cout << "\nPress enter to continue...";
    char temp;
    cin.get(temp);
}

/**
 * @brief Reveals data about a specific user input major
 * 
 * @param vectorToRead 
 */
void majorSpecific(vector<GradEmploymentData> vectorToRead){
    GradEmploymentData holder;
    string major;
    int foundAt, index;

    cout << "What major would you look to see the info for? (Case Sensitive)" << endl;
    cin.ignore();
    getline(cin, major);

    
    
    // insertion sort using first letter ascii values to figure out < or >
    char charOne, charTwo; // holds the first character of the strings that you are comparing
	int key;
	GradEmploymentData majorHolder;
	for(int i=1; i<vectorToRead.size(); i++){
		key = i;	
		for(int x=1; x<=i; x++){
			charOne = vectorToRead[key].educationMajor.at(0);
			charTwo = vectorToRead[i-x].educationMajor.at(0);
			if(charOne < charTwo){
				majorHolder = vectorToRead[i-x];
				vectorToRead[i-x] = vectorToRead[key];
				vectorToRead[key] = majorHolder;
				key--;
			}
		}
	}
	
	

	// binary search on the sorted majors
    int low = 0;
    int high = vectorToRead.size()-1;
    int mid = (low+high)/2;
    int counter;

    while(true){
        if(vectorToRead[mid].educationMajor == major){
            break;
        } else {
            counter = 0;
            while(vectorToRead[mid].educationMajor[counter] == major[counter]) {counter++;};

            if(vectorToRead[mid].educationMajor[counter] > major[counter]){
                high = mid;
                mid = (low+high)/2;
            } else{
                low = mid+1;
                mid = (low+high)/2;
            }
        }

        index = mid;

    }

    	
    cout << endl << setw(35) << left << major << right << setw(11) << "Data" << endl;
    cout << "------------------------------------------------" << endl;
    cout << setw(35) << left << "Demographics Total" << right << setw(11) << fixed << setprecision(2) << vectorToRead[index].demographicsTotal << endl;
    cout << setw(35) << left << "Mean Salary" << right << setw(11) << fixed << setprecision(2) << vectorToRead[index].meanSalary << endl;
    cout << setw(35) << left << "Median Salary" << right << setw(11) << fixed << setprecision(2) << vectorToRead[index].medianSalary << endl;
    cout << setw(35) << left << "Ethnicity Asian" << right << setw(11) << fixed << setprecision(2) << vectorToRead[index].demographicsAsian << endl;
    cout << setw(35) << left << "Demographic Minorities" << right << setw(11) << fixed << setprecision(2) << vectorToRead[index].demographicsMinority << endl;
    cout << setw(35) << left << "Ethnicity White" << right << setw(11) << fixed << setprecision(2) << vectorToRead[index].demographicsWhite << endl;
    cout << setw(35) << left << "Gender Female" << right << setw(11) << fixed << setprecision(2) << vectorToRead[index].demographicsFemales << endl;
    cout << setw(35) << left << "Gender Male" << right << setw(11) << fixed << setprecision(2) << vectorToRead[index].demographicsMales << endl;
    cout << setw(35) << left << "Bachelors Degree" << right << setw(11) << fixed << setprecision(2) << vectorToRead[index].educationBachelor << endl;
    cout << setw(35) << left << "Doctorate Degree" << right << setw(11) << fixed << setprecision(2) << vectorToRead[index].educationDoctorate << endl;
    cout << setw(35) << left << "Masters Degree" << right << setw(11) << fixed << setprecision(2) << vectorToRead[index].educationMasters << endl;
	


    cout << "\nPress enter to continue...";
    char temp;
    cin.get(temp);
}
