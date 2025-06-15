#include "Person.h"
#include <iostream>
#include <string>

using namespace std;

// 构造函数：初始化用户名和密码
Person::Person(string user_name, string password): user_name(user_name), password(password) { ; }

// 设置密码
void Person::setPassword(const string &new_password) { password = new_password; }

// 获取用户名
string Person::getUserName() { return user_name; }

// 获取密码
string Person::getPassword() { return password; }

// 修改密码
void Person::modifyPassword() {
    cout << "请输入新密码：";
    string new_password;
    cin >> new_password;
    setPassword(new_password);
    cout << "密码修改成功！" << endl;
}
