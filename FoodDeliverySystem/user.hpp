#pragma once

#include <string>
#include <ctime>

// Роль пользователя в системе
enum class UserRole {
	Client,
	Courier,
	Administrator
};

// Базовый класс пользователя
class User
{
private:
	static unsigned int nextId;
	unsigned int id;
	std::string passwordHash;
	std::string login;
	std::time_t registrationDate;
	std::string fullName;

protected:
	std::string email;
	std::string phone;
	bool isActive;
	UserRole role;

public:
	User();
	User(const User& other);
	virtual ~User();

	int getId() const;
	std::string getLogin() const;
	std::time_t getRegistrationDate() const;
	std::string getFullName() const;
	std::string getEmail() const;
	std::string getPhone() const;
	bool getIsActive() const;
	UserRole getRole() const;

	void setFullName(const std::string& name);
	void setEmail(const std::string& email);
	void setPhone(const std::string& phone);
	void setPassword(const std::string& password);
	void setLogin(const std::string& login);
	void registerUser(const std::string& login, const std::string& password);
	void activate();
	void deactivate();

	bool authenticate(const std::string& inputPassword) const;
	void changePassword(const std::string& oldPassword, const std::string& newPassword);
	void displaySecureInfo(const std::string& inputPassword) const;

	virtual std::string getUserType() const = 0;  // Возвращает роль пользователя

protected:
	virtual void displayInfo() const = 0;  // Вывод информации о пользователе

private:
	std::string hashPassword(const std::string& password) const;
};