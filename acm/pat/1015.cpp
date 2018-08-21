#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
typedef struct {
	long long num;
	int de, cai;
	int score;
	int grade;
}student;
vector<student> a;
bool comp(const student &a, const student &b)
{
	if (a.grade < b.grade)
		return 1;
	else if (a.grade == b.grade)
		return a.score != b.score ? a.score>b.score :a.de != b.de ? a.de>b.de :a.num<b.num;
	else
		return 0;
}
int main()
{
	int N, L, count = 0, H;
	student stu;
	cin >> N >> L >> H;
	for (int i = 0; i<N; i++)
	{
		cin >> stu.num >> stu.de >> stu.cai;
		stu.score = stu.de + stu.cai;
		if (stu.de >= L && stu.cai >= L)
		{
			count++;
			if (stu.de >= H && stu.cai >= H)
				stu.grade = 1;
			else if (stu.de >= H && stu.cai < H)
				stu.grade = 2;
			else if (stu.de >= stu.cai && stu.de < H && stu.cai < H)
				stu.grade = 3;
			else
				stu.grade = 4;
			a.push_back(stu);
		}
	}
	sort(a.begin(), a.end(), comp);
	cout << count << endl;
	for (int i = 0; i<a.size(); i++)
		cout << a[i].num << ' ' << a[i].de << ' ' << a[i].cai << endl;
	return 0;
}
