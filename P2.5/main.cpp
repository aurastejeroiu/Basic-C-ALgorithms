#include <iostream>
#include <iomanip>
using namespace std;

int main()
{   int m,k,n,M[20][20];
    cout <<"da dim Triunghiului:";
    cin  >>n;
    for(m=0;m<=n;m++)               //initializare matrice
        for(k=0;k<=n;k++)
           M[m][k]=0;
    for(m=0;m<=n;m++) M[m][0]=1;    //initializare prima coloana cu 1
                                    //creare triunghi Pascal
    for(m=1;m<=n;m++)
        for(k=1;k<=n;k++)
           M[m][k]=M[m-1][k-1]+M[m-1][k];
                                    //afisare
    for(m=0;m<=n;m++)               //initializare matrice
        {for(k=0;k<=n;k++)
           if(M[m][k]) cout<<setw(5)<<M[m][k];
         cout<<endl;
        }
    cout << "Hello world!" << endl;
    return 0;
}
