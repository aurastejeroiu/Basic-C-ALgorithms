#include <iostream>

using namespace std;

///P1.11. Sa se determine toate numerele naturale de 3 cifre abc cu proprietatea
///       abc=a^3+b^3+c^3

int SumaCub(int n){
    int a,b,c;
    c=n%10;         ///ultima cifra (a unitatilor)
    b=(n/10)%10;    ///cifra zecilor
    a=(n/100);      ///cifra sutelor
    if(a*a*a+b*b*b+c*c*c==n) return n;
                             return 0;
}

int SumaPat(int n){
    int a,b;
    b=n%10;
    a=n/10;
    if(a*a+b*b==n) return n;
                   return 0;
}
int SumaQuatro(int n){
    int a,b,c,d;
    d=n%10;
    c=(n/10)%10;
    b=(n/100)%10;
    a=(n/1000);
    if(a*a*a*a+b*b*b*b+c*c*c*c+d*d*d*d==n)return n;
                                          return 0;
}

int main()
{   for(int n=100;n<=999;n++)
      if (SumaCub(n)) cout<<n<<endl;

    for(int n=10;n<=99;n++)
      if (SumaPat(n)) cout<<n<<endl;

    for(int n=1000;n<=9999;n++)
      if(SumaQuatro(n)) cout<<n<<endl;

    cout << "Program terminat" << endl;
    return 0;
}
