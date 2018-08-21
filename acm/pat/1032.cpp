#include<iostream>
#include<vector>
using namespace std;
int main()
{
    int score[100010]={0};
    int N, a, b, maxscore = 0, maxschool = 0;
    cin >> N;
    for(int i = 0;i<N;i++)
    {
        cin >> a >> b;
        score[a] += b;
        if(score[a] >= maxscore)
        {
             maxscore = score[a];
             maxschool = a;
        }
    }
    cout << maxschool <<' ' << score[maxschool];
    return 0;
}
