#include "alumni_list.h"
#include <iostream>

using namespace std;

int main()
{
    system("chcp 65001");
    AlumniList list("data/alumni_data.txt");
    list.display();
    system("pause");
    return 0;
}