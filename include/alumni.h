#include <iostream>
#include <string>

using namespace std;

class Alumni
{
protected:
    string name;
    string gender;
    int age;
    int graduationYear;
    string department;
    string className;
    string address;
    string phone;
    string qq;
    string email;

public:
    Alumni(string name, string gender, int age, int graduationYear, string department, string className, string address, string phone, string qq, string email) {};

    void setName(string newName);
    void setGender(string newGender);
    void setAge(int newAge);
    void setGraduationYear(int newGraduationYear);
    void setDepartment(string newDepartment);
    void setClassName(string newClassName);
    void setAddress(string newAddress);
    void setPhone(string newPhone);
    void setQq(string newQq);
    void setEmail(string newEmail);

    string getName();
    string getGender();
    int getAge();
    int getGraduationYear();
    string getDepartment();
    string getClassName();
    string getAddress();
    string getPhone();
    string getQq();
    string getEmail();
};