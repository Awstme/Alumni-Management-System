#ifndef PERSON_H
#define PERSON_H

#include <string>

class Person {
public:
    // Person(int identity);
    Person(std::string user_name, std::string password);

    void setUserName(std::string new_name);

    void setPassword(std::string new_password);

    std::string getUserName();

    std::string getPassword();

    std::string modifyPassword();

protected:
    std::string user_name;
    std::string password;
    // int identity;
};


#endif //PERSON_H
