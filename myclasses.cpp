#include "myclasses.h"
using namespace std;


Vehicle::Vehicle() {
	cout << "Введите количество колес: ";
	cin >> wheel;
	cout << "Введите количество пассажирских мест: ";
	cin >> people;
	cout << "Введите среднюю скорость: ";
	cin >> speed;
	int k = 1;
	while (k)
	{
		cout << "Введите комфортность по шкале от 1 до 5: "
			<< "\n1. Очень комфортно"
			<< "\n2. Комфортно"
			<< "\n3. Средне"
			<< "\n4. Некомфортно"
			<< "\n5. Сильно некомфортно\n";
		cin >> comfort;
		k = 0;
		if (!(comfort == 1) && !(comfort == 2) && !(comfort == 3) && !(comfort == 4) && !(comfort == 5))
		{
			cout << "Ошибка! Неверные данные! Введите число от 1 до 5!\n";
			k = 1;
		}
	}
	cin.ignore(3267, '\n');
	cout << "Введите цвет: ";
	getline(cin, color);
}

Car::Car() : Vehicle() {
	//cin.ignore(3267, '\n');
	cout << "Введите модель: ";
	getline(cin, model);
}

void Car::Show()
{
	cout << "\nКоличество колес: " << GetWheel();
	cout << "\nКоличество пассажирских мест:" << GetPeople();
	cout << "\nCредняя скорость: " << GetSpeed();
	cout << "\nКомфортность: ";
	switch (GetComfort())
	{
	case 1:  
		cout << "Очень комфортно";
		break;
	case 2:  
		cout << "Комфортно";
		break;
	case 3:  
		cout << "Средне";
		break;
	case 4:  
		cout << "Некомфортно";
		break;
	case 5:  
		cout << "Сильно некомфортно";
		break;
	}
	cout << "\nЦвет: " << GetColor();
	cout << "\nМодель: " << GetModel();
}

Bicycle::Bicycle() : Vehicle() 
{
	int k = 1;
	while (k)
	{
		cout << "Укажите, есть ли корзинка: "
			<< "\n0. Нет"
			<< "\n1. Есть";
		cin >> basket;
		k = 0;
		if (!(basket == 1) && !(basket == 0))
		{
			cout << "Ошибка! Неверные данные! Введите либо 0 либо 1!\n";
			k = 1;
		}
	}
}

void Bicycle::Show()
{
	cout << "\nКоличество колес: " << GetWheel();
	cout << "\nКоличество пассажирских мест:" << GetPeople();
	cout << "\nCредняя скорость: " << GetSpeed();
	cout << "\nЦвет: " << GetColor();
	cout << "\nКорзинка: ";
	switch (GetBasket())
	{
	case 1:
		cout << "Есть";
		break;
	case 0:
		cout << "Нет";
		break;
	}
}

Cart::Cart() : Vehicle()
{
	cout << "Введите количество лошадей: ";
	cin >> horses;
	int k = 1;
	/*while (k)
	{
		cout << "Укажите, есть ли кучер: "
			<< "\n0. Нет"
			<< "\n1. Есть";
		cin >> coachman;
		k = 0;
		if (!(coachman == 1) && !(coachman == 0))
		{
			cout << "Ошибка! Неверные данные! Введите либо 0 либо 1!";
			k = 1;
		}
	}
	if (coachman == 1)
	{
		cin.ignore(3267, '\n');
		cout << "Введите имя кучера: ";
		getline(cin, name);
	}*/
	cout << "Введите имя кучера: ";
	cin.ignore(3267, '\n');
	getline(cin, name);
}

void Cart::Show()
{
	cout << "\nКоличество колес: " << GetWheel();
	cout << "\nКоличество пассажирских мест:" << GetPeople();
	cout << "\nCредняя скорость: " << GetSpeed();
	cout << "\nЦвет: " << GetColor();
	cout << "\nКоличество лошадей: " << GetHorses();
	cout << "\nКучер: " << GetName();
	//cout << "\nКучер: ";
	/*if (GetСoachman() == 1)
	{
		cout << "Есть";
		cout << "\nЕго имя:" << GetName();
	}
	else cout << "Нет";*/
	/*switch (GetСoachman())
	{
	case 1:
		cout << "Есть";
		cout << "\nЕго имя:" << GetName();
		break;
	case 0:
		cout << "Нет";
		break;
	}*/
}

Item::Item() {
	cout << "Введите инвентарный номер: ";
	cin >> invNumber;
	bool k = 1;
	while (k)
	{
		cout << "Укажите состояние: "
			<< "\n0. Взято на руки"
			<< "\n1. Имеется в наличии\n";
		cin >> taken;
		k = 0;
		if (!(taken == 1) && !(taken == 0))
		{
			cout << "Ошибка! Неверные данные! Введите либо 0 либо 1!\n";
			k = 1;
		}
	}
}


void Item::Take()
{
	SetTaken(0);
}

void  Item::Return()
{
	SetTaken(1);
}

Book::Book() : Item() {
	cout << "Введите автора: ";
	cin.ignore(3267, '\n');
	getline(cin, author);
	cout << "Введите название произведения: ";
	getline(cin, title);
	cout << "Введите издательство: ";
	getline(cin, publisher);
	cout << "Введите год издания: ";
	cin >> year;
}

void Book::Show()
{
	cout << "\nИнвернтарный номер: " << GetInvNumber();
	cout << "\nИмеется ли в наличии: ";
	switch (isAvailable())
	{
	case 0:
		cout << "Нет в наличии";
		break;
	case 1:
		cout << "Есть в наличии";
		break;
	}
	cout << "\nАвтор: " << Author();
	cout << "\nНазвание: " << Title();
	cout << "\nИздательство: " << Publisher();
	cout << "\nГод издания: " << YearOfPublishing();
}

Magazin::Magazin() : Item() {
	cout << "Введите количество страниц: ";
	cin >> volume;
	cout << "Введите название журнала: ";
	cin.ignore(3267, '\n');
	getline(cin, title);
	cout << "Введите тираж (кол-вокопий): ";
	cin >> number;
	cout << "Введите год издания: ";
	cin >> year;
}

void Magazin::Show()
{
	cout << "\nИнвернтарный номер: " << GetInvNumber();
	cout << "\nИмеется ли в наличии: ";
	switch (isAvailable())
	{
	case 0:
		cout << "Нет в наличии";
		break;
	case 1:
		cout << "Есть в наличии";
		break;
	}
	cout << "\nКоличество страниц: " << Volume();
	cout << "\nНазвание: " << Title();
	cout << "\nТираж (кол-вокопий): " << Number();
	cout << "\nГод выпуска: " << Year();
}