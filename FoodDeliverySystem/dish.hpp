#pragma once
#include <string>

class Dish
{
private:
	static unsigned int nextId;  // Для автоинкремента id
	unsigned int id; 
	std::string name;  // Название блюда
	double price;  // Цена блюда

public:
	Dish();
	~Dish();

	// Сеттеры
	void setName(const std::string& name);
	void setPrice(double price);

	// Геттеры
	double getPrice() const;
	unsigned int getID() const;
	const std::string& getName() const;
};