#include<iostream>
#include<string>

using namespace std;

class Alumni
{
protected:
    string name;
    bool sex;
    int age;
    int graduationYear;
    string department;
    string className;
    string address;
    string phone;
    string qq;
    string email;
public:
    Alumni(string name,bool sex,int age,int graduationYear,string department,string className,string address,string phone,string qq,string email){}
};