#include <iostream>
#include "user.hpp"
#include <functional>
#include <sstream>
#include <iomanip>

// Инициализация статического счетчика id
unsigned int User::nextId = 1;

// Конструктор
User::User()
	: id(nextId++),
	passwordHash(""),
	login(""),
	registrationDate(std::time(nullptr)),
	fullName(""),
	email(""),
	phone(""),
	isActive(true),
	role(UserRole::Client)
{

}

// Конcтруктор копировния   
User::User(const User& other)
	: id(other.id),
	passwordHash(other.passwordHash),
	login(other.login),
	registrationDate(other.registrationDate),
	fullName(other.fullName),
	email(other.email),
	phone(other.phone),
	isActive(other.isActive),
	role(other.role)
{

}

// Деструктор
User::~User()
{
	std::cout << "User destructor : " << id << "-" << login << std::endl;
}


// ==== Геттеры ==== 

int User::getId() const
{
	return id;
}

std::string User::getLogin() const
{
	return login;
}

std::time_t User::getRegistrationDate() const
{
	return registrationDate;
}

std::string User::getFullName() const
{
	return fullName;
}

std::string User::getEmail() const
{
	return email;
}

std::string User::getPhone() const
{
	return phone;
}

bool User::getIsActive() const
{
	return isActive;
}

UserRole User::getRole() const
{
	return role;
}


// ==== Сеттеры ====

void User::setFullName(const std::string& name)
{
	fullName = name;
}

void User::setEmail(const std::string& email)
{
	this->email = email;
}

void User::setPhone(const std::string& phone)
{
	this->phone = phone;
}

void User::setLogin(const std::string& login)
{
	if (this->login.empty())
	{
		this->login = login;
		std::cout << "Логин успешно установлен!" << std::endl;
	}
	else
		std::cout << "Ошибка: логин уже установлен!" << std::endl;
}

void User::setPassword(const std::string& password)
{
	if (passwordHash.empty())
	{
		passwordHash = hashPassword(password);
		std::cout << "Пароль успешно установлен!" << std::endl;
	}

	else
		std::cout << "Ошибка: пароль уже установлен!" << std::endl;
}

// Регистрация пользователя
void User::registerUser(const std::string& login, const std::string& password)
{
	setLogin(login);
	setPassword(password);
	activate();
}

// Методы активации 
void User::activate()
{
	isActive = true;
}

void User::deactivate() {
	isActive = false;
}

// Аутенфикация
bool User::authenticate(const std::string& inputPassword) const
{
	std::string inputHash = hashPassword(inputPassword);
	return inputHash == passwordHash;
}

// Смена пароля
void User::changePassword(const std::string& oldPassword, const std::string& newPassword)
{
	if (authenticate(oldPassword))
	{
		passwordHash = hashPassword(newPassword);
		std::cout << "Пароль успешно изменен!" << std::endl;
	}

	else
	{
		std::cout << "Ошибка: текущий пароль введен неверно! " << std::endl;
	}

}

// Хэширование
std::string User::hashPassword(const std::string& password) const
{
	std::hash<std::string> hasher;
	size_t hashValue = hasher(password);

	// Преобразуем хэш в hex-строку
	std::stringstream ss;
	ss << std::hex << hashValue;
	return ss.str();
}

// Метод для защищенного вывода информации о пользователе
void User::displaySecureInfo(const std::string& inputPassword) const
{
	if (authenticate(inputPassword))
	{
		displayInfo();  // показываем информацию
	}

	else
	{
		std::cout << "Ошибка: неверный пароль!" << std::endl;
	}
}


