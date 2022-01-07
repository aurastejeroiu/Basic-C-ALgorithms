#include <iostream>

using namespace std;

long Pare(long n)
{ long Par=0;
  long Uc=0;
  long M10=1;

  while(n>0)
  {Uc=n%10;
   if(Uc%2==0) {Par=Par+Uc*M10;
                M10=M10*10;
               }
   n=n/10;
  }
  return Par;
}

long Impare(long n)
{ long Impar=0;
  long Uc=0;
  long M10=1;

  while(n>0)
  {Uc=n%10;
   if(Uc%2==1) {Impar=Impar+Uc*M10;
                M10=M10*10;
               }
   n=n/10;
  }
  return Impar;
}

int main()
{   long n;
    cout<<"da un natural:";
    cin >> n;
    cout<<"numarul cu cifrele pare este: "<<Pare(n)<<"\n";
    cout<<"numarul cu cifrele impare este: "<<Impare(n)<<"\n";
    cout<< "Program terminat" << endl;
    return 0;
}
