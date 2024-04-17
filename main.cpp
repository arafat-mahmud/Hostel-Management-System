#include <iostream>
#include <fstream>

using namespace std;

class hostelManage
{
private:
    int st_id;
    string st_name;
    string st_room;

public:
    // Constructor
    hostelManage()
    {
        st_id = 0;
        st_name = "";
        st_room = "";
    }

    // Function to add student data
    void st_add_data(int id, string name, string room_no)
    {
        st_id = id;
        st_name = name;
        st_room = room_no;
        saveStudentData(); // Save student data to file
    };

    // Function to show student data
    void st_show_data()
    {
        ifstream inFile("database.txt");
        if (inFile.is_open())
        {
            cout << "-----------------------------------------\n";
            cout << "Student ID  |  Student Name  |  Room No |\n-----------------------------------------\n";
            while (inFile >> st_id >> st_name >> st_room)
            {
                cout << st_id << "    |    " << st_name << "       |   " << st_room << "    |" << endl;
                cout << "-----------------------------------------\n";
            }
            inFile.close();
        }
        else
        {
            cout << "No student data available." << endl;
        }
    };

    // Search for student data
    void st_search_data(int id)
    {
        ifstream inFile("database.txt");
        if (inFile.is_open())
        {
            while (inFile >> st_id >> st_name >> st_room)
            {
                if (st_id == id)
                {
                    cout << "Student ID: " << st_id << endl;
                    cout << "Student Name: " << st_name << endl;
                    cout << "Student Room: " << st_room << endl;
                    return;
                }
            }
            cout << "Student not found." << endl;
            inFile.close();
        }
        else
        {
            cout << "No student data available." << endl;
        }
    };

    // Update student data
    void st_update_data(int id, string name, string room_no)
    {
        ifstream inFile("database.txt");
        ofstream outFile("temp.txt");
        bool found = false;
        if (inFile.is_open() && outFile.is_open())
        {
            while (inFile >> st_id >> st_name >> st_room)
            {
                if (st_id == id)
                {
                    outFile << id << " " << name << " " << room_no << endl;
                    found = true;
                }
                else
                {
                    outFile << st_id << " " << st_name << " " << st_room << endl;
                }
            }
            inFile.close();
            outFile.close();
            remove("database.txt");
            rename("temp.txt", "database.txt");
        }
        else
        {
            cout << "Unable to open files." << endl;
        }

        if (found)
        {
            cout << "Student data updated successfully." << endl;
        }
        else
        {
            cout << "Student not found." << endl;
        }
    };

    // Delete student data
    void st_delete_data(int id)
    {
        ifstream inFile("database.txt");
        ofstream outFile("temp.txt");
        bool found = false;
        if (inFile.is_open() && outFile.is_open())
        {
            while (inFile >> st_id >> st_name >> st_room)
            {
                if (st_id == id)
                {
                    found = true;
                }
                else
                {
                    outFile << st_id << " " << st_name << " " << st_room << endl;
                }
            }
            inFile.close();
            outFile.close();
            remove("database.txt");
            rename("temp.txt", "database.txt");
        }
        else
        {
            cout << "Unable to open files." << endl;
        }

        if (found)
        {
            cout << "Student data deleted successfully." << endl;
        }
        else
        {
            cout << "Student not found." << endl;
        }
    };

private:
    // Save student data to file
    void saveStudentData()
    {
        ofstream outFile("database.txt", ios::app);
        if (outFile.is_open())
        {
            outFile << st_id << " " << st_name << " " << st_room << endl;
            outFile.close();
        }
        else
        {
            cout << "Anything Mistake" << endl;
        }
    }
};

// Admin login
bool admin_login(string username, string pass)
{
    if (username == "a" && pass == "a")
    {
        cout << "\nLogin successful" << endl;
        return true;
    }
    else
    {
        cout << "Login failed" << endl;
        return false;
    }
};

int main()
{
    cout << "\nWelcome to Student Hostel Management System" << endl;
    cout << "===========================================\n"
         << endl;

    string username;
    string password;
    bool loggedIn = false;

    do
    {
        cout << "Enter username: ";
        cin >> username;
        cout << "Enter password: ";
        cin >> password;
        loggedIn = admin_login(username, password);
    } while (!loggedIn);

    hostelManage adm;

    int choice;
    do
    {
        cout << "\nChoose any option-\n" << endl;
        cout << "1. Add data" << endl;
        cout << "2. Show data" << endl;
        cout << "3. Search data" << endl;
        cout << "4. Update data" << endl;
        cout << "5. Delete data" << endl;
        cout << "6. Logout" << endl;
        cout << "7. Exit\n" << endl;
        cout << "Enter the number: ";
        cin >> choice;
        cout << "====================\n";


        switch (choice)
        {
        case 1:
        {
            int id;
            string name, room_no;
            cout << "Enqueue new student in this hostel\n";
            cout << "----------------------------------\n";
            cout << "\nEnter Student ID: ";
            cin >> id;
            cout << "Enter Student Name: ";
            cin >> name;
            cout << "Enter Student Room: ";
            cin >> room_no;
            adm.st_add_data(id, name, room_no);
            break;
        }
        case 2:
            adm.st_show_data();
            break;
        case 3:
        {
            int id;
            cout << "Enter student ID to search: ";
            cin >> id;
            adm.st_search_data(id);
            break;
        }
        case 4:
        {
            int id;
            string name, room_no;
            cout << "Enter student ID to update: ";
            cin >> id;
            cout << "Enter updated student name: ";
            cin >> name;
            cout << "Enter updated student room_no: ";
            cin >> room_no;
            adm.st_update_data(id, name, room_no);
            break;
        }
        case 5:
        {
            int id;
            cout << "Enter student ID to delete: ";
            cin >> id;
            adm.st_delete_data(id);
            break;
        }

        }

    } while (choice != 6 && choice != 7);


}