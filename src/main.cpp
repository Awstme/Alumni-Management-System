#include "Menu.h"
#include <iostream>
#include <string>

using namespace std;

// 程序入口函数
int main() {
    // 设置控制台编码为UTF-8
    system("chcp 65001");
    // 清屏
    system("cls");

    // 初始化校友数据文件名
    const string file_name = "alumni_data.txt";
    // 创建菜单对象并显示登录菜单
    Menu menu(file_name);
    menu.displayLoginMenu();

    // 暂停并等待用户按键
    system("pause");
    return 0;
}
