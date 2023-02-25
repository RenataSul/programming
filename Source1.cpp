#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string>
#include <cstring>
#include <cmath>
#include <time.h>
#include <vector>
#include <map>
#include <fstream>
#include <set>
#include <iterator>
using namespace std;

template <typename Type>
void Sort(Type *m1,int n1, Type *m2, int n2 )
{
	Type* a, * b;
	a = &m1[0];
	b = &m2[0];
	Type *M= new Type[n1 + n2];
	int ca = 0, cb = 0;

	for (int i = 0; i < n1+n2; i++)
	{
		if (ca == n1)
		{
			for (int j = i; j < n1+n2; j++)
			{
				M[j] = *b;
				b++;
				cb++;
			}
			i = n1+n2;
		}

		if (cb == n2)
		{
			for (int j = i; j < n1 + n2; j++)
			{
				M[j] = *a;
				a++;
				ca++;
			}
			i = n1 + n2;
		}

		if (*a < *b)
		{
			M[i] = *a;
			if (*a != m1[n1 -1])
			{
				a++;
				ca++;
			}
			else
			{
				for (int j = i + 1; j < n1 +n2; j++)
				{
					M[j] = *b;
					b++;
					cb++;
				}
				i = n1 +n2;
			}
		}
		else
		{
			M[i] = *b;
			if (*b != m2[n2-1])
			{
				b++;
				cb++;
			}
			else
			{
				for (int j = i + 1; j < n1 + n2; j++)
				{
					M[j] = *a;
					a++;
					ca++;
				}
				i = n1 + n2;
			}
		}
	}
	cout << "Answer: ";
	for (int i = 0; i < n1 +n2; i++)
	{
		cout << M[i] << ", ";
	}
}
int main()
{
	setlocale(0, "rus");
	int n1, n2;
	cout << "¬ведите m:" << endl;
	cin >> n1;
	cout << "¬ведите n:" << endl;
	cin >> n2;
	int* m1 = new int[n1];
	int* m2 = new int[n2];

	cout << "¬ведите m1:" << endl;
	for (int i = 0; i < n1; i++)
	{
		cin >> m1[i];
	}

	cout << "¬ведите m2:" << endl;
	for (int i = 0; i < n2; i++)
	{
		cin >> m2[i];
	}

	Sort(m1, n1, m2, n2);
}