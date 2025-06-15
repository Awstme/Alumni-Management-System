#ifndef PERSON_H
#define PERSON_H

#include <string>

class Person {
public:
    Person(std::string user_name, std::string password);

    // void setUserName(std::string new_name);

    void setPassword(const std::string &new_password);

    std::string getUserName();

    std::string getPassword();

    void modifyPassword();

protected:
    std::string user_name;
    std::string password;
};


#endif //PERSON_H
