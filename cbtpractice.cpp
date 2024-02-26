// COMPUTER BASED TEST PROGRAM FOR C++
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <limits>
using namespace std;

void signup(){
    vector<string> vfile;
    string inp;
    cout << "Enter a username: ";
    cin.ignore();
    getline(cin, inp);

    string inp2;
    cout << "Enter a password: ";
    getline(cin, inp2);

    string combinedlogin = inp + "," + inp2;
    vfile.push_back(combinedlogin);

    ofstream nfile("signup.login.csv", ios::app);
    if (nfile.is_open()) {
        for (const auto &file : vfile) {
            nfile << file << endl;
        }
        cout << "Login Details Saved Successfully\nWelcome to the CBT program " << endl;
        nfile.close();
    } else {
        cout << "Unable to open the file" << endl;
    }
}

bool login(){
    string filename = "signup.login.csv";
    ifstream file(filename);

    if (!file.is_open()){
        cerr << "Error opening file: " << filename << endl;
        return false;
    }

    string line;
    string inp;
    string inp2;

    cout << "Enter a username: ";
    cin.ignore();
    getline(cin, inp);

    cout << "Enter a password: ";
    getline(cin, inp2);

    bool loginsuccessful = false;

    while(getline(file, line)) {
        stringstream ss(line);
        string uname, pass;
        getline(ss, uname, ',');
        getline(ss, pass);

        if(uname == inp && pass == inp2){
            loginsuccessful = true;
            break;
        }
    }

    file.close();
    return loginsuccessful;
}
void qdisplay(int start, int end){
    string filename = "questions.csv";
    ifstream file(filename);
    if (!file.is_open()) {
        cerr << "Error opening file: " << filename << endl;
        return;
    }
    string line;
    int current = 0;
    while (getline(file, line)) {
        current++;
        if (current >= start && current <= end) {
            cout<< line << endl;
        }
        if (current == end) {
            break;
        }
    }
    file.close();
}
void adisplay(){
    string ans;
    cout <<"Do you want to view corrections?(Y/N)\nOption: ";
    cin >> ans;
    if(ans == "y" || ans == "Y"){
        ifstream qans("answers.csv");
        string line;
        if(qans.is_open()){
            while(getline (qans,line)){
                cout << line << '\n';
            }
            qans.close();
            cout <<"THANK YOU FOR USING THIS CBT PROGRAM!"<<endl;
        }
        else{
            cout <<"Unable to open file";
        }
    }
    else if(ans == "n" || ans == "N"){
        cout <<"THANK YOU FOR USING THIS CBT PROGRAM!"<<endl;
    }
    else{
        cout <<"Choose a valid Option" <<endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); //To prevent infinite loop due to invalid input
        adisplay();
    }
}
void skip1(); //Prototype Declaration
void skip23(); //Prototype Declaration
void skip34(); //Prototype Declaration
void skip45(); //Prototype Declaration
int i = 0;
string sinp, s23inp, s34inp, s45inp, b5inp;
vector <string> answers;
void tscript(){
    ofstream qans("testscript.csv");
    if(qans.is_open()){
        for (const auto &tans : answers) {
            qans << tans << endl;
        }
        qans.close();
    } else {
        cout << "Unable to open the file" << endl;
    }
    char uscript;
    cout <<"Do you want to view your test script(Y/N)\nOption: ";
    cin >> uscript;
    if(uscript=='y' || uscript=='Y'){
        ifstream tans("testscript.csv");
        string line;
        if(tans.is_open()){
            while(getline (tans,line)){
                cout << line << '\n';
            }
            tans.close();
        }
        else{
            cout <<"Unable to open file";
        }
        adisplay();
    }
    else if(uscript=='n' || uscript=='N'){
        adisplay();
    }
    else{
        cout <<"Choose a valid Option" <<endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); //To prevent infinite loop due to invalid input
        tscript();
    }
}
void test(){
    vector <string> qq, qanswer;
    qq.push_back("CSC 201 TEST");
    qq.push_back("Q1. Which is a Programming Language?\nA. C++\tB. FIFA 23\tC. 1XBET");
    qq.push_back("Q2. Which is NOT a loop?\nA. for\tB. while\tC. void");
    qq.push_back("Q3. Which is a bitwise operator?\nA. $\tB. ^\tC. :");
    qq.push_back("Q4. Which is NOT a function in C++?\nA. void test()\tB. def work()\tC. int main()");
    qq.push_back("Q5. Which is used to declare a comment?\nA. //\tB. >>\tC. !!");
    qanswer.push_back("CSC 201 TEST ANSWERS");
    qanswer.push_back("Q1. a/A");
    qanswer.push_back("Q2. c/C");
    qanswer.push_back("Q3. b/B");
    qanswer.push_back("Q4. b/B");
    qanswer.push_back("Q5. a/A");
    answers.push_back("YOUR TEST ANSWERS");

    ofstream tqq("questions.csv");
    if (tqq.is_open()){
        for (const auto &tq : qq){
            tqq << tq << endl;
        }
        tqq.close();
    } else{
        cout << "Unable to open the file" << endl;
    }
    ofstream tqa("answers.csv");
    if (tqa.is_open()){
        for (const auto &qa : qanswer) {
            tqa << qa << endl;
        }
        tqa.close();
    } else{
        cout << "Unable to open the file" << endl;
    }
    qdisplay(1, 3);
    string qinp;
    cout <<"Press S to skip or input your answer\nOption: ";
    cin >> qinp;
    if(qinp=="s" || qinp=="S"){
        skip23();
    }
    else if(qinp=="a" || qinp=="A"){  
        i++;     
        cout << "Your Ans: A"<<endl;
        string aline = "Q1. " + qinp;
        answers.push_back(aline);
        skip23();
    }
    else if(qinp=="b" || qinp=="B"){       
        cout << "Your Ans: B"<<endl;
        string aline = "Q1. " + qinp;
        answers.push_back(aline);
        skip23();
    }
    else if(qinp=="c" || qinp=="C"){       
        cout << "Your Ans: C"<<endl;
        string aline = "Q1. " + qinp;
        answers.push_back(aline);
        skip23();
    }
    else{
        cout <<"Choose a valid Option" <<endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); //To prevent infinite loop due to invalid input
        skip1();
    }
    if(qinp=="a" || qinp=="A"){
        i++;
    }
    if(s23inp=="c" || s23inp=="C"){
        i++;
    }
    if(s34inp=="b" || s34inp=="B"){
        i++;
    }
    if(s45inp=="b" || s45inp=="B"){
        i++;
    }
    if(b5inp=="a" || b5inp=="A"){
        i++;
    }
    cout <<"Your score is: " << i <<endl; 
    tscript();
}
void back5(){
    qdisplay(10, 11);
    string b5inp;
    cout <<"Press S to skip, P for previous question or input your answer\nOption: ";
    cin >> b5inp;
    if(b5inp=="s" || b5inp=="S"){
        string s5inp;
        cout <<"Press F to finish\nOption: ";
        cin >>s5inp;
        if(s5inp=="f" || s5inp=="F"){
            
        }
        else{
            cout <<"Choose a valid Option" <<endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); //To prevent infinite loop due to invalid input
            back5();
        }
    }
    else if(b5inp=="p" || b5inp=="P"){
        skip45();
    }
    else if(b5inp=="a" || b5inp=="A"){
        cout << "Your Ans: A"<<endl;
        string aline1 = "Q5. " + b5inp;
        answers.push_back(aline1);
    }
    else if(b5inp=="b" || b5inp=="B"){       
        cout << "Your Ans: B"<<endl;
        string aline1 = "Q5. " + b5inp;
        answers.push_back(aline1);
    }
    else if(b5inp=="c" || b5inp=="C"){       
        cout << "Your Ans: C"<<endl;
        string aline1 = "Q5. " + b5inp;
        answers.push_back(aline1);
    }
    else{
        cout <<"Choose a valid Option" <<endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); //To prevent infinite loop due to invalid input
        back5();
    }
}
void skip45(){
    qdisplay(8, 9);
    string s45inp;
    cout <<"Press S to skip, P for previous question or input your answer\nOption: ";
    cin >> s45inp;
    if(s45inp=="s" || s45inp=="S"){
        back5();
    }
    else if(s45inp=="p" || s45inp=="P"){
        skip34();
    }
    else if(s45inp=="b" || s45inp=="B"){
        cout << "Your Ans: B"<<endl;
        string aline2 = "Q4. " + s45inp;
        answers.push_back(aline2);
        back5();
    }
    else if(s45inp=="a" || s45inp=="A"){       
        cout << "Your Ans: A"<<endl;
        string aline2 = "Q4. " + s45inp;
        answers.push_back(aline2);
        back5();
    }
    else if(s45inp=="c" || s45inp=="C"){       
        cout << "Your Ans: C"<<endl;
        string aline2 = "Q4. " + s45inp;
        answers.push_back(aline2);
        back5();
    }
    else{
        cout <<"Choose a valid Option" <<endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); //To prevent infinite loop due to invalid input
        skip45();
    }
}
void skip34(){
    qdisplay(6, 7);
    string s34inp;
    cout <<"Press S to skip, P for previous question or input your answer\nOption: ";
    cin >> s34inp;
    if(s34inp=="s" || s34inp=="S"){
        skip45();
    }
    else if(s34inp=="p" || s34inp=="P"){
        skip23();
    }
    else if(s34inp=="b" || s34inp=="B"){
        cout << "Your Ans: B"<<endl;
        string aline3 = "Q3. " + s34inp;
        answers.push_back(aline3);
        skip45();
    }
    else if(s34inp=="a" || s34inp=="A"){
        cout << "Your Ans: A"<<endl;
        string aline3 = "Q3. " + s34inp;
        answers.push_back(aline3);
        skip45();
    }
    else if(s34inp=="c" || s34inp=="C"){
        cout << "Your Ans: C"<<endl;
        string aline3 = "Q3. " + s34inp;
        answers.push_back(aline3);
        skip45();
    }
    else{
        cout <<"Choose a valid Option" <<endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); //To prevent infinite loop due to invalid input
        skip34();
    }
}
void skip23(){
    qdisplay(4, 5);
    string s23inp;
    cout <<"Press S to skip, P for previous question or input your answer\nOption: ";
    cin >> s23inp;
    if(s23inp=="s" || s23inp=="S"){
        skip34();
    }
    else if(s23inp=="p" || s23inp=="P"){
        skip1();
    }
    else if(s23inp=="c" || s23inp=="C"){
        cout << "Your Ans: C"<<endl;
        string aline4 = "Q2. " + s23inp;
        answers.push_back(aline4);
        skip34();
    }
    else if(s23inp=="a" || s23inp=="A"){
        cout << "Your Ans: A"<<endl;
        string aline4 = "Q2. " + s23inp;
        answers.push_back(aline4);
        skip34();
    }
    else if(s23inp=="b" || s23inp=="B"){
        cout << "Your Ans: B"<<endl;
        string aline4 = "Q2. " + s23inp;
        answers.push_back(aline4);
        skip34();
    }
    else{
        cout <<"Choose a valid Option" <<endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); //To prevent infinite loop due to invalid input
        skip23();
    }
}
void skip1(){
    qdisplay(2,3);
    string sinp;
    cout <<"Press S to skip or input your answer\nOption: ";
    cin >> sinp;
    if(sinp=="s" || sinp=="S"){
    skip23();
    }
    else if(sinp=="a" || sinp=="A"){
        cout << "Your Ans: A"<<endl;
        string aline5 = "Q1. " + sinp;
        answers.push_back(aline5);
        skip23();
    }
    else if(sinp=="b" || sinp=="B"){
        cout << "Your Ans: B"<<endl;
        string aline5 = "Q1. " + sinp;
        answers.push_back(aline5);
        skip23();
    }
    else if(sinp=="c" || sinp=="C"){
        cout << "Your Ans: C"<<endl;
        string aline5 = "Q1. " + sinp;
        answers.push_back(aline5);
        skip23();
    }
    else{
        cout <<"Choose a valid Option" <<endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); //To prevent infinite loop due to invalid input
        skip1();
    }
}  

int cbt(){
    int topt;
    cout <<"1. Start Test\n2. Upload Questions\n3. Exit CBT\nOption: " <<endl;
    cin >>topt;
    if(topt ==1){
        test();
        
    }
    else if(topt ==2){
        vector <string> questions;
        string upl;
        cout << "Enter a question ";
        getline(cin, upl);
        questions.push_back(upl);
        cout <<"Question uploaded successfully"<<endl;
        cbt();
    }
    else if(topt ==3){
        cout <<"CBT Program Closed" <<endl;
    }else{
        cout <<"Invaid Input\nChoose a valid option: " <<endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); //To prevent infinite loop due to invalid input
        for(int i = 0; i<1; i++){
            cbt();
        }
    }
    return topt;
}

int main(){
    cout << "CBT PROGRAM SIGNUP/LOGIN" << endl;
    int user;
    cout << "1. New user \n2. Existing user\nOption: ";
    cin >> user;

    if (user == 1){
        signup();
        cbt();
    }else if (user == 2){
        if (login() == true){
            cout << "Login Successful\nWelcome to the CBT program " << endl;
            cbt();
        } else {
            cout << "Incorrect Username/Password\nPlease Re-login" << endl;
            main();
        } 
    }
    else{
        cout << "Invalid Input\nAssign a valid input" << endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); //To prevent infinite loop due to invalid input
        for(int i = 0; i<1; i++){
            main();
        }
    }
    return 0;  
}
