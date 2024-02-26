#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <vector>
#include <windows.h>
#include <limits>
#include <algorithm>

// I handled the void viewResults() Function

using namespace std;

// Data structure to store login information
struct LoginDetails {
    string username;
    string password;
};

// Function to read login information from a file and store it in a map
map<string, string> readLoginDetails(const string& filename);

// Function to authenticate the user
bool authenticate(const map<string, string>& loginMap);

// Function to display student records for a specific matriculation number
// This Function was handled by me (OBIEKWE KENE CHRISTOPHER)
void viewResults(const string& matriculationNumber);

// Function to display student records for all files
void viewAllResults();

// Function to update student records based on subjects and scores
void updateResults();

// Function to create a new student record
void createNewRecord();

// Function to get a list of files in a directory (Windows)
void getFilesInDirectory(const string& directory, vector<string>& fileNames);

int main() {
	
	cout << "\t\t**Welcome to PAU Result Management System**\n";
	
    const string LOGIN_DETAILS_FILE = "admin_details.txt";

    // Read login details into a map
    map<string, string> loginMap = readLoginDetails(LOGIN_DETAILS_FILE);

    if (loginMap.empty()) {
        cerr << "[Error] Unable to authenticate. Exiting program." << endl;
        return 1;
    }

    // Authenticate user
    if (authenticate(loginMap)) {
        // Display the main menu
        char choice;
        do {
            cout << "\nResult Management System Menu:\n";
            cout << "a. View Student Records\n";
            cout << "b. Update Results\n";
            cout << "c. View All Records\n";
            cout << "d. Create New Record\n";
            cout << "e. Exit\n";
            cout << "Enter your choice: ";

            if (!(cin >> choice)) {
                cerr << "[Error]Invalid input. Exiting program..." << endl;
                return 1;
            }
            
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // discard invalid input

            switch (tolower(choice)) {
                case 'a': {
                    string matriculationNumber;
                    do {
                        cout << "Enter student's matriculation number: ";
                        cin >> matriculationNumber;

                        // Validate matriculation number
                        if (matriculationNumber.size() != 11 || matriculationNumber.substr(0, 6) != "221206") {
                            cout << "[Error]Invalid matriculation number. Please try again...\n";
                        } else {
                            break;  // Valid matriculation number
                        }
                    } while (true);

                    viewResults(matriculationNumber);
                    break;
                }
                case 'b':
                    updateResults();
                    break;
                case 'c':
                    viewAllResults(); 
                    break;
                case 'd':
                    createNewRecord();
                    break;
                case 'e':
                    cout << "Exiting program. Goodbye!\n";
                    break;
                default:
                    cout << "Invalid choice. Please try again...\n";
                    cin.clear(); // clear the error flag
                    
            }
        } while (choice != 'e');
    } else {
        cerr << "[Error]Authentication failed. Exiting program..." << endl;
        return 1;
    }

    return 0;
}

// Function to read login information from a file and store it in a map
map<string, string> readLoginDetails(const string& filename) {
    map<string, string> loginMap;
    ifstream inFile(filename);

    if (!inFile) {
        cerr << "[Error]Unable to open login details file." << endl;
        return loginMap;  // Empty map on failure
    }

    LoginDetails login;
    string line;

    while (getline(inFile, line)) {
        size_t pos = line.find(',');
        if (pos != string::npos) {
            login.username = line.substr(0, pos);
            login.password = line.substr(pos + 1);
            loginMap[login.username] = login.password;
        }
    }

    inFile.close();

    return loginMap;
}

// Function to authenticate the user
bool authenticate(const map<string, string>& loginMap) {
    string username, password;
    bool authenticated = false;

    do {
        cout << "Enter username: ";
        if (!getline(cin, username)) {
            cerr << "[Error]Unable to read username. Exiting program..." << endl;
            return false;
        }

        cout << "Enter password: ";
        if (!(cin >> password)) {
            cerr << "[Error]Unable to read password. Exiting program..." << endl;
            return false;
        }

        // Clear any remaining characters in the input buffer
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        auto it = loginMap.find(username);

        if (it != loginMap.end() && it->second == password) {
            authenticated = true;  // Authentication successful
        } else {
            cout << "Authentication failed. Please try again.\n";
        }

    } while (!authenticated);

    cout << "Authentication successful. Proceeding with the program...\n";
    return true;
}

// Function to display student records for a specific matriculation number
// This Function was handled by me (OBIEKWE KENE CHRISTOPHER)
void viewResults(const string& matriculationNumber) {
    string filename = matriculationNumber + ".txt";
    ifstream inFile(filename);

    if (!inFile) {
        cout << "Error opening file. Student record not found.\n";
        return;
    }

    string line;
    cout << "\n*** Student Records ***\n";
    while (getline(inFile, line)) {
        cout << line << endl;
    }

    inFile.close();
}

// Function to get a list of files in a directory
void getFilesInDirectory(const string& directory, vector<string>& fileNames) {
    string searchPath = directory + "/*";
    WIN32_FIND_DATA findFileData;
    HANDLE hFind = FindFirstFile(searchPath.c_str(), &findFileData);

    if (hFind == INVALID_HANDLE_VALUE) {
        cerr << "Error opening directory: " << directory << endl;
        return;
    }

    do {
        string filename = findFileData.cFileName;
        if (filename != "." && filename != "..") {
            fileNames.push_back(filename);
        }
    } while (FindNextFile(hFind, &findFileData) != 0);

    FindClose(hFind);
}

// Function to update student records based on subjects and scores
void updateResults() {
    string matriculationNumber;
    cout << "Enter student's matriculation number: ";
    cin >> matriculationNumber;

    string filename = matriculationNumber + ".txt";
    ifstream inFile(filename);
    ofstream outFile("temp.txt");  // Temporary file for updating records

    if (!inFile || !outFile) {
        cerr << "Error opening files for updating records.\n";
        return;
    }

    string targetCourseCode;
    const vector<string> validCourseCodes = {"MTH201", "CSC201", "CSC203", "ENT201", "INS204", "SEN114", "SEN201", "SEN211", "SEN292"};

    do {
        cout << "Enter the course code of the subject to be modified (or 'exit' to stop): ";
        cin >> targetCourseCode;

        if (targetCourseCode == "exit") {
            break;
        }

        // Check if the entered course code is valid
        if (find(validCourseCodes.begin(), validCourseCodes.end(), targetCourseCode) == validCourseCodes.end()) {
            cout << "[Error]Invalid course code. Please enter a valid course code.\n";
            continue;
        }

        string replacementValue;
        cout << "Enter the replacement value: ";
        cin >> replacementValue;

        // Validate that the replacement value is a number less than or equal to 100
        try {
            double replacementValueNum = stod(replacementValue);
            if (replacementValueNum < 0 || replacementValueNum > 100) {
                cout << "[Error]Replacement value must be a number between 0 and 100.\n";
                continue;
            }
        } catch (const invalid_argument& e) {
            cout << "[Error]Invalid replacement value. Please enter a valid number.\n";
            continue;
        }

        string line;
        bool recordFound = false;

        while (getline(inFile, line)) {
            size_t pos = line.find(targetCourseCode);
            if (pos != string::npos && !recordFound) {
                line = targetCourseCode + "          " + replacementValue;
                recordFound = true;
            }
            outFile << line << endl;
        }

        inFile.clear(); // Clear the end-of-file flag
        inFile.seekg(0, ios::beg); // Move file pointer to the beginning

        if (recordFound) {
            cout << "Record updated successfully.\n";
        } else {
            cout << "Student with matriculation number " << matriculationNumber << " not found.\n";
        }
    } while (true);

    // Close the files
    inFile.close();
    outFile.close();

     // Display the updated file contents
    ifstream updatedFile("temp.txt");
    if (updatedFile) {
        cout << "\n*** Updated Student Records ***\n";
        string line;
        while (getline(updatedFile, line)) {
            cout << line << endl;
        }
        updatedFile.close();
    } else {
        cerr << "Error opening updated file.\n";
    }

    // Rename the temporary file
    remove(filename.c_str());
    rename("temp.txt", filename.c_str());
}

// Function to display student records for all files
void viewAllResults() {
    const string prefix = "221206";
    cout << "\n*** All Student Records ***\n";

    // Get a list of files in the current directory
    vector<string> fileNames;
    getFilesInDirectory(".", fileNames);

    for (const string& filename : fileNames) {
        if (filename.substr(0, prefix.size()) == prefix) {
            cout << "\n*** Student Records for " << filename << " ***\n";
            ifstream inFile(filename);

            if (!inFile) {
                cout << "Error opening file. Student record not found.\n";
                continue;  // Move to the next file
            }

            string line;
            while (getline(inFile, line)) {
                cout << line << endl;
            }

            inFile.close();
        }
    }
}


void createNewRecord() {
    string matriculationNumber;
    cout << "Enter student's matriculation number: ";
    cin >> matriculationNumber;

    // Check if the matriculation number is valid
    if (matriculationNumber.size() != 11 || matriculationNumber.substr(0, 6) != "221206") {
        cout << "[Error] Invalid matriculation number. Aborting record creation.\n";
        return;
    }

    // Check if the file already exists
    string filename = matriculationNumber + ".txt";
    ifstream fileExists(filename);
    if (fileExists) {
        cout << "[Error] A record with matriculation number " << matriculationNumber << " already exists. Try again with a different matriculation number.\n";
        return;
    }

    ofstream outFile(filename);

    if (!outFile) {
        cerr << "[Error] Unable to open file for record creation.\n";
        return;
    }

    // Input student details
    string name;
    cout << "Enter student's name: ";
    cin.ignore(); // Clear newline character from the buffer
    getline(cin, name);

    outFile << "Matriculation Number: " << matriculationNumber << endl;
    outFile << "Stundent Name: " << name << endl;

    // Input scores for each course
    const vector<string> courseCodes = {"MTH201", "CSC201", "CSC203", "ENT201", "INS204", "SEN114", "SEN201", "SEN211", "SEN292"};

    for (const string& courseCode : courseCodes) {
        double score;
        cout << "Enter score for " << courseCode << ": ";
        while (!(cin >> score) || score < 0 || score > 100) {
            cout << "[Error] Invalid score. Please enter a valid score between 0 and 100.\n";
            cin.clear(); // Clear the error flag
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard invalid input
        }

        outFile << courseCode << "          " << score << endl;
    }

    cout << "\nRecord created successfully.\n";
    outFile.close();

    // Display the contents of the newly created file
    ifstream inFile(filename);
    if (inFile) {
        cout << "\n*** New Student Record ***\n";
        string line;
        while (getline(inFile, line)) {
            cout << line << endl;
        }
        inFile.close();
    } else {
        cerr << "Error opening newly created file.\n";
    }
}