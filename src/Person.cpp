#include "Person.h"

#include <iostream>
#include <string>

using namespace std;

Person::Person(string user_name, string password): user_name(user_name), password(password) { ; }

void Person::setPassword(const string &new_password) { password = new_password; }

string Person::getUserName() { return user_name; }
string Person::getPassword() { return password; }

void Person::modifyPassword() {
    cout << "请输入新密码：";
    string new_password;
    cin >> new_password;
    setPassword(new_password);
    cout << "密码修改成功！" << endl;
}
