#include <iostream>
#include <conio.h>
using namespace std;
int main()
{
    // Data Storage (Arrays)
    int size = 50;

    string names[size] = {"Ali", "Nasir", "Sara", "Hassan", "Ayesha", "Bilal", "Fatima"};
    int roll_num[size] = {101, 102, 103, 104, 105, 106, 107};
    int rooms[size] = {1, 2, 3, 4, 5, 6, 7};
    bool fee_paid[size] = {true,true, true, true, true, true, true};

    int total_students = 7;

    int choice;

    // ================= PASSWORD SYSTEM =================
    string password = "123";
    string input;
    bool access = false;

    for (int i = 0; i < 3; i++)
    {
        cout << "Enter Password: ";
        cin >> input;

        if (input == password)
        {
            cout << "Access Granted!\n";
            access = true;
            break;
        }
        else
        {
            cout << "Wrong Password!\n";
        }
    }

    if (access == false)
    {
        cout << "Access Denied!\n";
        return 0;
    }

    while (true)
    {
        //  Main Menu
        cout << "|-------------------------------------------------------|\n";
        cout << "|--------------- Hostel Management System---------------|\n";
        cout << "|-------------------------------------------------------|\n";

        system("cls");
        cout << "1. Add Student" << endl;
        cout << "2. View Students" << endl;
        cout << "3. Search Students" << endl;
        cout << "4. Assing Room" << endl;
        cout << "5. Fee Submit" << endl;
        cout << "6. Delete Student" << endl;
        cout << "7. Fine System" << endl;
        cout << "8. Exit" << endl;
        cout << "9. Change Room" << endl;
        cout << "10. Total Fee Colection" << endl;
        cout << "11. Mess System" << endl;
        cout << "12. Update Student" << endl;

        cout << "Enter choice: ";
        cin >> choice;

        // =====================================================
        //  1. ADD STUDENT
        // =====================================================
        if (choice == 1)
        {
            if (total_students == size)
            {
                cout << "Hostel is Full!" << endl;
            }
            else
            {
                cout << "Enter name: ";
                cin >> names[total_students];

                cout << "Enter Roll Number: ";
                cin >> roll_num[total_students];

                // idher check ho rha ka rollNum same to nhi kisi ka  
                bool exist = false;
                for (int i = 0; i < total_students; i++)
                {
                    if (roll_num[i] == roll_num[total_students])
                    {
                        exist = true;
                    }
                }

                if (exist == true)
                {
                    cout << "Roll number already exists!\n";
                }
                else
                {
                    rooms[total_students] = total_students + 1;
                    fee_paid[total_students] = false;
                    total_students++;
                    cout << "Student Added!\n";
                }
            }
            cout << "Press any key to continue..." << endl;
            getch();
            system("cls");
        }
        // =====================================================
        //  2. VIEW STUDENTS
        // =====================================================
        else if (choice == 2)
        {
            for (int i = 0; i < total_students; i++)
            {
                cout << "\n name: " << names[i];
                cout << "\n Roll number: " << roll_num[i];
                cout << "\n Room: " << rooms[i];

                if (fee_paid[i] == true)
                {
                    cout << "\n Fee: Paid";
                }
                else
                {
                    cout << "\n Fee: Unpaid";
                }

                cout << "\n --------------------------";
            }
            cout << "Press any key to continue..." << endl;
            getch();
            system("cls");
        }
        // =====================================================
        //  3. SEARCH STUDENT
        // =====================================================
        else if (choice == 3)
        {
            int search_roll_num;
            cout << "Enter the Roll Number: ";
            cin >> search_roll_num;

            bool found = false;

            for (int i = 0; i < total_students; i++)
            {
                if (roll_num[i] == search_roll_num)
                {
                    cout << "Found: " << names[i] << " | Roll: " << roll_num[i] << endl;
                    found = true;
                    break;
                }
            }
            if (found == false)
            {
                cout << "Not found!" << endl;
            }

            cout << "Press any key to continue..." << endl;
            getch();
            system("cls");
        }
        // =====================================================
        //  4. ASSIGN ROOM
        // =====================================================
        else if (choice == 4)
        {
            int roll, roomNo;
            cout << "Enter the roll number: ";
            cin >> roll;
            cout << "Enter the Room No";
            cin >> roomNo;

            bool found = false;

            for (int i = 0; i < total_students; i++)
            {
                if (roll_num[i] == roll)
                {
                    // check room is already taken ?
                    bool taken = false;

                    for (int j = 0; j < total_students; j++)
                    {
                        if (rooms[j] == roomNo)
                        {
                            taken = true;
                        }
                    }
                    if (taken == false)
                    {
                        rooms[i] = roomNo;
                        cout << "Room Assigned!" << endl;
                    }
                    else
                    {
                        cout << "Room already taken!" << endl;
                    }
                    found = true;
                }
            }
            if (found == false)
            {
                cout << "Student not found!" << endl;
            }

            cout << "Press any key to continue..." << endl;
            getch();
            system("cls");
        }
        // =====================================================
        //  5. FEE SUBMIT
        // =====================================================
        else if (choice == 5)
        {
            int roll;
            cout << "Enter roll number: ";
            cin >> roll;

            bool found = false;

            for (int i = 0; i < total_students; i++)
            {
                if (roll_num[i] == roll)
                {
                    fee_paid[i] = true;
                    cout << "Fee Submitted: " << endl;
                    found = true;
                }
            }
            if (found == false)
            {
                cout << "Student not found! " << endl;
            }

            cout << "Press any key to continue..." << endl;
            getch();
            system("cls");
        }
        // =====================================================
        //  6. DELETE STUDENT
        // =====================================================
        else if (choice == 6)
        {
            int roll;
            cout << "Enter the roll number you want to delete: ";
            cin >> roll;

            bool found = false;

            for (int i = 0; i < total_students; i++)
            {
                if (roll_num[i] == roll)
                {
                    for (int j = i; j < total_students - 1; j++)
                    {
                        names[j] = names[j + 1];
                        roll_num[j] = roll_num[j + 1];
                        rooms[j] = rooms[j + 1];
                        fee_paid[j] = fee_paid[j + 1];
                    }
                    total_students--;
                    cout << "Student Deleted! " << endl;
                    found = true;
                    break;
                }
            }
            if (found == false)
            {
                cout << "Student not found!" << endl;
            }
            cout << "Press any key to continue..." << endl;
            getch();
            system("cls");
        }
        // =====================================================
        //  7. FINE SYSTEM
        // =====================================================
        else if (choice == 7)
        {
            string name;
            int days_late;

            cout << "Enter name: ";
            cin >> name;
            cout << "Enter late Days: ";
            cin >> days_late;

            bool found = false;

            for (int i = 0; i < total_students; i++)
            {
                if (names[i] == name)
                {
                    found = true;

                    if (fee_paid[i] == false && days_late > 5)
                    {
                        cout << names[i] << " has fine Rs.500: " << endl;
                    }
                    else
                    {
                        cout << "No Fine: " << endl;
                    }
                }
            }
            if (found == false)
            {
                cout << "Name not found: ";
            }

            cout << "Press any key to continue..." << endl;
            getch();
            system("cls");
        }
        // =====================================================
        //  8. EXIT
        // =====================================================
        else if (choice == 8)
        {
            cout << "Exiting...." << endl;
            break;
        }
        // =====================================================
        //  9. CHANGE ROOM
        // =====================================================
        else if (choice == 9)
        {
            int roll, newRoom;
            cout << "Enter Roll Number: ";
            cin >> roll;
            cout << "Enter new room Number: ";
            cin >> newRoom;

            for (int i = 0; i < total_students; i++)
            {
                if (roll_num[i] == roll)
                {
                    bool taken = false;

                    for (int j = 0; j < total_students; j++)
                    {
                        if (rooms[j] == newRoom)
                        {
                            taken = true;
                        }
                    }
                    if (taken == false)
                    {
                        rooms[i] = newRoom;
                        cout << "Room Changed! " << endl;
                    }
                    else
                    {
                        cout << "Room is already taken! " << endl;
                    }
                }
            }
            cout << "Press any key to continue..." << endl;
            getch();
            system("cls");
        }
        // =====================================================
        //  10. TOTAL FEE COLLECTION
        // =====================================================
        else if (choice == 10)
        {
            int total = 0;

            for (int i = 0; i < total_students; i++)
            {
                if (fee_paid[i] == true)
                {
                    total = total + 5000;
                }
            }
            cout << "Total Fee Collection = Rs. " << total << endl;

            cout << "Press any key to continue..." << endl;
            getch();
            system("cls");
        }
        // =====================================================
        //  11. MESS SYSTEM
        // =====================================================
        else if (choice == 11)
        {
            int days;
            cout << "Enter days: ";
            cin >> days;

            cout << "Bill = Rs. " << days * 200 << endl;

            cout << "Press any key to continue..." << endl;
            getch();
            system("cls");
        }
        // =====================================================
        //  12. UPDATE STUDENT
        // =====================================================
        else if (choice == 12)
        {
            int roll;
            cout << "Enter Roll Number: ";
            cin >> roll;

            bool found = false;

            for (int i = 0; i < total_students; i++)
            {
                if (roll_num[i] == roll)
                {
                    cout << "Enter the Name: ";
                    cin >> names[i];
                    cout << "Enter Roll Number: ";
                    cin >> roll_num[i];

                    found = true;

                    cout << "Found: " << names[i] << "| Roll Number: " << roll_num[i] << endl;
                }
            }
            if (found == false)
            {
                cout << "Student not found!\n";
            }
            cout << "Press any key to continue..." << endl;
            getch();
            system("cls");
        }
        else
        {
            cout << "Invalid choice!" << endl;

            cout << "Press any key to continue..." << endl;
            getch();
            system("cls");
        }
    }
}