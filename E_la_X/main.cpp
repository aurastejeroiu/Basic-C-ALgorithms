#include <iostream>
#include <math.h>

using namespace std;

double CalculE(double x, double eps){
 double E,n,nFact,PutX;
 nFact=1;
 E=1;
 PutX=1;
 n=0;
 while(PutX/nFact>=eps){
    n++;
    nFact*=n;
    PutX*=x;
    E+=PutX/nFact;
    cout<<E<<endl;
 }
 return E;
}

int main()
{   double x,eps;
    cout<<"da exponent:";
    cin >> x;
    cout<<"da precizia:";
    cin >>eps;
    cout<<CalculE(x,eps)<<endl;
    cout << "\nProgram terminat" << endl;
    return 0;
}
