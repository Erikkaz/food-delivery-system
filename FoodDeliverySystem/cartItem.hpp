#pragma once
#include "dish.hpp"

class CartItem
{
private:
	Dish dish;  // Блюдо в корзине
	int quantity;  // Количество данного блюда

public:
	CartItem();
	~CartItem();
	CartItem(const Dish& d, int q);  // Конструктор с параметрами

	double getTotalPrice() const;  // Общая стоимость позиции
	const Dish& getDish() const;  // Получить блюдо
	int getQuantity() const;  // Получить количество

	void increaseQuantity();  // Увеличить количество на 1
	void decreaseQuantity();  // Уменьшить количество на 1
	void updateQuantity(int newQuantity);  // Установить новое количество
};