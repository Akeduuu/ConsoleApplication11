
#include <stdio.h>
#include <conio.h>
#include <iostream>
#include <string.h>
#include <windows.h>
using namespace std;

HANDLE H = GetStdHandle(STD_OUTPUT_HANDLE);

class String
{
private:
    char* string;
public:
    String() //По умолчанию.
    {
        int size = 80;
        string = new char[size];
    }
    String(char* string)
    {
        string = new char[];
    }
    void Initialization()
    {
        cout << "Введите строку: ";
        gets(string);
        system("cls");
        ChoiseShowString();
    }
    void ChoiseShowString()
    {
        int choiseshowstring;
        cout << "Показать строку?\n\n"
            << "1 - Да. \n"
            << "2 - Выйти.\n\n";
        cout << "Введите ваш выбор: ";
        cin >> choiseshowstring;
        if (choiseshowstring == 1)
        {
            ShowString();
        }
        else if (choiseshowstring == 2)
        {
            exit(0);
        }
        else
        {
            system("cls");
            cout << "Не верный ввод, повторите выбор!\n\n";
            ChoiseShowString();
        }
    }
    void ShowString()
    {
        system("cls");
        OemToAnsi(string, string);
        cout << "Строка: " << string << endl << endl;
    }
    ~String()
    {
        delete[] string;
    }
};

void Stand(int x, int y, int key, char* str)
{
    CONSOLE_CURSOR_INFO ci; ci.bVisible = 0; ci.dwSize = 100; SetConsoleCursorInfo(H, &ci);
    COORD c;
    c.X = x; c.Y = y;
    SetConsoleCursorPosition(H, c);
    SetConsoleTextAttribute(H, key);
    cout << str << "\n";
}
void main()
{
    system("mode con cols=30 lines=10");
    system("title String");
    setlocale(LC_ALL, "RUS");
    String s;
    Stand(5, 1, 10, "FAQ о задании \"String\"");
    Stand(5, 3, 2, "Произвольная строка");
    Stand(5, 5, 2, "Создать строку");
    Stand(5, 7, 2, "Выход");

    int key;
    int punkt = 1;

    while (1)
    {
        key = getch();
        if (key == 80)
        {
            if (punkt < 4)
            {
                punkt++;
                if (punkt == 2)
                {
                    Stand(5, 1, 2, "FAQ о задании \"String\"");
                    Stand(5, 3, 10, "Произвольная строка");
                }
                else if (punkt == 3)
                {
                    Stand(5, 3, 2, "Произвольная строка");
                    Stand(5, 5, 10, "Создать строку");
                }
                else if (punkt == 4)
                {
                    Stand(5, 5, 2, "Создать строку");
                    Stand(5, 7, 10, "Выход");
                }
            }
        }
        else if (key == 72)
        {
            if (punkt > 1)
            {
                punkt--;
                if (punkt == 3)
                {
                    Stand(5, 5, 10, "Создать строку");
                    Stand(5, 7, 2, "Выход");
                }
                else if (punkt == 2)
                {
                    Stand(5, 3, 10, "Произвольная строка");
                    Stand(5, 5, 2, "Создать строку");
                }
                else if (punkt == 1)
                {
                    Stand(5, 1, 10, "FAQ о задании \"String\"");
                    Stand(5, 3, 2, "Произвольная строка");
                }
            }
        }
        else if (key == 13)
        {
            system("cls");
            SetConsoleTextAttribute(H, 15);
            if (punkt == 1)
            {
                system("title FAQ о задании \"String\"");
                system("mode con cols=43 lines=23");
                SetConsoleTextAttribute(H, 10);
                cout << "\n  Разработать класс String, который в \n  дальнейшем будет использоваться для \n\t работы со строками.\n\n";
                SetConsoleTextAttribute(H, 14);
                cout << "\tКласс должен содержать:\n\n";
                SetConsoleTextAttribute(H, 15);
                cout << " - конструктор по умолчанию, позволяющий \n   создать строку длиной 80 символов.\n\n"
                    << "      - конструктор, позволяющий \n  создавать строку произвольного размера.\n\n"
                    << "  - конструктор, который создаёт строку и \n  инициализирует её строкой, полученной от \t\tпользователя.\n\n"
                    << "   - методы для ввода строк с клавиатуры \n        и вывода строк на экран.\n\n";
                SetConsoleTextAttribute(H, 11);
            }
            else if (punkt == 2)
            {
                system("title String произв. размера");
                system("mode con cols=43 lines=13");

                String b();
                s.Initialization();
            }
            else if (punkt == 3)
            {
                cout << "Создать строку!\n\n";
                getch();
            }
            else if (punkt == 4)
            {
                DWORD size = 1024;
                char buf[1024];
                GetUserNameA(buf, &size);
                SetConsoleTextAttribute(H, 11);
                system("mode con cols=30 lines=6");
                SetConsoleTextAttribute(H, 14);
                system("title До свидания!");
                cout << "   До свидания ув. " << buf << endl << endl << "   ";
                SetConsoleTextAttribute(H, 11);
            }
            else
            {
                cout << "До свидания!\n\n";
                getch();
            }
            exit(0);
        }
    }

}