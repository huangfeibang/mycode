#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
    string A, B, C;
    char system13[] = "0123456789JQK";
    cin >> A >> B;
    reverse(A.begin(), A.end());
    reverse(B.begin(), B.end());
    int lenA = A.length(), lenB = B.length();
    string S(abs(lenA -lenB),'0');
    lenA<lenB? A+=S : B+=S;
    for(int i = 0;i < A.length();i++)
        if(i & 1)
            C.push_back((B[i] - A[i] + 10)%10 + 48);
        else
            C.push_back(system13[(A[i] + B[i] - 96)%13]);
    reverse(C.begin(),C.end());
    cout << C;
    return 0;
}
