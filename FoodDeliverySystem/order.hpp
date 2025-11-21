#pragma once
#include <ctime>
#include <string>

// Статусы заказа
enum class OrderStatus
{
    Cooking,      // Готовится
    Ready_for_pickup, // Готов к выдаче/курьеру 
    On_the_way,   // В пути
    Delivered,    // Доставлен
    Cancelled,    // Отменен
    Not_found     // Не найден
};

class Order
{
private:
    static unsigned int nextId; // для автоматической генерации id
	unsigned int id;  // id заказа
    double price;  // сумма заказа
    double courierProfit;  // Прибыль курьера
    std::time_t orderTime;  // Время создания заказа
    std::string clientName;  // Имя клиента, оформившего заказ
    OrderStatus status;   // Статус заказа

public:
    Order();   // Конструктор по умолчанию
    Order(int id, double price);  // Конструктор с Id и ценой
    ~Order();  // Деструктор

    void setStatus(OrderStatus newStatus);  // Установить статус заказа

    // === Геттеры === 
    unsigned int getId() const;
    double getPrice() const;
    OrderStatus getStatus() const;
    double getCourierProfit() const;
    std::time_t getOrderTime() const;
    std::string getClientName() const;
};