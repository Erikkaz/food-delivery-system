#include <iostream>
#include "client.hpp"

Client::Client()
	: User(),
	bonusBalance(0),
	deliveryAddress("")
{

}

// Освобождаем динамически выделенную память  
Client::~Client()
{
	clearOrderHistory();  // освобождаем заказы
	clearReviews();       // освобождаем отзывы
}

// Регистрация клиента
void Client::registerClient(const std::string& login, const std::string& password)
{
	std::cout << "=== РЕГИСТРАЦИЯ КЛИЕНТА ===" << std::endl;
	registerUser(login, password);

	std::cout << "Начислено 50 бонусов за регистрацию!" << std::endl;
	addBonus(50);

	std::cout << "Клиент успешно зарегистрирован!" << std::endl;
}

// Добавить блюдо в корзину
void Client::addToCart(Dish* dish, int quantity)
{
	if (dish!=nullptr && quantity > 0)
	{
		cart.addDish(dish, quantity);
		std::cout << "Добавлено в корзину!" << std::endl;
	}

	else if (!dish)
	{
		std::cout << "Ошибка: Блюдо не найдено!" << std::endl;
	}

	else if (quantity < 0)
	{
		std::cout << "Ошибка: неверное количество!" << std::endl;
	}
}

// Просмотр истории заказов
std::vector<Order*> Client::viewOrderHistory() const {
	return orderHistory;
}

// Оплата заказа 
bool Client::payOrder(Order* order, PaymentMethod method)
{
	if (!order)
	{
		std::cout << "Ошибка: блюдо не найдено" << std::endl;
		return false;
	}

	bool paymentSuccess = false;  // флаг для проверки успешности оплаты

	switch (method)
	{
	case PaymentMethod::Cash:
		paymentSuccess = true;
		std::cout << "Оплата наличными" << std::endl;
		break;
	
	case PaymentMethod::Card:
		paymentSuccess = true;
		std::cout << "Оплата картой" << std::endl;
		break;

	case PaymentMethod::Transfer:
		paymentSuccess = true;
		std::cout << "Оплата переводом" << std::endl;
		break;

	case PaymentMethod::QR:
		paymentSuccess = true;
		std::cout << "Оплата QR-кодом" << std::endl;
		break;

	default:
		std::cout << "Ошибка: оплата не прошла!" << std::endl;
		return false;
	}

	double total = order->getPrice();  // Общая сумма заказа
	double orderBonus = total * 0.05;  // бонусы за заказ 5%

	if (paymentSuccess)
	{
		order->setStatus(OrderStatus::Cooking);
		addBonus(orderBonus);  
		return true;
	}

}

// Метод для начисления бонуса 
void Client::addBonus(double amount)
{
	if (amount > 0)
	{
		bonusBalance += amount;
	}
	
}

// Информация о клиенте 
void Client::displayInfo() const
{
	std::cout << "=== ИНФОРМАЦИЯ О КЛИЕНТЕ ===" << std::endl;
	std::cout << "Логин : " << getLogin() << std::endl;
	std::cout << "Email : " << getEmail() << std::endl;
	std::cout << "Телефон : " << getPhone() << std::endl;
	std::cout << "Бонусный баланс : " << bonusBalance << std::endl;
	std::cout << "Количество заказов : " << orderHistory.size() << std::endl;
	std::cout << "Статус : " << (getIsActive() ? "Активен" : "Неактивен") << std::endl;
}

// Получить тип пользователя
std::string Client::getUserType() const {
	return "Client";
}

double Client::getBonusBalance() const
{
	return bonusBalance;
}

// Сеттер
void Client::setDeliveryAddress(const std::string& address)
{
	if (!address.empty())
	{
		deliveryAddress = address;
	}

	else
	{
		std::cout << "Ошибка: не удалось установить адрес доставки!" << std::endl;
	}
}

// метод для отображения корзины
void Client::showCart() const
{
	cart.displayCart();
}

// метод для очистки корзины
void Client::clearCart() 
{
	cart.clear();
}


// Оформление заказа из корзины 
Order* Client::placeOrder()
{
	if (cart.isEmpty())
	{
		std::cout << "Ошибка: корзина пуста!" << std::endl;
		return nullptr;
	}

	if (deliveryAddress.empty())
	{
		std::cout << "Ошибка: адрес не указан!" << std::endl;
		return nullptr;
	}

	Order* order = new Order();
	orderHistory.push_back(order);
	clearCart();

	std::cout << "Заказ успешно оформлен!" << std::endl;
	return order;
}

// Оставить отзыв
void Client::addReview(Reviewable* target, Review* review)
{
	if (target && review)
	{
		target->addReview(review);
		reviews.push_back(review);
		std::cout << "Отзыв успешно добавлен!" << std::endl;
	}
}

// метод для отслеживания статуса заказа
OrderStatus Client::trackOrderStatus(int orderId) const
{
	auto it = std::find_if(orderHistory.begin(), orderHistory.end(), [orderId](Order* order)
		{
			return order->getId() == orderId;
		});

	if (it != orderHistory.end()) {
		return (*it)->getStatus();
	}

	else
		return OrderStatus::Not_found;
}


// Очистка истории заказов
void Client::clearOrderHistory()
{
	for (Order* order : orderHistory) {
		delete order;
	}

	orderHistory.clear();
}

// Очистка отзывов
void Client::clearReviews() 
{
	for (Review* review : reviews) {
		delete review;
	}

	reviews.clear();
}