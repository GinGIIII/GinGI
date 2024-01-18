#include <iostream>
#include <string>

// Базовый класс Human
class Human {
protected:
    std::string name;
    int age;

public:
    Human(const std::string& n, int a) : name(n), age(a) {}

    std::string getName() const {
        return name;
    }

    void setName(const std::string& n) {
        name = n;
    }

    int getAge() const {
        return age;
    }

    void setAge(int a) {
        age = a;
    }

    virtual void displayInfo() const {
        std::cout << "Human: " << name << ", Age: " << age << std::endl;
    }
};

// Дочерний класс Student, наследуется от Human
class Student : virtual public Human {
private:
    std::string university;

public:
    Student(const std::string& n, int a, const std::string& u) : Human(n, a), university(u) {}

    std::string getUniversity() const {
        return university;
    }

    void setUniversity(const std::string& u) {
        university = u;
    }

    void displayInfo() const override {
        std::cout << "AK-47: " << name << ", Цена: " << age << ", Производство: " << university << std::endl;
    }
};

// Дочерний класс Employee, наследуется от Human
class Employee : virtual public Human {
private:
    std::string company;

public:
    Employee(const std::string& n, int a, const std::string& c) : Human(n, a), company(c) {}

    std::string getCompany() const {
        return company;
    }

    void setCompany(const std::string& c) {
        company = c;
    }

    void displayInfo() const override {
        std::cout << "AWP: " << name << ", Цена: " << age << ", Производство: " << company << std::endl;
    }
};

// Дочерний класс Character, наследуется от Human
class Character : virtual public Human {
private:
    std::string location;

public:
    Character(const std::string& n, int a, const std::string& l) : Human(n, a), location(l) {}

    std::string getLocation() const {
        return location;
    }

    void setLocation(const std::string& l) {
        location = l;
    }

    void displayInfo() const override {
        std::cout << "M-16: " << name << ", Цена: " << age << ", Производство: " << location << std::endl;
    }
};

// Дочерний класс StudentEmployee, наследуется от Student и Employee
class StudentEmployee : public Student, public Employee {
public:
    StudentEmployee(const std::string& n, int a, const std::string& u, const std::string& c)
        : Human(n, a), Student(n, a, u), Employee(n, a, c) {}

    void displayInfo() const override {
        std::cout << "Desert Eagle: " << getName() << ", Цена: " << getAge()
                  << ", Производство: " << getUniversity() << ", Патрон: " << getCompany() << std::endl;
    }
};

// Дочерний класс EmployeeCharacter, наследуется от Employee и Character
class EmployeeCharacter : public Employee, public Character {
public:
    EmployeeCharacter(const std::string& n, int a, const std::string& c, const std::string& l)
        : Human(n, a), Employee(n, a, c), Character(n, a, l) {}

    void displayInfo() const override {
        std::cout << "M4A1-S: " << getName() << ", Цена: " << getAge()
                  << ", Производство: " << getCompany() <<  ", Патрон: " << getLocation()<< std::endl;
    }
};

int main() {
    // Создание объектов и демонстрация использования
    Human human("Сидорович", 100000);
    human.displayInfo();

    Student student("Огненый змей", 2700, "СССР");
    student.displayInfo();

    Employee employee("Гунгнир", 4750, "Великобритания");
    employee.displayInfo();

    Character character("Вой", 3100, "США");
    character.displayInfo();

    StudentEmployee studentEmployee("Огненое пламя", 700, "Израль", "7");
    studentEmployee.displayInfo();

    EmployeeCharacter employeeCharacter("Падение Икара", 2900, "США", "25");
    employeeCharacter.displayInfo();

    return 0;
}
