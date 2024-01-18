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
        std::cout << "Student: " << name << ", Age: " << age << ", University: " << university << std::endl;
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
        std::cout << "Employee: " << name << ", Age: " << age << ", Company: " << company << std::endl;
    }
};

// Дочерний класс Character, наследуется от Human
class Character : virtual public Human {
private:
    char gender;

public:
    Character(const std::string& n, int a, char g) : Human(n, a), gender(g) {}

    char getGender() const {
        return gender;
    }

    void setGender(char g) {
        gender = g;
    }

    void displayInfo() const override {
        std::cout << "Character: " << name << ", Age: " << age << ", Gender: " << gender << std::endl;
    }
};

// Дочерний класс StudentEmployee, наследуется от Student и Employee
class StudentEmployee : public Student, public Employee {
public:
    StudentEmployee(const std::string& n, int a, const std::string& u, const std::string& c)
        : Human(n, a), Student(n, a, u), Employee(n, a, c) {}

    void displayInfo() const override {
        std::cout << "Studen: " << getName() << ", Age: " << getAge()
                  << ", University: " << getUniversity() << ", Company: " << getCompany() << std::endl;
    }
};

// Дочерний класс EmployeeCharacter, наследуется от Employee и Character
class EmployeeCharacter : public Employee, public Character {
public:
    EmployeeCharacter(const std::string& n, int a, const std::string& c, char g)
        : Human(n, a), Employee(n, a, c), Character(n, a, g) {}

    void displayInfo() const override {
        std::cout << "EmployeeCharacter: " << getName() << ", Age: " << getAge()
                  << ", Company: " << getCompany() << ", Gender: " << getGender() << std::endl;
    }
};

int main() {
    // Создание объектов и демонстрация использования
    Human human("John Doe", 25);
    human.displayInfo();

    Student student("ГГ", 20, "University X");
    student.displayInfo();

    Employee employee("Eva Brown", 35, "Company Y");
    employee.displayInfo();

    Character character("Bob Johnson", 30, 'M');
    character.displayInfo();

    StudentEmployee studentEmployee("Mark Davis", 22, "University Z", "Company Z");
    studentEmployee.displayInfo();

    EmployeeCharacter employeeCharacter("Laura White", 28, "Company W", 'F');
    employeeCharacter.displayInfo();

    return 0;
}
