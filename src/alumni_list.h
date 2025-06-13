#ifndef ALUMNI_LIST_H
#define ALUMNI_LIST_H

#include "alumni.h"

class AlumniList {
public:
    AlumniList(const std::string &fileName);

    // void addAlumni(Alumni alumni);
    // void deleteAlumni(std::string name);
    void display();

    void displayDetail();

    // void search(std::string name);
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
    Alumni *head = NULL;
};

#endif
