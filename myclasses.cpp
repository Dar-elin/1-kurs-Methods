#include "myclasses.h"
using namespace std;


Vehicle::Vehicle() {
	cout << "������� ���������� �����: ";
	cin >> wheel;
	cout << "������� ���������� ������������ ����: ";
	cin >> people;
	cout << "������� ������� ��������: ";
	cin >> speed;
	int k = 1;
	while (k)
	{
		cout << "������� ������������ �� ����� �� 1 �� 5: "
			<< "\n1. ����� ���������"
			<< "\n2. ���������"
			<< "\n3. ������"
			<< "\n4. �����������"
			<< "\n5. ������ �����������\n";
		cin >> comfort;
		k = 0;
		if (!(comfort == 1) && !(comfort == 2) && !(comfort == 3) && !(comfort == 4) && !(comfort == 5))
		{
			cout << "������! �������� ������! ������� ����� �� 1 �� 5!\n";
			k = 1;
		}
	}
	cin.ignore(3267, '\n');
	cout << "������� ����: ";
	getline(cin, color);
}

Car::Car() : Vehicle() {
	//cin.ignore(3267, '\n');
	cout << "������� ������: ";
	getline(cin, model);
}

void Car::Show()
{
	cout << "\n���������� �����: " << GetWheel();
	cout << "\n���������� ������������ ����:" << GetPeople();
	cout << "\nC������ ��������: " << GetSpeed();
	cout << "\n������������: ";
	switch (GetComfort())
	{
	case 1:  
		cout << "����� ���������";
		break;
	case 2:  
		cout << "���������";
		break;
	case 3:  
		cout << "������";
		break;
	case 4:  
		cout << "�����������";
		break;
	case 5:  
		cout << "������ �����������";
		break;
	}
	cout << "\n����: " << GetColor();
	cout << "\n������: " << GetModel();
}

Bicycle::Bicycle() : Vehicle() 
{
	int k = 1;
	while (k)
	{
		cout << "�������, ���� �� ��������: "
			<< "\n0. ���"
			<< "\n1. ����";
		cin >> basket;
		k = 0;
		if (!(basket == 1) && !(basket == 0))
		{
			cout << "������! �������� ������! ������� ���� 0 ���� 1!\n";
			k = 1;
		}
	}
}

void Bicycle::Show()
{
	cout << "\n���������� �����: " << GetWheel();
	cout << "\n���������� ������������ ����:" << GetPeople();
	cout << "\nC������ ��������: " << GetSpeed();
	cout << "\n����: " << GetColor();
	cout << "\n��������: ";
	switch (GetBasket())
	{
	case 1:
		cout << "����";
		break;
	case 0:
		cout << "���";
		break;
	}
}

Cart::Cart() : Vehicle()
{
	cout << "������� ���������� �������: ";
	cin >> horses;
	int k = 1;
	/*while (k)
	{
		cout << "�������, ���� �� �����: "
			<< "\n0. ���"
			<< "\n1. ����";
		cin >> coachman;
		k = 0;
		if (!(coachman == 1) && !(coachman == 0))
		{
			cout << "������! �������� ������! ������� ���� 0 ���� 1!";
			k = 1;
		}
	}
	if (coachman == 1)
	{
		cin.ignore(3267, '\n');
		cout << "������� ��� ������: ";
		getline(cin, name);
	}*/
	cout << "������� ��� ������: ";
	cin.ignore(3267, '\n');
	getline(cin, name);
}

void Cart::Show()
{
	cout << "\n���������� �����: " << GetWheel();
	cout << "\n���������� ������������ ����:" << GetPeople();
	cout << "\nC������ ��������: " << GetSpeed();
	cout << "\n����: " << GetColor();
	cout << "\n���������� �������: " << GetHorses();
	cout << "\n�����: " << GetName();
	//cout << "\n�����: ";
	/*if (Get�oachman() == 1)
	{
		cout << "����";
		cout << "\n��� ���:" << GetName();
	}
	else cout << "���";*/
	/*switch (Get�oachman())
	{
	case 1:
		cout << "����";
		cout << "\n��� ���:" << GetName();
		break;
	case 0:
		cout << "���";
		break;
	}*/
}

Item::Item() {
	cout << "������� ����������� �����: ";
	cin >> invNumber;
	bool k = 1;
	while (k)
	{
		cout << "������� ���������: "
			<< "\n0. ����� �� ����"
			<< "\n1. ������� � �������\n";
		cin >> taken;
		k = 0;
		if (!(taken == 1) && !(taken == 0))
		{
			cout << "������! �������� ������! ������� ���� 0 ���� 1!\n";
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
	cout << "������� ������: ";
	cin.ignore(3267, '\n');
	getline(cin, author);
	cout << "������� �������� ������������: ";
	getline(cin, title);
	cout << "������� ������������: ";
	getline(cin, publisher);
	cout << "������� ��� �������: ";
	cin >> year;
}

void Book::Show()
{
	cout << "\n������������ �����: " << GetInvNumber();
	cout << "\n������� �� � �������: ";
	switch (isAvailable())
	{
	case 0:
		cout << "��� � �������";
		break;
	case 1:
		cout << "���� � �������";
		break;
	}
	cout << "\n�����: " << Author();
	cout << "\n��������: " << Title();
	cout << "\n������������: " << Publisher();
	cout << "\n��� �������: " << YearOfPublishing();
}

Magazin::Magazin() : Item() {
	cout << "������� ���������� �������: ";
	cin >> volume;
	cout << "������� �������� �������: ";
	cin.ignore(3267, '\n');
	getline(cin, title);
	cout << "������� ����� (���-�������): ";
	cin >> number;
	cout << "������� ��� �������: ";
	cin >> year;
}

void Magazin::Show()
{
	cout << "\n������������ �����: " << GetInvNumber();
	cout << "\n������� �� � �������: ";
	switch (isAvailable())
	{
	case 0:
		cout << "��� � �������";
		break;
	case 1:
		cout << "���� � �������";
		break;
	}
	cout << "\n���������� �������: " << Volume();
	cout << "\n��������: " << Title();
	cout << "\n����� (���-�������): " << Number();
	cout << "\n��� �������: " << Year();
}