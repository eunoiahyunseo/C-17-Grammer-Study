#include <fstream>
#include <iostream>
#include <string.h>

class Human
{
    std::string name;
    int age;

public:
    Human(const std::string &name, int age)
        : name(name), age(age) {}
};