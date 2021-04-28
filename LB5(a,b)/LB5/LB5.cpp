#include <\Мехмат\___ПРОГА\___ПРОГА\myfunctions.h>
#include <\Мехмат\___ПРОГА\___ПРОГА\myclasses.h>
#include <iostream>
#include <windows.h>

using namespace std;

void MyBook();
void MyMagazin();
int Choise();

int main() {
	setlocale(LC_CTYPE, "Rus");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	cout << "Добро пожаловать!\n";
	try {
		while (true) {
			cout << "\nКакая у вас единица хранения?\n";
			cout << "1. Книга\n";
			cout << "2. Журнал\n";
			cout << "Ваш ответ: ";
			int answer;
			cin >> answer;
			switch (answer) {
			case 1:
				MyBook();
				break;
			case 2:
				MyMagazin();
				break;
			default:
				cout << "\nНет такого варианта ответа.\n";
			}
			cout << "\nХотите продолжить?\n";
			cout << "1. Да.\n";
			cout << "2. Нет.\n";
			int choise;
			while (true) {
				cout << "Ваш выбор: ";
				cin >> choise;
				if (choise == 1 || choise == 2) break;
				else cout << "\nВы можете ввести только 1 или 2.\n";
			}
			if (choise == 2) return 0;
		}
	}
	catch (const char* ex) {
		cout << ex;
	}
}

void MyBook() {
	Book book;
	book.Show();

	switch (book.isAvailable()) {
	case 0:
		cout << "\nЖелаете вернуть книгу?";
		cout << "\n1. Да.";
		cout << "\n2. Нет.";
		switch (Choise())
		{
			case 1:
				book.Return();
				cout << "Вы вернули данную книгу!";
				break;
			case 2:
				break;
		}
		break;
	case 1:
		cout << "\nЖелаете взять книгу?";
		cout << "\n1. Да.";
		cout << "\n2. Нет.";
		switch (Choise())
		{
		case 1:
			book.Take();
			cout << "\nВы взяли данную книгу!";
			break;
		case 2:
			break;
		}
		break;
	default:
		cout << "\nНет такого варианта ответа.\n";
	}
}

int Choise()
{
	int choise;
	while (true) {
		cout << "Ваш выбор: ";
		cin >> choise;
		if (choise == 1 || choise == 2) break;
		else cout << "\nВы можете ввести только 1 или 2.\n";
	}
	return choise;
}

void MyMagazin() {
	Magazin magazine;
	magazine.Show();
	switch (magazine.isAvailable()) {
	case 0:
		cout << "\nЖелаете вернуть журнал?";
		cout << "\n1. Да.";
		cout << "\n2. Нет.";
		switch (Choise())
		{
		case 1:
			magazine.Return();
			cout << "Вы вернули данный журнал!";
			break;
		case 2:
			break;
		}
		break;
	case 1:
		cout << "\nЖелаете взять журнал?";
		cout << "\n1. Да.";
		cout << "\n2. Нет.";
		switch (Choise())
		{
		case 1:
			magazine.Take();
			cout << "\nВы взяли данный журнал!";
			break;
		case 2:
			break;
		}
		break;
	default:
		cout << "\nНет такого варианта ответа.\n";
	}
}