#include "courier.hpp"
#include <iostream>

Courier::Courier()
	: User(),
	passport(""),
	contactInfo(""),
	snils(""),
	deliveredOrders(),
	currentOrder(nullptr),  // Курьер изначально свободен
	rating(0),
	approvedByAdmin(false)
{

}

Courier::~Courier()
{

}

void Courier::provideDocuments(const std::string& passport, const std::string& snils, const std::string& contactInfo)
{
	// Курьер передаёт свои документы 
	this->passport = passport;
	this->snils = snils;
	this->contactInfo = contactInfo;
	std::cout << "Документы успешно переданы администратору!" << std::endl;
}

void Courier::setApproved(bool state)
{
	// Администратор устанавливает, допущен ли курьер к работе.
	approvedByAdmin = state;
}

bool Courier::isApproved() const
{
	return approvedByAdmin;
}

void Courier::registerCourier(const std::string& login, const std::string& password) 
{
	// Проверка одобрен ли курьер
	if (!isApproved())
	{
		std::cout << "Ошибка: Курьер не одобрен администратором!" << std::endl;
		return;
	}

	std::cout << "=== РЕГИСТРАЦИЯ КУРЬЕРА ===" << std::endl;
	registerUser(login,password);
}


double Courier::getTotalEarnings() const
{
	// Вычисляем общую прибыль курьера
	double total = 0;
	for (const auto& order : deliveredOrders)
	{
		total += order.getCourierProfit();
	}

	return total;
}

void Courier::viewEarnings() const
{
	std::cout << "\n=== ДОХОДЫ КУРЬЕРА ===\n";

	if (deliveredOrders.empty())
	{
		std::cout << "Нет выполненных заказов. \n";
		return;
	}

	int index = 1;  // переменная для нумерации заказа

	for (const auto& order : deliveredOrders) {
		std::cout << "Заказ №" << index << " | Заработано: " << order.getCourierProfit() << " руб." << std::endl;
		index++;
	}

	std::cout << "---------------------------" << std::endl;
	std::cout << "ИТОГО: " << getTotalEarnings() << " руб. \n\n";
}

bool Courier::acceptOrder(Order* order)
{
	// Проверяем, пустой ли заказ
	if (order == nullptr)
	{
		std::cout << "Ошибка: заказ не найден.\n";
		return false;
	}

	// Проверяем, свободен ли курьер
	if (currentOrder != nullptr)
	{
		std::cout << "Невозможно принять заказ: курьер уже выполняет другой.\n";
		return false;
	}

	// Заказ должен быть готов к выдаче
	if (order->getStatus() != OrderStatus::Ready_for_pickup)
	{
		std::cout << "Заказ еще не готов или уже принят/доставлен.\n";
		return false;
	}

	// Курьер принимает заказ
	order->setStatus(OrderStatus::On_the_way);
	currentOrder = order;

	return true;
}

bool Courier::completeCurrentOrder()
{
	if (currentOrder == nullptr)
	{
		std::cout << "Нет активного заказа у курьера." << std::endl;
		return false;
	}

	// Проверяем статус
	if (currentOrder->getStatus() != OrderStatus::On_the_way)
	{
		std::cout << "Невозможно завершить заказ: он еще не в пути." << std::endl;
		return false;
	}

	// Помечаем заказ как доставленный
	currentOrder->setStatus(OrderStatus::Delivered);

	// Добавляем в список завершённых 
	deliveredOrders.push_back(*currentOrder);

	// Курьер становится свободен  (Обнуляем указатель)
	currentOrder = nullptr;

	std::cout << "Заказ успешно доставлен.\n";
	return true;
}