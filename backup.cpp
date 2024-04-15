#include <iostream>
#include <fstream>

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
        if (st_id != 0)
        {
            cout << "Student ID: " << st_id << endl;
            cout << "Student Name: " << st_name << endl;
            cout << "Student Email: " << st_email << endl;
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
    };

    // Function to update student data
    void st_update_data(int id, string name, string email)
    {
        // Implement update functionality
    };

    // Function to delete student data
    void st_delete_data(int id)
    {
        // Implement delete functionality
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
            cout << "Unable to open file for saving student data." << endl;
        }
    }
};

// Function to handle admin login
void admin_login(string username, string pass)
{
    if (username == "admin" && pass == "hostel")
    {
        cout << "\nlogin successful" << endl;
    }
    else
    {
        cout << "login fail" << endl;
    }
};

int main()
{
    cout << "Welcome to Student Hostel Management System" << endl;
    cout << "===========================================\n"
         << endl;

    hostelManage adm;
    string username;
    string password;
    cout << "Enter username: ";
    cin >> username;
    cout << "Enter password: ";
    cin >> password;
    admin_login(username, password);

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
        // Implement cases for other options (3, 4, 5, 6, 7)
        }

    } while (choice != 7);

    return 0;
}
