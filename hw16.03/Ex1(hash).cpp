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

//РЕЗУЛЬТАТЫ ВЫВОДА
/*
Ex 1a:
9198
Ex 1b:
8 0 2 3 7 2 3 3 6 0 1 4 1 7 7 2 0 4 7 7 3 1 1 0 1 0
0)
Chapter 1

It is a truth universally acknowledged, that a single man in possession of a good fortune
a)9198
b)8 0 2 3 7 2 3 3 6 0 1 4 1 7 7 2 0 4 7 7 3 1 1 0 1 0
--------

1)
, must be in want of a wife.

However little known the feelings or views of such a man may be on his
a)8860
b)5 2 1 0 10 4 1 4 6 0 1 3 3 7 6 0 0 2 5 5 2 2 5 0 1 0
--------

2)
 first entering a neighbourhood, this truth is so well fixed in the minds of the surrounding familie
a)9455
b)2 1 0 4 8 4 3 6 11 0 0 3 2 7 6 0 0 6 6 7 4 0 1 1 0 0
--------

3)
s, that he is considered the rightful property of some one or other of their daughters.

"My dear Mr
a)9071
b)3 0 1 4 11 3 2 7 4 0 0 1 3 2 8 2 0 10 5 8 2 0 0 0 2 0
--------

4)
. Bennet," said his lady to him one day, "have you heard that Netherfield Park is let at last?"

Mr.
a)8528
b)9 1 0 5 9 1 0 6 5 0 1 4 2 4 3 1 0 4 4 8 1 1 0 0 3 0
--------

5)
 Bennet replied that he had not.

"But it is," returned she; "for Mrs. Long has just been here, and
a)8463
b)4 3 0 4 12 1 1 6 3 1 0 2 1 7 3 1 0 6 5 8 3 0 0 0 0 0
--------

6)
she told me all about it."

Mr. Bennet made no answer.

"Do you not want to know who has taken it?"
a)8451
b)7 2 0 3 7 0 0 3 2 0 2 3 3 8 9 0 0 2 3 9 2 0 4 0 1 0
--------

7)
cried his wife impatiently.

"You want to tell me, and I have no objection to hearing it."

This was
a)8754
b)6 1 2 2 8 1 1 4 10 1 0 3 2 6 6 1 0 2 3 9 1 1 3 0 2 0
--------

8)
 invitation enough.

"Why, my dear, you must know, Mrs. Long says that Netherfield is taken by a you
a)8901
b)6 1 0 2 6 1 2 4 5 0 2 2 3 7 6 0 0 3 5 7 4 1 2 0 6 0
--------

9)
ng man of large fortune from the north of England; that he came down on Monday in a chaise and four
a)8994
b)9 0 2 4 7 5 3 5 2 0 0 2 4 11 9 0 0 5 1 5 2 0 1 0 1 0
--------

10)
to see the place, and was so much delighted with it, that he agreed with Mr. Morris immediately; tha
a)9061
b)7 0 2 5 11 0 2 8 7 0 0 3 5 1 3 1 0 4 4 10 1 0 3 0 1 0
--------

11)
t he is to take possession before Michaelmas, and some of his servants are to be in the house by the
a)9150
b)6 3 1 1 13 2 0 6 5 0 1 1 3 4 8 1 0 3 11 7 1 1 0 0 1 0
--------

12)
 end of next week."

"What is his name?"

"Bingley."

"Is he married or single?"

"Oh!
 Single, my d
a)7706
b)3 1 0 3 10 1 3 4 7 0 1 3 3 6 3 0 0 3 5 2 0 0 2 1 2 0
--------

13)
ear, to be sure!

A single man of large fortune; four or five thousand a year.

What a fine thing fo
a)8678
b)9 1 0 1 9 6 3 3 4 0 0 2 1 6 7 0 0 7 3 5 4 1 1 0 1 0
--------

14)
r our girls!"

"How so?

How can it affect them?"

"My dear Mr. Bennet," replied his wife, "how can
a)8011
b)4 1 3 2 8 3 1 5 5 0 0 2 3 4 5 1 0 6 3 4 1 0 4 0 1 0
--------

15)
you be so tiresome!

You must know that I am thinking of his marrying one of them."

"Is that his de
a)8723
b)4 1 0 1 6 2 2 6 8 0 2 0 5 5 8 0 0 3 6 8 3 0 1 0 3 0
--------

16)
sign in settling here?"

"Design!

Nonsense, how can you talk so!

But it is very likely that he may
a)8618
b)4 1 1 1 9 0 3 4 7 0 2 4 1 8 4 0 0 2 7 7 2 1 1 0 4 0
--------

17)
 fall in love with one of them, and therefore you must visit him as soon as he comes."

"I see no oc
a)8713
b)4 0 2 1 10 3 0 5 6 0 0 3 4 5 10 0 0 2 7 5 2 2 1 0 1 0
--------

18)
casion for that.

You and the girls may go, or you may send them by themselves, which perhaps will b
a)9046
b)6 2 2 2 7 1 2 7 4 0 0 4 4 3 6 2 0 4 6 5 2 1 2 0 5 0
--------

19)
e still better, for as you are as handsome as any of them, Mr. Bingley may like you the best of the
a)8866
b)7 3 0 1 11 3 1 4 3 0 1 4 4 3 6 0 0 4 6 7 2 0 0 0 5 0
--------

20)
party."

"My dear, you flatter me.

I certainly have had my share of beauty, but I do not pretend to
a)8637
b)8 2 1 4 9 2 0 3 3 0 0 2 3 3 5 2 0 6 1 9 3 1 0 0 6 0
--------

21)
 be anything extraordinary now.

When a woman has five grown-up daughters, she ought to give over th
a)9221
b)7 1 0 2 8 1 5 7 4 0 0 0 1 7 7 1 0 6 3 6 3 3 4 1 2 0
--------

22)
inking of her own beauty."

"In such cases, a woman has not often much beauty to think of."

"But, m
a)8512
b)6 3 3 0 5 3 1 5 4 0 2 0 3 8 7 0 0 1 4 7 5 0 2 0 2 0
--------

23)
y dear, you must indeed go and see Mr. Bingley when he comes into the neighbourhood."

"It is more t
a)8785
b)2 2 1 5 12 0 3 5 6 0 0 1 4 6 8 0 0 4 4 5 3 0 1 0 3 0
--------

24)
han I engage for, I assure you."

"But consider your daughters.

Only think what an establishment it
a)8902
b)7 2 1 2 7 1 3 5 6 0 1 2 1 7 5 0 0 5 6 7 5 0 1 0 3 0
--------

25)
 would be for one of them.

Sir William and Lady Lucas are determined to go, merely on that account,
a)8869
b)7 1 3 5 9 2 1 2 4 0 0 6 4 5 8 0 0 5 2 6 3 0 2 0 2 0
--------

26)
 for in general, you know, they visit no newcomers.

Indeed you must go, for it will be impossible f
a)9020
b)1 2 1 2 9 3 2 1 8 0 1 4 3 6 9 1 0 4 5 4 3 1 3 0 3 0
--------

27)
or us to visit him if you do not."

"You are over-scrupulous, surely.

I dare say Mr. Bingley will b
a)8679
b)3 2 1 2 5 1 1 1 7 0 0 5 2 2 8 1 0 7 6 3 7 2 1 0 5 0
--------

28)
e very glad to see you; and I will send a few lines by you to assure him of my hearty consent to his
a)9036
b)5 1 1 3 10 2 1 3 5 0 0 4 2 5 7 0 0 3 7 5 3 1 2 0 6 0
--------

29)
 marrying whichever he chooses of the girls; though I must throw in a good word for my little Lizzy.
a)9278
b)2 0 2 2 6 2 4 8 7 0 0 4 3 2 9 0 0 7 4 6 2 1 3 0 3 2
--------

30)
"

"I desire you will do no such thing.

Lizzy is not a bit better than the others; and I am sure sh
a)8582
b)4 2 1 3 7 0 1 6 8 0 0 3 1 5 5 0 0 4 6 8 3 0 1 0 2 2
--------

31)
e is not half so handsome as Jane, nor half so good-humoured as Lydia.

But you are always giving he
a)8914
b)10 1 0 4 6 2 3 5 4 1 0 4 2 5 9 0 0 3 7 2 4 1 1 0 3 0
--------

32)
r the preference."

"They have none of them much to recommend them," replied he; "they are all silly
a)8822
b)3 0 3 2 17 2 0 8 2 0 0 5 5 4 4 2 0 6 1 6 1 1 0 0 3 0
--------

33)
 and ignorant like other girls; but Lizzy has something more of quickness than her sisters."

"Mr. B
a)9017
b)4 2 1 1 7 1 3 5 7 0 2 3 3 6 5 0 1 7 8 6 2 0 0 0 1 2
--------

34)
ennet, how can you abuse your own children in such a way?

You take delight in vexing me.

You have
a)8846
b)6 1 3 2 9 0 2 5 5 0 1 2 1 8 6 0 0 2 2 3 6 2 3 1 5 0
--------

35)
no compassion for my poor nerves."

"You mistake me, my dear.

I have a high respect for your nerves
a)8857
b)5 0 2 1 10 2 1 3 4 0 1 0 5 4 9 3 0 8 6 2 2 3 0 0 4 0
--------

36)
.

They are my old friends.

I have heard you mention them with consideration these last twenty year
a)9107
b)6 0 1 4 12 1 0 6 6 0 0 2 3 6 5 0 0 5 4 9 1 1 2 0 5 0
--------

37)
s at least."

"Ah, you do not know what I suffer."

"But I hope you will get over it, and live to se
a)8290
b)5 1 0 2 7 2 1 3 5 0 1 4 0 3 8 1 0 2 4 8 4 2 3 0 2 0
--------

38)
e many young men of four thousand a year come into the neighbourhood."

"It will be no use to us, if
a)8883
b)4 2 1 2 8 3 2 4 5 0 0 2 3 7 11 0 0 3 3 5 6 0 1 0 3 0
--------

39)
 twenty such should come, since you will not visit them."

"Depend upon it, my dear, that when there
a)8956
b)2 0 3 4 10 0 0 6 5 0 0 3 3 6 5 2 0 2 4 9 4 1 3 0 3 0
--------

40)
 are twenty, I will visit them all."

Mr. Bennet was so odd a mixture of quick parts, sarcastic humo
a)8868
b)7 1 3 2 6 1 0 2 7 0 1 4 4 3 4 1 1 5 6 8 3 1 3 1 1 0
--------

41)
ur, reserve, and caprice, that the experience of three-and-twenty years had been insufficient to mak
a)9342
b)7 1 4 3 16 3 0 4 5 0 1 0 1 7 2 2 0 7 3 8 2 1 1 1 2 0
--------

42)
e his wife understand his character.

Her mind was less difficult to develop.

She was a woman of me
a)8939
b)7 0 3 5 10 4 0 5 6 0 0 3 3 4 4 1 0 4 8 4 2 1 4 0 0 0
--------

43)
an understanding, little information, and uncertain temper.

When she was discontented, she fancied
a)9331
b)7 0 3 6 11 2 1 3 7 0 0 2 2 13 3 1 0 4 5 8 2 0 2 0 0 0
--------

44)
herself nervous.

The business of her life was to get her daughters married; its solace was visiting
a)9328
b)5 1 1 2 12 3 3 5 7 0 0 3 1 3 4 0 0 7 11 6 3 2 2 0 0 0
--------

45)
 and news.

Chapter 2

Mr. Bennet was among the earliest of those who waited on Mr. Bingley.

He had
a)8435
b)7 2 1 3 11 1 2 6 3 0 0 2 3 7 5 1 0 4 4 6 0 0 4 0 1 0
--------

46)
 always intended to visit him, though to the last always assuring his wife that he should not go; an
a)9289
b)8 0 0 3 5 1 3 8 7 0 0 4 1 5 6 0 0 1 8 10 3 1 3 0 2 0
--------

47)
d till the evening after the visit was paid she had no knowledge of it.

It was then disclosed in th
a)9011
b)5 0 1 6 10 2 2 6 9 0 1 4 0 6 4 1 0 1 6 9 0 2 3 0 0 0
--------

48)
e following manner.

Observing his second daughter employed in trimming a hat, he suddenly addressed
a)9383
b)5 1 1 8 11 1 4 4 6 0 0 4 4 8 5 1 0 5 6 3 2 1 1 0 2 0
--------

49)
 her with:

"I hope Mr. Bingley will like it, Lizzy."

"We are not in a way to know what Mr. Bingley
a)8288
b)4 2 0 0 7 0 2 4 9 0 2 6 2 5 4 1 0 4 0 5 0 0 6 0 4 2
--------

Ex 1c:
1) 0
2) 0
*/
