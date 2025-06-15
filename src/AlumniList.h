#ifndef ALUMNI_LIST_H
#define ALUMNI_LIST_H

#include "Alumni.h"

// 校友列表类，实现校友信息的增删改查和排序功能
// 使用单链表结构存储校友数据
class AlumniList {
public:
    // 构造函数：从文件加载校友数据
    AlumniList(const std::string &fileName);

    // 添加校友信息
    void addAlumni(Alumni *new_alumni);

    // 更新校友信息
    void updateAlumni(const std::string &name);

    // 删除校友信息
    void deleteAlumni(const std::string &name);

    // 显示所有校友信息
    void display(const int &detailValue);

    // 按用户名搜索校友（用于登录验证）
    Alumni *searchByUserName(const std::string &user_name);

    // 按姓名搜索校友
    void searchByName(const std::string &name);

    // 按届级搜索校友
    void searchByGraduationYear(int year);

    // 按专业搜索校友
    void searchByMajor(const std::string &major);

    // 按班级搜索校友
    void searchByClassName(const std::string &class_name);

    // 按届级升序排序
    void ascendingSortGraduationYear();

    // 按届级降序排序
    void descendingSortGraduationYear();

    // 按姓名升序排序
    void ascendingSortName();

    // 按姓名降序排序
    void descendingSortName();

    // 保存数据到文件
    void save();

    // 用户登录验证
    Alumni *login(const std::string &username, const std::string &password);

protected:
    int size;        // 校友总数
    Alumni *head;     // 链表头指针
    std::string file_name;  // 数据文件名
};

#endif
