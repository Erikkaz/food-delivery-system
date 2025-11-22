#include "restaurant.hpp"

// Инициализация статической переменной
unsigned int Restaurant::nextId = 1;

// Инициализируем поля в конструкторе
Restaurant::Restaurant()
	: id(nextId++),
	name(""),
	address(""),
	workingHours(""),
	contactDetails(""),
	rating(0)
{

}

// Деструктор
Restaurant::~Restaurant()
{

}

void Restaurant::addDishToMenu(const Dish& dish)
{
	dishes.push_back(dish);  // добавляем блюдо в вектор
}

const std::vector<Dish>& Restaurant::getDishes() const
{
	return dishes;
}

std::vector<Dish>& Restaurant::getDishes()
{
	return dishes;
}

unsigned int Restaurant::getId() const
{
	return id;
}

void Restaurant::setName(const std::string& name)
{
	this->name = name;
}

void Restaurant::setAddress(const std::string& address)
{
	this->address = address;
}

void Restaurant::setWorkingHours(const std::string& workingHours)
{
	this->workingHours = workingHours;
}

void Restaurant::setContactDetails(const std::string& contactDetails)
{
	this->contactDetails = contactDetails;
}

void Restaurant::setRating(double rating)
{
	this->rating = rating;
}

std::string Restaurant::getName() const
{
	return name;
}