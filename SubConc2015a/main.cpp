#include <iostream>

using namespace std;

double E(double eps){
 double n, xn1, fact;
 xn1= n= fact= (double)1;
 //n   =(double)1;
 //fact=(double)1;
 while( 1/fact>=eps){
    xn1=xn1+1/fact;
    //set fixed ;
    //cout<<precision(8)<<xn1<<endl;
    n++;
    fact=fact*n;
 }
 return xn1;
 }

int main()
{   double eps;
    cout<<"da precizia:";
    cin >>eps;
    cout<<E(eps)<<endl;
    cout << "Hello world!" << endl;
    return 0;
}
