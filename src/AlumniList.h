#ifndef ALUMNI_LIST_H
#define ALUMNI_LIST_H

#include "Alumni.h"

class AlumniList {
public:
    AlumniList(const std::string &fileName);

    void addAlumni(Alumni *new_alumni);
    // void deleteAlumni(std::string name);
    void display();

    void displayDetail();

    void searchByName(const std::string &name);

    void searchByGraduationYear(int year);

    void searchByMajor(const std::string &major);

    void searchByClassName(const std::string &class_name);

    void ascendingSortGraduationYear();

    void descendingSortGraduationYear();

    void ascendingSortName();

    void descendingSortName();

    // void save();
    // void load();
    // void clear();
    // void update(std::string name, Alumni newAlumni);
    // vector<Alumni> readAllAlumni();
    // void displayAllAlumni();
    // void displayAllAlumniByGender(string gender);
    // void displayAllAlumniByDepartment(string department);
protected:
    int size;
    Alumni *head;
};

#endif
