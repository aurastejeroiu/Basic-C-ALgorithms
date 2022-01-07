#include <iostream>

using namespace std;
//1.3. Sa se verifice daca numarul natural nenul, n este perfect.
//     Un numar natural n este perfect daca este egal cu suma divizorilor sai
//     (mai putin el insusi).
//     Exemplu 6=1+2+3

int  SumaDiv(long n){    //retur suma divizorilor lui n (fara n)
     long div=2, Suma=1;
     if(n<=1)  return 0;
     while (div*div<=n){			//O(rad(n))
       if(n%div==0)
            if (div==n/div) Suma+=div;
            else            Suma+=div+n/div;
       div++;
     }
     return Suma;
}
int main()
{   long n;
    do{                                 //citire cu validare natural nenul
      cout<<"da numar natural, nenul:";
      cin >>n;
      if(n<=0) cout<<"ai gresit!!!";
    }
    while (n<=0);
    if(SumaDiv(n)==n) cout<<n<<" este perfect "<<SumaDiv(n);
    else              cout<<n<<" nu este perfect "<<SumaDiv(n);
    cout << endl;
    cout << "Program terminat" <<endl;
    return 0;
}
