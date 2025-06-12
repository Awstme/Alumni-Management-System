#include "Menu.h"
#include <iostream>

using namespace std;

void Menu::displayLoginMenu() {
    cout << "=====================================" << endl;
    cout << "        校友录管理系统 - 登录        " << endl;
    cout << "=====================================" << endl;
    cout << "1. 校友登录" << endl;
    cout << "2. 访客登录" << endl;
    cout << "3. 管理员登录" << endl;
    cout << "=====================================" << endl;
    cout << "请选择登录身份（输入数字 1-3）: ";
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
    cout << "请选择功能（输入数字 1-6）: ";
}

void Menu::handleAlumniMenu() {
    int choice;
    cin >> choice;

    switch (choice) {
        case 1:
            cout << "您选择了：" <<displayAlumniList<< endl;
            break;
        case 2:
            cout << "您选择了：" <<search << endl;
            break;
        case 3:
            cout << "您选择了：" <<profile << endl;
            break;
        case 4:
            cout << "您选择了：" <<modify_profile << endl;
            break;
        case 5:
            cout <<  "您选择了：" <<modify_password << endl;
            break;
        case 6:
            cout << logout<<"..." << endl;
            // 可以再次调用 displayLoginMenu 或其他操作
            break;
        default:
            cout << invalid_input << endl;
            displayAlumniMenu(); // 如果选择无效，重新显示菜单
            handleAlumniMenu(); // 递归调用以重新选择
            break;
    }
}
void Menu::displayVisitorMenu()
{
    cout << "=====================================" << endl;
    cout << "       校友录管理系统 - 访客功能菜单      " << endl;
    cout << "=====================================" << endl;
    cout << "1. " << displayAlumniList << endl;
    cout << "2. " << search << endl;
    cout << "3. " << logout << endl;
    cout << "=====================================" << endl;
    cout << "请选择功能（输入数字 1-3）: ";
}

void Menu::handleVisitorMenu(){}

void Menu::displayManagerMenu()
{
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
    cout << "请选择功能（输入数字 1-9）: ";
}

void Menu::handleManagerMenu(){}

#include "menu.h"
