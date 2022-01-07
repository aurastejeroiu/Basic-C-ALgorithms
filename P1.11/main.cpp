#include <iostream>

using namespace std;

//P1.11. Sa se determine toate numerele naturale de 3 cifre abc cu proprietatea
//       abc=a^3+b^3+c^3

int SumaCub(int n){
    int a,b,c;
    c=n%10;         //ultima cifra (a unitatilor)
    b=(n/10)%10;    //cifra zecilor
    a=(n/100);      //cifra sutelor
    if(a*a*a+b*b*b+c*c*c==n) return n;
                             return 0;
}

int main()
{   for(int i=100;i<=999;i++)
      if (SumaCub(i)) cout<<i<<endl;
    cout << "Program terminat" << endl;
    return 0;
}
