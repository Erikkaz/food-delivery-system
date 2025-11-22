#pragma once
#include "user.hpp"
#include "cart.hpp"
#include "order.hpp"
#include "review.hpp"
#include "dish.hpp"
#include <vector>
#include "reviewable.hpp"

enum class PaymentMethod
{
    Cash,  // Наличные
    Card,  // Карта
    Transfer,  // Перевод
    QR
};


class Client : public User
{
private:
    double bonusBalance;
	std::string deliveryAddress;
	Cart cart;
	std::vector<Order*> orderHistory;
	std::vector<Review*> reviews;

public:
	// Конструктор
	Client();
    
    //Деструктор
    ~Client();

    // Методы для освобождения динамической памяти
    void clearOrderHistory();  
    void clearReviews();

	// Переопределенный виртуальный метод
	std::string getUserType() const override;

    // Основные методы клиента
    void registerClient(const std::string& login, const std::string& password);
    void addToCart(Dish* dish, int quantity);
    std::vector<Order*> viewOrderHistory() const;
    Order* placeOrder();
    bool payOrder(Order* order, PaymentMethod method);

    OrderStatus trackOrderStatus(int orderId) const;
    void addReview(Reviewable* target, Review* review);
    void addBonus(double amount);
    void showCart() const;
    void clearCart();

    // Геттер
    double getBonusBalance() const;

    // Сеттер
    void setDeliveryAddress(const std::string& address);
  

protected:
    void displayInfo() const override;
};