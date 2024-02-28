#include <iostream>

using namespace std;

class hostelManage{

    private:
    int st_id;
    string st_password;
    string st_name;
    string st_email;
    
    public:
    // login
    void st_login(int id, string st_password);

    // Student Add
    void st_add_data(int id, string name, string email);

    // Student Show data
    void st_show_data(int id,  string name, string email);

    // Student search data
    void st_search_data(int id);

    // Student update data
    void st_update_data(int id, string name, string email);

    // Student delete
    void st_delete_data(int id);
};

int main(){
    cout << "Hostel Management System" << endl;
    cout << "========================" << endl;

};
