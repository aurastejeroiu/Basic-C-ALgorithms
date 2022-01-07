#include <iostream>
#include <iomanip>
#include <cmath>
/*
  Sa se scrie o functie cu un parametru real Eps care aproximeaza valoarea radical de ordinul 2 din a
  cu o precizie data (Eps), de exemplu cu 2 zecimale exacte => Eps=0.01.
  Se stie ca sirul x[n]=1/2(x[n-1]+a/x[n-1]), x[1]=1

  Aproximarea cu valoarea Eps este data de relatia abs(x[n+1]-x[n])<Eps
  retur x[n+1]
*/

using namespace std;

double Aprox(double a, double Eps)
{  double x,y;
   x=1;
   y=1.0/2*(x+a/x);
   while (abs(x-y)>Eps){
      x=y;
      y=1.0/2*(x+a/x);
      cout<<y<<endl;
   }
   return y;
}


int main()
{   double  Eps,a;
    cout<<"din ce numar vrei radical:";
    cin >> a;
    cout   <<"Da precizia:";
    cin    >>Eps;
    cout   <<setw(10.8)<<Aprox(a,Eps);
    return 0;
}
