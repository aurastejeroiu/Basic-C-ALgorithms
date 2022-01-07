#include <iostream>
#include <math.h>

using namespace std;

double CalculE(double eps){
 double E,n,nFact;
 nFact=n=1;
 E=2;

 while(1/nFact>=eps){
    n++;
    nFact*=n;
    E+=1/nFact;
    cout<<E<<endl;
 }
 return E;
}

int main()
{   double eps;
    cout<<"da precizia:";
    cin >>eps;
    cout<<CalculE(eps)<<endl;
    cout << "\nProgram terminat" << endl;
    return 0;
}
