#include "dish.hpp"

// Инициализация статической переменной
unsigned int Dish::nextId = 1;

// Конструктор по умолчанию
Dish::Dish()
    : id(nextId++),    // Автоматически присваиваем следующий ID
    name(""), 
    price(0)
{

}

// Деструктор
Dish::~Dish()
{
}

// Установка названия блюда
void Dish::setName(const std::string& name)
{
    this->name = name;
}

// Установка цены 
void Dish::setPrice(double price)
{
    if (price < 0)
        this->price = 0;
    else
        this->price = price;
}

// Получение цены блюда
double Dish::getPrice() const
{
    return price;
}

// Получение Id блюда
unsigned int Dish::getID() const
{
    return id;
}

// Получение названия блюда
const std::string& Dish::getName() const
{
    return name;
}