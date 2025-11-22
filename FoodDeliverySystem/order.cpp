#include "order.hpp"

// Инициализация статической переменной
unsigned int Order::nextId = 1;

// Конструктор по умолчанию
Order::Order()
	: id(nextId++),
	price(0),
	courierProfit(0),
	clientName(""),
	status(OrderStatus::Not_found),
	orderTime(std::time(nullptr))
{

}

// Конструктор с заданным id и ценой
Order::Order(int id_, double price_) 
	: id(id_), 
	price(price_),
	courierProfit(price_ * 0.05), // 5% от стоимости заказа
	orderTime(std::time(nullptr)),
	clientName(""),
	status(OrderStatus::Cooking)
{
	
}

// Деструктор
Order::~Order()
{

}

// Получить Id заказа
unsigned int Order::getId() const
{
	return id;
}

// Получить сумму заказа
double Order::getPrice() const
{
	return price;
}

// Получить прибыль курьера
double Order::getCourierProfit() const
{
	return courierProfit;
}

// Получить текущий статус заказа
OrderStatus Order::getStatus() const
{
	return status;
}

// Установить новый статус заказа
void Order::setStatus(OrderStatus newStatus)
{
	status = newStatus;
}

// Получить время создания заказа
std::time_t Order::getOrderTime() const
{
	return orderTime;
}

// Получить имя клиента, оформившего заказ
std::string Order::getClientName() const
{
	return clientName;
}