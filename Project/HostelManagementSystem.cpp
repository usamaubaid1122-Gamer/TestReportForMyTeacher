#include <iostream>
#include <fstream>  // data save karna ka lia
#include <conio.h>  // getch() ka lia
#include <stdlib.h> // system(cls) ka lia
#include <string>   // string datatype ka lia
#include <iomanip>  // ye dataformatting ka lia kam ata jasa ka next value ka lia 10 ya os sa ziada spaces ki witdth rakho
using namespace std;

const int MAX_ROOMS = 100;
const int MAX_STUDENTS = 200;
const int MAX_COMPLAINS = 100;
const int MAX_EXPENSES = 100;

//-------array for rooms-------
int room_no[MAX_ROOMS];
int room_capacity[MAX_ROOMS];
int room_occupied[MAX_ROOMS];
float room_rent[MAX_ROOMS];
string room_type[MAX_ROOMS]; // single / double / shared
int totalRooms = 0;

//------array for students------
int stu_id[MAX_STUDENTS];
string stu_name[MAX_STUDENTS];
int stu_age[MAX_STUDENTS];
string stu_course[MAX_STUDENTS];
string stu_phone[MAX_STUDENTS];
int stu_room[MAX_STUDENTS];
string stu_password[MAX_STUDENTS];
bool stu_feePaid[MAX_STUDENTS];
string stu_leaveStatus[MAX_STUDENTS]; // "None", "Pending", "Approved", "Rejected"
string stu_leaveReason[MAX_STUDENTS];
int totalStudents = 0;

//-------array for complains-------
int comp_studentId[MAX_COMPLAINS];
string comp_text[MAX_COMPLAINS];
string comp_status[MAX_COMPLAINS]; // pending or resolved
int totalComplains = 0;

//-------array for Expenses--------
string exp_description[MAX_EXPENSES];
float exp_amount[MAX_EXPENSES];
string exp_date[MAX_EXPENSES];
int totalExpenses = 0;

// ------Function prototypes--------

// basic
void pause();
void loadAllData();
void saveAllData();
int findStudentIndex(int id);
int findRoomIndex(int rNo);

// admin
bool adminLogin();
void adminMenu();
void addRoom();
void viewAllRooms();
void changeRoom();
void freeRoom();
void searchStudent();
void viewAllocatedStudents();
void updateRoomRent();
void checkHostelExpenses();
void viewComplaints();
void generateReport();
void registerStudent();

// user
void userLoginMenu();
void userMenu(int sIndex);
void viewMyProfile(int sIndex);
void checkRoomAvailability();
void applyForLeave(int sIndex);
void viewLeaveStatus(int sIndex);
void fileComplaint(int sIndex);
void viewFeeStatus(int sIndex);
void payFeeSimulate(int sIndex);
void viewHostelRules();
void viewMessMenu();
void changePassword(int sIndex);

//======================================================================
//                          BASIC FUNCTIONS
//======================================================================

void pause()
{
    cout << "\nPress any key to continue..." << endl;
    getch();
}

int findStudentIndex(int id)
{
    for (int i = 0; i < totalStudents; i++)
    {
        if (stu_id[i] == id)
        {
            return i;
        }
    }
    return -1;
}

int findRoomIndex(int rNo)
{
    for (int i = 0; i < totalRooms; i++)
    {
        if (room_no[i] == rNo)
        {
            return i;
        }
    }
    return -1;
}

//======================================================================
//                      File Handling
//======================================================================

void loadAllData()
{
    ifstream fin("rooms.txt");
    if (fin.is_open())
    {
        totalRooms = 0;
        while (fin >> room_no[totalRooms] >> room_capacity[totalRooms] >> room_occupied[totalRooms] >> room_rent[totalRooms] >> room_type[totalRooms])
        {
            totalRooms++;
            if (totalRooms >= MAX_ROOMS)
            {
                break;
            }
        }
        fin.close();
    }

    ifstream fs("students.txt");
    if (fs.is_open())
    {
        totalStudents = 0;
        while (fs >> stu_id[totalStudents] >> stu_name[totalStudents] >> stu_age[totalStudents] >> stu_course[totalStudents] >> stu_phone[totalStudents] >> stu_room[totalStudents] >> stu_password[totalStudents] >> stu_feePaid[totalStudents] >> stu_leaveStatus[totalStudents] >> stu_leaveReason[totalStudents])
        {
            totalStudents++;
            if (totalStudents >= MAX_STUDENTS)
            {
                break;
            }
        }
        fs.close();
    }

    ifstream fc("complains.txt");
    if (fc.is_open())
    {
        totalComplains = 0;
        int sid;
        while (fc >> sid)
        {
            comp_studentId[totalComplains] = sid;
            fc >> comp_status[totalComplains];
            fc.ignore();
            getline(fc, comp_text[totalComplains]);
            totalComplains++;
            if (totalComplains >= MAX_COMPLAINS)
            {
                break;
            }
        }
        fc.close();
    }

    ifstream fe("expenses.txt");
    if (fe.is_open())
    {
        totalExpenses = 0;
        while (fe >> exp_amount[totalExpenses] >> exp_date[totalExpenses])
        {
            fe.ignore();
            getline(fe, exp_description[totalExpenses]);
            totalExpenses++;
            if (totalExpenses >= MAX_EXPENSES)
            {
                break;
            }
        }
        fe.close();
    }
}

void saveAllData()
{
    // rooms
    ofstream fout("rooms.txt");
    for (int i = 0; i < totalRooms; i++)
    {
        fout << room_no[i] << " "
             << room_capacity[i] << " "
             << room_occupied[i] << " "
             << room_rent[i] << " "
             << room_type[i] << "\n";
    }
    fout.close();

    // students
    ofstream fs("students.txt");
    for (int i = 0; i < totalStudents; i++)
    {
        // agar koi field empty ho to placeholder rakhna zaruri hai
        string lr = stu_leaveReason[i];
        if (lr == "")
        {
            lr = "NA";
        }
        string ls = stu_leaveStatus[i];
        if (ls == "")
        {
            ls = "None";
        }

        fs << stu_id[i] << " "
           << stu_name[i] << " "
           << stu_age[i] << " "
           << stu_course[i] << " "
           << stu_phone[i] << " "
           << stu_room[i] << " "
           << stu_password[i] << " "
           << stu_feePaid[i] << " "
           << ls << " "
           << lr << "\n";
    }
    fs.close();

    // complains
    ofstream fc("complains.txt");
    for (int i = 0; i < totalComplains; i++)
    {
        fc << comp_studentId[i] << " "
           << comp_status[i] << " "
           << comp_text[i] << "\n";
    }
    fc.close();

    // expenses
    ofstream fe("expenses.txt");
    for (int i = 0; i < totalExpenses; i++)
    {
        fe << exp_amount[i] << " "
           << exp_date[i] << " "
           << exp_description[i] << "\n";
    }
    fe.close();
}

//======================================================================
//                              ADMIN
//======================================================================

bool adminLogin()
{
    system("cls");
    string user, pass;
    cout << "=====================================" << endl;
    cout << "          ADMIN LOGIN" << endl;
    cout << "=====================================" << endl;
    cout << "Username: ";
    cin >> user;

    cout << "Password: ";
    cin >> pass;
    cout << endl;

    if (user == "admin" && pass == "1234")
    {
        cout << "\n Login Successfull" << endl;
        pause();
        return true;
    }
    else
    {
        cout << "\n Wrong username or Password" << endl;
        pause();
        return false;
    }
}

void addRoom()
{
    system("cls");
    cout << "------- ADD NEW ROOM -------" << endl;

    if (totalRooms >= MAX_ROOMS)
    {
        cout << "Room storage full" << endl;
        pause();
        return;
    }

    int rNo;
    cout << "Enter Room Number: ";
    cin >> rNo;

    // duplicate check
    if (findRoomIndex(rNo) != -1)
    {
        cout << "this room already exists" << endl;
        pause();
        return;
    }

    room_no[totalRooms] = rNo;
    cout << "Enter Capacity: ";
    cin >> room_capacity[totalRooms];
    cout << "Enter Rent: ";
    cin >> room_rent[totalRooms];
    cout << "Enter Type(single/double/shared): ";
    cin >> room_type[totalRooms];

    room_occupied[totalRooms] = 0;
    totalRooms++;
    saveAllData();

    system("cls");
    cout << "your data has been saved" << endl;
    pause();
}

void viewAllRooms()
{
    system("cls");
    cout << "-----------ALL ROOMS-------------" << endl;
    if (totalRooms == 0)
    {
        cout << "No rooms added yet." << endl;
        pause();
        return;
    }

    cout << left << setw(8) << "room#"
         << setw(10) << "Capacity"
         << setw(10) << "Occupied"
         << setw(10) << "Rent"
         << setw(12) << "Type"
         << setw(12) << "Status" << endl;

    cout << "------------------------------------------------------------" << endl;

    for (int i = 0; i < totalRooms; i++)
    {
        string status;
        if (room_occupied[i] == 0)
        {
            status = "Empty";
        }
        else if (room_occupied[i] >= room_capacity[i])
        {
            status = "Full";
        }
        else
        {
            status = "Available";
        }

        cout << left << setw(8) << room_no[i]
             << setw(10) << room_capacity[i]
             << setw(10) << room_occupied[i]
             << setw(10) << room_rent[i]
             << setw(12) << room_type[i]
             << setw(12) << status << endl;
    }
    pause();
}

void registerStudent()
{
    system("cls");
    cout << "------- REGISTER NEW STUDENT -------" << endl;

    if (totalStudents >= MAX_STUDENTS)
    {
        cout << "Student storage full!" << endl;
        pause();
        return;
    }

    int id;
    cout << "Enter Student Id: ";
    cin >> id;

    if (findStudentIndex(id) != -1)
    {
        cout << "Student ID already exists!" << endl;
        pause();
        return;
    }

    stu_id[totalStudents] = id;
    cout << "Enter Name (no spaces, use _ instead): ";
    cin >> stu_name[totalStudents];
    cout << "Enter Age: ";
    cin >> stu_age[totalStudents];
    cout << "Enter Course: ";
    cin >> stu_course[totalStudents];
    cout << "Phone Number: ";
    cin >> stu_phone[totalStudents];
    cout << "Set Password: ";
    cin >> stu_password[totalStudents];

    stu_room[totalStudents] = 0;
    stu_feePaid[totalStudents] = false;
    stu_leaveStatus[totalStudents] = "None";
    stu_leaveReason[totalStudents] = "NA";

    totalStudents++;
    saveAllData();

    system("cls");
    cout << "Your data has been saved" << endl;
    pause();
}

void changeRoom()
{
    system("cls");
    cout << "------- Change ROOM -------" << endl;

    int id, rNo;
    cout << "Enter Student ID: ";
    cin >> id;
    int si = findStudentIndex(id);
    if (si == -1)
    {
        cout << "Student not Found" << endl;
        pause();
        return;
    }

    if (stu_room[si] != 0)
    {
        cout << "This student is already in room " << stu_room[si] << endl;
        pause();
        return;
    }

    cout << "Enter room number to change: ";
    cin >> rNo;
    int ri = findRoomIndex(rNo);
    if (ri == -1)
    {
        cout << "Room not found" << endl;
        pause();
        return;
    }

    if (room_occupied[ri] >= room_capacity[ri])
    {
        cout << "This room is already full" << endl;
        pause();
        return;
    }

    stu_room[si] = rNo;
    room_occupied[ri]++;
    saveAllData();

    system("cls");
    cout << "your data has been saved" << endl;
    pause();
}

void freeRoom()
{
    system("cls");
    cout << "------- Free ROOM -------" << endl;

    int id;
    cout << "Enter Student ID: ";
    cin >> id;
    int si = findStudentIndex(id);
    if (si == -1)
    {
        cout << "Student Not Found" << endl;
        pause();
        return;
    }

    if (stu_room[si] == 0)
    {
        cout << "This student has no room allocated." << endl;
        pause();
        return;
    }

    int ri = findRoomIndex(stu_room[si]);
    if (ri != -1 && room_occupied[ri] > 0)
    {
        room_occupied[ri]--;
    }
    stu_room[si] = 0;
    saveAllData();

    system("cls");
    cout << "Your data has been saved" << endl;
    pause();
}

void searchStudent()
{
    system("cls");
    cout << "------- SEARCH STUDENT -------" << endl;
    cout << "1. Search by ID" << endl;
    cout << "2. Search by Name" << endl;
    cout << "Choice: ";
    int ch;
    cin >> ch;

    if (ch == 1)
    {
        int id;
        cout << "Enter ID: ";
        cin >> id;
        int si = findStudentIndex(id);
        if (si == -1)
        {
            cout << "Student not found!" << endl;
        }
        else
        {
            cout << "\n-- Student Details --" << endl;
            cout << "ID     : " << stu_id[si] << endl;
            cout << "Name   : " << stu_name[si] << endl;
            cout << "Age    : " << stu_age[si] << endl;
            cout << "Course : " << stu_course[si] << endl;
            cout << "Phone  : " << stu_phone[si] << endl;
            cout << "Room   : ";

            if (stu_room[si] == 0)
            {
                cout << "Not Allocated";
            }
            else
            {
                cout << stu_room[si];
            }
            cout << endl;
        }
    }
    else if (ch == 2)
    {
        string name;
        cout << "Enter Name: ";
        cin >> name;
        bool found = false;
        for (int i = 0; i < totalStudents; i++)
        {
            if (stu_name[i] == name)
            {
                cout << "\nID: " << stu_id[i]
                     << " | Name: " << stu_name[i]
                     << " | Room: " << stu_room[i] << endl;
                found = true;
            }
        }
        if (!found)
        {
            cout << "No student with that name." << endl;
        }
    }
    else
    {
        cout << "Invalid choice." << endl;
    }
    pause();
}

void viewAllocatedStudents()
{
    system("cls");
    cout << "------- ALLOCATED STUDENTS -------" << endl;

    cout << left << setw(8) << "ID"
         << setw(20) << "Name"
         << setw(15) << "Course"
         << setw(8) << "Room" << endl;
    cout << "------------------------------------------------" << endl;

    int count = 0;
    for (int i = 0; i < totalStudents; i++)
    {
        if (stu_room[i] != 0)
        {
            cout << left << setw(8) << stu_id[i]
                 << setw(20) << stu_name[i]
                 << setw(15) << stu_course[i]
                 << setw(8) << stu_room[i] << endl;
            count++;
        }
    }
    if (count == 0)
    {
        cout << "No students currently allocated." << endl;
    }
    pause();
}

void updateRoomRent()
{
    system("cls");
    cout << "------- UPDATE ROOM RENT -------" << endl;
    int rNo;
    cout << "Enter Room Number: ";
    cin >> rNo;
    int ri = findRoomIndex(rNo);
    if (ri == -1)
    {
        cout << "Room not found!" << endl;
        pause();
        return;
    }
    cout << "Current rent: " << room_rent[ri] << endl;
    cout << "Enter new rent: ";
    cin >> room_rent[ri];
    saveAllData();

    system("cls");
    cout << "Your data has been saved" << endl;
    pause();
}

void checkHostelExpenses()
{
    system("cls");
    cout << "------- HOSTEL EXPENSES -------" << endl;
    cout << "1. Add New Expense" << endl;
    cout << "2. View All Expenses" << endl;
    cout << "Choice: ";
    int ch;
    cin >> ch;

    if (ch == 1)
    {
        if (totalExpenses >= MAX_EXPENSES)
        {
            cout << "Expense list full!" << endl;
            pause();
            return;
        }
        cout << "Description (one word, use _): ";
        cin >> exp_description[totalExpenses];
        cout << "Amount: ";
        cin >> exp_amount[totalExpenses];
        cout << "Date (dd-mm-yyyy): ";
        cin >> exp_date[totalExpenses];
        totalExpenses++;
        saveAllData();

        system("cls");
        cout << "Your data has been saved" << endl;
        cout << "Press any key to continue... " << endl;
        getch();
    }
    else if (ch == 2)
    {
        system("cls");
        cout << "------- EXPENSE RECORDS -------" << endl;
        if (totalExpenses == 0)
        {
            cout << "No expenses recorded yet." << endl;
        }
        else
        {
            float total = 0;
            cout << left << setw(25) << "Description"
                 << setw(12) << "Amount"
                 << setw(15) << "Date" << endl;
            cout << "----------------------------------------------" << endl;
            for (int i = 0; i < totalExpenses; i++)
            {
                cout << left << setw(25) << exp_description[i]
                     << setw(12) << exp_amount[i]
                     << setw(15) << exp_date[i] << endl;
                total += exp_amount[i];
            }
            cout << "----------------------------------------------" << endl;
            cout << "TOTAL: " << total << endl;
        }
        pause();
    }
    else
    {
        cout << "Invalid choice." << endl;
        pause();
    }
}

void viewComplaints()
{
    system("cls");
    cout << "------- STUDENT COMPLAINTS -------" << endl;
    if (totalComplains == 0)
    {
        cout << "No complaints found." << endl;
        pause();
        return;
    }

    for (int i = 0; i < totalComplains; i++)
    {
        cout << "\n[" << (i + 1) << "] Student ID: " << comp_studentId[i] << endl;
        cout << "    Status   : " << comp_status[i] << endl;
        cout << "    Complaint: " << comp_text[i] << endl;
    }

    cout << "\nDo you want to mark any complaint as resolved? (y/n): ";
    char c;
    cin >> c;
    if (c == 'y' || c == 'Y')
    {
        int n;
        cout << "Enter complaint number: ";
        cin >> n;
        if (n >= 1 && n <= totalComplains)
        {
            comp_status[n - 1] = "Resolved";
            saveAllData();
            cout << "Marked as resolved." << endl;
        }
        else
        {
            cout << "Invalid number." << endl;
        }
    }
    pause();
}

void generateReport()
{
    system("cls");
    cout << "============================================" << endl;
    cout << "          HOSTEL OVERALL REPORT" << endl;
    cout << "============================================" << endl;

    int allocated = 0, freeRooms = 0, fullRooms = 0;
    int totalCapacity = 0, totalOccupied = 0;
    float totalRentCollected = 0;

    for (int i = 0; i < totalRooms; i++)
    {
        totalCapacity += room_capacity[i];
        totalOccupied += room_occupied[i];
        if (room_occupied[i] == 0)
            freeRooms++;
        else if (room_occupied[i] >= room_capacity[i])
            fullRooms++;
    }

    for (int i = 0; i < totalStudents; i++)
    {
        if (stu_room[i] != 0)
            allocated++;
        if (stu_feePaid[i] && stu_room[i] != 0)
        {
            int ri = findRoomIndex(stu_room[i]);
            if (ri != -1)
                totalRentCollected += room_rent[ri];
        }
    }

    float totalExpAmt = 0;
    for (int i = 0; i < totalExpenses; i++)
        totalExpAmt += exp_amount[i];

    cout << "Total Rooms          : " << totalRooms << endl;
    cout << "Free Rooms           : " << freeRooms << endl;
    cout << "Full Rooms           : " << fullRooms << endl;
    cout << "Total Capacity       : " << totalCapacity << endl;
    cout << "Currently Occupied   : " << totalOccupied << endl;
    cout << "--------------------------------------------" << endl;
    cout << "Total Students       : " << totalStudents << endl;
    cout << "Students with Room   : " << allocated << endl;
    cout << "--------------------------------------------" << endl;
    cout << "Total Complaints     : " << totalComplains << endl;
    cout << "Total Rent Collected : " << totalRentCollected << endl;
    cout << "Total Expenses       : " << totalExpAmt << endl;
    cout << "Net Balance          : " << (totalRentCollected - totalExpAmt) << endl;
    cout << "============================================" << endl;
    pause();
}

void adminMenu()
{
    int choice;
    while (true)
    {
        system("cls");
        cout << "==========================================" << endl;
        cout << "             ADMIN DASHBOARD" << endl;
        cout << "==========================================" << endl;
        cout << " 1.  Add New Room" << endl;
        cout << " 2.  View All Rooms" << endl;
        cout << " 3.  Register New Student" << endl;
        cout << " 4.  Change Room" << endl;
        cout << " 5.  Free Room" << endl;
        cout << " 6.  Search Student" << endl;
        cout << " 7.  View Allocated Students" << endl;
        cout << " 8.  Update Room Rent" << endl;
        cout << " 9.  Hostel Expenses" << endl;
        cout << " 10. View Complains" << endl;
        cout << " 11. Generate Report" << endl;
        cout << " 0.  Logout" << endl;
        cout << "==========================================" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1)
            addRoom();
        else if (choice == 2)
            viewAllRooms();
        else if (choice == 3)
            registerStudent();
        else if (choice == 4)
            changeRoom();
        else if (choice == 5)
            freeRoom();
        else if (choice == 6)
            searchStudent();
        else if (choice == 7)
            viewAllocatedStudents();
        else if (choice == 8)
            updateRoomRent();
        else if (choice == 9)
            checkHostelExpenses();
        else if (choice == 10)
            viewComplaints();
        else if (choice == 11)
            generateReport();
        else if (choice == 0)
        {
            cout << "Logging out..." << endl;
            pause();
            break;
        }
        else
        {
            cout << "Invalid choice, try again." << endl;
            pause();
        }
    }
}

// ===================================================================
//                               USER
// ===================================================================

void viewMyProfile(int sIndex)
{
    system("cls");
    cout << "------- MY PROFILE -------" << endl;
    cout << "ID        : " << stu_id[sIndex] << endl;
    cout << "Name      : " << stu_name[sIndex] << endl;
    cout << "Age       : " << stu_age[sIndex] << endl;
    cout << "Course    : " << stu_course[sIndex] << endl;
    cout << "Phone     : " << stu_phone[sIndex] << endl;
    cout << "Room No   : " << (stu_room[sIndex] == 0 ? "Not Allocated" : to_string(stu_room[sIndex])) << endl;
    cout << "Fee Paid  : " << (stu_feePaid[sIndex] ? "Yes" : "No") << endl;
    pause();
}

void checkRoomAvailability()
{
    system("cls");
    cout << "------- AVAILABLE ROOMS -------" << endl;

    bool any = false;
    cout << left << setw(8) << "Room#"
         << setw(10) << "Type"
         << setw(10) << "Rent"
         << setw(15) << "Seats Left" << endl;
    cout << "------------------------------------------" << endl;
    for (int i = 0; i < totalRooms; i++)
    {
        if (room_occupied[i] < room_capacity[i])
        {
            cout << left << setw(8) << room_no[i]
                 << setw(10) << room_type[i]
                 << setw(10) << room_rent[i]
                 << setw(15) << (room_capacity[i] - room_occupied[i]) << endl;
            any = true;
        }
    }
    if (!any)
        cout << "Sorry, no rooms available right now." << endl;
    pause();
}

void applyForLeave(int sIndex)
{
    system("cls");
    cout << "------- APPLY FOR LEAVE -------" << endl;

    if (stu_leaveStatus[sIndex] == "Pending")
    {
        cout << "You already have a pending leave request!" << endl;
        pause();
        return;
    }

    cout << "Enter reason (one word, use _ for spaces): ";
    string reason;
    cin >> reason;
    stu_leaveReason[sIndex] = reason;
    stu_leaveStatus[sIndex] = "Pending";
    saveAllData();

    system("cls");
    cout << "Your data has been saved" << endl;
    pause();
}

void viewLeaveStatus(int sIndex)
{
    system("cls");
    cout << "------- LEAVE STATUS -------" << endl;
    cout << "Reason : " << stu_leaveReason[sIndex] << endl;
    cout << "Status : " << stu_leaveStatus[sIndex] << endl;
    pause();
}

void fileComplaint(int sIndex)
{
    system("cls");
    cout << "------- FILE A COMPLAINT -------" << endl;
    if (totalComplains >= MAX_COMPLAINS)
    {
        cout << "Complaint storage full!" << endl;
        pause();
        return;
    }

    cout << "Write your complaint: ";
    cin.ignore();
    string txt;
    getline(cin, txt);

    comp_studentId[totalComplains] = stu_id[sIndex];
    comp_text[totalComplains] = txt;
    comp_status[totalComplains] = "Pending";
    totalComplains++;
    saveAllData();

    system("cls");
    cout << "Your data has been saved" << endl;
    pause();
}

void viewFeeStatus(int sIndex)
{
    system("cls");
    cout << "------- FEE STATUS -------" << endl;

    if (stu_room[sIndex] == 0)
    {
        cout << "You don't have a room allocated yet, so no rent due." << endl;
    }
    else
    {
        int ri = findRoomIndex(stu_room[sIndex]);
        if (ri != -1)
        {
            cout << "Room Number : " << room_no[ri] << endl;
            cout << "Monthly Rent: " << room_rent[ri] << endl;
            cout << "Status      : " << (stu_feePaid[sIndex] ? "PAID" : "PENDING") << endl;
        }
    }
    pause();
}

void payFeeSimulate(int sIndex)
{
    system("cls");
    cout << "------- PAY FEE -------" << endl;

    if (stu_room[sIndex] == 0)
    {
        cout << "You have no room, so nothing to pay." << endl;
        pause();
        return;
    }
    if (stu_feePaid[sIndex])
    {
        cout << "Your fee is already paid for this month." << endl;
        pause();
        return;
    }
    int ri = findRoomIndex(stu_room[sIndex]);
    if (ri == -1)
    {
        cout << "Room info missing!" << endl;
        pause();
        return;
    }

    cout << "Amount due: " << room_rent[ri] << endl;
    cout << "Confirm payment? (y/n): ";
    char c;
    cin >> c;
    if (c == 'y' || c == 'Y')
    {
        stu_feePaid[sIndex] = true;
        saveAllData();
        system("cls");
        cout << "Your data has been saved" << endl;
        cout << "Press any key to continue... " << endl;
        getch();
    }
    else
    {
        cout << "Payment cancelled." << endl;
        pause();
    }
}

void viewHostelRules()
{
    system("cls");
    cout << "============================================" << endl;
    cout << "             HOSTEL RULES" << endl;
    cout << "============================================" << endl;
    cout << " 1. Gate closes at 10:00 PM sharp." << endl;
    cout << " 2. Smoking and alcohol are strictly prohibited." << endl;
    cout << " 3. Guests are not allowed after 8:00 PM." << endl;
    cout << " 4. Keep your rooms clean." << endl;
    cout << " 5. Pay your monthly fee before the 10th." << endl;
    cout << " 6. Damage to property will be charged." << endl;
    cout << " 7. Report any issue using the complaint section." << endl;
    cout << " 8. Maintain silence during study hours (8 PM - 11 PM)." << endl;
    cout << " 9. Ragging is a serious offence." << endl;
    cout << "10. Notify warden before leaving for vacation." << endl;
    cout << "============================================" << endl;
    pause();
}

void viewMessMenu()
{
    system("cls");
    cout << "============================================" << endl;
    cout << "             WEEKLY MESS MENU" << endl;
    cout << "============================================" << endl;
    cout << left << setw(12) << "Day"
         << setw(18) << "Breakfast"
         << setw(18) << "Lunch"
         << setw(18) << "Dinner" << endl;
    cout << "--------------------------------------------------------------" << endl;

    string days[7] = {"Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday"};
    string bf[7] = {"Paratha+Tea", "Omelette", "Halwa Puri", "Toast+Egg", "Channa", "Paratha", "Cornflakes"};
    string lunch[7] = {"Daal Chawal", "Chicken", "Biryani", "Beef", "Daal", "Qorma", "Pulao"};
    string dinner[7] = {"Sabzi+Roti", "Karahi", "Chapli Kabab", "Mix Veg", "Fish", "Mutton", "BBQ"};

    for (int i = 0; i < 7; i++)
    {
        cout << left << setw(12) << days[i]
             << setw(18) << bf[i]
             << setw(18) << lunch[i]
             << setw(18) << dinner[i] << endl;
    }
    cout << "============================================" << endl;
    pause();
}

void changePassword(int sIndex)
{
    system("cls");
    cout << "------- CHANGE PASSWORD -------" << endl;
    string oldP, newP, confirmP;
    cout << "Enter current password: ";
    cin >> oldP;

    if (oldP != stu_password[sIndex])
    {
        cout << "Wrong password!" << endl;
        pause();
        return;
    }

    cout << "Enter new password: ";
    cin >> newP;
    cout << "Confirm new password: ";
    cin >> confirmP;

    if (newP != confirmP)
    {
        cout << "Passwords don't match!" << endl;
        pause();
        return;
    }
    if (newP.length() < 4)
    {
        cout << "Password too short (min 4 chars)." << endl;
        pause();
        return;
    }

    stu_password[sIndex] = newP;
    saveAllData();

    system("cls");
    cout << "Your data has been saved" << endl;
    cout << "Press any key to continue... " << endl;
    getch();
}

void userMenu(int sIndex)
{
    int choice;
    while (true)
    {
        system("cls");
        cout << "==========================================" << endl;
        cout << "    Welcome, " << stu_name[sIndex] << "!" << endl;
        cout << "==========================================" << endl;
        cout << " 1.  View My Profile" << endl;
        cout << " 2.  Check Room Availability" << endl;
        cout << " 3.  Apply for Leave" << endl;
        cout << " 4.  View Leave Status" << endl;
        cout << " 5.  File a Complaint" << endl;
        cout << " 6.  View Fee Status" << endl;
        cout << " 7.  Pay Fee" << endl;
        cout << " 8.  View Hostel Rules" << endl;
        cout << " 9.  View Mess Menu" << endl;
        cout << " 10. Change Password" << endl;
        cout << " 0.  Logout" << endl;
        cout << "==========================================" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1)
            viewMyProfile(sIndex);
        else if (choice == 2)
            checkRoomAvailability();
        else if (choice == 3)
            applyForLeave(sIndex);
        else if (choice == 4)
            viewLeaveStatus(sIndex);
        else if (choice == 5)
            fileComplaint(sIndex);
        else if (choice == 6)
            viewFeeStatus(sIndex);
        else if (choice == 7)
            payFeeSimulate(sIndex);
        else if (choice == 8)
            viewHostelRules();
        else if (choice == 9)
            viewMessMenu();
        else if (choice == 10)
            changePassword(sIndex);
        else if (choice == 0)
        {
            cout << "Logging out..." << endl;
            pause();
            break;
        }
        else
        {
            cout << "Invalid choice." << endl;
            pause();
        }
    }
}

void userLoginMenu()
{
    system("cls");
    cout << "=====================================" << endl;
    cout << "         STUDENT LOGIN" << endl;
    cout << "=====================================" << endl;
    int id;
    string pass;
    cout << "Enter Student ID: ";
    cin >> id;
    cout << "Enter Password: ";
    cin >> pass;
    cout << endl;

    int si = findStudentIndex(id);
    if (si == -1)
    {
        cout << "Student not registered. Ask admin to register you first." << endl;
        pause();
        return;
    }

    if (stu_password[si] != pass)
    {
        cout << "Wrong password!" << endl;
        pause();
        return;
    }

    cout << "Login successful!" << endl;
    pause();
    userMenu(si);
}

// ===================================================================
//                          MAIN FUNCTION
// ===================================================================

int main()
{
    system("color 1F");

    loadAllData();

    int choice;
    while (true)
    {
        system("cls");
        cout << "##########################################" << endl;
        cout << "#                                        #" << endl;
        cout << "#      HOSTEL MANAGEMENT SYSTEM          #" << endl;
        cout << "#                                        #" << endl;
        cout << "##########################################" << endl;
        cout << endl;
        cout << "         1. Admin Login" << endl;
        cout << "         2. Student Login" << endl;
        cout << "         3. Exit" << endl;
        cout << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1)
        {
            if (adminLogin())
            {
                adminMenu();
            }
        }
        else if (choice == 2)
        {
            userLoginMenu();
        }
        else if (choice == 3)
        {
            system("cls");
            cout << "Saving everything before exit..." << endl;
            saveAllData();
            cout << "\nThank you for using Hostel Management System!" << endl;
            cout << "Goodbye :)" << endl;
            pause();
            break;
        }
        else
        {
            cout << "Invalid choice! Try again." << endl;
            pause();
        }
    }

    return 0;
}