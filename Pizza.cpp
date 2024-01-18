#include<iostream>
#include <vector>
#include <ctime>

using namespace std;

class Pizza  {

public:

    virtual double GetCost() {
        return 0.0;
    }

    virtual void Prise() {
        cout << "Я не знаю цену неизвестной пиццы...";
    }

    virtual void Print_Info() { //отдельная функция,выводит инфу о пицце
        cout << "Это информация о выброной пицце \n Это пицца.. \n";
    }

    virtual void Set_Size(int value) {
        cout << "Ты хочешь " << value << " сантиметров пиццы?\n Okey...\n";
    }

    virtual void Salt_Pizza() {
        cout << "Почему ты хочешь поссолить пиццу?...\n";
    };

    virtual void Add_Cheese() {
        cout << "Почему в пиццу нужно добавлять сыр?...\n";
    };

};

class Julien : public Pizza {
private:
    string Name;
    string Info;
    unsigned int Size;
    double cost;
    int Salt_value;
    int Cheese_value;

public:
    Julien() { Name = "Жульен"; Info = "Няма-Няма, Грибная с курочкой!"; Size = 0; cost = 0; Salt_value = 0; Cheese_value = 0; }

    void Prise() override {
        switch (this->Size) {
        case 25:
            this->cost += 100 + this->Cheese_value * 20 + this->Salt_value * 0.5;
            break;
        case 30:
            this->cost += 105 + this->Cheese_value * 20 + this->Salt_value * 0.5;
            break;
        case 35:
            this->cost += 110 + this->Cheese_value * 20 + this->Salt_value * 0.5;
            break;
        case 40:
            this->cost += 115 + this->Cheese_value * 20 + this->Salt_value * 0.5;
            break;
        default:
            cout << "Выберите размер пиццы!\n";
            break;
        }
    }

    void Print_Info() { //отдельная функция, выводит инфу о пицце
        cout << "Название: " << this->Name << endl;
        cout << "Информация: " << this->Info << endl;
        cout << "Размер: " << this->Size << endl;
        cout << "Добавка сыра: " << this->Cheese_value << endl;
        cout << "Добавка соли: " << this->Salt_value << endl;
        cout << "Цена: " << this->cost << endl;
    }

    double GetCost() {
        return this->cost;
    }

    void Add_Cheese() override {
        unsigned int ches_value = 0;
        cout << "Сколько сыра добавить?\n";
        cin >> ches_value;
        if (ches_value > 0)
        this->Cheese_value = ches_value;
    };

    void Salt_Pizza() override {
        unsigned int salt_val = 0;
        cout << "Сколько соли добавить?\n";
        cin >> salt_val;
        if(salt_val>0)
            this->Salt_value = salt_val;
    };

    void Set_Size(int value) override {
        switch (value) {
        case 1:
            this->Size = 25;
            break;
        case 2:
            this->Size = 30;
            break;
        case 3:
            this->Size = 35;
            break;
        case 4:
            this->Size = 40;
            break;
        default:
            cout << "Этот размер недооцененный!\n";
            break;
        }
    }

};

class Pepperoni : public Pizza {
private:
    string Name;
    string Info;
    unsigned int Size;
    double cost;
    int Salt_value;
    int Cheese_value;

public:
    Pepperoni() { Name = "Пепперони"; Info = "Жгучая чертовка"; Size = 0; cost = 0; Salt_value = 0; Cheese_value = 0; }

    void Print_Info() { 
        cout << "Название: " << this->Name << endl;
        cout << "Информация: " << this->Info << endl;
        cout << "Размер: " << this->Size << endl;
        cout << "Добавка сыра: " << this->Cheese_value << endl;
        cout << "Добавка соли: " << this->Salt_value << endl;
        cout << "Цена: " <<this->cost << endl;
    }

    void Prise() override {
        switch (this->Size) {
        case 25:
            this->cost += 130 + this->Cheese_value * 40 + this->Salt_value * 0.5;
            break;
        case 30:
            this->cost += 135 + this->Cheese_value * 40 + this->Salt_value * 0.5;
            break;
        case 35:
            this->cost += 140 + this->Cheese_value * 40 + this->Salt_value * 0.5;
            break;
        case 40:
            this->cost += 145 + this->Cheese_value * 40 + this->Salt_value * 0.5;
            break;
        default:
            cout << "Выберите размер пиццы!\n";
            break;
        }
    }

    double GetCost() {
        return this->cost;
    }

    void Add_Cheese() override {
        unsigned int ches_value = 0;
        cout << "Сколько сыра добавить?\n";
        cin >> ches_value;
        if (ches_value > 0)
        this->Cheese_value = ches_value;
    };

    void Salt_Pizza() override {
        unsigned int salt_val = 0;
        cout << "Сколько соли добавить?\n";
        cin >> salt_val;
        if (salt_val > 0)
        this->Salt_value = salt_val;
    };

    void Set_Size(int value) override {
        switch (value) {
        case 1:
            this->Size = 25;
            break;
        case 2:
            this->Size = 30;
            break;
        case 3:
            this->Size = 35;
            break;
        case 4:
            this->Size = 40;
            break;
        default:
            cout << "Этот размер недооцененный!\n";
            break;
        }
    }
};

class FourСheeses : public Pizza {
private:
    string Name;
    string Info;
    unsigned int Size;
    double cost;
    int Salt_value;
    int Cheese_value;

public:
    FourСheeses() { Name = "Четыре сыра"; Info = "Сырная кома"; Size = 0; cost = 0; Salt_value = 0; Cheese_value = 0; }

    void Print_Info() { 
        cout << "Название: " << this->Name << endl;
        cout << "Информация: " << this->Info << endl;
        cout << "Размер: " << this->Size << endl;
        cout << "Добавка сыра: " << this->Cheese_value << endl;
        cout << "Добавка соли: " << this->Salt_value << endl;
        cout << "Цена: " << this->cost << endl;
    }

    void Prise() override {
        switch (this->Size) {
        case 25:
            this->cost += 170 + this->Cheese_value * 10 + this->Salt_value * 0.5;
            break;
        case 30:
            this->cost += 175 + this->Cheese_value * 10 + this->Salt_value * 0.5;
            break;
        case 35:
            this->cost += 180 + this->Cheese_value * 10 + this->Salt_value * 0.5;
            break;
        case 40:
            this->cost += 185 + this->Cheese_value * 10 + this->Salt_value * 0.5;
            break;
        default:
            cout << "Выберите размер пиццы!\n";
            break;
        }
    }

    double GetCost() {
        return this->cost;
    }

    void Add_Cheese() override {
        unsigned int ches_value = 0;
        cout << "Сколько сыра добавить?\n";
        cin >> ches_value;
        if (ches_value > 0)
        this->Cheese_value = ches_value;
    };

    void Salt_Pizza() override {
        unsigned int salt_val = 0;
        cout << "Сколько соли добавить?\n";
        cin >> salt_val;
        if (salt_val > 0)
        this->Salt_value = salt_val;
    };

    void Set_Size(int value) override {
        switch (value) {
        case 1:
            this->Size = 25;
            break;
        case 2:
            this->Size = 30;
            break;
        case 3:
            this->Size = 35;
            break;
        case 4:
            this->Size = 40;
            break;
        default:
            cout << "Этот размер недооцененный!\n";
            break;
        }
    }

};

class Pizzeria_Window {

private:
    vector <Pizza*> Order_List; //это мой лист заказа
public:

    void Print_Menu() { //процедура выводы меню для выбора действия
        int N = 0;
        cout << "Меню заказа\nВыберите действие:\n";
        cout << "1)Добавить пиццу в заказ\n";
        cout << "2)Распечатать чек заказа\n";
        cout << "3)Подтвердить и оплатить\n";
        cout << "-----> ";
        cin >> N;
        cout << endl;
        switch (N) {
        case 1:
            Vibor_Pizza();
            break;
        case 2:
            Print_Order();
            break;
        case 3:
            cout << "Заказ в процессе приготовления" << endl;
            break;
        default:
            cout << "Выберите верное действие!\n\n";
            Print_Menu();
        }
    };

    void Vibor_Pizza() {
        int N = 0;
        Pizza* pizza = nullptr;
        cout << "Выберите пиццу из списка:\n";
        cout << "1)Жульен\n";
        cout << "2)Пепперони\n";
        cout << "3)Четыре сыра\n";
        cout << "4)Меню\n";
        cout << "-----> ";
        cin >> N;
        cout << endl;
        switch (N) {
        case 1:
            pizza = new Julien();
            break;
        case 2:
            pizza = new Pepperoni();
            break;
        case 3:
            pizza = new FourСheeses();
            break;
        case 4:
            Print_Menu();
        }

        cout << "Выберите размер пиццы:\n";
        cout << "1)25\n";
        cout << "2)30\n";
        cout << "3)35\n";
        cout << "4)40\n";
        cout << "-----> ";
        cin >> N;
        cout << endl;
        if (N > 0 and N < 5) {
            pizza->Set_Size(N);
            pizza->Add_Cheese();
            pizza->Salt_Pizza();
            pizza->Prise();
            this->Order_List.push_back(pizza);
            cout << endl;
            Print_Menu();
        }
        else {
            cout << "Неверный параметр, попробуйте ещё раз...";
            Print_Menu();
        };

    };

    void Print_Order() {
        cout << "Это ваш заказ: \n\n";
        for (int i = 0; i < this->Order_List.size(); i++) {
            cout << "Позиция "<<i+1<<"\n\n";
            this->Order_List[i]->Print_Info();
            cout << endl;
        }
        Print_Sum_Cost();
    };

    void Print_Sum_Cost() {
        double SumCost = 0.0;
        for (int i = 0; i < this->Order_List.size(); i++) {
            SumCost+=this->Order_List[i]->GetCost();
        }
        cout << "Итоговая сумма = " << SumCost;
    }
};

int main() {

    Pizzeria_Window window;
    window.Print_Menu();
    return 0;
}
