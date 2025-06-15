#ifndef MENU_H
#define MENU_H

#include "AlumniList.h"
#include <string>

// 菜单类，实现不同身份的用户界面交互
// 支持登录菜单、校友菜单、访客菜单和管理员菜单
// 每个菜单提供对应身份的功能选项，并实现菜单间的导航
class Menu {
public:
    // 构造函数：初始化校友列表和用户指针
    Menu(std::string file_name);

    // 显示登录菜单
    void displayLoginMenu();

    // 处理登录操作
    void handleLogin();

    // 处理校友登录
    void handleAlumniLogin();

    // 处理管理员登录
    void handleManagerLogin();

    // 显示校友功能菜单
    void displayAlumniMenu();

    // 处理校友菜单选择
    void handleAlumniMenu();

    // 显示访客功能菜单
    void displayVisitorMenu();

    // 处理访客菜单选择
    void handleVisitorMenu();

    // 显示管理员功能菜单
    void displayManagerMenu();

    // 处理管理员菜单选择
    void handleManagerMenu();

    // 返回上一级菜单
    void backToMenu(int identity);

    // 显示排序菜单
    void displaySortMenu();

    // 处理排序菜单选择
    void handleSortMenu();

    // 显示搜索菜单
    void displaySearchMenu();

    // 处理搜索菜单选择
    void handleSearchMenu(const int &identity);

    // 处理添加校友信息
    void handleAdd();

    // 处理删除校友信息
    void handleDelete();

    // 处理修改校友信息
    void handleUpdate();

protected:
    AlumniList alumni_list;  // 校友列表对象
    Alumni *user_ptr;        // 当前用户指针
    int identity;            // 用户身份标识
    // 菜单文本常量
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
