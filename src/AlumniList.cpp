#include "AlumniList.h"
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

void AlumniList::addAlumni(Alumni *new_alumni) {
    new_alumni->next = head;
    head = new_alumni;
    size++;
    head->display();
    cout << "添加成功！" << endl;
}

void AlumniList::deleteAlumni(const std::string &name) {
    Alumni *current = head, *pre = nullptr;
    while (current != nullptr) {
        if (current->getName() == name) {
            if (pre == nullptr) {
                head = current->next;
            } else {
                pre->next = current->next;
            }
            size--;
            // delete current;
            cout << "删除成功！" << endl;
            return;
        }
        pre = current;
        current = current->next;
    }
    cout << "未找到此校友！" << endl;
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

void AlumniList::searchByName(const std::string &name) {
    Alumni *current = head;
    int count = 0;
    while (current != nullptr) {
        if (current->getName() == name) {
            cout << "找到校友：" << endl;
            current->display();
            count++;
        }
        current = current->next;
    }
    if (count > 0) {
        cout << "共找到" << count << "位校友！" << endl;
        return;
    } else {
        cout << "未查找到此校友！" << endl;
        return;
    }
}

void AlumniList::searchByGraduationYear(const int year) {
    Alumni *current = head;
    int count = 0;
    while (current != nullptr) {
        if (current->getGraduationYear() == year) {
            cout << "找到校友：" << endl;
            current->display();
            count++;
        }
        current = current->next;
    }
    if (count > 0) {
        cout << "共找到" << count << "位校友！" << endl;
        return;
    } else {
        cout << "未查找到此校友！" << endl;
        return;
    }
}

void AlumniList::searchByMajor(const std::string &major) {
    Alumni *current = head;
    int count = 0;
    while (current != nullptr) {
        if (current->getMajor() == major) {
            cout << "找到校友：" << endl;
            current->display();
            count++;
        }
        current = current->next;
    }
    if (count > 0) {
        cout << "共找到" << count << "位校友！" << endl;
        return;
    } else {
        cout << "未查找到此校友！" << endl;
        return;
    }
}

void AlumniList::searchByClassName(const std::string &class_name) {
    Alumni *current = head;
    int count = 0;
    while (current != nullptr) {
        if (current->getClassName() == class_name) {
            cout << "找到校友：" << endl;
            current->display();
            count++;
        }
        current = current->next;
    }
    if (count > 0) {
        cout << "共找到" << count << "位校友！" << endl;
        return;
    } else {
        cout << "未查找到此校友！" << endl;
        return;
    }
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

void AlumniList::ascendingSortName() {
    for (int i = 0; i < size; i++) {
        Alumni *current = head, *pre = nullptr, *next = current->next;
        while (next != nullptr) {
            if (current->getName() >= next->getName()) {
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

void AlumniList::descendingSortName() {
    for (int i = 0; i < size; i++) {
        Alumni *current = head, *pre = nullptr, *next = current->next;
        while (next != nullptr) {
            if (current->getName() <= next->getName()) {
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
