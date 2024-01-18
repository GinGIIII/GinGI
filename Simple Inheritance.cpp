#include <iostream>
#include <string>

// Базовый класс Human
class Human {
protected:
    std::string model;
    int price;

public:
    Human(const std::string& m, int p) : model(m), price(p) {}

    std::string getModel() const {
        return model;
    }

    void setModel(const std::string& m) {
        model = m;
    }

    int getPrice() const {
        return price;
    }

    void setPrice(int p) {
        price = p;
    }

    virtual void displayInfo() const {
        std::cout << "Дилер: " << model << std::endl;
    }
};

// Дочерний класс Gun1, наследуется от Human
class Gun1 : virtual public Human {
private:
    std::string production;

public:
    Gun1(const std::string& m, int p, const std::string& prod) : Human(m, p), production(prod) {}

    std::string getProduction() const {
        return production;
    }

    void setProduction(const std::string& prod) {
        production = prod;
    }

    void displayInfo() const override {
        std::cout << "1) Модель: " << model << ", Цена: " << price << ", Производство: " << production << std::endl;
    }
};

// Дочерний класс Gun2, наследуется от Human
class Gun2 : virtual public Human {
private:
    std::string patron;

public:
    Gun2(const std::string& m, int p, const std::string& pat) : Human(m, p), patron(pat) {}

    std::string getPatron() const {
        return patron;
    }

    void setPatron(const std::string& pat) {
        patron = pat;
    }

    void displayInfo() const override {
        std::cout << "2) Модель: " << model << ", Цена: " << price  << ", Патрон: " << patron << std::endl;
    }
};

// Дочерний класс Gun3, наследуется от Human
class Gun3 : virtual public Human {
private:
    std::string production;

public:
    Gun3(const std::string& m, int p, const std::string& prod) : Human(m, p), production(prod) {}

    std::string getProduction() const {
        return production;
    }

    void setProduction(const std::string& prod) {
        production = prod;
    }

    void displayInfo() const override {
        std::cout << "3) Модель: " << model << ", Цена: " << price << ", Производство: " << production << std::endl;
    }
};

// Дочерний класс Gun1Gun2, наследуется от Gun1 и Gun2
class Gun1Gun2 : public Gun1, public Gun2 {
public:
    Gun1Gun2(const std::string& m, int p, const std::string& prod, const std::string& pat)
        : Human(m, p), Gun1(m, p, prod), Gun2(m, p, pat) {}

    void displayInfo() const override {
        std::cout << "4) Модель: " << getModel() << ", Цена: " << getPrice()
                  << ", Производство: " << getProduction() << ", Патрон: " << getPatron() << std::endl;
    }
};

// Дочерний класс Gun2Gun3, наследуется от Gun2 и Gun3
class Gun2Gun3 : public Gun2, public Gun3 {
public:
    Gun2Gun3(const std::string& m, int p, const std::string& pat, const std::string& prod)
        : Human(m, p), Gun2(m, p, pat), Gun3(m, p, prod) {}

    void displayInfo() const override {
        std::cout << "5) Модель: " << getModel() << ", Цена: " << getPrice()
                   << ", Производство: " << getProduction() << ", Патрон: " << getPatron() << std::endl;
    }
};

int main() {
    // Создание объектов и демонстрация использования
    Human human("Сидорович", 1);
    human.displayInfo();

    Gun1 Gun1("AK-47", 2700, "СССР");
    Gun1.displayInfo();

    Gun2 Gun2("AWP", 4750, "Великобритания");
    Gun2.displayInfo();

    Gun3 Gun3("M16", 30, "США");
    Gun3.displayInfo();

    Gun1Gun2 Gun1Gun2("Desert Eagle", 700, "Израиль", "7");
    Gun1Gun2 .displayInfo();

    Gun2Gun3 Gun2Gun3("M4A1-S", 2900, "25", "США");
    Gun2Gun3 .displayInfo();

    return 0;
}
