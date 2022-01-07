#include <iostream>

using namespace std;

long F(long n){
   long u,m;
   if(n<10)
     return (n%2==0)? n:-1;
   u=(n%2==0)?(n%10):-1;
   m=F(n/10);
   return (u>m)?(u):m;
}

int main()
{
    cout << F(1234) << endl;
    cout << F(13) << endl;
    cout << F(248244) << endl;


    return 0;
}
