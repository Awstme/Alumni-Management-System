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
    cout << "4. 退出系统" << endl;
    cout << "=====================================" << endl;
    cout << select;
}

void Menu::handleLogin() {
    int choice;
    cin >> choice;

    switch (choice) {
        case 1:
            cout << "您选择了：校友登录" << endl;
            displayAlumniMenu();
            handleAlumniMenu();
            break;
        case 2:
            cout << "您选择了：访客登录" << endl;
            displayVisitorMenu();
            handleVisitorMenu();
            break;
        case 3:
            cout << "您选择了：管理员登录" << endl;
            displayManagerMenu();
            handleManagerMenu();
            break;
        case 4:
            cout << "您选择了：退出系统" << endl;
            cout << "感谢使用校友录管理系统！" << endl;
            exit(0);
            break;
        default:
            cout << "无效的选择，请重新输入！" << endl;
            displayLoginMenu(); // 如果选择无效，重新显示菜单
            handleLogin(); // 递归调用以重新选择
            break;
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
    cout << "6. " << logout << endl;
    cout << "=====================================" << endl;
    cout << select;
}

void Menu::handleAlumniMenu() {
    int choice;
    cin >> choice;

    switch (choice) {
        case 1:
            cout << you_select << displayAlumniList << endl;
            displaySortMenu();
            handleSortMenu();
            break;
        case 2:
            cout << you_select << search << endl;
            break;
        case 3:
            cout << you_select << profile << endl;
            break;
        case 4:
            cout << you_select << modify_profile << endl;
            break;
        case 5:
            cout << you_select << modify_password << endl;
            break;
        case 6:
            cout << logout << "..." << endl;
            // 可以再次调用 displayLoginMenu 或其他操作
            break;
        default:
            cout << invalid_input << endl;
            displayAlumniMenu(); // 如果选择无效，重新显示菜单
            handleAlumniMenu(); // 递归调用以重新选择
            break;
    }
}

void Menu::displayVisitorMenu() {
    cout << "=====================================" << endl;
    cout << "       校友录管理系统 - 访客功能菜单      " << endl;
    cout << "=====================================" << endl;
    cout << "1. " << displayAlumniList << endl;
    cout << "2. " << search << endl;
    cout << "3. " << logout << endl;
    cout << "=====================================" << endl;
    cout << select;
}

void Menu::handleVisitorMenu() {
}

void Menu::displayManagerMenu() {
    cout << "=====================================" << endl;
    cout << "       校友录管理系统 - 管理员功能菜单      " << endl;
    cout << "=====================================" << endl;
    cout << "1. " << displayAlumniList << endl;
    cout << "2. " << search << endl;
    cout << "3. " << enter_alumni << endl;
    cout << "4. " << change_alumni << endl;
    cout << "5. " << delete_alumni << endl;
    cout << "6. " << profile << endl;
    cout << "7. " << modify_profile << endl;
    cout << "8. " << modify_password << endl;
    cout << "9. " << logout << endl;
    cout << "=====================================" << endl;
    cout << select;
}

void Menu::handleManagerMenu() {
}

void Menu::displaySortMenu() {
    cout << "=====================================" << endl;
    cout << "       校友录管理系统 - 排序功能菜单      " << endl;
    cout << "=====================================" << endl;
    cout << "1. " << ascending_sort_by_gratuation_year << endl;
    cout << "2. " << descending_sort_by_gratuation_year << endl;
    cout << "=====================================" << endl;
}

void Menu::handleSortMenu() {
    int choice;
    cin >> choice;
    switch (choice) {
        case 1:
            alumni_list.ascendingSortGraduationYear();
            alumni_list.display();
            break;
        case 2:
            alumni_list.descendingSortGraduationYear();
            alumni_list.display();
            break;
    }
}

#include "menu.h"
