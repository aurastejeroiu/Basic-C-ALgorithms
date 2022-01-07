#include <iostream>
#include <math.h>

using namespace std;
double Radical(double A, double eps){
 double xn, xn1;
 xn=1;
 xn1=(double)1/2*(xn+A/xn);
 while( fabs(xn1-xn)>=eps){
    xn=xn1;
    xn1=(double)1/2*(xn+A/xn);
    cout<<xn1<<endl;
 }
 return xn1;
}

int main()
{   double A,eps;
    cout<<"da numarul:";
    cin >>A;
    cout<<"da precizia:";
    cin >>eps;
    cout<<Radical(A,eps)<<endl;
    cout << "Hello world!" << endl;
    return 0;
}
