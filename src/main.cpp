#include "menu.h"
#include "alumni_list.h"
#include "globals.h"
#include <iostream>
#include <string>


using namespace std;

int main() {
    system("chcp 65001");
    system("cd");
    const string file_name = "alumni_data.txt";
    AlumniList alumni_list(file_name);
    Menu menu;
    menu.displayLoginMenu();
    menu.handleLogin();
    if (is_sort) {
        switch (sort_value) {
            case 1:
                alumni_list.ascendingSortGraduationYear();
                alumni_list.display();
                break;
            case 2:
                alumni_list.descendingSortGraduationYear();
                alumni_list.display();
                break;
        }
    }

    // system("pause");
    return 0;
}
