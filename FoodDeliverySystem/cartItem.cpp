#include "cartitem.hpp" 

// Конструктор по умолчанию - пустая корзина
CartItem::CartItem()
    : dish(),
    quantity(0)
{

}

// Конструктор с параметрами - блюдо и начальное количество
CartItem::CartItem(const Dish& d, int q)
    : dish(d),
    quantity(q)
{

}

// Деструктор
CartItem::~CartItem()
{

}

// Расчет общей стоимости позиции
double CartItem::getTotalPrice() const
{
    return dish.getPrice() * quantity;
}

// Получение ссылки на блюдо в позиции
const Dish& CartItem::getDish() const
{
    return dish;
}

void CartItem::increaseQuantity()
{
    quantity++;
}

int CartItem::getQuantity() const
{
    return quantity;
}

void CartItem::decreaseQuantity()
{
    if (quantity > 0)
        quantity--;
}

// Установка нового количества
void CartItem::updateQuantity(int newQuantity)
{
    if (newQuantity < 0)
        quantity = 0;
    else
        quantity = newQuantity;
}