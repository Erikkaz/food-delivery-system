#pragma once
#include "courier.hpp"
#include <vector>
#include "restaurant.hpp"
#include "client.hpp"

// Типы отчётов для администратора
enum class ReportType
{
	Restaurants,
	Couriers,
	Clients,
	Orders,
	Earnings
};

class Administrator : public User
{
private:
	std::vector<Restaurant*> restaurants;  // Список ресторанов
	std::vector<Courier*> couriers;  // Список курьеров
	std::vector<Client*> clients;  //  Список клиентов
	std::vector<Order*> orders;  //  Список заказов

public:
	Administrator();
	~Administrator();

	// Регистрация админа
	void registerAdmin(const std::string& login, const std::string& password);

	// Управление ресторанами
	void addRestaurant(Restaurant& restaurant);
	void removeRestaurant(Restaurant& restaurant);
	void editRestaurant(Restaurant& restaurant);
	void manageRestaurantMenu(Restaurant& restaurant,int choice);

	// Управление меню ресторана
	bool addDish(Restaurant& restaurant);      // Добавить блюдо
	bool removeDish(Restaurant& restaurant);   // Удалить блюдо
	void displayMenu(Restaurant& restaurant);  // Показать меню
	bool deleteDishById(Restaurant& restaurant, int dishId);  // Удалить блюдо по ID
	bool editDish(Restaurant& restaurant);  // Редактировать блюдо

	// Управление курьерами
	void addCourier(Courier& courier);   
	void removeCourier(Courier& courier);  

	// Генерация отчётов
	void generateReport(ReportType type, time_t start, time_t end);

};