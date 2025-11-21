#include "review.hpp"

// Инициализация статической переменной 
unsigned int Review::nextId = 1;

// Конструктор отзыва
Review::Review(const Client* author,
    const Reviewable* target,
    float rating,
    const std::string& comment,
    const std::string& date)
    : id(nextId++),
    author(author),
    target(target),
    rating(rating < 0 ? 0 : (rating > 5 ? 5 : rating)), // ограничиваем 0–5
    comment(comment),
    date(date)
{

}

// Получение id
unsigned int Review::getId() const 
{ 
    return id; 
}

// Получение указателя на автора отзыва
const Client* Review::getAuthor() const 
{ 
    return author; 
}

// Получение указателя на объект отзыва
const Reviewable* Review::getTarget() const 
{ 
    return target; 
}

// Получение оценки отзыва
float Review::getRating() const 
{ 
    return rating; 
}

// Получение отзыва
const std::string& Review::getComment() const 
{
    return comment; 
}

// Получение даты создания отзыва
const std::string& Review::getDate() const 
{ 
    return date; 
}