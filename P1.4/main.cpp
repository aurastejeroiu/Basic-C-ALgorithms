#include <iostream>

using namespace std;

//1.4. Sa se determine toate numerele perfecte din intervalul [a,b], a si b date.


int  SumaDiv(long n){           //retur 1 daca n este perfect, 0 altfel
     long d=2, Suma=1;
     if(n<=1)  return 0;
     while (d*d<n)			    //O(rad(n))
       {if(n%d==0) Suma+=d+n/d;
        d++;
       }
     if(d*d==n) Suma+=d;
     return Suma;
}

int main()
{   long n,a,b;
    do{                                 //citire cu validare natural nenul
      cout<<"da capatul stang,a(>0):";
      cin >>a;
      if(a<=0) cout<<"ai gresit!!!";
    }
    while (a<=0);
    do{                                 //citire cu validare natural >=a
      cout<<"da capatul drept,(b>a):";
      cin >>b;
      if(b<=a) cout<<"ai gresit!!!";
    }
    while (b<=a);
    for(n=a;n<=b;n++)
        if(SumaDiv(n)==n) cout<<n<<" este perfect"<<endl;
    cout << "Program terminat" <<endl;
    return 0;
}
