#include "AlumniList.h"
#include <iostream>
#include <fstream>

using namespace std;

// 构造函数：从文件加载校友数据到链表
AlumniList::AlumniList(const string &fileName) : size(0), head(nullptr), file_name(fileName) {
    ifstream inFile(fileName);
    // 检查文件是否成功打开
    if (!inFile) {
        cerr << "File not found!" << endl;
        return;
    }
    // 读取文件到链表中
    Alumni *current = nullptr;
    while (!inFile.eof()) {
        string user_name, password, name, gender, major, className, address, phone, qq, email;
        int age, graduationYear, is_manager;
        inFile >> user_name >> password >> is_manager
                >> name >> gender >> age >> graduationYear >> major >> className
                >> address >> phone >> qq >> email;
        if (size == 0) {
            head = new Alumni(user_name, password,
                              name, gender, age, graduationYear,
                              major, className,
                              address, phone, qq, email,
                              is_manager);
            current = head;
            size++;
        } else {
            current->next = new Alumni(user_name, password,
                                       name, gender, age, graduationYear,
                                       major, className,
                                       address, phone, qq, email,
                                       is_manager);
            current = current->next;
            size++;
        }
    }
    inFile.close();
}

// 添加校友信息到链表头部
void AlumniList::addAlumni(Alumni *new_alumni) {
    new_alumni->next = head;
    head = new_alumni;
    size++;
    head->display(1);
    cout << "添加成功！" << endl;
}

// 更新校友信息
void AlumniList::updateAlumni(const std::string &name) {
    Alumni *current = head;
    while (current != nullptr) {
        if (current->getName() == name) {
            cout << "=====================================" << endl;
            cout << "1. 修改地址" << endl;
            cout << "2. 修改手机号" << endl;
            cout << "3. 修改QQ" << endl;
            cout << "4. 修改邮箱" << endl;
            cout << "0. 返回" << endl;
            cout << "=====================================" << endl;
            cout << "请选择要修改的信息：";
            int choice;
            cin >> choice;
            switch (choice) {
                case 1: {
                    cout << "请输入新的地址：";
                    string new_address;
                    cin >> new_address;
                    current->setAddress(new_address);
                    cout << "修改成功！" << endl;
                    break;
                }
                case 2: {
                    cout << "请输入新手机号：";
                    string new_phone;
                    cin >> new_phone;
                    current->setPhone(new_phone);
                    cout << "修改成功！" << endl;
                    break;
                }
                case 3: {
                    cout << "请输入新QQ号：";
                    string new_qq;
                    cin >> new_qq;
                    current->setQq(new_qq);
                    cout << "修改成功！" << endl;
                    break;
                }
                case 4: {
                    cout << "请输入新邮箱：";
                    string new_email;
                    cin >> new_email;
                    current->setEmail(new_email);
                    cout << "修改成功！" << endl;
                    break;
                }
                case 0: {
                    cout << "已取消修改！" << endl;
                    break;
                }
                default: {
                    system("cls");
                    cout << "输入错误！请重新输入！" << endl;
                    updateAlumni(name);
                    break;
                }
            }
            return;
        }
        current = current->next;
    }
    cout << "未找到此校友！" << endl;
}

// 删除指定姓名的校友
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
            return;
        }
        pre = current;
        current = current->next;
    }
    cout << "未找到此校友！" << endl;
}

// 显示所有校友信息
void AlumniList::display(const int &detailValue) {
    Alumni *current = head;
    while (current != nullptr) {
        current->display(detailValue);
        current = current->next;
    }
}

// 按用户名搜索校友（用于登录验证）
Alumni *AlumniList::searchByUserName(const std::string &user_name) {
    Alumni *current = head;
    while (current != nullptr) {
        if (current->getUserName() == user_name) {
            return current;
        }
        current = current->next;
    }
    return nullptr;
}

// 按姓名搜索并显示校友信息
void AlumniList::searchByName(const std::string &name) {
    Alumni *current = head;
    int count = 0;
    while (current != nullptr) {
        if (current->getName() == name) {
            cout << "找到校友：" << endl;
            current->display(1);
            count++;
        }
        current = current->next;
    }
    if (count > 0) {
        cout << "共找到" << count << "位校友！" << endl;
    } else {
        cout << "未查找到此校友！" << endl;
    }
}

// 按届级搜索并显示校友信息
void AlumniList::searchByGraduationYear(const int year) {
    Alumni *current = head;
    int count = 0;
    while (current != nullptr) {
        if (current->getGraduationYear() == year) {
            cout << "找到校友：" << endl;
            current->display(1);
            count++;
        }
        current = current->next;
    }
    if (count > 0) {
        cout << "共找到" << count << "位校友！" << endl;
    } else {
        cout << "未查找到此校友！" << endl;
    }
}

// 按专业搜索并显示校友信息
void AlumniList::searchByMajor(const std::string &major) {
    Alumni *current = head;
    int count = 0;
    while (current != nullptr) {
        if (current->getMajor() == major) {
            cout << "找到校友：" << endl;
            current->display(1);
            count++;
        }
        current = current->next;
    }
    if (count > 0) {
        cout << "共找到" << count << "位校友！" << endl;
    } else {
        cout << "未查找到此校友！" << endl;
    }
}

// 按班级搜索并显示校友信息
void AlumniList::searchByClassName(const std::string &class_name) {
    Alumni *current = head;
    int count = 0;
    while (current != nullptr) {
        if (current->getClassName() == class_name) {
            cout << "找到校友：" << endl;
            current->display(1);
            count++;
        }
        current = current->next;
    }
    if (count > 0) {
        cout << "共找到" << count << "位校友！" << endl;
    } else {
        cout << "未查找到此校友！" << endl;
    }
}

// 按届级升序排序
void AlumniList::ascendingSortGraduationYear() {
    for (int i = 0; i < size; i++) {
        Alumni *current = head, *pre = nullptr, *next = current->next;
        while (next != nullptr) {
            // 如果当前节点的届级大于下一个节点，交换位置
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
                // 向后移动指针
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

// 按届级降序排序
void AlumniList::descendingSortGraduationYear() {
    for (int i = 0; i < size; i++) {
        Alumni *current = head, *pre = nullptr, *next = current->next;
        while (next != nullptr) {
            // 如果当前节点的届级小于下一个节点，交换位置
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
                // 向后移动指针
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

// 按姓名升序排序（冒泡排序）
void AlumniList::ascendingSortName() {
    for (int i = 0; i < size; i++) {
        Alumni *current = head, *pre = nullptr, *next = current->next;
        while (next != nullptr) {
            // 如果当前节点的姓名大于下一个节点，交换位置
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
                // 向后移动指针
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

// 按姓名降序排序
void AlumniList::descendingSortName() {
    for (int i = 0; i < size; i++) {
        Alumni *current = head, *pre = nullptr, *next = current->next;
        while (next != nullptr) {
            // 如果当前节点的姓名小于下一个节点，交换位置
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
                // 向后移动指针
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

// 将校友数据保存到文件
void AlumniList::save() {
    ofstream outfile(file_name, ios::out);
    Alumni *current = head;
    while (current != nullptr) {
        outfile << current->getUserName() << " "
                << current->getPassword() << " "
                << current->isManager() << " "
                << current->getName() << " "
                << current->getGender() << " "
                << current->getAge() << " "
                << current->getGraduationYear() << " "
                << current->getMajor() << " "
                << current->getClassName() << " "
                << current->getAddress() << " "
                << current->getPhone() << " "
                << current->getQq() << " "
                << current->getEmail();
        current = current->next;
        if (current != nullptr) {
            outfile << endl;
        }
    }
    outfile.close();
}

// 用户登录验证
Alumni *AlumniList::login(const std::string &username, const std::string &password) {
    Alumni *user = searchByUserName(username);
    if (user != nullptr && user->getPassword() == password) {
        return user;
    }
    return nullptr;
}
