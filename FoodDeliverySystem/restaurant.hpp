#pragma once
#include <string>
#include <vector>
#include "dish.hpp"
#include "reviewable.hpp"

class  Restaurant : public Reviewable
{
private:
	static unsigned int nextId;  // Статическая переменная для автоинкремента
	unsigned int id;      // id ресторана
	std::string name;     // Название ресторана
	std::string address;  // Адрес ресторана

	std::string workingHours;    // Часы работы 
	std::string contactDetails;  // Контактные данные 
	std::vector<Dish> dishes;    //  Меню ресторана - список блюд
	double rating;  // Рейтинг ресторана

public:
	Restaurant();   // Конструктор
	~Restaurant();  // Деструктор
	 
	void addDishToMenu(const Dish& dish);  // Добавить блюдо в меню ресторана
	const std::vector<Dish>& getDishes() const;  // Получить константную ссылку на меню 
	std::vector<Dish>& getDishes(); // получить изменяемую ссылку на меню
	std::string getName() const;    // Получить название ресторана
	unsigned int getId() const;     // Получить id ресторана

	void setName(const std::string& name);   // Установить название ресторана
	void setAddress(const std::string& address);   // Установить адрес
	void setWorkingHours(const std::string& workingHours);  // Установить часы работы
	void setContactDetails(const std::string& contactDetails);  // Установить контактные данные
	void setRating(double rating);  // Установить рейтинг

};