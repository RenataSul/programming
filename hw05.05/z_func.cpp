#include <iostream>
#include <vector>
#include <string>

using namespace std;

void z_naive(string s, int k) {
	int cnt = 0;
	int n = (int)s.length();
	vector<int> z(n);
	for (int i = 1; i < n; ++i)
		while (i + z[i] < n && s[z[i]] == s[i + z[i]])
		{
			++z[i];
		}
	cout << "Наивная: " << endl;
	for (int i = 0; i < z.size(); i++)
	{
		cout << z[i];
		if (z[i] >= k) cnt++;
	}
	cout << endl << "Ответ: " << cnt;

}

void z_line(string s, int k) {
	int cnt = 0;
	int n = (int)s.length();
	vector<int> z(n);
	for (int i = 1, l = 0, r = 0; i < n; ++i) {
		if (i <= r)
			z[i] = min(r - i + 1, z[i - l]);
		while (i + z[i] < n && s[z[i]] == s[i + z[i]])
		{
			++z[i];
		}
		if (i + z[i] - 1 > r)
			l = i, r = i + z[i] - 1;
	}
	cout << "За линию: " << endl;
	for (int i = 0; i < z.size(); i++)
	{
		cout << z[i];
		if (z[i] >= k) cnt++;
	}
	cout << endl << "Ответ: " << cnt;
}

int main() 
{
	setlocale(0, "rus");
	string s_start = "abacaba";
	string s_find = "b";
	int k = int(s_find.size()); // переменная в которой количество букв искомой подстроки

	string S = s_find + s_start ;

	z_naive(S, k);
	cout << endl << endl;
	z_line(S, k);

    return 0;
}
