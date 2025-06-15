#ifndef ALUMNI_LIST_H
#define ALUMNI_LIST_H

#include "Alumni.h"

class AlumniList {
public:
    AlumniList(const std::string &fileName);

    void addAlumni(Alumni *new_alumni);

    void updateAlumni(const std::string &name);

    void deleteAlumni(const std::string &name);

    void display(const int &detailValue);

    Alumni *searchByUserName(const std::string &user_name);

    void searchByName(const std::string &name);
    void searchByGraduationYear(int year);

    void searchByMajor(const std::string &major);

    void searchByClassName(const std::string &class_name);

    void ascendingSortGraduationYear();

    void descendingSortGraduationYear();

    void ascendingSortName();

    void descendingSortName();

    void save();

    Alumni *login(const std::string &username, const std::string &password);
protected:
    int size;
    Alumni *head;
    std::string file_name;
};

#endif
