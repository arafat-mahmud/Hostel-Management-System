#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

class hostelManage
{

private:
    int st_id;
    string st_name;
    string st_email;

public:
    // Constructor
    hostelManage()
    {
        st_id = 0;
        st_name = "";
        st_email = "";
    }

    // Function to add student data
    void st_add_data(int id, string name, string email)
    {
        st_id = id;
        st_name = name;
        st_email = email;
        saveStudentData(); // Save student data to file
    };

    // Function to show student data
    void st_show_data()
    {
        ifstream inFile("students.txt");
        if (inFile.is_open())
        {
            while (inFile >> st_id >> st_name >> st_email)
            {
                cout << "Student ID: " << st_id << endl;
                cout << "Student Name: " << st_name << endl;
                cout << "Student Email: " << st_email << endl;
            }
            inFile.close();
        }
        else
        {
            cout << "No student data available." << endl;
        }
    };

    // Function to search for student data
    void st_search_data(int id)
    {
        // Implement search functionality
        ifstream inFile("students.txt");
        if (inFile.is_open())
        {
            while (inFile >> st_id >> st_name >> st_email)
            {
                if (st_id == id)
                {
                    cout << "Student ID: " << st_id << endl;
                    cout << "Student Name: " << st_name << endl;
                    cout << "Student Email: " << st_email << endl;
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

    // Function to update student data
    void st_update_data(int id, string name, string email)
    {
        // Implement update functionality
        ifstream inFile("students.txt");
        ofstream outFile("temp.txt");
        bool found = false;
        if (inFile.is_open() && outFile.is_open())
        {
            while (inFile >> st_id >> st_name >> st_email)
            {
                if (st_id == id)
                {
                    outFile << id << " " << name << " " << email << endl;
                    found = true;
                }
                else
                {
                    outFile << st_id << " " << st_name << " " << st_email << endl;
                }
            }
            inFile.close();
            outFile.close();
            remove("students.txt");
            rename("temp.txt", "students.txt");
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

    // Function to delete student data
    void st_delete_data(int id)
    {
        // Implement delete functionality
        ifstream inFile("students.txt");
        ofstream outFile("temp.txt");
        bool found = false;
        if (inFile.is_open() && outFile.is_open())
        {
            while (inFile >> st_id >> st_name >> st_email)
            {
                if (st_id == id)
                {
                    found = true;
                }
                else
                {
                    outFile << st_id << " " << st_name << " " << st_email << endl;
                }
            }
            inFile.close();
            outFile.close();
            remove("students.txt");
            rename("temp.txt", "students.txt");
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
    // Function to save student data to file
    void saveStudentData()
    {
        ofstream outFile("students.txt", ios::app);
        if (outFile.is_open())
        {
            outFile << st_id << " " << st_name << " " << st_email << endl;
            outFile.close();
        }
        else
        {
            cout << "Anything Mistake" << endl;
        }
    }
};

// Function to handle admin login
bool admin_login(string username, string pass)
{
    if (username == "admin" && pass == "hostel")
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
    cout << "Welcome to Student Hostel Management System" << endl;
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
        cout << "\nChoose an option:" << endl;
        cout << "1. Add data" << endl;
        cout << "2. Show data" << endl;
        cout << "3. Search data" << endl;
        cout << "4. Update data" << endl;
        cout << "5. Delete data" << endl;
        cout << "6. Logout" << endl;
        cout << "7. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
        {
            int id;
            string name, email;
            cout << "Enter student ID: ";
            cin >> id;
            cout << "Enter student name: ";
            cin >> name;
            cout << "Enter student email: ";
            cin >> email;
            adm.st_add_data(id, name, email);
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
            string name, email;
            cout << "Enter student ID to update: ";
            cin >> id;
            cout << "Enter updated student name: ";
            cin >> name;
            cout << "Enter updated student email: ";
            cin >> email;
            adm.st_update_data(id, name, email);
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


    return 0;
}