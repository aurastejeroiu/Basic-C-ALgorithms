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

int main()
{  int n, x[100];
   int MaxNeg=0;
   CitireX(n,x);
   int i=1;
   while(i<=n && x[i]>=0)i++;
   if(i>n) cout<<"nu exista numere negative";
   else
   { MaxNeg=x[i];
     for(i=1;i<=n;i++)
        { if(x[i]<0)
           if(x[i]>MaxNeg) MaxNeg=x[i];
        }
     cout<<"val maxima negativa:"<<MaxNeg;
   }
    cout << "Hello world!" << endl;
    return 0;
}
