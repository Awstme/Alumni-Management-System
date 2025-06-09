#include "alumni.h"

class AlumniList
{
public:
    void addAlumni(Alumni alumni);
    void deleteAlumni(string name);
    void display();
    void search(string name);
    void sort();
    void save();
    void load();
    void clear();
    void update(string name, Alumni newAlumni);
    // vector<Alumni> readAllAlumni();
    // void displayAllAlumni();
    // void displayAllAlumniByGender(string gender);
    // void displayAllAlumniByDepartment(string department);
protected:
    int size;
    Alumni *head=NULL;
};