#pragma once
#include "dish.hpp"
#include "cartItem.hpp"
#include "restaurant.hpp"

class Cart
{
private:
	std::vector<CartItem> items;  // Список позиций в корзине
	Restaurant selectedRestaurant;   // Выбранный ресторан
	double subtotal;  // Общая стоимость корзины

	void updateSubtotal();   // Пересчет общей суммы

public:
	Cart();
	~Cart();

	void addDish(Dish* dish, int quantity);  // Добавить блюдо
	void removeDish(const std::string& dishName);  // Удалить блюдо по имени
	void displayCart() const;  // Показать содержимое корзины
	void clear();  // Очистить корзину
	bool isEmpty() const;   // Проверить пустоту корзины
};