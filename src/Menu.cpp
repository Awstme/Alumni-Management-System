#include "Menu.h"
// #include "globals.h"
#include <iostream>

using namespace std;

Menu::Menu(string file_name): alumni_list(AlumniList(file_name)) {
}

void Menu::displayLoginMenu() {
    cout << "=====================================" << endl;
    cout << "        校友录管理系统 - 登录菜单        " << endl;
    cout << "=====================================" << endl;
    cout << "1. 校友登录" << endl;
    cout << "2. 访客登录" << endl;
    cout << "3. 管理员登录" << endl;
    cout << "0. 退出系统" << endl;
    cout << "=====================================" << endl;
    cout << select;
    handleLogin();
}

void Menu::handleLogin() {
    int choice;
    cin >> choice;

    switch (choice) {
        case 1: {
            cout << "您选择了：校友登录" << endl;
            displayAlumniMenu();
            break;
        }
        case 2: {
            cout << "您选择了：访客登录" << endl;
            displayVisitorMenu();
            break;
        }
        case 3: {
            cout << "您选择了：管理员登录" << endl;
            displayManagerMenu();
            break;
        }
        case 0: {
            alumni_list.save();
            cout << "您选择了：退出系统" << endl;
            cout << "感谢使用校友录管理系统！" << endl;
            // exit(0);
            break;
        }
        default: {
            cout << "无效的选择，请重新输入！" << endl;
            displayLoginMenu(); // 如果选择无效，重新显示菜单
            break;
        }
    }
}

void Menu::displayAlumniMenu() {
    cout << "=====================================" << endl;
    cout << "       校友录管理系统 - 校友功能菜单      " << endl;
    cout << "=====================================" << endl;
    cout << "1. " << displayAlumniList << endl;
    cout << "2. " << search << endl;
    cout << "3. " << profile << endl;
    cout << "4. " << modify_profile << endl;
    cout << "5. " << modify_password << endl;
    cout << "0. " << logout << endl;
    cout << "=====================================" << endl;
    cout << select;
    handleAlumniMenu();
}

void Menu::handleAlumniMenu() {
    int choice;
    cin >> choice;

    switch (choice) {
        case 1: {
            cout << you_select << displayAlumniList << endl;
            displaySortMenu();
            handleSortMenu(1);
            break;
        }
        case 2: {
            cout << you_select << search << endl;
            displaySearchMenu();
            handleSearchMenu(1);
            break;
        }
        case 3: {
            cout << you_select << profile << endl;
            break;
        }
        case 4: {
            cout << you_select << modify_profile << endl;
            break;
        }
        case 5: {
            cout << you_select << modify_password << endl;
            break;
        }
        case 0: {
            cout << logout << "..." << endl;
            displayLoginMenu();
            break;
        }
        default: {
            cout << invalid_input << endl;
            displayAlumniMenu(); // 如果选择无效，重新显示菜单
            break;
        }
    }
}

void Menu::displayVisitorMenu() {
    cout << "=====================================" << endl;
    cout << "       校友录管理系统 - 访客功能菜单      " << endl;
    cout << "=====================================" << endl;
    cout << "1. " << displayAlumniList << endl;
    cout << "2. " << search << endl;
    cout << "0. " << logout << endl;
    cout << "=====================================" << endl;
    cout << select;
    handleVisitorMenu();
}

void Menu::handleVisitorMenu() {
    int choice;
    cin >> choice;

    switch (choice) {
        case 1: {
            cout << you_select << displayAlumniList << endl;
            displaySortMenu();
            handleSortMenu(2);
            break;
        }
        case 2: {
            cout << you_select << search << endl;
            displaySearchMenu();
            handleSearchMenu(2);
            break;
        }
        case 0: {
            cout << logout << "..." << endl;
            displayLoginMenu();
            break;
        }
        default: {
            cout << invalid_input << endl;
            displayVisitorMenu(); // 如果选择无效，重新显示菜单
            break;
        }
    }
}

void Menu::displayManagerMenu() {
    cout << "=====================================" << endl;
    cout << "       校友录管理系统 - 管理员功能菜单      " << endl;
    cout << "=====================================" << endl;
    cout << "1. " << displayAlumniList << endl;
    cout << "2. " << search << endl;
    cout << "3. " << add_alumni << endl;
    cout << "4. " << change_alumni << endl;
    cout << "5. " << delete_alumni << endl;
    cout << "6. " << profile << endl;
    cout << "7. " << modify_profile << endl;
    cout << "8. " << modify_password << endl;
    cout << "0. " << logout << endl;
    cout << "=====================================" << endl;
    cout << select;
    handleManagerMenu();
}

void Menu::handleManagerMenu() {
    int choice;
    cin >> choice;

    switch (choice) {
        case 1: {
            cout << you_select << displayAlumniList << endl;
            displaySortMenu();
            handleSortMenu(3);
            break;
        }
        case 2: {
            cout << you_select << search << endl;
            displaySearchMenu();
            handleSearchMenu(3);
            break;
        }
        case 3: {
            cout << you_select << add_alumni << endl;
            handleAdd();
            break;
        }
        case 4: {
            cout << you_select << change_alumni << endl;
            handleUpdate();
            break;
        }
        case 5: {
            cout << you_select << delete_alumni << endl;
            handleDelete();
            break;
        }
        case 0: {
            cout << logout << "..." << endl;
            displayLoginMenu();
            break;
        }
        default: {
            cout << invalid_input << endl;
            displayManagerMenu(); // 如果选择无效，重新显示菜单
            break;
        }
    }
}

void Menu::displaySortMenu() {
    cout << "=====================================" << endl;
    cout << "       校友录管理系统 - 排序功能菜单      " << endl;
    cout << "=====================================" << endl;
    cout << "1. 按届级升序" << endl;
    cout << "2. 按届级降序" << endl;
    cout << "3. 按姓名升序" << endl;
    cout << "4. 按姓名降序" << endl;
    cout << "0. " << back << endl;
    cout << "=====================================" << endl;
    cout << select;
}

void Menu::handleSortMenu(const int &identity) {
    int choice;
    cin >> choice;
    switch (choice) {
        case 1: {
            alumni_list.ascendingSortGraduationYear();
            alumni_list.display();
            break;
        }
        case 2: {
            alumni_list.descendingSortGraduationYear();
            alumni_list.display();
            break;
        }
        case 3: {
            alumni_list.ascendingSortName();
            alumni_list.display();
            break;
        }
        case 4: {
            alumni_list.descendingSortName();
            alumni_list.display();
            break;
        }
        case 0: {
            cout << "返回上一级菜单..." << endl;
            switch (identity) {
                case 1:
                    displayAlumniMenu();
                    break;
                case 2:
                    displayManagerMenu();
                    break;
                case 3:
                    displayVisitorMenu();
                    break;
            }
            return;
            // break;
        }
    }
    cout << "按任意键返回上级菜单" << endl;
    cin.ignore();
    cin.get();
    switch (identity) {
        case 1:
            displayAlumniMenu();
            break;
        case 2:
            displayManagerMenu();
            break;
        case 3:
            displayVisitorMenu();
            break;
    }
}

void Menu::displaySearchMenu() {
    cout << "=====================================" << endl;
    cout << "       校友录管理系统 - 查找功能菜单      " << endl;
    cout << "=====================================" << endl;
    cout << "1, 按姓名查找" << endl;
    cout << "2, 按届级查找" << endl;
    cout << "3, 按专业查找" << endl;
    cout << "4, 按班级查找" << endl;
    cout << "0. " << back << endl;
    cout << "=====================================" << endl;
    cout << select;
}

void Menu::handleSearchMenu(const int &identity) {
    int choice;
    cin >> choice;
    switch (choice) {
        case 1: {
            cout << "请输入姓名：" << endl;
            string name;
            cin >> name;
            alumni_list.searchByName(name);
            break;
        }
        case 2: {
            cout << "请输入届级：" << endl;
            int year;
            cin >> year;
            alumni_list.searchByGraduationYear(year);
            break;
        }
        case 3: {
            cout << "请输入专业：" << endl;
            string major;
            cin >> major;
            alumni_list.searchByMajor(major);
            break;
        }
        case 4: {
            cout << "请输入班级：" << endl;
            string className;
            cin >> className;
            alumni_list.searchByClassName(className);
            break;
        }
        case 0: {
            cout << "返回上一级菜单..." << endl;
            // 返回上一级菜单函数
            switch (identity) {
                case 1:
                    displayAlumniMenu();
                    break;
                case 2:
                    displayManagerMenu();
                    break;
                case 3:
                    displayVisitorMenu();
                    break;
            }

            break;
        }
        default: {
            cout << invalid_input << endl;
            break;
        }
    }
}

void Menu::handleAdd() {
    cout << "请输入新校友姓名：";
    string name;
    cin >> name;
    cout << "请输入新校友性别：";
    string gender;
    cin >> gender;
    cout << "请输入新校友年龄：";
    int age;
    cin >> age;
    cout << "请输入新校友届级：";
    int graduationYear;
    cin >> graduationYear;
    cout << "请输入新校友班级：";
    string className;
    cin >> className;
    cout << "请输入新校友专业：";
    string major;
    cin >> major;
    cout << "请输入新校友地址：";
    string address;
    cin >> address;
    cout << "请输入新校友手机号：";
    string phone;
    cin >> phone;
    cout << "请输入新校友QQ：";
    string qq;
    cin >> qq;
    cout << "请输入新校友邮箱：";
    string email;
    cin >> email;
    Alumni *new_alumni = new Alumni(name, gender, age, graduationYear, className, major, address, phone, qq, email);
    alumni_list.addAlumni(new_alumni);
    displayManagerMenu(); // 返回上级菜单
}

void Menu::handleDelete() {
    cout << "请输入要删除的校友姓名：";
    string name;
    cin >> name;
    alumni_list.deleteAlumni(name);
    displayManagerMenu(); // 返回上级菜单
}

void Menu::handleUpdate() {
    cout << "请输入要修改的校友姓名：";
    string name;
    cin >> name;
    alumni_list.updateAlumni(name);
    displayManagerMenu(); // 返回上级菜单
}
