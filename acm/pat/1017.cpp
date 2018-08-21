#include<iostream>
#include<cmath>
using namespace std;
int zhuan(char c)
{
	if (c == 'J')    return 0;
	if (c == 'C')    return 1;
	if (c == 'B')    return 2;
}
int main()
{
	int n, c1, c2, max = 0;
	char x1, x2, ss[] = { 'J', 'C', 'B' };
	int a[3] = { 0 }, b[3] = { 0 }, wina[3] = { 0 }, winb[3] = { 0 };
	cin >> n;

	for (int i = 0; i< n; i++)
	{
		cin >> x1 >> x2;
		c1 = zhuan(x1);
		c2 = zhuan(x2);
		if ((2 + c1 - c2) % 3 == 0)
			wina[c1]++;
		if ((2 + c2 - c1) % 3 == 0)
			winb[c2]++;
		a[(2 + c1 - c2) % 3]++;
		b[(2 + c2 - c1) % 3]++;
	}

	for (int i = 2; i>0; i--)
		cout << a[(i + 1) % 3] << ' ';
	cout << a[1] << endl;
	for (int i = 2; i > 0; i--)
		cout << b[(i + 1) % 3] << ' ';
	cout << b[1] << endl;

	for (int i = 0; i <= 2; i++)
		if (wina[i] > max)
			max = wina[i];
	for (int i = 2; i >= 0; i--)
		if (wina[i] == max)
		{
			cout << ss[i] << ' ';
			break;
		}

	max = 0;
	for (int i = 0; i <= 2; i++)
		if (winb[i] > max)
			max = winb[i];
	for (int i = 2; i >= 0; i--)
		if (winb[i] == max)
		{
			cout << ss[i] << endl;
			break;
		}

	return 0;
}
