#include "alumni.h"

Alumni::Alumni(string name, string gender, int age, int graduationYear, string department, string className, string address, string phone, string qq, string email) : name(name), gender(gender), age(age), graduationYear(graduationYear), department(department), className(className), address(address), phone(phone), qq(qq), email(email) {}

void Alumni::setName(string newName) { name = newName; }

void Alumni::setGender(string newGender) { gender = newGender; }

void Alumni::setAge(int newAge) { age = newAge; }

void Alumni::setGraduationYear(int newGraduationYear) { graduationYear = newGraduationYear; }

void Alumni::setDepartment(string newDepartment) { department = newDepartment; }

void Alumni::setClassName(string newClassName) { className = newClassName; }

void Alumni::setAddress(string newAddress) { address = newAddress;}

void Alumni::setPhone(string newPhone) { phone = newPhone; }

void Alumni::setQq(string newQq) { qq = newQq; }

void Alumni::setEmail(string newEmail) { email = newEmail; }

string Alumni::getName() { return name; }

string Alumni::getGender() { return gender; }

int Alumni::getAge() { return age; }

int Alumni::getGraduationYear() { return graduationYear; }

string Alumni::getDepartment() { return department; }

string Alumni::getClassName() { return className; }

string Alumni::getAddress() { return address; }

string Alumni::getPhone() { return phone; }

string Alumni::getQq() { return qq; }

string Alumni::getEmail() { return email; }