#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <string>
#include <cmath>
#include <map>
using namespace std;

void bubble(int* a, int n) {
   int k;
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - 1; j++) {
            if (a[j] < a[j + 1]) {
                k = a[j];
                a[j] = a[j + 1];
                a[j + 1] = k;
            }
        }
    }
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

string Ex2_a(string str) // шифровка методом сдвига вправо на 5
{
    char letter;
    for (int i = 0; i < 100; i++)
    {
        letter = str[i];
        if (letter >= 65 && letter <= 90) letter += 32;
        if ( letter >96 && letter < 123) str[i] = letter + 5;
    }
    return str;
}

string Ex2_b(string str) // дешифровка
{
    char letter;
    for (int i = 0; i < 100; i++)
    {
        letter = str[i];
        if (letter > 101 && letter < 128) str[i] = letter - 5;
        //str[i] = letter-5;
    }
    return str;
}

void Ex2_c(string str) // сверка частотности символов
{
    int statistic[31] = {};
    char letter;
    int sortstat[31] = {};
    Ex1_b(str, statistic);
    

    int max1, max2, max3; // три максимальных числа в массиве statistic
    for (int i = 0; i < 26; i++)
    {
        sortstat[i] = statistic[i];
    }
    
    bubble(sortstat, 26);
    max1 = sortstat[0];
    max2 = sortstat[1];
    max3 = sortstat[2];
    int k;

    string newstr;
    k = 0;
    string signs = ";";
    for (int i = 0; i < 100; i++)
    {
        letter = str[i];
        newstr.push_back(str[i]);
        if (statistic[letter - 97] != max1 && statistic[letter - 97] !=max2 && statistic[letter - 97]!= max3)
        {
            newstr.push_back(str[i]);
        }
    }
    cout << newstr;
    Ex1_b(newstr, statistic);
    cout << "\nНОВАЯ статистика букв: \n";
    for (int i = 0; i < 31; i++)
    {
        cout << statistic[i] << " ";
    }
     
}
    
void stat(string str)
{
    int statistic[31] = {};
    char letter;
    int sortstat[31] = {};
    Ex1_b(str, statistic);
    cout << "\nстатистика букв: \n";
    for (int i = 0; i < 31; i++)
    {
        cout << statistic[i] << " ";
    }
}
int main()
{
    setlocale(LC_ALL, "RUS");
    string str;
    ifstream f;
    f.open("C://Users//Рената//Desktop//Pride and Prejudice.txt");

    string key = "qazxswedcvfrtgbnhyujmkiolp";
    
    for (int i = 0; i < 100; i++)
    {
        str += f.get();
    }

    cout <<"строка: \n" << str;
    stat(str);

    str = Ex2_a(str);
    cout <<"\n-----------------\nстрока после шифрования:\n" << str;
    stat(str);

    str = Ex2_b(str);
    cout << "\n-----------------\nстрока после дешифровки: \n" << str;

    cout << "\n-----------------\nпосле борьбы со статистическими неравномерностями\n\n";
    Ex2_c(str);
    

    f.close();
}

