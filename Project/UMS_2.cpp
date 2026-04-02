#include <iostream>
#include <conio.h>
using namespace std;
main()
{
    int TOTAL_STUDENTS = 1000; // total size
    int index = 7;

    // Data Structures
    string name_array[1000] = {"Ali", "Nasir", "Sara", "Hassan", "Ayesha", "Bilal", "Fatima"};
    int age_array[1000] = {19, 20, 18, 21, 19, 22, 20};
    float matric_array[1000] = {1050, 890, 1020, 970, 950, 1000, 980};
    float inter_array[1000] = {980, 850, 910, 890, 940, 960, 905};
    float ecat_array[1000] = {350, 280, 310, 295, 330, 325, 300};

    string pref1_array[1000] = {"CE", "EE", "CS", "CE", "CS", "EE", "CE"};
    string pref2_array[1000] = {"CS", "CE", "EE", "CE", "CE", "CS", "EE"};
    string pref3_array[1000] = {"EE", "CS", "CE", "CS", "EE", "CE", "CS"};

    float aggregate_array[1000];

    // Discipline seat capacity
    const int CE_SEATS = 3;
    const int CS_SEATS = 3;
    const int EE_SEATS = 3;

    string ce_students[CE_SEATS];
    string cs_students[CS_SEATS];
    string ee_students[EE_SEATS];

    while (true)
    {
        system("cls");
        cout << endl;
        cout << "-------------------------------------------------------" << endl;
        cout << "------- University Addmission Management System -------" << endl;
        cout << "-------------------------------------------------------" << endl;

        cout << "User Menu" << endl;
        cout << "1 Admin" << endl;
        cout << "2 Student" << endl;
        cout << "3 EXIT" << endl;
        cout << "Choose option: ";
        string user_option;
        cin >> user_option;

        cout << "You Choose " << user_option << endl;
        if (user_option == "1")
        {
            for (int i = 0; i < 3; i++)
            {
                system("cls");
                cout << "Admin Menu : Login Attempt " << i + 1 << endl;
                cout << "Enter username : ";
                string username;
                cin >> username;
                cout << "Enter Password : ";
                string password;
                cin >> password;

                if (username == "admin" && password == "123")
                {
                    cout << "Login Success" << endl;
                    while (true)
                    {
                        system("cls");
                        cout << "1. Show all students " << endl;
                        cout << "2. Search Student" << endl;
                        cout << "3. Update Student Record " << endl;
                        cout << "4. Generate Merit List " << endl;
                        cout << "5. Delete student record " << endl;
                        cout << "6. Logout " << endl;
                        cout << "Choose the option : ";
                        string admin_option;
                        cin >> admin_option;

                        if (admin_option == "1")
                        {
                            // Show all students
                            cout << "Name\tAge\tMatric\tInter\tECAT\tP1\tP2\tP3" << endl;
                            for (int i = 0; i < index; i++)
                            {
                                if (name_array[i] != "")
                                {
                                    cout << name_array[i] << "\t" << age_array[i] << "\t"
                                         << matric_array[i] << "\t" << inter_array[i] << "\t"
                                         << ecat_array[i] << "\t" << pref1_array[i] << "\t"
                                         << pref2_array[i] << "\t" << pref3_array[i] << endl;
                                }
                            }
                        }
                        else if (admin_option == "2")
                        {
                            system("cls");
                            // Search student
                            cout << "Enter the name you want to search : ";
                            string name;
                            cin >> name;
                            bool found = false;
                            int found_index = -1;
                            for (int i = 0; i < index; i++)
                            {
                                if (name_array[i] == name)
                                {
                                    found_index = i;
                                    found = true;
                                }
                            }
                            if (found == false)
                            {
                                cout << "Record not found against name " << endl;
                            }
                            else
                            {
                                cout << "Name\tAge\tMatric\tInter\tECAT\tP1\tP2\tP3" << endl;
                                cout << name_array[found_index] << "\t" << age_array[found_index] << "\t"
                                     << matric_array[found_index] << "\t" << inter_array[found_index] << "\t"
                                     << ecat_array[found_index] << "\t" << pref1_array[found_index] << "\t"
                                     << pref2_array[found_index] << "\t" << pref3_array[found_index] << endl;
                            }
                        }
                        else if (admin_option == "3")
                        {
                            // Update student record
                            cout << "Enter the name you want to update record of : ";
                            string name;
                            cin >> name;
                            bool found = false;
                            int found_index = -1;
                            for (int i = 0; i < index; i++)
                            {
                                if (name_array[i] == name)
                                {
                                    found_index = i;
                                    found = true;
                                    break;
                                }
                            }
                            if (found == true)
                            {
                                cout << "------Old Record------ " << endl;
                                cout << "Name\tAge\tMatric\tInter\tECAT\tP1\tP2\tP3" << endl;
                                cout << name_array[found_index] << "\t" << age_array[found_index] << "\t"
                                     << matric_array[found_index] << "\t" << inter_array[found_index] << "\t"
                                     << ecat_array[found_index] << "\t" << pref1_array[found_index] << "\t"
                                     << pref2_array[found_index] << "\t" << pref3_array[found_index] << endl;

                                cout << "Enter new record for update " << endl;
                                cout << "Enter your Name : ";
                                string newname;
                                cin >> newname;
                                cout << "Enter Age : ";
                                int age;
                                cin >> age;
                                cout << "Enter Matric Marks : ";
                                float matric;
                                cin >> matric;
                                cout << "Enter your Inter Marks : ";
                                float inter;
                                cin >> inter;
                                cout << "Enter ECAT Marks : ";
                                float ecat;
                                cin >> ecat;
                                cout << "Enter CS, CE, EE as your preferences" << endl;
                                cout << "Enter your 1st pref : ";
                                string pref1;
                                cin >> pref1;
                                cout << "Enter your 2nd pref : ";
                                string pref2;
                                cin >> pref2;
                                cout << "Enter your 3rd pref : ";
                                string pref3;
                                cin >> pref3;

                                name_array[found_index] = newname;
                                age_array[found_index] = age;
                                matric_array[found_index] = matric;
                                inter_array[found_index] = inter;
                                ecat_array[found_index] = ecat;
                                pref1_array[found_index] = pref1;
                                pref2_array[found_index] = pref2;
                                pref3_array[found_index] = pref3;

                                cout << "Record updated successfully!" << endl;
                            }
                            else
                            {
                                cout << "Record not found " << endl;
                            }
                        }
                        else if (admin_option == "4")
                        {
                            // Generate merit list
                            for (int i = 0; i < index; i++)
                            {
                                aggregate_array[i] = matric_array[i] / 1050.0 * 100 * 0.30 + inter_array[i] / 1100.0 * 100 * 0.40 + ecat_array[i] / 400.0 * 100 * 0.30;
                            }

                            // Display before sorting
                            cout << "\n--- Aggregate Before Sorting ---" << endl;
                            cout << "Name\tAge\tAggregate" << endl;
                            for (int i = 0; i < index; i++)
                            {
                                if (name_array[i] != "")
                                    cout << name_array[i] << "\t" << age_array[i] << "\t" << aggregate_array[i] << endl;
                            }

                            // Sorting by aggregate (highest to lowest)
                            for (int i = 0; i < index; i++)
                            {
                                for (int j = i + 1; j < index; j++)
                                {
                                    if (aggregate_array[i] < aggregate_array[j])
                                    {
                                        // swapping name
                                        string temp = name_array[i];
                                        name_array[i] = name_array[j];
                                        name_array[j] = temp;
                                        // swapping age
                                        int tempAge = age_array[i];
                                        age_array[i] = age_array[j];
                                        age_array[j] = tempAge;
                                        // swapping matric
                                        float tempMatric = matric_array[i];
                                        matric_array[i] = matric_array[j];
                                        matric_array[j] = tempMatric;
                                        // swapping inter
                                        float tempInter = inter_array[i];
                                        inter_array[i] = inter_array[j];
                                        inter_array[j] = tempInter;
                                        // swapping ecat
                                        float tempEcat = ecat_array[i];
                                        ecat_array[i] = ecat_array[j];
                                        ecat_array[j] = tempEcat;
                                        // swapping pref1
                                        string tempP1 = pref1_array[i];
                                        pref1_array[i] = pref1_array[j];
                                        pref1_array[j] = tempP1;
                                        // swapping pref2
                                        string tempP2 = pref2_array[i];
                                        pref2_array[i] = pref2_array[j];
                                        pref2_array[j] = tempP2;
                                        // swapping pref3
                                        string tempP3 = pref3_array[i];
                                        pref3_array[i] = pref3_array[j];
                                        pref3_array[j] = tempP3;
                                        // swapping aggregate
                                        float tempAgg = aggregate_array[i];
                                        aggregate_array[i] = aggregate_array[j];
                                        aggregate_array[j] = tempAgg;
                                    }
                                }
                            }

                            // Display Merit List after sorting
                            cout << "\n--- Merit List (Sorted) ---" << endl;
                            cout << "Rank\tName\tAggregate" << endl;
                            for (int i = 0; i < index; i++)
                            {
                                if (name_array[i] != "")
                                    cout << i + 1 << "\t" << name_array[i] << "\t" << aggregate_array[i] << endl;
                            }

                            // ===== ADMIT STUDENTS INTO DISCIPLINE =====
                            int ce_count = 0;
                            int cs_count = 0;
                            int ee_count = 0;

                            // Reset discipline arrays
                            for (int i = 0; i < CE_SEATS; i++)
                                ce_students[i] = "";
                            for (int i = 0; i < CS_SEATS; i++)
                                cs_students[i] = "";
                            for (int i = 0; i < EE_SEATS; i++)
                                ee_students[i] = "";

                            cout << "\n===== ADMISSION PROCESS =====" << endl;

                            for (int i = 0; i < index; i++)
                            {
                                if (name_array[i] == "")
                                    continue;

                                bool admitted = false;
                                string prefs[3] = {pref1_array[i], pref2_array[i], pref3_array[i]};
                                string pref_labels[3] = {"1st", "2nd", "3rd"};

                                cout << "\nProcessing: " << name_array[i]
                                     << " | Aggregate: " << aggregate_array[i] << endl;

                                for (int p = 0; p < 3; p++)
                                {
                                    if (prefs[p] == "CE" && ce_count < CE_SEATS)
                                    {
                                        ce_students[ce_count++] = name_array[i];
                                        cout << name_array[i] << " admitted to CE ("
                                             << pref_labels[p] << " Preference)" << endl;
                                        admitted = true;
                                        break;
                                    }
                                    else if (prefs[p] == "CS" && cs_count < CS_SEATS)
                                    {
                                        cs_students[cs_count++] = name_array[i];
                                        cout << name_array[i] << " admitted to CS ("
                                             << pref_labels[p] << " Preference)" << endl;
                                        admitted = true;
                                        break;
                                    }
                                    else if (prefs[p] == "EE" && ee_count < EE_SEATS)
                                    {
                                        ee_students[ee_count++] = name_array[i];
                                        cout << name_array[i] << " admitted to EE ("
                                             << pref_labels[p] << " Preference)" << endl;
                                        admitted = true;
                                        break;
                                    }
                                    else
                                    {
                                        cout << prefs[p] << " is full, trying next preference..." << endl;
                                    }
                                }

                                if (!admitted)
                                    cout << name_array[i] << " could NOT be admitted (All preferences full)" << endl;
                            }

                            // Final Admission List
                            cout << "\n========================================" << endl;
                            cout << "         FINAL ADMISSION LIST           " << endl;
                            cout << "========================================" << endl;

                            cout << "\n--- Computer Engineering (CE) [" << ce_count << "/" << CE_SEATS << "] ---" << endl;
                            for (int i = 0; i < ce_count; i++)
                                cout << "  " << i + 1 << ". " << ce_students[i] << endl;

                            cout << "\n--- Computer Science (CS) [" << cs_count << "/" << CS_SEATS << "] ---" << endl;
                            for (int i = 0; i < cs_count; i++)
                                cout << "  " << i + 1 << ". " << cs_students[i] << endl;

                            cout << "\n--- Electrical Engineering (EE) [" << ee_count << "/" << EE_SEATS << "] ---" << endl;
                            for (int i = 0; i < ee_count; i++)
                                cout << "  " << i + 1 << ". " << ee_students[i] << endl;

                            cout << "\n========================================" << endl;
                            cout << "Total Admitted: " << ce_count + cs_count + ee_count
                                 << " / " << index << endl;
                            cout << "========================================" << endl;
                        }
                        else if (admin_option == "5")
                        {
                            // Delete student record
                            cout << "Enter the name you want to delete record of : ";
                            string name;
                            cin >> name;
                            bool found = false;
                            int found_index = -1;
                            for (int i = 0; i < index; i++)
                            {
                                if (name_array[i] == name)
                                {
                                    found_index = i;
                                    found = true;
                                    break;
                                }
                            }
                            if (found == true)
                            {
                                name_array[found_index] = "";
                                age_array[found_index] = 0;
                                matric_array[found_index] = 0;
                                inter_array[found_index] = 0;
                                ecat_array[found_index] = 0;
                                pref1_array[found_index] = "";
                                pref2_array[found_index] = "";
                                pref3_array[found_index] = "";
                                cout << "Record of " << name << " Deleted" << endl;
                            }
                            else
                            {
                                cout << "Record not found " << endl;
                            }
                        }
                        else if (admin_option == "6")
                        {
                            break;
                        }
                        else
                        {
                            cout << "Wrong option selected " << endl;
                        }
                        cout << "Press any key to continue... " << endl;
                        getch();
                    }
                    break;
                }
                else
                {
                    cout << "Username or password is invalid" << endl;
                }
                cout << "Press any key to continue... " << endl;
                getch();
            }
            cout << "Press any key to continue... " << endl;
            getch();
        }
        else if (user_option == "2")
        {
            // Student registration
            system("cls");
            cout << "Welcome to UMS Student Menu" << endl;
            cout << "Enter your Name : ";
            string name;
            cin >> name;
            cout << "Enter Age : ";
            int age;
            cin >> age;
            cout << "Enter Matric Marks : ";
            float matric;
            cin >> matric;
            cout << "Enter your Inter Marks : ";
            float inter;
            cin >> inter;
            cout << "Enter ECAT Marks : ";
            float ecat;
            cin >> ecat;
            cout << "Enter CS, CE, EE as your preferences" << endl;
            cout << "Enter your 1st pref : ";
            string pref1;
            cin >> pref1;
            cout << "Enter your 2nd pref : ";
            string pref2;
            cin >> pref2;
            cout << "Enter your 3rd pref : ";
            string pref3;
            cin >> pref3;

            name_array[index] = name;
            age_array[index] = age;
            matric_array[index] = matric;
            inter_array[index] = inter;
            ecat_array[index] = ecat;
            pref1_array[index] = pref1;
            pref2_array[index] = pref2;
            pref3_array[index] = pref3;
            index++;

            cout << "Your data has been saved" << endl;
            cout << "Press any key to continue... " << endl;
            getch();
        }
        else if (user_option == "3")
        {
            break;
        }
        else
        {
            cout << "You entered a wrong option" << endl;
        }
    }

    cout << endl
         << "Thanks for using the software" << endl;
}