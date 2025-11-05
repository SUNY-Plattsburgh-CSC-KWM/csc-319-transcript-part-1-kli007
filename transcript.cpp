#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <C:\Users\likev\OneDrive - plattsburgh.edu\SchoolWork\2025-6 Fall\OODesign\transcript\banner.cpp>
#include <C:\Users\likev\OneDrive - plattsburgh.edu\SchoolWork\2025-6 Fall\OODesign\transcript\banner2.cpp>

using namespace std;

enum CommandType {
    CREATE_SEMESTER,
    DELETE_SEMESTER,
    DISPLAY_SUMMARY,
    CALCULATE_GPA,
    STORE_DATA,
    READ_DATA,
    CREATE_COURSE,
    DELETE_COURSE,
    DISPLAY_SEMESTER,
    SORT_BY_GRADE,
    SORT_BY_NUMBER,
    CALC_SEM_GPA,
    DISPLAY_COURSE,
    DEFAULT
};

int main(){
    map<string, CommandType> commandMap = {
        {"create_semester", CREATE_SEMESTER},
        {"delete_semester", DELETE_SEMESTER},
        {"display_summary", DISPLAY_SUMMARY},
        {"calculate_gpa", CALCULATE_GPA},
        {"store_data", STORE_DATA},
        {"read_data", READ_DATA},
        {"create_course", CREATE_COURSE},
        {"delete_course", DELETE_COURSE},
        {"display_semester", DISPLAY_SEMESTER},
        {"sort_by_grade", SORT_BY_GRADE},
        {"sort_by_number", SORT_BY_NUMBER},
        {"calc_sem_gpa", CALC_SEM_GPA},
        {"display_course", DISPLAY_COURSE}
    };

    string command = "";
    string c_in;
    string s_in;

    Transcript t1;
    Semester* Sptr;
    Course* Cptr;

    CommandType type;

    cout << "Enter commands to manage the transcript (type 'exit' to quit):" << endl;
    cout << "Command: ";
    cin >> command;

    while (command != "exit") {
        if (commandMap.count(command)) type = commandMap[command];
        else type = DEFAULT;

        switch (type)
        {
        case CREATE_SEMESTER:
            s_in = t1.getSemester();
            t1.createSemester(s_in);
            break;

        case DELETE_SEMESTER:
            s_in = t1.getSemester();
            t1.deleteSemester(s_in);
            break;
        
        case DISPLAY_SUMMARY:
            t1.displaySummary();
            break;

        case STORE_DATA:
            t1.storeData();
            break;

        case READ_DATA:
            t1.readData();
            break;

        case DISPLAY_SEMESTER:
            s_in = t1.getSemester();
            Sptr = t1.returnSemester(s_in);
            if (t1.checkSPointer(Sptr)) break;
            Sptr -> displaySemester();
            break;

        case CALC_SEM_GPA:
            s_in = t1.getSemester();
            Sptr = t1.returnSemester(s_in);
            if (t1.checkSPointer(Sptr)) break;
            Sptr -> calcSemGPA();
            cout << "Semester GPA calculated: " << Sptr -> getSemGPA() << endl;
            break;

        case SORT_BY_NUMBER:
            s_in = t1.getSemester();
            Sptr = t1.returnSemester(s_in);
            if (t1.checkSPointer(Sptr)) break;
            Sptr -> sortByNumber();
            Sptr -> displaySemester();
            break;

        case SORT_BY_GRADE:
            s_in = t1.getSemester();
            Sptr = t1.returnSemester(s_in);
            if (t1.checkSPointer(Sptr)) break;
            Sptr -> sortByGrade();
            Sptr -> displaySemester();
            break;
        
        case CREATE_COURSE:
            s_in = t1.getSemester();
            c_in = t1.getCourse();
            Sptr = t1.returnSemester(s_in);
            if (t1.checkSPointer(Sptr)) break;
            Sptr -> createCourse(c_in);
            break;

        case DELETE_COURSE:
            s_in = t1.getSemester();
            c_in = t1.getCourse();
            Sptr = t1.returnSemester(s_in);
            if (t1.checkSPointer(Sptr)) break;
            Sptr -> deleteCourse(c_in);
            break;

        case DISPLAY_COURSE:
            s_in = t1.getSemester();
            c_in = t1.getCourse();
            Sptr = t1.returnSemester(s_in);
            if (t1.checkSPointer(Sptr)) break;
            Cptr = Sptr -> returnCourse(c_in);
            if (t1.checkCPointer(Cptr)) break;
            Cptr -> displayCourse();
            break;


        default:
            cout << "Invalid command. Please try again." << endl;
            break;


        }
        
        Sptr = nullptr;
        Cptr = nullptr;
        cout << "Command: ";
        cin >> command;
    }
    return 0;
}