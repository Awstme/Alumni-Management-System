#include "Alumni.h"
#include <iostream>
#include <iomanip>

using namespace std;

Alumni::Alumni(string user_name, string password,
               string name, string gender, int age, int graduationYear,
               string major, string className,
               string address, string phone, string qq, string email) : Person(user_name, password), next(nullptr),
                                                                        name(name), gender(gender), age(age),
                                                                        graduationYear(graduationYear),
                                                                        major(major), className(className),
                                                                        address(address), phone(phone),
                                                                        qq(qq), email(email) { ; }

void Alumni::setName(string newName) { name = newName; }
void Alumni::setGender(string newGender) { gender = newGender; }
void Alumni::setAge(int newAge) { age = newAge; }
void Alumni::setGraduationYear(int newGraduationYear) { graduationYear = newGraduationYear; }
void Alumni::setDepartment(string newDepartment) { major = newDepartment; }
void Alumni::setClassName(string newClassName) { className = newClassName; }
void Alumni::setAddress(string newAddress) { address = newAddress; }
void Alumni::setPhone(string newPhone) { phone = newPhone; }
void Alumni::setQq(string newQq) { qq = newQq; }
void Alumni::setEmail(string newEmail) { email = newEmail; }

string Alumni::getName() { return name; }
string Alumni::getGender() { return gender; }
int Alumni::getAge() { return age; }
int Alumni::getGraduationYear() { return graduationYear; }
string Alumni::getMajor() { return major; }
string Alumni::getClassName() { return className; }
string Alumni::getAddress() { return address; }
string Alumni::getPhone() { return phone; }
string Alumni::getQq() { return qq; }
string Alumni::getEmail() { return email; }

void Alumni::display(const int &detailValue) {
    cout << left << setfill(' ');
    if (detailValue >= 3) {
        cout << setw(10) << "用户名：" << setw(12) << user_name;
    }
    cout << setw(6) << "姓名：" << setw(12) << name
            << setw(6) << "性别：" << setw(6) << gender
            << setw(6) << "年龄：" << setw(3) << age
            << setw(6) << "届级：" << setw(5) << graduationYear
            << setw(6) << "学院：" << setw(15) << major
            << setw(6) << "班级：" << setw(8) << className << endl;
    if (detailValue >= 2) {
        cout << setw(6) << "地址：" << setw(20) << address
                << setw(6) << "电话：" << setw(15) << phone
                << setw(4) << "QQ：" << setw(12) << qq
                << setw(6) << "邮箱：" << setw(15) << email << endl;
    }
    cout << setw(80) << setfill('-') << "-" << endl;
}
