#ifndef ALUMNI_H
#define ALUMNI_H

#include "Person.h"


class Alumni : public Person {
public:
    Alumni *next;

    Alumni(std::string user_name, std::string password,
           std::string name, std::string gender, int age, int graduationYear,
           std::string major, std::string className,
           std::string address, std::string phone, std::string qq, std::string email);

    void setName(std::string newName);

    void setGender(std::string newGender);

    void setAge(int newAge);

    void setGraduationYear(int newGraduationYear);

    void setDepartment(std::string newDepartment);

    void setClassName(std::string newClassName);

    void setAddress(std::string newAddress);

    void setPhone(std::string newPhone);

    void setQq(std::string newQq);

    void setEmail(std::string newEmail);

    std::string getName();

    std::string getGender();

    int getAge();

    int getGraduationYear();

    std::string getMajor();

    std::string getClassName();

    std::string getAddress();

    std::string getPhone();

    std::string getQq();

    std::string getEmail();

    void display(const int &detailValue);
protected:
    std::string name;
    std::string gender;
    int age;
    int graduationYear;
    // int stu_id;
    std::string major;
    std::string className;
    std::string address;
    std::string phone;
    std::string qq;
    std::string email;
};

#endif // ALUMNI_H
