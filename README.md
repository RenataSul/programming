# programming

template <typename Type>
void Sort(Type *m1, Type *m2, Type *M)
{
	Type* a, * b;
	a = &m1[0];
	b = &m2[0];
	int ca = 0, cb = 0;

	for (int i = 0; i < 10; i++)
	{
		if (ca == 5)
		{
			for (int j = i; j < 10; j++)
			{
				M[j] = *b;
				b++;
				cb++;
			}
			i = 10;
		}

		if (cb == 5)
		{
			for (int j = i; j < 10; j++)
			{
				M[j] = *a;
				a++;
				ca++;
			}
			i = 10;
		}


		if (*a < *b)
		{
			M[i] = *a;
			if (*a != m1[4])
			{
				a++;
				ca++;
			}
			else
			{
				for (int j = i + 1; j < 10; j++)
				{
					M[j] = *b;
					b++;
					cb++;
				}
				i = 10;
			}
		}
		else
		{
			M[i] = *b;
			if (*b != m2[4])
			{
				b++;
				cb++;
			}
			else
			{
				for (int j = i + 1; j < 10; j++)
				{
					M[j] = *a;
					a++;
					ca++;
				}
				i = 10;
			}
		}
	}


	for (int i = 0; i < 10; i++)
	{
		cout << M[i] << " ";
	}
}
int main()
{
	int m1[5] = { 1, 3, 5, 7, 9 };
	int m2[5] = { 2, 4, 6, 8, 10 };

	int M[10] = {};
	Sort(m1, m2, M);
	
}
