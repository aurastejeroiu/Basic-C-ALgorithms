#include <iostream>

using namespace std;

int main()
{   int a[11]={0,3,4,5,-6,-5,20,-20,-30,17,-18};
    int n=10;
    int i,j,aux;
    i=j=1;
    while(j<=n){
        if(a[j]>0) j++;
        else { aux =a[j];
               a[j]=a[i];
               a[i]=aux;
               i++,j++;
        }
    }
    for(i=1;i<=n;i++)
        cout<<a[i]<<" ";
    cout << "Hello world!" << endl;
    return 0;
}
