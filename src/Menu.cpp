#include "Menu.h"
#include <iostream>

using namespace std;

// 构造函数：初始化校友列表和用户指针
Menu::Menu(string file_name): alumni_list(AlumniList(file_name)), user_ptr(nullptr) {
}

// 显示登录菜单
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
    identity = 0;
    handleLogin();
}

// 处理登录菜单选择
void Menu::handleLogin() {
    int choice;
    cin >> choice;

    switch (choice) {
        case 1: {
            system("cls");
            cout << "您选择了：校友登录" << endl;
            handleAlumniLogin();
            break;
        }
        case 2: {
            system("cls");
            cout << "您选择了：访客登录" << endl;
            displayVisitorMenu();
            break;
        }
        case 3: {
            system("cls");
            cout << "您选择了：管理员登录" << endl;
            handleManagerLogin();
            break;
        }
        case 0: {
            alumni_list.save();
            system("cls");
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

// 处理校友登录
void Menu::handleAlumniLogin() {
    cout << "请输入用户名：" << endl;
    string user_name;
    cin >> user_name;
    cout << "请输入密码：" << endl;
    string password;
    cin >> password;
    user_ptr = alumni_list.login(user_name, password);
    if (user_ptr) {
        system("cls");
        cout << "登录成功！" << endl;
        displayAlumniMenu();
    } else {
        system("cls");
        cout << "登录失败：用户名或密码错误" << endl;
        displayLoginMenu();
    }
}

// 处理管理员登录
void Menu::handleManagerLogin() {
    cout << "请输入用户名：" << endl;
    string user_name;
    cin >> user_name;
    cout << "请输入密码：" << endl;
    string password;
    cin >> password;
    user_ptr = alumni_list.login(user_name, password);
    if (user_ptr) {
        if (user_ptr->isManager()) {
            system("cls");
            cout << "登录成功！" << endl;
            displayManagerMenu();
            return;
        }
        system("cls");
        cout << "您未拥有管理员权限！" << endl;
    } else {
        system("cls");
        cout << "登录失败：用户名或密码错误" << endl;
    }
    displayLoginMenu();
}

// 显示校友功能菜单
void Menu::displayAlumniMenu() {
    system("cls");
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
    identity = 1;  // 设置身份标识为校友
    handleAlumniMenu();
}

// 处理校友菜单选择
void Menu::handleAlumniMenu() {
    int choice;
    cin >> choice;

    switch (choice) {
        case 1: {
            cout << you_select << displayAlumniList << endl;
            displaySortMenu();
            handleSortMenu();
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
            user_ptr->display(3);
            cout << press_any_key_to_back << endl;
            cin.ignore();
            cin.get();
            backToMenu(identity);
            break;
        }
        case 4: {
            cout << you_select << modify_profile << endl;
            alumni_list.updateAlumni(user_ptr->getName());
            backToMenu(identity);
            break;
        }
        case 5: {
            cout << you_select << modify_password << endl;
            user_ptr->modifyPassword();
            backToMenu(identity);
            break;
        }
        case 0: {
            system("cls");
            cout << logout << "..." << endl;
            displayLoginMenu();
            break;
        }
        default: {
            cout << invalid_input << endl;
            displayAlumniMenu();
            break;
        }
    }
}

// 显示访客功能菜单
void Menu::displayVisitorMenu() {
    system("cls");
    cout << "=====================================" << endl;
    cout << "       校友录管理系统 - 访客功能菜单      " << endl;
    cout << "=====================================" << endl;
    cout << "1. " << displayAlumniList << endl;
    cout << "2. " << search << endl;
    cout << "0. " << logout << endl;
    cout << "=====================================" << endl;
    cout << select;
    identity = 2;  // 设置身份标识为访客
    handleVisitorMenu();
}

// 处理访客菜单选择
void Menu::handleVisitorMenu() {
    int choice;
    cin >> choice;

    switch (choice) {
        case 1: {
            cout << you_select << displayAlumniList << endl;
            displaySortMenu();
            handleSortMenu();
            break;
        }
        case 2: {
            cout << you_select << search << endl;
            displaySearchMenu();
            handleSearchMenu(2);
            break;
        }
        case 0: {
            system("cls");
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

// 显示管理员功能菜单
void Menu::displayManagerMenu() {
    system("cls");
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
    identity = 3;  // 设置身份标识为管理员
    handleManagerMenu();
}

// 处理管理员菜单选择
void Menu::handleManagerMenu() {
    int choice;
    cin >> choice;

    switch (choice) {
        case 1: {
            cout << you_select << displayAlumniList << endl;
            displaySortMenu();
            handleSortMenu();
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
        case 6: {
            cout << you_select << profile << endl;
            user_ptr->display(3);
            cout << press_any_key_to_back << endl;
            cin.ignore();
            cin.get();
            backToMenu(identity);
            break;
        }
        case 7: {
            cout << you_select << modify_profile << endl;
            alumni_list.updateAlumni(user_ptr->getName());
            backToMenu(identity);
            break;
        }
        case 8: {
            cout << you_select << modify_password << endl;
            user_ptr->modifyPassword();
            backToMenu(identity);
            break;
        }
        case 0: {
            system("cls");
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

// 返回上一级菜单
void Menu::backToMenu(int identity) {
    switch (identity) {
        case 1: {
            displayAlumniMenu();
            break;
        }
        case 2: {
            displayVisitorMenu();
            break;
        }
        case 3: {
            displayManagerMenu();
            break;
        }
    }
}

// 显示排序菜单
void Menu::displaySortMenu() {
    system("cls");
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

// 处理排序菜单选择
void Menu::handleSortMenu() {
    int choice;
    cin >> choice;
    switch (choice) {
        case 1: {
            alumni_list.ascendingSortGraduationYear();
            if (identity == 1 || identity == 3) { alumni_list.display(2); } else { alumni_list.display(1); }
            break;
        }
        case 2: {
            alumni_list.descendingSortGraduationYear();
            if (identity == 1 || identity == 3) { alumni_list.display(2); } else { alumni_list.display(1); }
            break;
        }
        case 3: {
            alumni_list.ascendingSortName();
            if (identity == 1 || identity == 3) { alumni_list.display(2); } else { alumni_list.display(1); }
            break;
        }
        case 4: {
            alumni_list.descendingSortName();
            if (identity == 1 || identity == 3) { alumni_list.display(2); } else { alumni_list.display(1); }
            break;
        }
        case 0: {
            cout << "返回上一级菜单..." << endl;
            backToMenu(identity);
            return;
        }
    }
    cout << press_any_key_to_back << endl;
    cin.ignore();
    cin.get();
    backToMenu(identity);
}

// 显示搜索菜单
void Menu::displaySearchMenu() {
    system("cls");
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

// 处理搜索菜单选择
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
            backToMenu(identity);
            break;
        }
        default: {
            cout << invalid_input << endl;
            break;
        }
    }
}

// 录入新校友信息
void Menu::handleAdd() {
    system("cls");
    cout << "请输入新校友用户名：";
    string user_name;
    cin >> user_name;
    cout << "请输入新校友密码：";
    string password;
    cin >> password;
    cout << "是否授予管理员权限（请输入1授予或0不授予）：";
    int is_manager;
    cin >> is_manager;
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
    Alumni *new_alumni = new Alumni(user_name, password,
                                    name, gender, age, graduationYear,
                                    major, className,
                                    address, phone, qq, email,
                                    is_manager);
    alumni_list.addAlumni(new_alumni);
    backToMenu(identity);
}

// 删除校友信息
void Menu::handleDelete() {
    system("cls");
    cout << "请输入要删除的校友姓名：";
    string name;
    cin >> name;
    alumni_list.deleteAlumni(name);
    cout << "删除成功！" << endl;
    cout << press_any_key_to_back;
    cin.ignore();
    cin.get();
    backToMenu(identity);
}

// 修改校友信息
void Menu::handleUpdate() {
    cout << "请输入要修改的校友姓名：";
    string name;
    cin >> name;
    alumni_list.updateAlumni(name);
    cout << press_any_key_to_back;
    cin.ignore();
    cin.get();
    backToMenu(identity);
}
