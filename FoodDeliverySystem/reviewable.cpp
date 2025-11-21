#include "reviewable.hpp"
#include "review.hpp" 

// Получение константной ссылки на вектор отзывов
const std::vector<Review*>& Reviewable::getReviews() const
{
    return reviews;
}

// Добавление нового отзыва 
void Reviewable::addReview(Review* review)
{
    reviews.push_back(review);
}

// Удаление отзыва по id
void Reviewable::removeReview(unsigned int reviewId)
{
    // Поиск отзыва по id в векторе
    for (auto it = reviews.begin(); it != reviews.end(); ++it)
    {
        if ((*it)->getId() == reviewId)
        {
            reviews.erase(it);  // Удаление найденного отзыва
            return;
        }
    }
}

// Расчет средней оценки 
double Reviewable::calculateRating() const
{
    // Если отзывов нет - возвращаем 0
    if (reviews.empty())
        return 0;

    // Суммируем все оценки
    double sum = 0;
    for (const auto& r : reviews)
        sum += r->getRating();

    return sum / reviews.size();
}