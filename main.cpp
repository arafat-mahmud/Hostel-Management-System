#include <iostream>

using namespace std;

class hostelManage
{

private:
    int st_id;
    string st_password;
    string st_name;
    string st_email;

public:
    // login 1
    void st_login(int id, string st_password);

    // Student Add
    void st_add_data(int id, string name, string email)
    {
        st_id = id;
        st_name = name;
        st_email = email;
    };

    // Student Show data
    void st_show_data(int id, string name, string email)
    {
        st_id = id;
        st_name = name;
        st_email = email;
    };

    // Student search data
    void st_search_data(int id)
    {
        st_id = id;
    };

    // Student update data
    void st_update_data(int id, string name, string email)
    {
        st_id = id;
        st_name = name;
        st_email = email;
    };

    // Student delete
    void st_delete_data(int id)
    {
        st_id = id;
    };
};

// login 2
void hostelManage::st_login(int id, string password)
{
    if (id == st_id && password == st_password)
    {
        cout << "Login successful!" << endl;
        cout << "Student ID: " << st_id << endl;
        cout << "Student Name: " << st_name << endl;
        cout << "Student Email: " << st_email << endl;
    }
    else
    {
        cout << "Invalid User" << endl;
    }
};

int main()
{
    cout << "Welcome to Student Hostel Management System" << endl;
    cout << "===========================================\n" << endl;

    cout << "1. Add data" << endl;
    cout << "2. Show data:" << endl;
    cout << "3. Search data:" << endl;
    cout << "4. Update data:" << endl;
    cout << "5. Delete data:" << endl;
    cout << "6. Logout" << endl;
    cout << "7. Exit" << endl;


};
