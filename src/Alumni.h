#ifndef ALUMNI_H
#define ALUMNI_H

#include "Person.h"

// 校友类，继承自Person类
// 存储校友的详细信息，并提供数据访问方法
class Alumni : public Person {
public:
    Alumni *next;  // 指向下一个校友节点的指针

    // 构造函数：初始化校友的所有属性
    Alumni(std::string user_name, std::string password,
           std::string name, std::string gender, int age, int graduationYear,
           std::string major, std::string className,
           std::string address, std::string phone, std::string qq, std::string email,
           int is_manager);

    // 设置姓名
    void setName(std::string newName);

    // 设置性别
    void setGender(std::string newGender);

    // 设置年龄
    void setAge(int newAge);

    // 设置届级
    void setGraduationYear(int newGraduationYear);

    // 设置专业（学院）
    void setMajor(std::string newMajor);

    // 设置班级
    void setClassName(std::string newClassName);

    // 设置地址
    void setAddress(std::string newAddress);

    // 设置电话号码
    void setPhone(std::string newPhone);

    // 设置QQ号
    void setQq(std::string newQq);

    // 设置邮箱
    void setEmail(std::string newEmail);

    // 获取姓名
    std::string getName();

    // 获取性别
    std::string getGender();

    // 获取年龄
    int getAge();

    // 获取届级
    int getGraduationYear();

    // 获取专业（学院）
    std::string getMajor();

    // 获取班级
    std::string getClassName();

    // 获取地址
    std::string getAddress();

    // 获取电话号码
    std::string getPhone();

    // 获取QQ号
    std::string getQq();

    // 获取邮箱
    std::string getEmail();

    // 判断是否为管理员
    int isManager();

    // 显示校友信息
    void display(const int &detailValue);

protected:
    std::string name;     // 姓名
    std::string gender;   // 性别
    int age;              // 年龄
    int graduationYear;   // 届级
    std::string major;    // 专业（学院）
    std::string className; // 班级
    std::string address;  // 地址
    std::string phone;    // 电话号码
    std::string qq;       // QQ号
    std::string email;    // 邮箱
    int is_manager;       // 是否为管理员标识
};

#endif // ALUMNI_H
