#include "cart.hpp"
#include <iostream>

// Конструктор
Cart::Cart() : subtotal(0)
{

}

// Деструктор
Cart::~Cart()
{

}

// Пересчитываем сумму корзины
void Cart::updateSubtotal()
{
    subtotal = 0;
    for (const auto& item : items)
        subtotal += item.getTotalPrice();  // Суммируем стоимость всех позиций
}

// Добавление блюда в корзину
void Cart::addDish(Dish* dish, int quantity)
{
    // Проверка валидности параметров
    if (!dish || quantity <= 0)
        return;

    // Поиск блюда в корзине
    for (auto& item : items)
    {
        if (item.getDish().getName() == dish->getName())
        {
            item.updateQuantity(item.getQuantity() + quantity);
            updateSubtotal(); // Пересчитываем сумму
            return;
        }
    }

    // Если блюда нет в корзине - добавляем новую позицию
    items.emplace_back(*dish, quantity);

    updateSubtotal();
}

// Удаление блюда из корзины по имени
void Cart::removeDish(const std::string& dishName)
{
    for (auto it = items.begin(); it != items.end(); ++it)
    {
        if (it->getDish().getName() == dishName)
        {
            items.erase(it);   // Удаляем позицию
            updateSubtotal();  // Пересчитываем сумму
            return;
        }
    }

    std::cout << "Блюдо '" << dishName << "' не найдено в корзине!\n";
}

// Очистка корзины
void Cart::clear()
{
    items.clear(); 
    subtotal = 0;
}
 
// Проверка пустоты
bool Cart::isEmpty() const
{
    return items.empty();
}

// Отображение содержимого корзины
void Cart::displayCart() const
{
    if (items.empty())
    {
        std::cout << "Корзина пуста." << std::endl;
        return;
    }

    std::cout << "===== КОРЗИНА =====" << std::endl;

    // Вывод каждой позиции с деталями
    for (const auto& item : items)
    {
        std::cout << item.getDish().getName()
            << " x" << item.getQuantity()
            << "  Цена: " << item.getDish().getPrice()
            << "  Сумма: " << item.getTotalPrice()
            << std::endl;
    }

    std::cout << "---------------------" << std::endl;
    std::cout << "Итого: " << subtotal <<  std::endl;
    std::cout << "=====================" << std::endl;
}