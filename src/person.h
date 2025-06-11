//
// Created by Awstme on 25-6-11.
//

#ifndef PERSON_H
#define PERSON_H

#include <string>

class person {
public:
    void setUserName(std::string new_name);
    void setPassword(std::string new_password);
    std::string getUserName();
    std::string modifyPassword();
protected:
    std::string user_name;
    std::string password;
};



#endif //PERSON_H
