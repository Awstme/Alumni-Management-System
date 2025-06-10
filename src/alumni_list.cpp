#include "alumni_list.h"
#include <iostream>
#include <fstream>

using namespace std;

AlumniList::AlumniList(string fileName) : size(0), head(NULL)
{
    ifstream inFile(fileName);
    // 检查文件是否成功打开
    if (!inFile)
    {
        cerr << "File not found!" << endl;
        return;
    }
    // 读取文件到链表中
        Alumni *current = NULL;
    while (!inFile.eof())
    {
        string name, gender, department, className, address, phone, qq, email;
        int age, graduationYear;
        inFile >> name >> gender >> age >> graduationYear >> department >> className >> address >> phone >> qq >> email;
        if (size == 0)
        {
            head = new Alumni(name, gender, age, graduationYear, department, className, address, phone, qq, email);
            current = head;
            size++;
        }
        else
        {
            current->next = new Alumni(name, gender, age, graduationYear, department, className, address, phone, qq, email);
            current = current->next;
            size++;
        }
    }
}

void AlumniList::display()
{
    Alumni *current = head;
    while (current != NULL)
    {
        cout  << "Name: " << current->getName() << " Gender: " << current->getGender() << " Age: " << current->getAge() << " Graduation Year: " << current->getGraduationYear() << " Department: " << current->getDepartment() << " Class Name: " << current->getClassName() << " Address: " << current->getAddress() << " Phone: " << current->getPhone() << " QQ: " << current->getQq() << " Email: " << current->getEmail() << endl;
        current = current->next;
    }
}