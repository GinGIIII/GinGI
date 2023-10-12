#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath> // Добавляем заголовочный файл для sqrt

int main() {
    // Инициализация генератора случайных чисел
    srand(time(0));

    int totalPoints = 0;

    // Цикл для 5 выстрелов
    for (int i = 0; i < 5; ++i) {
        double xi, yi;
        std::cout << "Введите координаты xi и yi для выстрела " << i + 1 << ": ";
        std::cin >> xi >> yi;

        // Генерация случайных отклонений от попадания
        int random_xi = rand() % 11 - 5; // От -5 до 5
        int random_yi = rand() % 11 - 5;

        // Вычисление расстояния от центра мишени
        double distance = sqrt(xi * xi + yi * yi);

        // Оценка баллов в зависимости от расстояния
        int points = 0;
        if (distance < 1.0) {
            points = 5;
        } else if (distance < 2.0) {
            points = 4;
        } else if (distance < 3.0) {
            points = 3;
        } else if (distance < 4.0) {
            points = 2;
        } else if (distance < 5.0) {
            points = 1;
        }

        // Суммирование баллов
        totalPoints += points;

        // Вывод результата выстрела
        std::cout << "Попадание в (" << xi << ", " << yi << ") со случайными отклонениями (" << random_xi << ", " << random_yi << "). Заработано " << points << " баллов." << std::endl;
    }

    // Вывод общего числа баллов и статуса "лузер"
    std::cout << "Сумма баллов: " << totalPoints << std::endl;
    if (totalPoints < 10) {
        std::cout << "Лузер" << std::endl;
    }

    return 0;
}
