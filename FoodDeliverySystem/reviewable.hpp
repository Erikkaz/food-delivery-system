#pragma once
#include <vector>

class Review;

class Reviewable
{
protected:
    std::vector<Review*> reviews;  // Коллекция указателей на отзывы

public:
    const std::vector<Review*>& getReviews() const;   // Получение всех отзывов объекта
    void addReview(Review* review);  // Добавление нового отзыва
    void removeReview(unsigned int reviewId);   // Удаление отзыва 
    double calculateRating() const; // Расчет средней оценки
};