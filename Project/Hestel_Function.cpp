#include <iostream>
#include <string>
#include <conio.h>
using namespace std;

// ---------- FUNCTION DECLARATIONS ----------
void main_menu();
void pause_screen();
bool invalid();
int find_student(int);
bool room_taken(int);

void add_student();
void view_all();
void search_student();
void assign_room();
void pay_fee();
void remove_student();
void revenue();
void unpaid();
void student_view();
void admin_panel();

// ---------- GLOBAL DATA ----------
string names[100] = {"Ali", "Nasir", "Sara", "Hassan", "Ayesha"};
int rolls[100] = {101, 102, 103, 104, 105};
int rooms[100] = {1, 2, 3, 4, 5};
bool fee[100] = {true, true, false, true, false};
int total = 5;

// ---------------- MAIN ----------------
int main()
{
    int choice;

    while (true)
    {
        system("cls");
        main_menu();
        cin >> choice;

        if (invalid())
        {
            cout << "Invalid Choice!\n";
            pause_screen();
            continue;
        }

        if (choice == 1)
        {
            string pass;
            int attempts = 3;
            bool login = false;

            while (attempts > 0)
            {
                system("cls");
                cout << "----------- ADMIN LOGIN -----------\n";
                cout << "Enter Password (" << attempts << " left): ";
                cin >> pass;

                if (pass == "123")
                {
                    login = true;
                    break;
                }
                else
                {
                    attempts--;
                    if (attempts > 0)
                    {
                        cout << "Wrong Password!\n";
                        getch();
                    }
                }
            }

            if (login)
                admin_panel();
            else
            {
                cout << "Access Denied! Too many wrong attempts.\n";
                pause_screen();
            }
        }
        else if (choice == 2)
        {
            system("cls");
            student_view();
            pause_screen();
        }
        else if (choice == 3)
        {
            cout << "Exiting System...\n";
            break;
        }
        else
        {
            cout << "Invalid Choice!\n";
            pause_screen();
        }
    }

    return 0;
}

// ---------- MAIN MENU ----------
void main_menu()
{
    cout << "=================================================\n";
    cout << "           HOSTEL MANAGEMENT SYSTEM              \n";
    cout << "=================================================\n";
    cout << "1. Admin Login\n";
    cout << "2. Student View\n";
    cout << "3. Exit\n";
    cout << "=================================================\n";
    cout << "Enter Choice: ";
}

// ---------- PAUSE ----------
void pause_screen()
{
    cout << "\nPress any key...";
    getch();
}

// ---------- INPUT CHECK ----------
bool invalid()
{
    if (cin.fail())
    {
        cin.clear();
        cin.ignore(1000, '\n');
        return true;
    }
    return false;
}

// ---------- FIND STUDENT ----------
int find_student(int roll)
{
    for (int i = 0; i < total; i++)
    {
        if (rolls[i] == roll)
            return i;
    }
    return -1;
}

// ---------- ROOM CHECK ----------
bool room_taken(int room)
{
    for (int i = 0; i < total; i++)
    {
        if (rooms[i] == room)
            return true;
    }
    return false;
}

// ---------- ADD STUDENT ----------
void add_student()
{
    int roll, room;
    string name;

    if (total >= 100)
    {
        cout << "Hostel Full!\n";
        return;
    }

    cout << "Enter Roll: ";
    cin >> roll;

    if (invalid())
    {
        cout << "Invalid Roll!\n";
        return;
    }

    if (find_student(roll) != -1)
    {
        cout << "Roll Already Exists!\n";
        return;
    }

    cin.ignore();
    cout << "Enter Name: ";
    getline(cin, name);

    cout << "Enter Room: ";
    cin >> room;

    if (invalid() || room <= 0)
    {
        cout << "Invalid Room!\n";
        return;
    }

    if (room_taken(room))
    {
        cout << "Room Already Occupied!\n";
        return;
    }

    names[total] = name;
    rolls[total] = roll;
    rooms[total] = room;
    fee[total] = false;
    total++;

    cout << "Student Added Successfully!\n";
}

// ---------- VIEW ALL ----------
void view_all()
{
    cout << "Roll\tName\tRoom\tFee\n";
    cout << "----------------------------------\n";

    for (int i = 0; i < total; i++)
    {
        cout << rolls[i] << "\t" << names[i] << "\t" << rooms[i]
             << "\t" << (fee[i] ? "Paid" : "Unpaid") << endl;
    }
}

// ---------- SEARCH ----------
void search_student()
{
    int roll;

    cout << "Enter Roll: ";
    cin >> roll;

    if (invalid())
    {
        cout << "Invalid Roll!\n";
        return;
    }

    int i = find_student(roll);

    if (i == -1)
        cout << "Student Not Found!\n";
    else
        cout << "Name: " << names[i] << " | Room: " << rooms[i]
             << " | Fee: " << (fee[i] ? "Paid" : "Unpaid") << endl;
}

// ---------- ASSIGN ROOM ----------
void assign_room()
{
    int roll, room;

    cout << "Enter Roll: ";
    cin >> roll;

    if (invalid())
    {
        cout << "Invalid Roll!\n";
        return;
    }

    int i = find_student(roll);

    if (i == -1)
    {
        cout << "Student Not Found!\n";
        return;
    }

    cout << "Current Room: " << rooms[i] << endl;
    cout << "Enter New Room: ";
    cin >> room;

    if (invalid() || room <= 0)
    {
        cout << "Invalid Room!\n";
        return;
    }
    if (rooms[i] == room)
    {
        cout << "Student Already In This Room!\n";
        return;
    }

    if (room_taken(room))
    {
        cout << "Room Already Occupied!\n";
        return;
    }

    rooms[i] = room;
    cout << "Room Assigned Successfully!\n";
}

// ---------- PAY FEE ----------
void pay_fee()
{
    int roll;

    cout << "Enter Roll: ";
    cin >> roll;

    if (invalid())
    {
        cout << "Invalid Roll!\n";
        return;
    }

    int i = find_student(roll);

    if (i == -1)
        cout << "Student Not Found!\n";
    else if (fee[i])
        cout << "Fee Already Paid!\n";
    else
    {
        fee[i] = true;
        cout << "Fee Submitted Successfully!\n";
    }
}

// ---------- DELETE ----------
void remove_student()
{
    int roll;

    cout << "Enter Roll: ";
    cin >> roll;
    if (invalid())
    {
        cout << "Invalid Roll!\n";
        return;
    }

    int i = find_student(roll);

    if (i == -1)
    {
        cout << "Student Not Found!\n";
        return;
    }

    for (int j = i; j < total - 1; j++)
    {
        names[j] = names[j + 1];
        rolls[j] = rolls[j + 1];
        rooms[j] = rooms[j + 1];
        fee[j] = fee[j + 1];
    }

    total--;
    cout << "Record Deleted Successfully!\n";
}

// ---------- REVENUE ----------
void revenue()
{
    int sum = 0;

    for (int i = 0; i < total; i++)
    {
        if (fee[i])
            sum += 5000;
    }

    cout << "Total Revenue: Rs. " << sum << endl;
}

// ---------- UNPAID ----------
void unpaid()
{
    bool found = false;
    cout << "UNPAID STUDENTS:\n";

    for (int i = 0; i < total; i++)
    {
        if (!fee[i])
        {
            cout << rolls[i] << " - " << names[i] << endl;
            found = true;
        }
    }
    if (!found)
        cout << "All Students Have Paid!\n";
}

// ---------- STUDENT VIEW ----------
void student_view()
{
    cout << "Roll\tName\n";
    cout << "-----------------\n";

    for (int i = 0; i < total; i++)
    {
        cout << rolls[i] << "\t" << names[i] << endl;
    }
}

// ---------- ADMIN PANEL ----------
void admin_panel()
{
    int choice = 0;

    while (choice != 9)
    {
        system("cls");

        cout << "============== ADMIN PANEL ==============\n";
        cout << "1. Add Student\n";
        cout << "2. View All Students\n";
        cout << "3. Search Student\n";
        cout << "4. Assign Room\n";
        cout << "5. Pay Fee\n";
        cout << "6. Delete Student\n";
        cout << "7. Revenue\n";
        cout << "8. Unpaid List\n";
        cout << "9. Logout\n";
        cout << "=========================================\n";
        cout << "Enter Choice: ";
        cin >> choice;

        if (invalid())
        {
            cout << "Invalid Choice!\n";
            pause_screen();
            continue;
        }

        system("cls");

        if (choice == 1)
            add_student();
        else if (choice == 2)
            view_all();
        else if (choice == 3)
            search_student();
        else if (choice == 4)
            assign_room();
        else if (choice == 5)
            pay_fee();
        else if (choice == 6)
            remove_student();
        else if (choice == 7)
            revenue();
        else if (choice == 8)
            unpaid();
        else if (choice == 9)
            cout << "Logging Out...\n";
        else
            cout << "Invalid Choice!\n";

        if (choice != 9)
            pause_screen();
    }
}