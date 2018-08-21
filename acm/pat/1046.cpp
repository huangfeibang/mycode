 #include<iostream>
 using namespace std;
 int main()
 {
     int N, a1, a2, b1, b2, sum;
     int count1 = 0, count2 = 0;
     cin >> N;
     for(int i = 0;i < N;i++)
     {
         cin >> a1 >> a2 >> b1 >> b2;
         sum = a1 + b1;
         if(a2 == sum && b2 != sum)
            count2++;
         if(b2 == sum && a2 != sum)
            count1++;
     }
     cout << count1 << ' ' << count2 << endl;
     return 0;
 }
