#include <iostream>
#include <iomanip>

using namespace std;


long Mediere (long n)
{ int Max,min,Med;      //M pentru cifra maxima, m pentru cifra minima, Med numarul mediat
  long CopieN;          //copie a lui n
  long P10=1;           //puterea a lui 10, iniial este 1
  nn=n;
  Max=0; min=9;         //determinare cifra maxima si minima
  while(n>0)
  { int cif=n%10;
    if(cif>Max) Max=cif;
    if(cif<min) min=cif;
    n/=10;
  }
  //cout<<"cifra minima:"<<min<<endl;
  //cout<<"cifra maxima:"<<Max<<endl;
  Med=0;
  n=CopieN;
  while(n>0)
  { int cif=n%10;
    if(cif!=Max && cif!=min)
      { Med=Med+cif*P10;
        P10*=10;
      }
    n/=10;
  }
  return Med;
}

int main()
{ for(int i=8000;i<=9999;i++)
  { cout<<"("<<i<<","<<setw(2)<<Mediere(i)<<") ";

  }

  cout << "Hello world!" << endl;
  return 0;
}
