#pragma once
#include <iostream>
#include <string>
#include <typeinfo>
using namespace std;
//***************** class Vehicle **************************
class Vehicle {
protected:
    int wheel; //кол-во колес
    int people; //кол-во пассажирских мест
    double speed; // средняя скорость
    int comfort; //комфортность по школе от 1 до 5
    string color; //цвет средства передвижения
    double time; //время перевозки               
    double money; //стоимость перевозки
public:
    Vehicle();
    ~Vehicle() {}


    int GetWheel() { return this->wheel; }
    int GetPeople() { return this->people; }
    double GetSpeed() { return this->speed; }
    int GetComfort() { return this->comfort; }
    string GetColor() { return this->color; }
    double GetTime() { return this->time; }
    double GetMoney() { return this->money; }
    void SetWheel(int wheel) { this->wheel = wheel; }
    void SetPeople(int people) { this->people = people; }
    void SetSpeed(int speed) { this->speed = speed; }
    void SetComfort(int comfort) { this->comfort = comfort; }
    void SetColor(string color) { this->color = color; }
    void SetTime(double time) { this->time = time; }
    void SetMoney(double money) { this->money = money; }
    virtual void Show() = 0;
};
//**************classs Car **************************
class Car : public Vehicle {
private:
    string model;
public:
    Car();
    ~Car() {}

    string GetModel() { return this->model; }
    void SetModel(string model) { this->model = model; }
    void Show();
};
//**************** class Bicycle ************************
class Bicycle : public Vehicle {
private:
    int basket; //есть ли корзинка 
    int bb;
public:
    Bicycle();
    ~Bicycle() {}

    int GetBasket() { return this->basket; }
    void SetBasket(int basket) { this->basket = basket; }

    void Show();
};
//****************** class Cart ********************
class Cart : public Vehicle {
private:
    int horses; //кол-во лошадей
    string name; //имя кучера
public:
    Cart();
    ~Cart() {}

    int GetHorses() { return this->horses; }
    string GetName() { return this->name; }
    void SetHorses(int horses) { this->horses = horses; }
    void SetName(string name) { this->name = name; }
    void Show();
};


//***************** class Item  **************************
class Item {
protected:
    double invNumber; // инвентарный номер
    bool taken; //взято на руки или имеется в наличии
public:
    Item();
    ~Item() {}

    double GetInvNumber() { return this->invNumber; }
    bool GetTaken() { return this->taken; }
    double SetInvNumber(double invNumber) { this->invNumber = invNumber; }
    bool SetTaken(bool taken) { this->taken = taken; return taken; }

    virtual void Show() = 0; //показать  информацию о единице хранения
    bool isAvailable() { return this->taken; }; // есть ли единица хранения в наличии ?
    void Take(); //  операция «взять»
    void Return(); //  операция «вернуть»    
};

class Book : public Item {
protected:
    string author;
    string title;
    string publisher;
    int year;
public:
    Book();
    ~Book() {}

    string Author() { return this->author; }
    string Title() { return this->title; }
    string Publisher() { return this->publisher; }
    int YearOfPublishing() { return this->year; }
    string SetAuthor(string author) { this->author = author; }
    string SetTitle(string title) { this->title = title; }
    string SetPublisher(string publisher) { this->publisher = publisher; }
    int SetYear(int year) { this->year = year; }


    void Show();
};

class Magazin : public Item {
protected:
    int volume; //кол-во страниц
    int number; //тираж
    int year; 
    string title;
public:
    Magazin();
    ~Magazin() {}

    int Volume() { return this->volume; }
    string Title() { return this->title; }
    int Number() { return this->number; }
    int Year() { return this->year; }
    int SetVolume(int volume) { this->volume = volume; }
    string SetTitle(string title) { this->title = title; }
    int SetNumber(int number) { this->number = number; }
    int SetYear(int year) { this->year = year; }

    void Show();
};