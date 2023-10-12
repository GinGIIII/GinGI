#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>

int main() {
    std::srand(static_cast<unsigned>(std::time(nullptr)));

    int totalPoints = 0;

    for (int i = 0; i < 5; ++i) {
        int xi, yi;
        std::cout << "Введите координаты для выстрела " << i + 1 << " (x y): ";
        std::cin >> xi >> yi;

        // Добавим случайное отклонение от -5 до 5
        int random_xi = std::rand() % 11 - 5;
        int random_yi = std::rand() % 11 - 5;

        // Вычислим радиус точки
        double radius = std::sqrt((xi + random_xi) * (xi + random_xi) + (yi + random_yi) * (yi + random_yi));

        // Вычислим баллы за выстрел
        int points = 0;
        if (radius >= 0 && radius < 1) {
            points = 5;
        } else if (radius >= 1 && radius < 2) {
            points = 4;
        } else if (radius >= 2 && radius < 3) {
            points = 3;
        } else if (radius >= 3 && radius < 4) {
            points = 2;
        } else if (radius >= 4 && radius < 5) {
            points = 1;
        } else {
            // Если вы попали вне радиуса, начислить 0 баллов
            points = 0;
        }
        
        
        totalPoints += points;
        // Вывод случайного отклонения
        std::cout << "Случайное отклонение (random_x, random_y): " << random_xi << ", " << random_yi << std::endl;
        std::cout << "За выстрел " << i + 1 << " получено " << points << " баллов. Радиус точки: " << radius << ". Всего баллов: " << totalPoints << std::endl;
    }
    // Проверим, является ли игрок "лузером"
    if (totalPoints < 10) {
    std::cout << "Сумма баллов: " << totalPoints << " лузер" << std::endl;
} else {
    std::cout << "Сумма баллов: " << totalPoints << " чеееел, мега крут!" << std::endl;
}
return 0;
}
