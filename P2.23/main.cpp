#include <iostream>

using namespace std;


void CitireX(int& n, int x[])
{ cout<<"da dim sirului:";
  cin >>n;
  for(int i=1; i<=n;i++)
  {  cout<<"x["<<i<<"]=";
     cin >>x[i];
  }
}

int MaiMici(int n, int X[], int i)
{   int j=1,cnt=0;
    while(j<i)
    {if(X[j] <X[i]) cnt++;
     j++;
    }
    return cnt;
}

void CreY(int n, int X[], int Y[])
{ for(int i=1;i<=n;i++)
      Y[i]=MaiMici(n,X,i);
}

void AfisY (int n, int  y[])
{
    for(int i=1;i<=n;i++)
        cout<<y[i]<<",";
}
int main()
{ int n;
  int X[100], Y[100];
  CitireX(n,X);
  CreY   (n,X,Y);
  AfisY  (n,Y);
  cout << "Program terminat" << endl;
  return 0;
}
