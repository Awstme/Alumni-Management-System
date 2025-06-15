#ifndef PERSON_H
#define PERSON_H

#include <string>

// 人员基类，定义所有人员共有的属性和方法
// 包含用户名和密码两个基本属性
class Person {
public:
    // 构造函数：初始化用户名和密码
    Person(std::string user_name, std::string password);

    // 设置密码（已禁用）
    // void setUserName(std::string new_name);

    // 设置密码
    void setPassword(const std::string &new_password);

    // 获取用户名
    std::string getUserName();

    // 获取密码
    std::string getPassword();

    // 修改密码
    void modifyPassword();

protected:
    std::string user_name;  // 用户名
    std::string password;     // 密码
};


#endif //PERSON_H
