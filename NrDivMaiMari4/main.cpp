#include <iostream>

using namespace std;

int NrDiv(int n){
   int cont=0;
   int i;
   for(i=1;i*i<n;i++)
     if(n%i==0) cont+=2;
   if(i*i==n) cont++;
   return cont;
}

int main()
{   int cont5=0;
    for(int i=1;i<=100;i++)
       if(NrDiv(i)>4) cont5++;

    cout << cont5<<" Hello world!" << endl;

    cont5=100/4-3;
    for(int i=12;i<=100;i+=4)
        for(int j=1;j<=3;j++)
           if((i+j)%10==0) cont5++;
           else if(NrDiv(i+j)>4) cont5++;

    cout << cont5<<" Hello world!" << endl;
    return 0;
}
