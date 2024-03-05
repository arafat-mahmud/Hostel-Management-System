#include <iostream>

using namespace std;

class hostelManage
{

private:
    int st_id;
    // string st_password;
    string st_name;
    string st_email;

public:
    // login 1
    void admin_login(string username, string pass);

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
void hostelManage::admin_login(string username, string pass)
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
    adm.admin_login(username, password);

    cout << "1. Add data" << endl;
    cout << "2. Show data:" << endl;
    cout << "3. Search data:" << endl;
    cout << "4. Update data:" << endl;
    cout << "5. Delete data:" << endl;
    cout << "6. Logout" << endl;
    cout << "7. Exit" << endl;
};
