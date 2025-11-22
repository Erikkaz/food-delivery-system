#include <iostream>
#include <vector>
#include <memory>
#include <Windows.h>
#include "client.hpp"
#include "courier.hpp"
#include "dish.hpp"
#include "restaurant.hpp"
#include "review.hpp"
#include "order.hpp"
#include "cart.hpp"

using std::cout;
using std::endl;

void demonstrateStaticInitialization() {
    cout << "=== ДЕМОНСТРАЦИЯ СТАТИЧЕСКОЙ ИНИЦИАЛИЗАЦИИ ===" << endl;

    // Статическая инициализация объектов
    Dish dish1;
    dish1.setName("Пицца Маргарита");
    dish1.setPrice(450.0);

    Dish dish2;
    dish2.setName("Паста Карбонара");
    dish2.setPrice(380.0);

    Cart cart1;  // Статический объект корзины

    cout << "Статические объекты созданы:" << endl;
    cout << "Блюдо 1: " << dish1.getName() << " - " << dish1.getPrice() << " руб." << endl;
    cout << "Блюдо 2: " << dish2.getName() << " - " << dish2.getPrice() << " руб." << endl;
    cout << endl;
}

void demonstrateDynamicInitialization() {
    cout << "=== ДЕМОНСТРАЦИЯ ДИНАМИЧЕСКОЙ ИНИЦИАЛИЗАЦИИ ===" << endl;

    // Динамическая инициализация с new
    Dish* dynamicDish1 = new Dish();
    dynamicDish1->setName("Стейк Рибай");
    dynamicDish1->setPrice(1200.0);

    Dish* dynamicDish2 = new Dish();
    dynamicDish2->setName("Салат Цезарь");
    dynamicDish2->setPrice(320.0);

    Client* dynamicClient = new Client();

    cout << "Динамические объекты созданы:" << endl;
    cout << "Блюдо 1: " << dynamicDish1->getName() << " - " << dynamicDish1->getPrice() << " руб." << endl;
    cout << "Блюдо 2: " << dynamicDish2->getName() << " - " << dynamicDish2->getPrice() << " руб." << endl;

    // Освобождение памяти с delete
    delete dynamicDish1;
    delete dynamicDish2;
    delete dynamicClient;

    cout << "Динамические объекты удалены" << endl;
    cout << endl;
}

void demonstrateReferencesAndPointers() {
    cout << "=== ДЕМОНСТРАЦИЯ РАБОТЫ С ССЫЛКАМИ И УКАЗАТЕЛЯМИ ===" << endl;

    // Создаем объекты
    Dish dish;
    dish.setName("Суши Калифорния");
    dish.setPrice(280.0);

    // Работа со ссылками
    Dish& dishRef = dish;  // Ссылка на объект
    cout << "Через ссылку: " << dishRef.getName() << " - " << dishRef.getPrice() << " руб." << endl;

    dishRef.setPrice(300.0);  // Изменение через ссылку
    cout << "Цена изменена через ссылку: " << dish.getPrice() << " руб." << endl;

    // Работа с указателями
    Dish* dishPtr = &dish;  // Указатель на объект
    cout << "Через указатель: " << dishPtr->getName() << " - " << dishPtr->getPrice() << " руб." << endl;

    dishPtr->setName("Суши Филадельфия");  // Изменение через указатель
    cout << "Название изменено через указатель: " << dish.getName() << endl;

    cout << endl;
}

void demonstrateDynamicArrayOfObjects() {
    cout << "=== ДИНАМИЧЕСКИЙ МАССИВ ОБЪЕКТОВ КЛАССА ===" << endl;

    // Динамический массив объектов Dish
    const int arraySize = 3;
    Dish* dishesArray = new Dish[arraySize];  // Массив объектов

    // Инициализация массива
    dishesArray[0].setName("Борщ");
    dishesArray[0].setPrice(250.0);

    dishesArray[1].setName("Пельмени");
    dishesArray[1].setPrice(320.0);

    dishesArray[2].setName("Компот");
    dishesArray[2].setPrice(80.0);

    cout << "Динамический массив объектов:" << endl;
    for (int i = 0; i < arraySize; ++i) {
        cout << i + 1 << ". " << dishesArray[i].getName()
            << " - " << dishesArray[i].getPrice() << " руб." << endl;
    }

    // Освобождение массива
    delete[] dishesArray;
    cout << "Динамический массив удален" << endl;
    cout << endl;
}

void demonstrateArrayOfDynamicObjects() {
    cout << "=== МАССИВ ДИНАМИЧЕСКИХ ОБЪЕКТОВ КЛАССА ===" << endl;

    // Массив указателей на динамические объекты
    const int arraySize = 3;
    Dish** dynamicDishesArray = new Dish * [arraySize];  // Массив указателей

    // Создание динамических объектов
    dynamicDishesArray[0] = new Dish();
    dynamicDishesArray[0]->setName("Шашлык");
    dynamicDishesArray[0]->setPrice(450.0);

    dynamicDishesArray[1] = new Dish();
    dynamicDishesArray[1]->setName("Хинкали");
    dynamicDishesArray[1]->setPrice(380.0);

    dynamicDishesArray[2] = new Dish();
    dynamicDishesArray[2]->setName("Чай");
    dynamicDishesArray[2]->setPrice(120.0);

    cout << "Массив динамических объектов:" << endl;
    for (int i = 0; i < arraySize; ++i) {
        cout << i + 1 << ". " << dynamicDishesArray[i]->getName()
            << " - " << dynamicDishesArray[i]->getPrice() << " руб." << endl;
    }

    // Освобождение памяти
    for (int i = 0; i < arraySize; ++i) {
        delete dynamicDishesArray[i];  // Удаляем каждый объект
    }
    delete[] dynamicDishesArray;  // Удаляем массив указателей

    cout << "Массив динамических объектов удален" << endl;
    cout << endl;
}

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    cout << "ДЕМОНСТРАЦИЯ РАБОТЫ ПРОЕКТА С РАЗЛИЧНЫМИ ТИПАМИ ИНИЦИАЛИЗАЦИИ" << endl;
    cout << "=============================================================" << endl;
    demonstrateStaticInitialization();
    demonstrateDynamicInitialization();
    demonstrateReferencesAndPointers();
    demonstrateDynamicArrayOfObjects();
    demonstrateArrayOfDynamicObjects();
    return 0;
}