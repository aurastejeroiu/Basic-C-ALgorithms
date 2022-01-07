#include <iostream>

using namespace std;

void CitireX(int& n, long x[])
{ cout<<"da dim sirului:";
  cin >>n;
  for(int i=1; i<=n;i++)
  {  cout<<"x["<<i<<"]=";
     cin >>x[i];
  }
}

long  MaxY(int n, long  X[], long Y[])
{  Y[1]=X[1]*X[1];
   long Max= Y[1]*X[1];
   for(int i=2;i<=n;i++)
      { Y[i]=Y[i-1]+X[i]*X[i];
        if(Y[i]*X[i]>Max) Max=Y[i]*X[i];
      }
   return Max;
}
void AfisY (int n, long Y[])
{  cout<<"sirul Y:"<<endl;
   for(int i=1;i<=n;i++)
        cout<<Y[i]<<" ";
}

int main()
{ long X[100],Y[100];
  int n;
  CitireX(n,X);
  cout<<"maximul este:"<<MaxY(n,X,Y)<<endl;
  AfisY  (n,Y);
  cout << "Program terminat" << endl;
  return 0;
}
