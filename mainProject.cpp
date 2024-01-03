//                             ****************************************
//                             ****         Alireza Mehraban       ****
//                             ****         Mehr Application       ****
//                             ****           1401 / 04 / 1        ****
//                             ****        advanced programming    ****
//                             ****************************************
#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include <unistd.h> // time(sleep)
using namespace std;
unsigned int microseconds = 2000000;
unsigned int microseconds2 = 1000000;
int main();
void BackExit();
//=========================================== database file
ofstream DataBase99("./database/99DataBase.txt", ios::app);       // 99 databae
ofstream mainDataBase400("./database/400DataBase.txt", ios::app); // 400 database
ofstream mainDataBase401("./database/401DataBase.txt", ios::app); // 401 database
ofstream choose("./database/ChoosedLesson.txt", ios::app);        // Lessons
fstream MyFile,Lessons,FileScore;

// important global varibels for discover people (Teacher or Student)
long int u;
string n, l;
string seeScore = "\t\t========== Empty ==========";

//! =========================================== teacher Part
class Teacher
{
public:
    // publice variabels
    int choice;
    string new_name, new_lastname, back;
    long int new_id;
    string read_name, read_lastname;
    long int read_id;
    // define lessons for students in the Function Lessons
    string lessons99;
    string lessons400;
    string lessons401;
    void lessons();
    void viewAll();
    void removeStudent();
    void editStudent();
    void AddScore();
    void searchStId();
    void welcome(string name, string lastname, long int Id)
    {
        system("cls");
        cout << endl
             << endl;
        cout << "\t\t\t********** welcome " << name << " **********\t/Teacher/" << endl;
        cout << "\t\t1. Term and lessons" << endl;
        cout << "\t\t2. View All Messages" << endl;
        cout << "\t\t3. Edit students" << endl;
        cout << "\t\t4. Search Students By ID" << endl;
        cout << "\t\t5. Back to first page" << endl;
        cout << "\t\t6. Exit" << endl;
        cout << "\t\tEnter your choice no.";
        cin >> choice;
        switch (choice)
        {
        case 1:
            lessons();
            break;
        case 2:
            system("cls");
            MyFile.open("./database/StudentMessages.txt", ios::in);
            if (MyFile.is_open())
            {
                string line;
                while (getline(MyFile, line))
                {
                    cout << "\t\t" << line << endl;
                }
                MyFile.close();
            }
            cout << endl
                 << endl;
            cout << "\t\tBack Or Exit? (b,e):  ";
            cin >> back;
            if (back == "b")
            {
                welcome(n, l, u);
            }
            else if (back == "e")
            {
                cout << "\t\tThanx for using our app :) ";
                system("exit");
            }
            break;
        case 3:
            editStudent();
            break;
        case 4:
            searchStId();
            break;
        case 5:
            main();
            break;
        case 6:
            cout << endl;
            cout << "\t\tThanks " << n << ' ' << l << " For Using our app :) " << endl
                 << endl;
            break;
        default:
            system("cls");
            cout << endl;
            cout << "\t\tSomeThing went wrong !!! try again later" << endl;
            usleep(microseconds);
            welcome(n, l, u);
            break;
        }
    }
};

// =========================================== add lessons to the database for term 99 400 401
void Teacher::lessons()
{
    system("cls");
    int counter;
    int i = 0;
    int get_year;
    cout << "\t\tfor wich year you want to define lesson? (99, 1400, 1401): ";
    cin >> get_year;
    switch (get_year)
    {
    case 99:
        system("cls");
        cout << "\t\tHow Many Lessons do you want to add ?";
        cin >> counter;
        while (i < counter)
        {
            cout << "\t\tEnter the name of lesson " << i + 1 << " : ";
            cin >> lessons99;
            DataBase99 << lessons99 << endl;
            i++;
        }
        cout << endl;
        cout << "\t\tDone!";
        usleep(microseconds);
        welcome(n, l, u);
        break;
    case 1400:
        system("cls");
        cout << "\t\tHow Many Lessons do you want to add ?";
        cin >> counter;
        while (i < counter)
        {
            cout << "\t\tEnter the name of lesson " << i + 1 << " : ";
            cin >> lessons400;
            mainDataBase400 << lessons400 << endl;
            i++;
        }
        cout << endl;
        cout << "\t\tDone!";
        usleep(microseconds);
        welcome(n, l, u);
        break;
    case 1401:
        system("cls");
        cout << "\t\tHow Many Lessons do you want to add ?";
        cin >> counter;
        while (i < counter)
        {
            cout << "\t\tEnter the name of lesson " << i + 1 << " : ";
            cin >> lessons401;
            mainDataBase401 << lessons401 << endl;
            i++;
        }
        cout << endl;
        cout << "\t\tDone!";
        usleep(microseconds);
        welcome(n, l, u);
        break;
    default:
        system("cls");
        cout << endl;
        cout << "Oops! SomeThing Went Wrong. try again later ): " << endl;
        usleep(microseconds);
        lessons();
        break;
    }
}

// =========================================== add, remove, add score and etc...
void Teacher::editStudent()
{
    int checking, stNum, i = 0;
    string back;
    ifstream input2("./database/DataBase.txt");
    ofstream mainDataBase("./database/DataBase.txt", ios::app);
    int hi;
    system("cls");
    cout << "\t\t\t************ Edit Students ************" << endl;
    cout << "\t\t<1> Add student" << endl;
    cout << "\t\t<2> Remove student" << endl;
    cout << "\t\t<3> Add student scores" << endl;
    cout << "\t\t<4> View all students" << endl;
    cout << "\t\t<5> Back" << endl;
    cout << "\t\t<6> Exit" << endl;
    cout << "\t\tEnter your choice: ";
    cin >> checking;
    switch (checking)
    {
    case 1:
        // add new student to the database
        system("cls");
        cout << "\t\tHow many student you want to add? ";
        cin >> stNum;
        while (i < stNum)
        {
            cout << "\t\tEnter student name => ";
            cin >> new_name;
            cout << "\t\tEnter student last name => ";
            cin >> new_lastname;
            cout << "\t\tEnter student ID => ";
            cin >> new_id;
            mainDataBase << new_name << ' ' << new_lastname << ' ' << new_id << endl;
            i++;
        }
        cout << "\t\tDone..!" << endl;
        usleep(microseconds);
        welcome(n, l, u);
        break;
    case 2:
        // Remove student with ID
        removeStudent();
        break;
    case 3:
        // Add student score
        AddScore();
        break;
    case 4:
        // View All Students List
        viewAll();
        break;
    case 5:
        welcome(n, l, u);
        break;
    case 6:
        cout << "\t\tThanks for using our app :) " << endl;
        break;
    default:
        system("cls");
        cout << endl;
        cout << "Oops! SomeThing Went Wrong. try again later = ): " << endl;
        usleep(microseconds);
        editStudent();
        break;
    }
}

// =========================================== View All students
void Teacher::viewAll()
{
    ifstream input2("./database/DataBase.txt");
    system("cls");
    string back;
    cout << "\t\tName"
         << "\t\t\tLastname"
         << "\t\t\tID" << endl;
    cout << "\t\t==================================================================" << endl;
    while (input2 >> read_name >> read_lastname >> read_id)
    {
        if ((read_name == "ostad") && (read_id == 500))
        {
            continue;
        }
        if (!input2)
        {
            cout << "\t\tSorry we could not find the any students :(" << endl;
        }
        cout << "\t\t" << read_name << "\t\t\t" << read_lastname << "\t\t\t" << read_id << endl;
    }
    input2.close();
    cout << endl
         << endl;
    cout << "\t\tBack Or Exit? (b,e):  ";
    cin >> back;
    if (back == "b")
    {
        welcome(n, l, u);
    }
    else if (back == "e")
    {
        cout << "\t\tThanx for using our app :) ";
        system("exit");
    }
}

// =========================================== Search students
void Teacher::searchStId()
{
    ifstream input("./database/DataBase.txt");
    string back;
    system("cls");
    long int get_id;
    string n2, l2;
    int find_year = 99;
    long int i2;
    cout << "\t\tEnter your student ID to see his/her informaition: ";
    cin >> get_id;
    cout << endl
         << endl;
    if ((get_id > 2) && (get_id < 50))
    {
        find_year = 400;
    }
    else if ((get_id > 51) && (get_id < 100))
    {
        find_year = 401;
    }
    else if ((get_id > 101) && (get_id < 151))
    {
        find_year = 99;
    }

    cout << "\t\tName"
         << "\t\tLastname"
         << "\t\t\tID"
         << "\t\t\tYear" << endl;
    cout << "\t\t=====================================================================================" << endl;
    while (input >> n2 >> l2 >> i2)
    {
        if (i2 == get_id)
        {
            cout << "\t\t" << n2 << "\t\t" << l2 << "\t\t\t" << i2 << "\t\t\t" << find_year << endl;
        }
    }
    input.close();
    cout << endl
         << endl;
    cout << "\t\tBack Or Exit? (b,e):  ";
    cin >> back;
    if (back == "b")
    {
        welcome(n, l, u);
    }
    else if (back == "e")
    {
        cout << "\t\tThanx for using our app :) ";
        system("exit");
    }
}

// =========================================== Add Student scores
void Teacher::AddScore()
{
    ofstream scoreFile("./database/StudentScore.txt");
    system("cls");
    string _id, name;
    cout << "\t\tEnter Stuent ID: ";
    cin >> _id;
    cout << "\t\tEnter Student name: ";
    cin >> name;
    Lessons.open("./database/ChoosedLesson.txt");
    string line;
    char word;
    bool check = true;

    while (getline(Lessons, line))
    {
        do
        {
            if (line.find(_id) != string::npos)
            {
                if (line.find(name) != string::npos)
                {
                    cout << "\t\t"
                         << "Name"
                         << "\t"
                         << "Lastname"
                         << "\t"
                         << "ID"
                         << "\t"
                         << "Lesson Name" << endl;
                    cout << "\t\t-----------------------------------------------------------------" << endl;
                    cout << "\t\t" << line << endl;
                    cout << "\t\t=====================================================" << endl;
                    check = false;
                }
            }
            else
            {
                cout << "Not found ..." << endl;
                break;
                system("exit");
            }
        } while (check);
        break;
    }
    cout << endl;
    int counter, enter_score;
    string t;
    cout << "\t\tHow many scores you want to add? (In Order)";
    cin >> counter;
    for (int i = 0; i < counter; i++)
    {
        cout << "\t\tEnter score " << i + 1 << " : ";
        cin >> enter_score;
        line = line + to_string(enter_score) + " ";
    }
    cout << endl
         << endl;
    system("cls");
    cout << "\t\t" << line;
    seeScore = line;
    scoreFile << seeScore << endl;
    Lessons.close();
    scoreFile.close();
    cout << endl
         << endl;
    cout << "\t\tBack Or Exit? (b,e):  ";
    cin >> back;
    if (back == "b")
    {
        welcome(n, l, u);
    }
    else if (back == "e")
    {
        cout << "\t\tThanx for using our app :) ";
        system("exit");
    }
}

// =========================================== Remove(delete) Student          Working
void Teacher::removeStudent()
{
    system("cls");
    ifstream input;
    ofstream mainDataBase3;
    input.open("./database/DataBase.txt");
    mainDataBase3.open("./database/DataBase4.txt");
    string remove_id;
    string remove_name, remove_lastname, line;
    int skip = 0; // skip lines
    cout << "\t\t************* Remove Student *************" << endl;
    cout << "\t\tEnter student name to remove: ";
    cin >> remove_name;
    cout << "\t\tEnter student Id to remove: ";
    cin >> remove_id;
    while(getline(input,line)){
        if(line.find(remove_name) == string::npos){
            if(line.find(remove_id) == string::npos){
                mainDataBase3<<line<<endl;
            }else{
                cout<<"Something went wrong"<<endl;
            }
        }
        else{
            if(skip == 0){
                skip = 2;
            }
            else{
                --skip;
            }
        }
    }
    input.close();
    mainDataBase3.close();
    remove("./database/DataBase.txt");
    rename("./database/DataBase4.txt","./database/DataBase.txt");
    

}

//! =========================================== Student Part
class Student
{
public:
    int choice;
    int find_year = 99;
    void view_all_lessons(long int view_id);
    void send_message();
    void Chooselessons(long int view_id);
    void ViewScore();
    void RejectScore();
    // =========================================== Welcome
    void welcome(string s_name, string s_lastname, long int s_ID)
    {
        system("cls");
        cout << endl;
        cout << "\t\t\t********** welcome " << s_name << ' ' << s_lastname << " **********\t/Student/" << endl;
        cout << "\t\t1. View All lessons" << endl;
        cout << "\t\t2. Choose lessons" << endl;
        cout << "\t\t3. Send Message to teacher" << endl;
        cout << "\t\t4. View lessons & scores" << endl;
        cout << "\t\t5. View rejected lessons & scores" << endl;
        cout << "\t\t6. Exit" << endl;
        cout << "\t\tEnter your choice: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            system("cls");
            view_all_lessons(s_ID);
            break;
        case 2:
            Chooselessons(s_ID);
            break;
        case 3:
            send_message();
            break;
        case 4:
            ViewScore();
            break;
        case 5:
            RejectScore();
            break;
        case 6:
            cout << endl;
            cout << "\t\tThanks for Using Mehr App :)" << endl;
            break;
        default:
            system("cls");
            cout << endl;
            cout << "\t\tSomeThing went Wrong! Try again later :(" << endl;
            usleep(microseconds);
            welcome(n, l, u);
            break;
        }
    }
};

Student student;
// =========================================== Student can View All Lessons
void Student::view_all_lessons(long int view_id)
{
    ifstream input400("./database/400DataBase.txt");
    ifstream input401("./database/401DataBase.txt");
    ifstream input99("./database/99DataBase.txt");
    string lesson_name;
    string bargasht;
    if ((view_id > 2) && (view_id < 50))
    {
        find_year = 400;
    }
    else if ((view_id > 51) && (view_id < 100))
    {
        find_year = 401;
    }
    else if ((view_id > 101) && (view_id < 151))
    {
        find_year = 99;
    }

    switch (find_year)
    {
    case 400:
        cout << "\t\tName Of All Lessons" << endl;
        cout << "\t\t=======================================" << endl;
        while (input400 >> lesson_name)
        {
            cout << "\t\t" << lesson_name;
        }
        input400.close();
        BackExit();
        break;
    case 401:

        cout << "\t\tName Of All Lessons" << endl;
        cout << "\t\t=======================================" << endl;
        while (input401 >> lesson_name)
        {
            cout << "\t\t" << lesson_name;
        }
        input401.close();
        BackExit();
        break;
    case 99:

        cout << "\t\tName Of All Lessons" << endl;
        cout << "\t\t=======================================" << endl;
        while (input99 >> lesson_name)
        {
            cout << "\t\t" << lesson_name;
        }
        input99.close();
        BackExit();
        break;
    default:
        system("cls");
        cout << endl;
        cout << "\t\tSomeThing went Wrong! Try again later :(" << endl;
        usleep(microseconds);
        student.welcome(n, l, u);
        break;
    }
}

// =========================================== Send Message to Teacher
void Student::send_message()
{
    ofstream studentmessage("./database/StudentMessages.txt", ios::app);
    char message[1000000];
    system("cls");
    cout << "\t\t**************** Sending Message ****************" << endl;
    cout << "\t\tWanna Send Message to your teacher? feel free to do that :)" << endl;
    cout << "\t\tWrite your message:" << endl;
    cout << "\t\t";
    cin >> message;
    studentmessage << "MESSAGE:\t\t" << n << "\t\t" << l << "\t\t" << u << endl;
    studentmessage << "TEXT:\t" << message << endl;
    studentmessage << "------------------------------------------------------------------------------" << endl;
    cout << endl;
    cout << "\t\tDone!" << endl;
    usleep(microseconds);
    student.welcome(n, l, u);
}

// =========================================== Student can View All Scores
void Student::ViewScore()
{
    system("cls");
    string line;
    FileScore.open("./database/StudentScore.txt");
    while (getline(FileScore, line))
    {
        if (line.find(n) != string::npos)
        {
            if (line.find(to_string(u)) != string::npos)
            {
                cout << "\t\t" << line;
                break;
            }
        }
    }
    FileScore.close();
    BackExit();
}

// =========================================== Student can View rejected score
void Student::RejectScore()
{
    system("cls");
    cout << "\t\tNOTE: If you have score under 10, that means you are rejected :(" << endl;
    cout << "\t\t-----------------------------------------------------------------" << endl;
    string Line;
    FileScore.open("./database/StudentScore.txt");
    while (getline(FileScore, Line))
    {
        if (Line.find(to_string(u)) != string::npos)
        {
            if (Line.find(n) != string::npos)
            {
                if (Line.find(l) != string::npos)
                {
                    cout << "\t\t" << Line << endl;
                    break;
                }
            }
        }
        FileScore.close();
    }
    cout << "\t\t=========================================================" << endl;
    BackExit();
}

// Back function
void BackExit()
{
    string bargasht;
    cout << endl
         << endl;
    cout << "\t\tBack Or Exit? (b,e):  ";
    cin >> bargasht;
    if (bargasht == "b")
    {
        student.welcome(n, l, u);
    }
    else if (bargasht == "e")
    {
        cout << "\t\tThanx for using our app :) ";
        system("exit");
    }
}
// =========================================== Student can Choose lessons Here
void Student::Chooselessons(long int view_id)
{
    ifstream input400("./database/400DataBase.txt");
    ifstream input401("./database/401DataBase.txt");
    ifstream input99("./database/99DataBase.txt");
    string lesson_name;
    string bargasht;
    int tedad;
    string enter_lesson;
    system("cls");
    if ((view_id > 2) && (view_id < 50))
    {
        find_year = 400;
    }
    else if ((view_id > 51) && (view_id < 100))
    {
        find_year = 401;
    }
    else if ((view_id > 101) && (view_id < 151))
    {
        find_year = 99;
    }

    switch (find_year)
    {
    case 400:
        cout << "\t\tName Of All Lessons" << endl;
        cout << "\t\t==================================================" << endl;
        while (input400 >> lesson_name)
        {
            cout << "\t\t" << lesson_name;
        }
        cout << endl
             << endl;
        cout << "\t\t==================================================" << endl;
        cout << "\t\tHow many Lessons do you want? ";
        cin >> tedad;
        choose << n << "\t" << l << "\t" << u << " ==>";
        for (int j = 1; j <= tedad; j++)
        {
            cout << "\t\tEnter Lesson no." << j << " ";
            cin >> enter_lesson;
            choose << "\t" << enter_lesson << ' ';
        }
        input400.close();
        choose << endl;
        cout << "\t\tDone!";
        usleep(microseconds);
        welcome(n, l, u);
        break;
    case 401:
        cout << "\t\tName Of All Lessons" << endl;
        cout << "\t\t==================================================" << endl;
        while (input401 >> lesson_name)
        {
            cout << "\t\t" << lesson_name;
        }
        cout << endl
             << endl;
        cout << "\t\t==================================================" << endl;
        cout << "\t\tHow many Lessons do you want? ";
        cin >> tedad;
        choose << n << "\t" << l << "\t" << u << " ==>";
        for (int j = 1; j <= tedad; j++)
        {
            cout << "\t\tEnter Lesson no." << j << " ";
            cin >> enter_lesson;
            choose << ' ' << enter_lesson << ' ';
        }
        choose << endl;
        input401.close();
        cout << "\t\tDone!";
        usleep(microseconds);
        welcome(n, l, u);
        break;
    case 99:
        cout << "\t\tName Of All Lessons" << endl;
        cout << "\t\t==================================================" << endl;
        while (input99 >> lesson_name)
        {
            cout << "\t\t" << lesson_name;
        }
        cout << endl
             << endl;
        cout << "\t\t==================================================" << endl;
        cout << "\t\tHow many Lessons do you want? ";
        cin >> tedad;
        choose << n << "\t" << l << "\t" << u << " ==>";
        for (int j = 1; j <= tedad; j++)
        {
            cout << "\t\tEnter Lesson no." << j << " ";
            cin >> enter_lesson;
            choose << ' ' << enter_lesson << ' ';
        }
        choose << endl;
        input99.close();
        cout << "\t\tDone!";
        usleep(microseconds);
        student.welcome(n, l, u);
        break;
    default:
        system("cls");
        cout << endl;
        cout << "\t\tSomeThing went Wrong! Try again later :(" << endl;
        usleep(microseconds);
        student.welcome(n, l, u);
        break;
    }
}

// =========================================== recocnize that the entered id is teacher or student
class find_person
{
private:
    long int ID;

public:
    int count = 0;
    Teacher teacher;
    string line;
    void get_information()
    {
        cout << "\t\tNew Student? Enter 1 to signUp" << endl;
        cout << "\t\tEnter your ID: ";
        cin >> ID;
    }
    // ========================= new student
    void signup();
    //========================== recognize that the ID is the teacher or student
    void recognize()
    {
        ifstream input("./database/DataBase.txt");
        system("cls");
        if (ID == 1)
        {
            signup();
        }
        else
        {
            while (input >> n >> l >> u)
            {
                if (u == ID)
                {
                    if (n == "ostad")
                    {
                        teacher.welcome(n, l, u);
                    }
                    else
                    {
                        student.welcome(n, l, u);
                    }
                }
            }
            input.close();
        }
    }
};

// =========================================== SignUp (Register) Student
void find_person::signup()
{
    system("cls");
    ofstream mainDataBase("./database/DataBase.txt", ios::app);
    string NewStudentName, NewStudentLastName;
    int NewstudentId;
    cout << "\t\tHello, welcome to Mehr app for Students :)" << endl;
    cout << "\t\tfor signingup, please fill this for: " << endl;
    cout << "\t\tEnter your name ==> ";
    cin >> NewStudentName;
    cout << "\t\tEnter your last name ==> ";
    cin >> NewStudentLastName;
    cout << "\t\tEnter your ID ==> ";
    cin >> NewstudentId;
    mainDataBase << NewStudentName << ' ' << NewStudentLastName << ' ' << NewstudentId << endl;
    cout << "\t\tWait, your informatins are recordeing ..." << endl;
    usleep(microseconds);
    cout << "\t\tDone! ";
    usleep(microseconds2);
    main();
}

// =========================================== main function
int main()

{
    system("cls");
    cout << endl
         << endl;
    cout << "\t\t***********************************" << endl;
    cout << "\t\t******* Welcome to Mehr App *******" << endl;
    cout << "\t\t***********************************" << endl
         << endl;
    find_person find;
    find.get_information();
    find.recognize();
    return 0;
}
