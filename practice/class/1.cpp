#include <iostream>

class Animal
{
private:
    int food;
    int weight;

public:
    Animal(int _food, int _weight)
    {
        food = _food;
        weight = _weight;
    }

    void increase_food(int inc);

    void view_stat()
    {
        std::cout << "이 동물의 food    : " << food << std::endl;
        std::cout << "이 동물의 weight  : " << weight << std::endl;
    }
};

void Animal::increase_food(int inc)
{
    food += inc;
    weight += (inc / 3);
}

int main()
{
    Animal animal(100, 50);
    animal.increase_food(30);

    animal.view_stat();
    return 0;
}