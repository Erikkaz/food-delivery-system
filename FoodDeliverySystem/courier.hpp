#pragma once
#include <string>
#include <vector>
#include "user.hpp"
#include "order.hpp"
#include "review.hpp"

class Courier : public User
{
private:
	// Данные курьера, которые необходимо предоставить администратору
	std::string passport;
	std::string contactInfo;
	std::string snils;

	std::vector<Order> deliveredOrders;  // Список выполненных заказов
	Order* currentOrder;  // Текущий заказ

	float rating;  // Рейтинг курьера
	bool approvedByAdmin;  // Одобрен ли администратором

public:
	Courier();
	~Courier();
	
	// Передача документов администратору
	void provideDocuments(const std::string& passport, const std::string& snils, const std::string& contact);

	void setApproved(bool state);    // Установка флага "одобрен"
	bool isApproved() const;   // Решение администратора
	bool completeCurrentOrder();  // Завершение текущего заказа

	void registerCourier(const std::string& login, const std::string& password);  // Регистрация
	double getTotalEarnings() const;   // Общая прибыль
	std::string getPassport() const;
	std::string getSnils() const;

	bool acceptOrder(Order* order);   // Принять заказ
	//Order* viewAvailableOrders();
	//Review* viewReviews(); 
	void viewEarnings() const;    // Посмотреть заработок
};