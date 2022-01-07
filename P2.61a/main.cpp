#include <iostream>

using namespace std;

void CreV(int n, int V[]){
    int nr_elem=0,k=1;
    while(nr_elem<n)
    {
        for(int i=1;i<=k && nr_elem<n ;i++)
            V[++nr_elem]=i;
        k++;
    }

}

void AfisV(int n, int V[]){
      for(int i=1;i<=n;i++)
        cout<<V[i]<<" ";

}
int main()
{
    int n,V[1000];               ///n e lungimea lui  V
    cout<<"n:"; cin>>n;
    CreV  (n,V);
    AfisV (n,V);
    return 0;
}
