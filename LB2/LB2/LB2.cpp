#include </Мехмат/___ПРОГА/___ПРОГА/myfunctions.h>
#include <vector>
#include <iostream>
#include <windows.h>

using namespace std;

void Menu();
void Enter(vector<Complex>&);
void Display(vector<Complex>&);
int MenuText();
void Test();
void EnterComplexVectors(vector<vector<Complex>>&);
void DisplayComplexVectors(vector<vector<Complex>>&);
void AddComplexVectors(vector<vector<Complex>>&);
void DisplayComplexVector(vector<Complex>&);


int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    setlocale(LC_CTYPE, "rus");
    Menu();
}

void Menu()
{
    vector<Complex> group;
    vector<vector<Complex>> vectorGroup;
    enum
    {
        Enter_c = 1,
        Display_c,
        Test_c,
        Clear,
        EnterComplexVector_c,
        DisplayComplexVector_c,
        AddComplexVector_c,
        Exit
    };
    bool k = 1;
    while (k)
    {
        switch (MenuText())
        {
        case Exit: 
            k = 0;
            break;
        case Enter_c:
            Enter(group);
            break;
        case Display_c:
            Display(group);
            break;
        case Test_c:
            Test();
            break;
        case Clear:
            group.clear();
            break;
        case EnterComplexVector_c:
            EnterComplexVectors(vectorGroup);
            break;
        case DisplayComplexVector_c:
            DisplayComplexVectors(vectorGroup);
            break;
        case AddComplexVector_c:
            AddComplexVectors(vectorGroup);
            break;
        default:
            cout << "Ошибка! Введите число от 1 до 8!";
            break;
        }
    }
}

int MenuText()
{
    int key;
    cout << "\nЧто Вы хотите сделать?"
         <<"\n>> 1. Ввести комлпексное число"
         <<"\n>> 2. Вывести число на экран"
         <<"\n>> 3. Провести операции над числами"
         <<"\n>> 4. Очистить информацию"
         <<"\n>> 5. Ввести комплексный вектор"
         <<"\n>> 6. Вывести вектор на экран"
         <<"\n>> 7. Сложить комплексные векторы" 
         <<"\n>> 8. Выйти\n>> ";
    cin >> key;
    return key;
}

void Enter(vector<Complex>& group)
{
    int k = 1;
    while (k)
    {
        Complex buffComplex;
        buffComplex.EnterComplex();
        group.push_back(buffComplex);
        cout << "Вы желаете ввести еще одно число? "
            << "\n1. Да"
            << "\n0. Нет\n";
        cin >> k;
        if (!(k == 1) && !(k == 0))
        {
            cout << "Ошибка! Введите число от 0 до 1!";
            cin >> k;
        }
        if (k==0)
            return;
    }
}

void Display(vector<Complex>& group)
{
    cout << endl;
    for (size_t i = 0; i < group.size(); i++)
    {
        cout << "#" << i + 1 << " ";
        group[i].Display();
        cout << ";\n";
    }
}

void Test()
{
    double x1 = 0, x2 = 0, y1 = 0, y2 = 0;
    cout << "Введите действительную часть комплексного числа А: ";
    cin >> x1;
    cout << "Введите мнимую часть комплексного числа А: ";
    cin >> y1;
    cout << "Введите действительную часть комплексного числа В: ";
    cin >> x2;
    cout << "Введите мнимую часть комплексного числа В: ";
    cin >> y2;

    Complex a(x1, y1);
    cout << "A >> ";
    a.Display();
    cout << endl;
    Complex b(x2, y2);
    cout << "B >> ";
    b.Display();
    cout << endl;
    Complex c = a + b;
    cout << "A + B >> ";
    c.Display();
    cout << endl;
    c = a - b;
    cout << "A - B >> ";
    c.Display();
    cout << endl;
    c = a * b;
    cout << "A * B >> ";
    c.Display();
    cout << endl;
    c = a / b;
    cout << "A / B >> ";
    c.Display();
    cout << endl;
}


void EnterComplexVectors(vector<vector<Complex>>& vectorGroup)
{
    int k = 1, t = 1;
    while (k)
    {
        cout << "Вы желаете ввести вектор?"
            << "\n1. Да"
            << "\n0. Нет\n";
        cin >> k;
        if (!(k == 1) && !(k == 0))
        {
            cout << "Ошибка! Введите либо 0 либо 1!";
            cin >> k;
        }
        if (k == 0)
            return;
        vector<Complex> buffVector;
        while (k)
        {
            Complex buffComplex;
            buffComplex.EnterComplex();
            buffVector.push_back(buffComplex); //Для добавления элементов в вектор
            cout << "Вы желаете ввести комплексное число? "
                << "\n1. Да"
                << "\n0. Нет\n";
            cin >> k;
            if (!(k == 1) && !(k == 0))
            {
                cout << "Ошибка! Введите либо 0 либо 1!";
                cin >> k;
            }
            if (k == 0)
                break;
        }
        vectorGroup.push_back(buffVector);
    }
}

void DisplayComplexVectors(vector<vector<Complex>>& vectorGroup)
{
    for (size_t i = 0; i < vectorGroup.size(); i++)
    {
        cout << "\nКомплексный вектор #" << i + 1 << ":\n";
        cout << "(";
        for (size_t j = 0; j < vectorGroup[i].size(); j++)
        {
            if (j == vectorGroup[i].size() - 1)
            {
                vectorGroup[i][j].Display();
                break;
            }
            else
            {
                vectorGroup[i][j].Display();
                cout << ", ";
            }
        }
        cout << ")\n";
    }
}

void AddComplexVectors(vector<vector<Complex>>& vectorGroup)
{
    int vectorIndex1 = 0, vectorIndex2 = 0;
    while (true)
    {
        while (true)
        {
            cout << "\nВведите индексы векторов, которые вы хотите добавить"
                 << "\n(Введите число от 1 до " << vectorGroup.size() <<")"
                 << "\nВведите 0, чтобы выйти"
                 << "\nПервый индекс: ";
            cin >> vectorIndex1;
            if (vectorIndex1 == 0) return;
            if (vectorIndex1 > vectorGroup.size() || vectorIndex1 <= 0)
            {
                cout << "Ошибка! Введите верный индекс!\n";
                continue;
            }
            vectorIndex1--;

            cout << "\nВторой индекс: ";
            cin >> vectorIndex2;
            if (vectorIndex2 == 0) return;
            if (vectorIndex2 > vectorGroup.size() || vectorIndex2 <= 0)
            {
                cout << "Ошибка! Введите верный индекс!\n";
                continue;
            }
            vectorIndex2--;
            break;
        }

        vector<Complex> addGroup;
        for (size_t i = 0; i < vectorGroup[vectorIndex1].size(); i++)
        {
            addGroup.push_back(vectorGroup[vectorIndex1][i] + vectorGroup[vectorIndex2][i]);
        }
        cout << "\nРезультат сложения: \n";
        cout << "#1: ";
        DisplayComplexVector(vectorGroup[vectorIndex1]);
        cout << "#2: ";
        DisplayComplexVector(vectorGroup[vectorIndex2]);
        cout << "IS: ";
        DisplayComplexVector(addGroup);

        int k = 1;
        while (k)
        {
            cout << "\nВы желаете ввести еще один комплексный вектор? "
                << "\n1. Да"
                << "\n0. Нет\n";
            cin >> k;
            if (!(k == 1) && !(k == 0))
            {
                cout << "Ошибка! Введите либо 0 либо 1!";
                cin >> k;
            }
            if (k == 0) return;
        }
    }
}

void DisplayComplexVector(vector<Complex>& buffGroup)
{
    cout << "(";
    for (size_t j = 0; j < buffGroup.size(); j++)
    {
        if (j == buffGroup.size() - 1)
        {
            buffGroup[j].Display();
            break;
        }
        else
        {
            buffGroup[j].Display();
            cout << ", ";
        }
    }
    cout << ")\n";
}