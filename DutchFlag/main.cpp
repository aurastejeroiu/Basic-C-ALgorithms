#include <iostream>
using namespace std;

void Swap(char&a, char&b){
     char aux =a;
            a =b;
            b =aux;
}

int dutchFlag(int n,char P[])
{   int i,j,k;
    i=j=k=1;
    while(k<=n){
        if(P[k]=='w') k++;
        else
            if(P[k]=='b')
                {Swap(P[j],P[k]);
                 j++;
                 k++;
                }
             else
                { Swap(P[i],P[k]);
                  i++;
                  Swap(P[j],P[k]);
                  j++;
                  k++;
                 }
    }
}

int main()
{   char P[100];
    int n;
    cout<<"cati pioni:"; cin>>n;
    for(int i=1;i<=n;i++)
        {cout<<"p["<<i<<"]=";
         cin >> P[i];
        }
    dutchFlag(n,P);
    for(int i=1;i<=n;i++)
        cout<<P[i];
    cout << "\nHello world! I'm finished" << endl;
    return 0;
}
