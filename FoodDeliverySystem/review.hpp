#pragma once
#include <string>

// Предварительные объявления для избежания циклических включений
class Client;
class Reviewable;

class Review
{
private:
    static unsigned int nextId;  // Статическая переменная для автоинкремента id
    unsigned int id;
    const Client* author;  // Автор отзыва
    const Reviewable* target;  // Объект отзыва 
    float rating;   // Оценка от 0 до 5
    std::string comment;  // Текст отзыва
    std::string date;  // Дата создания отзыва

public:
    // Конструктор отзыва
    Review(const Client* author,
        const Reviewable* target,
        float rating,
        const std::string& comment,
        const std::string& date);

    // === Геттеры ===
    unsigned int getId() const;
    const Client* getAuthor() const;
    const Reviewable* getTarget() const;
    float getRating() const;
    const std::string& getComment() const;
    const std::string& getDate() const;
};