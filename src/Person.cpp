#include "Person.h"

using namespace std;

// Person::Person(int identity) : identity(identity) {
// }

Person::Person(string user_name, string password): user_name(user_name), password(password) { ; }
string Person::getUserName() { return user_name; }
string Person::getPassword() { return password; }
