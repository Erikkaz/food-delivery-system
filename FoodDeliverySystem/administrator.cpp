#include "administrator.hpp"
#include <iostream>

// Конструктор
Administrator::Administrator()
	: User()
{

}

// Деструктор
Administrator::~Administrator()
{

}

// Регистрация администратора
void Administrator::registerAdmin(const std::string& login, const std::string& password)
{
	std::cout << "=== РЕГИСТРАЦИЯ АДМИНА ===" << std::endl;
	registerUser(login, password);
}

// Добавление ресторана
void Administrator::addRestaurant(Restaurant& restaurant)
{
	// Перебираем все рестораны и проверяем не добавлен ли ресторан уже
	for (Restaurant* r : restaurants)
	{
		if (r == &restaurant)
		{
			std::cout << "Ресторан уже добавлен." << std::endl;
			return;
		}
	}

	// Добавляем указатель на ресторан
	restaurants.push_back(&restaurant);
	std::cout << "Ресторан успешно добавлен." << std::endl;

}

// Удаление ресторана
void Administrator::removeRestaurant(Restaurant& restaurant)
{
	// Поиск ресторана в векторе
	for (auto it = restaurants.begin(); it != restaurants.end(); it++)
	{
		if (*it == &restaurant)
		{
			restaurants.erase(it);  // Удаляем ресторан из вектора
			std::cout << "Ресторан удалён" << std::endl;
			return;
		}
	}

	std::cout << "Ресторан не найден." << std::endl;
}

// Редактирование ресторана
void Administrator::editRestaurant(Restaurant& restaurant)
{
	// Проверяем, есть ли ресторан в списке админа
	auto it = std::find(restaurants.begin(), restaurants.end(), &restaurant);
	if (it == restaurants.end()) {
		std::cout << "Ошибка: ресторан не найден!\n";
		return;
	}

	std::cout << "=== Редактирование ресторана: " << restaurant.getName() << " ===\n";

	int choice;
	std::cout << "Что хотите изменить?" << std::endl;
	std::cout << "1 - Название" << std::endl;
	std::cout << "2 - Адрес" << std::endl;
	std::cout << "3 - Часы работы" << std::endl;
	std::cout << "4 - Контактные данные" << std::endl;
	std::cout << "5 - Рейтинг" << std::endl;
	std::cout << "0 - Отмена" << std::endl;
	std::cout << "Ваш выбор: ";
	std::cin >> choice;

	// Очистка буфера для безопасного ввода строк
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

	switch (choice)
	{
	case 1: 
	{
		std::string newName;  // новое название
		std::cout << "Введите новое название: ";
		std::getline(std::cin, newName);
		restaurant.setName(newName);
		std::cout << "Название успешно изменено.\n";
		break;
	}

	case 2: 
	{
		std::string newAddress;  // новый адрес
		std::cout << "Введите новый адрес: ";
		std::getline(std::cin, newAddress);
		restaurant.setAddress(newAddress);
		std::cout << "Адрес успешно изменён.\n";
		break;
	}

	case 3: {
		std::string newHours;  // новые часы работы
		std::cout << "Введите часы работы: ";
		std::getline(std::cin, newHours);
		restaurant.setWorkingHours(newHours);
		std::cout << "Часы работы обновлены.\n";
		break;
	}

	case 4: {
		std::string newContacts;  // новые контакты
		std::cout << "Введите контактные данные: ";
		std::getline(std::cin, newContacts);
		restaurant.setContactDetails(newContacts);
		std::cout << "Контакты обновлены.\n";
		break;
	}

	case 5: {
		float newRating;  // новый рейтинг
		std::cout << "Введите новый рейтинг (0 – 5): ";
		std::cin >> newRating;

		if (newRating < 0 || newRating > 5) {
			std::cout << "Ошибка: рейтинг должен быть от 0 до 5!\n";
		}

		else {
			restaurant.setRating(newRating);
			std::cout << "Рейтинг обновлён.\n";
		}
		break;
	}

	case 0:
		std::cout << "Редактирование отменено.\n";
		break;

	default:
		std::cout << "Неверный выбор!\n";
		break;
	}
}

// Добавление блюда в меню ресторана
bool Administrator::addDish(Restaurant& restaurant)
{
	std::string name;  // Название нового блюда
	double price;  // цена блюда

	std::cout << "Название блюда : ";
	std::cin >> name;
	std::cout << "Цена : ";
	std::cin >> price;

	// Проверка ввода
	if (name.empty() || price < 0) {
		std::cout << "Ошибка: неверные данные!\n";
		return false;
	}

	Dish newDish; // Новый объект блюда

	newDish.setName(name);
	newDish.setPrice(price);

	// Добавление блюда в меню ресторана
	restaurant.addDishToMenu(newDish);

	return true;
}

// Удаление блюда по ID
bool Administrator::deleteDishById(Restaurant& restaurant, int dishId)
{
	// Ссылка на вектор блюд ресторана
	std::vector<Dish>& dishes = restaurant.getDishes();

	// Ищем блюдо по ID с помощью лямбда-функции
	auto it = std::find_if(dishes.begin(), dishes.end(),
		[dishId](const Dish& d) { return d.getID() == dishId; });

	if (it != dishes.end()) 
	{
		dishes.erase(it); // Удаляем блюдо из вектора
		return true;
	}

	else 
	{
		std::cout << "Блюдо с ID " << dishId << " не найдено!\n";
		return false;
	}
}

// Метод удаления блюда
bool Administrator::removeDish(Restaurant& restaurant) {

	displayMenu(restaurant); // Показываем текущее меню

	if (restaurant.getDishes().empty()) {
		std::cout << "Меню пустое!\n";
		return false;
	}

	int dishId;  // id блюда для удаления
	std::cout << "Введите ID блюда для удаления : ";
	std::cin >> dishId;

	return deleteDishById(restaurant, dishId);
}

// Вывод меню ресторана
void Administrator::displayMenu(Restaurant& restaurant)
{
	const std::vector<Dish>& dishes = restaurant.getDishes(); 	// список блюд
	std::cout << "=== Меню ресторана ===" << std::endl;

	for (const auto& dish : dishes)
	{
		std::cout << "ID : " << dish.getID() << " | " << dish.getName() << " | " << dish.getPrice() << "руб" << std::endl;
	}
}

// Редактирование блюда
bool Administrator::editDish(Restaurant& restaurant)
{
	displayMenu(restaurant);

	if (restaurant.getDishes().empty()) {
		std::cout << "Меню пустое!\n";
		return false;
	}

	int dishID;  // ID блюда для редактирования

	std::cout << "Введите ID блюда для редактирования : ";
	std::cin >> dishID;

	// Получаем ссылку на вектор блюд
	auto& dishes = restaurant.getDishes();

	// Ищем блюдо по ID
	auto it = std::find_if(dishes.begin(), dishes.end(),
		[dishID](const Dish& d) { return d.getID() == dishID; });

	if (it == dishes.end()) // если не нашли
	{
		std::cout << "Блюдо с таким ID не найдено.\n";
		return false;
	}

	Dish& dish = *it; // ссылку на само блюдо, чтобы менять

	int choice;
	std::cout << "\nЧто хотите изменить?\n";
	std::cout << "1 - Название" << std::endl;
	std::cout << "2 - Цена" << std::endl;
	std::cout << "Ваш выбор: ";
	std::cin >> choice;

	// очищаем остатки буфера на случай ввода строки
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

	switch (choice)
	{
	case 1: // Изменить название
	{
		std::string newName;   // Новое название
		std::cout << "Введите новое название: ";
		std::getline(std::cin, newName);
		dish.setName(newName);
		std::cout << "Название изменено.\n";
		break;
	}
	case 2: // Изменить цену
	{
		double newPrice;   // Новая цена
		std::cout << "Введите новую цену: ";
		std::cin >> newPrice;
		dish.setPrice(newPrice);
		std::cout << "Цена изменена.\n";
		break;
	}
	default:
		std::cout << "Неверный выбор.\n";
		break;
	}

	return true;
}


// Управление меню ресторана (добавление, удаление, редактирование)
void Administrator::manageRestaurantMenu(Restaurant& restaurant, int choice)
{
	bool success = false; // Флаг успешного выполнения операции

	switch (choice)
	{
	case 1:   // Добавить блюдо
		success = addDish(restaurant);
		if (success) 
			std::cout << "Блюдо добавлено." << std::endl;
		break;

	case 2:  // Удалить блюдо
		success = removeDish(restaurant);
		if(success)
			std::cout << "Блюдо удалено." << std::endl;
		break;

	case 3:  // Редактировать блюдо
		success = editDish(restaurant);
		if(success)
			std::cout << "Блюдо успешно отредактировано." << std::endl;
		break;

	case 0:  // Назад
		std::cout << "Возврат в предыдущее меню..." << std::endl;
		break;

	default:
		std::cout << "Неверный выбор!\n";
		break;
	}

}

// Добавление курьера
void Administrator::addCourier(Courier& courier)
{
	// Проверяем, есть ли уже такой курьер в системе
	for (Courier* c : couriers)
	{
		if (c == &courier)
		{
			std::cout << "Курьер уже добавлен в систему." << std::endl;
			return;
		}
	}

	// Проверяем, что курьер предоставил документы
	if (courier.getPassport().empty() || courier.getSnils().empty())
	{
		std::cout << "Ошибка: Курьер не предоставил все документы!" << std::endl;
		return;
	}

	// Проверяем, активен ли уже
	if (courier.getIsActive())
	{
		std::cout << "Курьер уже активен." << std::endl;
		return;
	}

	// Решение администратора — одобрить или нет
	char choice;
	std::cout << "Одобрить курьера? (y/n): ";
	std::cin >> choice;

	if (choice == 'y' || choice == 'Y')
	{
		courier.setApproved(true);
		courier.activate();
		couriers.push_back(&courier);
		std::cout << "Курьер одобрен, активирован и добавлен в систему." << std::endl;
	}

	else
	{
		courier.setApproved(false);
		courier.deactivate();
		std::cout << "Курьер не одобрен и не добавлен." << std::endl;
	}
}

// Удаление курьера
void Administrator::removeCourier(Courier& courier)
{
	auto it = std::find(couriers.begin(), couriers.end(), &courier);  // Поиск курьера

	if (it == couriers.end())
	{
		std::cout << "Курьер не найден." << std::endl;
		return;
	}

	// Подтверждение удаления
	char choice;
	std::cout << "Вы точно хотите удалить курьера " << courier.getFullName() << "? (y/n): ";
	std::cin >> choice;

	if (choice != 'y' && choice != 'Y')
	{
		std::cout << "Удаление отменено." << std::endl;
		return;
	}

	// Удаляем курьера и деактивируем
	couriers.erase(it);
	courier.deactivate();
	std::cout << "Курьер удалён и деактивирован." << std::endl;
}

// Создание отчёта
void Administrator::generateReport(ReportType type, time_t start, time_t end)
{
	std::cout << "=== Отчёт с " << std::ctime(&start) << " по " << std::ctime(&end)<< " ===\n";

	switch (type)
	{
	case ReportType::Restaurants:  // Отчет по ресторанам
		std::cout << "Рестораны в системе : " << std::endl;
		for (auto r : restaurants)
		{
			std::cout << "- " << r->getName() << std::endl;
		}
		break;


	case ReportType::Couriers:  // Отчет по курьерам
		std::cout << "Курьеры в системе : " << std::endl;
		for (auto c : couriers)
		{
			std::cout << "- " << c->getFullName()
				<< " | Одобрен: " << (c->isApproved() ? "Да" : "Нет")
				<< " | Активен: " << (c->getIsActive() ? "Да" : "Нет") << std::endl;
		}
		break;


	case ReportType::Clients:  // Отчет по клиентам
		std::cout << "Клиенты в системе:" << std::endl;
		for (auto cl : clients)
		{
			std::cout << "- " << cl->getFullName()
				<< " | Активен: " << (cl->getIsActive() ? "Да" : "Нет") << std::endl;
		}
		break;


	case ReportType::Orders:  // Отчет по заказам
		std::cout << "Заказы в системе : " << std::endl;
		for (auto o : orders)
		{
			// Проверка, попадает ли заказ в диапазон дат
			if (o->getOrderTime() >= start && o->getOrderTime() <= end)
			{
				std::cout << "Заказ ID: " << o->getID()
					<< " | Клиент: " << o->getClientName()
					<< " | Сумма: " << o->getPrice() << " руб" << std::endl;
			}
		}
		break;


	case ReportType::Earnings:  // Отчет по выручке
	{
		double total = 0;  // Общая сумма заказов
		for (auto o : orders)
		{
			if (o->getOrderTime() >= start && o->getOrderTime() <= end)
				total += o->getPrice();
		}
		std::cout << "Общая выручка за период: " << total << " руб" << std::endl;
		break;

	}

	default:
		std::cout << "Неизвестный тип отчёта!" << std::endl;
		break;
	}

	std::cout << "=== Конец отчёта ===" << std::endl;
}