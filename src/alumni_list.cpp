#include "alumni_list.h"
#include <iostream>
#include <fstream>

using namespace std;

AlumniList::AlumniList(const string &fileName) : size(0), head(nullptr) {
    ifstream inFile(fileName);
    // 检查文件是否成功打开
    if (!inFile) {
        cerr << "File not found!" << endl;
        return;
    }
    // 读取文件到链表中
    Alumni *current = nullptr;
    while (!inFile.eof()) {
        string name, gender, department, className, address, phone, qq, email;
        int age, graduationYear;
        inFile >> name >> gender >> age >> graduationYear >> department >> className >> address >> phone >> qq >> email;
        if (size == 0) {
            head = new Alumni(name, gender, age, graduationYear, department, className, address, phone, qq, email);
            current = head;
            size++;
        } else {
            current->next = new Alumni(name, gender, age, graduationYear, department, className, address, phone, qq,
                                       email);
            current = current->next;
            size++;
        }
    }
    inFile.close();
    ascendingSortGraduationYear();
}

void AlumniList::display() {
    Alumni *current = head;
    while (current != nullptr) {
        current->display();
        current = current->next;
    }
}

void AlumniList::displayDetail() {
}

void AlumniList::ascendingSortGraduationYear() {
    for (int i = 0; i < size; i++) {
        Alumni *current = head, *pre = nullptr, *next = current->next;
        while (next != nullptr) {
            if (current->getGraduationYear() >= next->getGraduationYear()) {
                current->next = next->next;
                next->next = current;
                if (pre == nullptr) {
                    head = next;
                } else {
                    pre->next = next;
                }
                pre = next;
                next = current->next;
            } else {
                if (pre == nullptr) {
                    pre = current;
                } else {
                    pre = pre->next;
                }
                current = current->next;
                next = next->next;
            }
        }
    }
}

void AlumniList::descendingSortGraduationYear() {
    for (int i = 0; i < size; i++) {
        Alumni *current = head, *pre = nullptr, *next = current->next;
        while (next != nullptr) {
            if (current->getGraduationYear() <= next->getGraduationYear()) {
                current->next = next->next;
                next->next = current;
                if (pre == nullptr) {
                    head = next;
                } else {
                    pre->next = next;
                }
                pre = next;
                next = current->next;
            } else {
                if (pre == nullptr) {
                    pre = current;
                } else {
                    pre = pre->next;
                }
                current = current->next;
                next = next->next;
            }
        }
    }
}
