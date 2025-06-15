#include "Alumni.h"
#include <iostream>
#include <iomanip>

using namespace std;

// 构造函数：初始化校友的所有属性
Alumni::Alumni(string user_name, string password,
               string name, string gender, int age, int graduationYear,
               string major, string className,
               string address, string phone, string qq, string email,
               int is_manager) : Person(user_name, password), next(nullptr),
                                 name(name), gender(gender), age(age),
                                 graduationYear(graduationYear),
                                 major(major), className(className),
                                 address(address), phone(phone),
                                 qq(qq), email(email),
                                 is_manager(is_manager) { ; }

// 设置姓名
void Alumni::setName(string newName) { name = newName; }

// 设置性别
void Alumni::setGender(string newGender) { gender = newGender; }

// 设置年龄
void Alumni::setAge(int newAge) { age = newAge; }

// 设置届级
void Alumni::setGraduationYear(int newGraduationYear) { graduationYear = newGraduationYear; }

// 设置专业
void Alumni::setMajor(string newMajor) { major = newMajor; }

// 设置班级
void Alumni::setClassName(string newClassName) { className = newClassName; }

// 设置地址
void Alumni::setAddress(string newAddress) { address = newAddress; }

// 设置电话号码
void Alumni::setPhone(string newPhone) { phone = newPhone; }

// 设置QQ号
void Alumni::setQq(string newQq) { qq = newQq; }

// 设置邮箱
void Alumni::setEmail(string newEmail) { email = newEmail; }

// 获取姓名
string Alumni::getName() { return name; }

// 获取性别
string Alumni::getGender() { return gender; }

// 获取年龄
int Alumni::getAge() { return age; }

// 获取届级
int Alumni::getGraduationYear() { return graduationYear; }

// 获取专业（学院）
string Alumni::getMajor() { return major; }

// 获取班级
string Alumni::getClassName() { return className; }

// 获取地址
string Alumni::getAddress() { return address; }

// 获取电话号码
string Alumni::getPhone() { return phone; }

// 获取QQ号
string Alumni::getQq() { return qq; }

// 获取邮箱
string Alumni::getEmail() { return email; }

// 判断是否为管理员
int Alumni::isManager() { return is_manager; }

// 显示校友信息，detailValue控制显示详细程度
void Alumni::display(const int &detailValue) {
    cout << left << setfill(' ');
    if (detailValue >= 3) {
        // 显示用户名（仅在detailValue >= 3时显示）
        cout << setw(10) << "用户名：" << setw(12) << user_name;
    }
    // 显示基本信息：姓名、性别、年龄、届级、专业、班级
    cout << setw(6) << "姓名：" << setw(12) << name
            << setw(6) << "性别：" << setw(6) << gender
            << setw(6) << "年龄：" << setw(3) << age
            << setw(6) << "届级：" << setw(5) << graduationYear
            << setw(6) << "学院：" << setw(15) << major
            << setw(6) << "班级：" << setw(8) << className << endl;
    if (detailValue >= 2) {
        // 显示详细信息：地址、电话、QQ、邮箱（仅在detailValue >= 2时显示）
        cout << setw(6) << "地址：" << setw(20) << address
                << setw(6) << "电话：" << setw(15) << phone
                << setw(4) << "QQ：" << setw(12) << qq
                << setw(6) << "邮箱：" << setw(15) << email << endl;
    }
    // 打印分隔线
    cout << setw(80) << setfill('-') << "-" << endl;
}
