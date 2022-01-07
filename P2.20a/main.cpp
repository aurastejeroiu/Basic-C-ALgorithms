#include <iostream>

using namespace std;

void CitireX(int& n, int x[])
{ cout<<"da lungimea sirului:";
  cin >>n;
  for(int i=1; i<=n;i++)
  {  cout<<"x["<<i<<"]=";
     cin >>x[i];
  }
}
void Neg(int n,int x[],int &k,double v[])
{
    k=0;
    int cont=0;
    double s=0;
    for(int i=1;i<=n;i++)
        if(x[i]<0)
        {
            if(cont==0)
                v[k++]=0;
            s=0;
            cont=0;
        }
        else
        {
            s=s+x[i];
            cont++;
        }
}

void Afisare(int k, double v[]){
  for(int i=1;i<k;i++)
    cout<<v[i]<<" ";
  cout<<endl;
}

int main()
{  int n,k, x[100];
   double v[100];
   CitireX (n,x);
   Neg(n,x,k,v);
   Afisare (k,v);
   cout << "Program terminat" << endl;
   return 0;
}
