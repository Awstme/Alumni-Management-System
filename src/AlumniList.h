#ifndef ALUMNI_LIST_H
#define ALUMNI_LIST_H

#include "Alumni.h"

class AlumniList {
public:
    AlumniList(const std::string &fileName);

    // void addAlumni(Alumni alumni);
    // void deleteAlumni(std::string name);
    void display();

    void displayDetail();

    void searchByName(std::string name);

    void searchByGraduationYear(int year);

    void searchByMajor(std::string major);

    void searchByClassName(std::string className);

    void ascendingSortGraduationYear();

    void descendingSortGraduationYear();

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
