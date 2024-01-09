#include <iostream>
#include <cmath>

class Date {
private:
    int year;
    short int month;
    short int day;
    short int hour;
    short int minute;
    short int second;
    bool isOurEra;

    int dayInM[13] = { 0,31,28,31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

public:
    // Конструктор по умолчанию
    Date() : year(1960), month(1), day(1), hour(0), minute(0), second(0), isOurEra(true) {}

    // Конструктор с параметрами
    Date(int y, short int m, short int d, short int h, short int mm, short int s, bool isOE) :
        year(abs(y)), month(abs(m)), day(abs(d)), hour(abs(h)), minute(abs(mm)), second(abs(s)), isOurEra(isOE) {}

    // Метод для добавления даты
    Date add(int y, short int m, short int d, short int h, short int min, short int s, bool isE) {
        Date fdata{ y,m,d,h,min,s,isE };
        *this = *this + fdata;
        return *this;
    }

    // Метод для вычитания даты
    Date subtract(int y, short int m, short int d, short int h, short int min, short int s, bool isE) {
        Date fdata{ y,m,d,h,min,s,isE };
        *this = *this - fdata;
        return *this;
    }

    // Перегрузка оператора вывода
    friend std::ostream& operator<<(std::ostream& os, const Date& data);

    // Перегрузка оператора сравнения "<"
    bool operator < (const Date& d2);

    // Перегрузка оператора сравнения ">"
    bool operator > (const Date& d2);

    // Перегрузка оператора сравнения "=="
    bool operator == (const Date& d2);

    // Перегрузка оператора сложения "+"
    Date operator + (const Date& d);

    // Перегрузка оператора сложения "+="
    void operator += (const Date& d);

    // Перегрузка оператора вычитания "-"
    Date operator - (const Date& d);

    // Перегрузка оператора вычитания "-="
    void operator -= (const Date& d);

    // Перегрузка оператора присваивания "="
    void operator = (const Date& d);

    // Метод для вывода информации о дате
    void getDate() const {
        std::cout << year << " " << month << " " << day << " " << hour << " " << minute << " " << second << std::endl;
    }

    // Метод для определения високосного года
    bool isVis() const {
        if (!(year % 100)) {
            if (!(year % 400)) return true;
        }
        if (!(year % 4)) return true;
        else return false;
    }
};

// Реализация перегрузки оператора вывода
std::ostream& operator<<(std::ostream& os, const Date& data) {
    os << "Date: [" << data.year << " year, " << data.month << " month, " << data.day << " day, ";
    os << data.hour << " hours, " << data.minute << " minutes, " << data.second << " sec., ";
    if (data.isOurEra) os << "Our Era]";
    else os << "Previous Era";
    return os;
}

// Реализация перегрузки оператора сравнения "<"
bool Date::operator < (const Date& d2) {
    if ((isOurEra == false) and (d2.isOurEra == true)) {
        return true;
    }

    if ((isOurEra == true) and (d2.isOurEra == false)) {
        return false;
    }

    if (!isOurEra) {
        if (year < d2.year) return true;
        else if (year > d2.year) return false;
        if (month < d2.month) return true;
        else if (month > d2.month) return false;
        if (day < d2.day) return true;
        else if (day > d2.day) return false;
        if (hour < d2.hour) return true;
        else if (hour > d2.hour) return false;
        if (minute < d2.minute) return true;
        else if (minute > d2.minute) return false;
        if (second < d2.second) return true;
        else if (second > d2.second) return false;
        return false;
    }
    else {
        if (year > d2.year) return true;
        else if (year < d2.year) return false;
        if (month > d2.month) return true;
        else if (month < d2.month) return false;
        if (day > d2.day) return true;
        else if (day < d2.day) return false;
        if (hour > d2.hour) return true;
        else if (hour < d2.hour) return false;
        if (minute > d2.minute) return true;
        else if (minute < d2.minute) return false;
        if (second > d2.second) return true;
        else if (second < d2.second) return false;
        return false;
    }
}

// Реализация перегрузки оператора сравнения ">"
bool Date::operator > (const Date& d2) {
    if ((isOurEra == true) and (d2.isOurEra == false)) {
        return true;
    }

    if ((isOurEra == false) and (d2.isOurEra == true)) {
        return false;
    }

    if (!isOurEra) {
        if (year < d2.year) return true;
        else if (year > d2.year) return false;
        if (month < d2.month) return true;
        else if (month > d2.month) return false;
        if (day < d2.day) return true;
        else if (day > d2.day) return false;
        if (hour < d2.hour) return true;
        else if (hour > d2.hour) return false;
        if (minute < d2.minute) return true;
        else if (minute > d2.minute) return false;
        if (second < d2.second) return true;
        else if (second > d2.second) return false;
        return false;
    }
    else {
        if (year > d2.year) return true;
        else if (year < d2.year) return false;
        if (month > d2.month) return true;
        else if (month < d2.month) return false;
        if (day > d2.day) return true;
        else if (day < d2.day) return false;
        if (hour > d2.hour) return true;
        else if (hour < d2.hour) return false;
        if (minute > d2.minute) return true;
        else if (minute < d2.minute) return false;
        if (second > d2.second) return true;
        else if (second < d2.second) return false;
        return false;
    }
}

// Реализация перегрузки оператора сравнения "=="
bool Date::operator == (const Date& d2) {
    if (isOurEra != d2.isOurEra) return false;
    if ((year == d2.year) and (month == d2.month) and (day == d2.day) and (hour == d2.hour) and (minute == d2.minute) and (second == d2.second)) {
        return true;
    }
    else return false;
}

// Реализация перегрузки оператора сложения "+"
Date Date::operator + (const Date& d) {
    Date result = *this; // Создаем копию текущего объекта

    if (isOurEra == d.isOurEra) {
        result.second += d.second;
        if (result.second >= 60) {
            result.second -= 60;
            result.minute += 1;
        }
        result.minute += d.minute;
        if (result.minute >= 60) {
            result.minute -= 60;
            result.hour += 1;
        }
        result.hour += d.hour;
        if (result.hour >= 24) {
            result.hour -= 24;
            result.day += 1;
        }
        result.day += d.day;
        if (result.isVis()) {
            dayInM[2] += 1;
            if (result.day > dayInM[result.month]) {
                result.day -= dayInM[result.month];
                result.month += 1;
            }
            dayInM[2] -= 1;
        }
        else if (result.day > dayInM[result.month]) {
            result.month += 1;
            result.day -= dayInM[result.month];
        }
        result.month += d.month;
        if (result.month > 12) {
            result.year += 1;
            result.month -= 12;
        }
        result.year += d.year;
    }
    return result;
}

// Реализация перегрузки оператора сложения "+="
void Date::operator += (const Date& d) {
    *this = *this + d;
}

// Реализация перегрузки оператора вычитания "-"
Date Date::operator - (const Date& d) {
    Date result = *this; // Создаем копию текущего объекта

    if (isOurEra == d.isOurEra) {
        result.second -= d.second;
        if (result.second < 0) {
            result.second += 60;
            result.minute -= 1;
        }
        result.minute -= d.minute;
        if (result.minute < 0) {
            result.minute += 60;
            result.hour -= 1;
        }
        result.hour -= d.hour;
        if (result.hour < 0) {
            result.hour += 24;
            result.day -= 1;
        }
        result.day -= d.day;
        if (result.isVis()) {
            dayInM[2] += 1;
            if (result.day < 0) {
                result.month -= 1;
                result.day += dayInM[result.month];
                if (result.month == 0) result.month = 12;
            }
            dayInM[2] -= 1;
        }
        else if (result.day < 0) {
            result.day -= dayInM[result.month];
            result.month += 1;
        }
        result.month -= d.month;
        if (result.month < 0) {
            result.year -= 1;
            result.month += 12;
        }
        result.year -= d.year;
        if (result.year < 0) {
            abs(result.year);
            result.isOurEra = !result.isOurEra;
        }
    }
    return result;
}

// Реализация перегрузки оператора вычитания "-="
void Date::operator -= (const Date& d) {
    *this = *this - d;
}

// Реализация перегрузки оператора присваивания "="
void Date::operator = (const Date& d) {
    isOurEra = d.isOurEra;
    year = d.year;
    month = d.month;
    day = d.day;
    hour = d.hour;
    minute = d.minute;
    second = d.second;
}

int main() {
    Date data;
    Date data1(1960, 2, 29, 0, 0, 5, true);
    std::cout << data << std::endl;
    std::cout << data1 << std::endl;
    data1.subtract(1, 2, 29, 12, 12, 45, true);
    std::cout << data1 << std::endl;
    data1.add(1, 2, 29, 12, 12, 45, true);
    std::cout << data1 << std::endl;

    return 0;
}
