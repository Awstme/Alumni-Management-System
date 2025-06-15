#include "Menu.h"
#include <iostream>
#include <string>


using namespace std;

int main() {
    system("chcp 65001");
    system("cls");
    // system("cd");

    const string file_name = "alumni_data.txt";
    Menu menu(file_name);
    menu.displayLoginMenu();

    system("pause");
    return 0;
}
