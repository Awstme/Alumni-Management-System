#include "alumni.h"
#include <iostream>
#include <iomanip>

using namespace std;

Alumni::Alumni(string name, string gender, int age, int graduationYear, string department, string className,
               string address, string phone, string qq, string email) : next(nullptr),
                                                                        name(name), gender(gender), age(age),
                                                                        graduationYear(graduationYear),
                                                                        department(department), className(className),
                                                                        address(address), phone(phone), qq(qq),
                                                                        email(email) {
}

void Alumni::setName(string newName) { name = newName; }
void Alumni::setGender(string newGender) { gender = newGender; }
void Alumni::setAge(int newAge) { age = newAge; }
void Alumni::setGraduationYear(int newGraduationYear) { graduationYear = newGraduationYear; }
void Alumni::setDepartment(string newDepartment) { department = newDepartment; }
void Alumni::setClassName(string newClassName) { className = newClassName; }
void Alumni::setAddress(string newAddress) { address = newAddress; }
void Alumni::setPhone(string newPhone) { phone = newPhone; }
void Alumni::setQq(string newQq) { qq = newQq; }
void Alumni::setEmail(string newEmail) { email = newEmail; }

string Alumni::getName() { return name; }
string Alumni::getGender() { return gender; }
int Alumni::getAge() { return age; }
int Alumni::getGraduationYear() { return graduationYear; }
string Alumni::getDepartment() { return department; }
string Alumni::getClassName() { return className; }
string Alumni::getAddress() { return address; }
string Alumni::getPhone() { return phone; }
string Alumni::getQq() { return qq; }
string Alumni::getEmail() { return email; }

void Alumni::display() {
    cout << left /*<<setfill(' ')*/
            << setw(6) << "姓名：" << setw(12) << name
            << setw(6) << "性别：" << setw(6) << gender
            << setw(6) << "年龄：" << setw(3) << age
            << setw(10) << "毕业年份：" << setw(5) << graduationYear
            << setw(6) << "学院：" << setw(15) << department
            << setw(6) << "班级：" << setw(8) << className
            << endl;
}

void Alumni::displayDetail() {
    cout << left
            << setw(6) << "姓名：" << setw(12) << name
            << setw(6) << "性别：" << setw(6) << gender
            << setw(6) << "年龄：" << setw(3) << age
            << setw(10) << "毕业年份：" << setw(5) << graduationYear
            << setw(6) << "学院：" << setw(15) << department
            << setw(6) << "班级：" << setw(8) << className
            << setw(6) << "地址：" << setw(10) << address
            << setw(6) << "电话：" << setw(10) << phone
            << setw(4) << "QQ：" << setw(10) << qq
            << setw(6) << "邮箱：" << setw(10) << email
            << endl;
}
