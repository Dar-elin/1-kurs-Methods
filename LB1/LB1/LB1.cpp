#include <iostream>
#include <iomanip>
#include <fstream>
#include <conio.h> //для менюшки
#include <string.h>
#include "..\\..\\myfunctions.h"
#include <Windows.h>
using namespace std;

class Student //ФИО, дата рождения, адрес, телефон, факультет, курс  
{
private:
	char surname[32];
	char name[32];
	char midName[32];
	int day;
	int month;
	int year;
	char address[64];
	char tel[14];
	char faculty[64];
	int kurs;
public:
	void set()
	{
		bool b = 1;
		cout << "Введите ФИО";
		cin >> surname >> name >> midName; 
		cout << "Введите дату рождения (дд мм гггг)";
		cin >> day;
		while (b)
		{
			if (day > 31 || day < 1)
			{
				cout << "Ошибка! Введите день рождения!";
				cin >> day;
			}
			else b = 0;
		}
		cin >> month;
		b = 1;
		while (b)
		{
			if (month > 12)
			{
				cout << "Ошибка! Введите месяц рождения!";
				cin >> month;
			}
			else b = 0;
		}
		cin >> year;
		b = 1;
		while (b)
		{
			if (year > 2015 || year < 1920)
			{
				cout << "Ошибка! Введите год рождения!";
				cin >> year;
			}
			else b = 0;
		}
		cout << "Введите адрес";
		cin >> address; 
		cout << "Введите телефон (80...)";
		cin >> tel;
		b = 1;
		while (b)
		{
			if (strncmp(tel, "80", 2))
			{
				cout << "Ошибка! Введите телефон в формате 80...";
				cin >> tel;
			}
			else b = 0;
		}
		cout << "Введите факультет";
		cin >> faculty;
		cout << "Введите курс";
		cin >> kurs;
		b = 1;
		while (b)
		{
			if (kurs > 6)
			{
				cout << "Ошибка! Введите верный курс!";
				cin >> kurs;
			}
			else b = 0;
		}
		
	};
	void set(ifstream& fin, const char* fname, Student* spis, int n)
	{
		fin.open(fname);
		char* s = new char[128];
		for (int i = 0; i < n; i++)
		{
			while (!fin.eof())
			{
				fin >> spis[i].surname >> spis[i].name >> spis[i].midName;
				fin >> s;
				spis[i].day = atoi(s);
				fin >> s;
				spis[i].month = atoi(s);
				fin >> s;
				spis[i].year = atoi(s);
				fin >> spis[i].address;
				fin >> spis[i].tel;
				fin >> spis[i].faculty;
				fin >> s;
				spis[i].kurs = atoi(s);
			}
		}
		fin.close();
		delete[] s;
	};
	void show()
	{
		cout << left << setw(15) << surname << setw(15) << name
			<< setw(15) << midName << setw(8) << day << setw(10) << month << setw(8) << year
			<< setw(15) << address << setw(15) << tel << setw(15) << faculty << setw(2) << kurs << endl;
	};
	char* getfac() { return faculty; };
	int getkurs() { return kurs; };
	int getyear() { return year; };
};

int menu(); 
void showSH();
void Spisfaculty(Student* spis, int n);
void SpisFacultyKurs(Student* spis, int n);
void SpisBornAfterYear(Student* spis, int n);
int myinput(char* s,                //s - строка, принимающая данные
	const char* fname,      //fname - имя файла
	const char  sep);

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	setlocale(LC_CTYPE, "rus");
	Student* spis;
	int n=0, k=1;
	/*cout << "Введите колличество студентов: ";
	cin >> n;*/
	ifstream fin;
	char fname[36]="Список.txt";
	const int maxlen = 128;
	cout << "Открытие файла " << fname << endl;
	fin.open(fname);
	if (!fin.is_open())
		cout << "Ошибка открытия файла " << fname << endl;
	char* tmp = new char[1024];
	n = myinput(tmp, fname, '\0');
	spis = new Student[n];
	spis->set(fin, fname, spis, n);
	delete[] tmp;
	fin.close();
	while (k)
	{
		switch (menu())
		{
		case 1:
			Spisfaculty(spis, n);
			break;
		case 2:
			SpisFacultyKurs(spis, n);
			break;
		case 3:
			SpisBornAfterYear(spis, n);
			break;
		case 4:
			k = 0;
			break;
		}
	}
	delete[] spis;
	cout << endl;
	return 0;
}

int menu()
{
	int k, tr = 1;
	while (tr)
	{
		cout << "Что Вы хотите сделать? \n"
			<< "1. Вывести список студентов заданного факультета\n"
			<< "2. Вывести списки студентов для каждого факультета и курса\n"
			<< "3. Вывести список студентов, родившихся после заданного года\n"
			<< "4. Выход" << endl;
		cin >> k;
		if (k != 1 && k != 2 && k != 3 && k != 4) cout << "Ошибка! Введите число от 1 до 4!";
		else
		{
			return k;
			tr = 0;
		}
	}
}

void showSH()
{
	cout << left << setw(15) << "Фамилия" << setw(15) << "Имя"
		<< setw(15) << "Отчество" << setw(8) << "День" << setw(10) << "Месяц" << setw(8) << "Год"
		<< setw(15) << "Адрес" << setw(15) << "Телефон" << setw(15) << "Факультет" << setw(2) << "Курс" << endl;
};
void Spisfaculty(Student* spis, int n) //список студентов заданного факультетата
{
	char faculty[64];
	cout << "Введите название факультета:";  
	cin >> faculty;
	showSH();
	for (int i = 0; i < n; i++)
		if (strcmp(spis[i].getfac(), faculty) == 0)spis[i].show();
}
void SpisFacultyKurs(Student* spis, int n) //список студентов заданных факультета и курса
{
	int k;
	char faculty[64];
	cout << "Введите название факультета:";
	cin >> faculty;
	cout << "Введите номер курса:";  cin >> k;
	showSH();
	for (int i = 0; i < n; i++)
		if ((strcmp(spis[i].getfac(), faculty) == 0) && (spis[i].getkurs() == k))
			spis[i].show();
}
void SpisBornAfterYear(Student* spis, int n) //список студентов, родившихся после заданного года
{
	int year;
	cout << "Введите год:";
	cin >> year;
	showSH();
	for (int i = 0; i < n; i++)
		if (spis[i].getyear() >= year)spis[i].show();
}
int myinput(char* s,                //s - строка, принимающая данные
	const char* fname,      //fname - имя файла
	const char  sep)        //sep - разделитель строк ('\n' по умолчанию)
{
	ifstream fin;                   //объявляем fin - поток данных из файла
	fin.open(fname, ios_base::in);   //связываем поток fin с файлом fname
	const int nt = 256; char t[nt];   //t - для ввода одной строки файла

	int nstr = 0, ln = 0;               //обнуляем счетчик строк и текущую длину строки s
	for (; !fin.eof(); nstr++) {        //цикл выполняется, пока не достигнут конец файла
		fin.getline(t, nt);        //читаем в t текущую строку файла
		#pragma warning(suppress : 4996)
		strcpy(s + ln, t); ln += strlen(t);//добавляем в конец s строку t
		s[ln] = sep; ln++; s[ln] = '\0';//добавляем в конец s разделитель sep
	}
	// Если в конце текста была пустая строка, удаляем ее
	if (s[ln - 2] == sep) { s[ln - 1] = '\0'; nstr--; }
	// Закрываем поток fin и возвращаем количество считанных строк
	fin.close(); return nstr;
}
