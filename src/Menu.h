#ifndef MENU_H
#define MENU_H

#include "AlumniList.h"
#include <string>


class Menu {
public:
    Menu(std::string file_name);

    // 显示登录菜单
    void displayLoginMenu();

    // 处理登录选项
    void handleLogin();

    void handleAlumniLogin();

    void handleManagerLogin();

    // 显示功能菜单
    void displayAlumniMenu();

    // 处理功能选项
    void handleAlumniMenu();

    void displayVisitorMenu();

    void handleVisitorMenu();

    void displayManagerMenu();

    void handleManagerMenu();

    void backToMenu(int identity);

    void displaySortMenu();

    void handleSortMenu();

    void displaySearchMenu();

    void handleSearchMenu(const int &identity);

    void handleAdd();

    void handleDelete();

    void handleUpdate();

protected:
    AlumniList alumni_list;
    Alumni *user_ptr;
    int identity;
    const std::string select = "输入数字序号选择功能:";
    const std::string you_select = "你选择了:";
    const std::string displayAlumniList = "显示校友列表";
    const std::string search = "搜索校友";
    const std::string profile = "查看个人资料";
    const std::string modify_profile = "修改个人资料";
    const std::string add_alumni = "录入校友信息";
    const std::string delete_alumni = "删除校友信息";
    const std::string change_alumni = "修改校友信息";
    const std::string modify_password = "修改密码";
    const std::string logout = "注销登录";
    const std::string back = "返回上一级";
    const std::string invalid_input = "无效的输入！";
    const std::string press_any_key_to_back="按任意键返回上一级菜单";
};


#endif //MENU_H
