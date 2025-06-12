#ifndef MENU_H
#define MENU_H
#include <string>


class Menu {
public:
    // 显示登录菜单
    void displayLoginMenu();

    // 处理登录选项
    void handleLogin();

    // 显示功能菜单
    void displayAlumniMenu();

    // 处理功能选项
    void handleAlumniMenu();

    void displayVisitorMenu();

    void handleVisitorMenu();

    void displayManagerMenu();

    void handleManagerMenu();
protected:
    const std::string displayAlumniList="显示校友列表";
    const std::string search="搜索校友";
    const std::string profile="查看个人资料";
    const std::string modify_profile="修改个人资料";
    const std::string enter_alumni="录入校友信息";
    const std::string delete_alumni="删除校友信息";
    const std::string change_alumni="修改校友信息";
    const std::string modify_password="修改密码";
    const std::string logout="注销登录";
    const std::string invalid_input="无效的输入！";
};


#endif //MENU_H
