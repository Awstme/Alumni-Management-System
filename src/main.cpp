#include "menu.h"
#include "alumni_list.h"
#include <iostream>


using namespace std;

int main()
{
    system("chcp 65001");
    system("cd");
    Menu menu;
    menu.displayLoginMenu();
    menu.handleLogin();
    AlumniList list("alumni_data.txt");
    list.display();
    // system("pause");
    return 0;
}