#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <string>
#include <cmath>
#include <map>
using namespace std;

int Ex1_a(string str) // использовала сложение вместо умножения
{
    int answ_a = 0;
    char letter;
    for (int i = 0; i < str.size(); i++)
    {
        letter = str[i];
        answ_a += static_cast<int>(letter);
    }
    return answ_a;
}

void Ex1_b(string str, int* answ)
{
    char letter;
    //обнуляем массив answ
    for (int i = 0; i < 26; i++)
    {
        answ[i] = 0;
    }
    
    // заполняем массив с количествами букв в строке
    for (int i = 0; i < 100; i++)
    {
        letter = str[i];
        if (letter >= 65 && letter <= 90) letter += 32;
        answ[int(letter) - 97] += 1;
    }
    
}

void Ex1_c(const char* name, int* answ)
{
    ifstream f;
    f.open(name);

    int exp1[50] = {}; //массив значений из функции (а)
    int exp2[50][26] = {};//матрица из массивов функции (б)
    
    for (int j = 0; j < 50; j++) //заполняем массивы exp1, exp2
    {
        //считываем строку из ста символов
        string str;
        for (int i = 0; i < 100; i++)
        {
            str += f.get();
        }

        exp1[j] = Ex1_a(str); //заполняем exp1
        
        int ex_b[26] = {};
        Ex1_b(str, ex_b);
        // выведем все строки с их результатами функций
        cout << "\n" << j << ")\n" << str << "\na)" << exp1[j] << "\nb)";

        for (int t = 0; t < 26; t++) //заполняем exp2
        {
            exp2[j][t] = ex_b[t];
            cout << ex_b[t] << " ";
        }
        cout << "\n--------\n";
    }

    //сравниваем
    int cnt1 = 0; //счетчик коллизий функции (а)
    for (int i = 0; i < 49; i++)
    {
        for (int j = i + 1; j < 50; j++)
        {
            if (exp1[i] == exp1[j])
            {
                cnt1 += 1;                
            }
        }
    }

    int cnt2 = 0; // счетчик коллизий функции (б)
    int cnt = 0;
    for (int i = 0; i < 49; i++)
    {
        for (int j = 0; j < 26; j++)
        {
            if (exp2[i][j] == exp2[i + 1][j]) cnt++;
        }
        if (cnt == 26) cnt2++;
        cnt = 0;
    }

    answ[0] = cnt1;
    answ[1] = cnt2;
    f.close();

}

int main()
{
    setlocale(LC_ALL, "RUS");
    string str;
    ifstream f;
    f.open("C://Users//Рената//Desktop//Pride and Prejudice.txt");


    for (int i = 0; i < 100; i++)
    {
        str += f.get();
    }
    
    int ex1_a = Ex1_a(str);
    cout << "Ex 1a:\n" << ex1_a;
    int ex1_b[26] = {};

    Ex1_b(str, ex1_b);
    cout << "\nEx 1b: \n";
    for (int i = 0; i < 26; i++)
    {
        cout << ex1_b[i] << " ";
    }
    
    int ex1_c[2] = {}; //ответ на №1с
    Ex1_c("C://Users//Рената//Desktop//Pride and Prejudice.txt", ex1_c);

    cout << "\nEx 1c: \n1) " << ex1_c[0] << "\n2) " << ex1_c[1];

    f.close();
}
