#include <iostream>
#include <fstream>

using namespace std;

ifstream fin("in.txt");

int q[100005];
int n;

void read(){
    fin>>n;
    for(int i=1; i<=n; i++)
        fin>>q[i];
}

int st[100005], dr[100005];

void getMaxStDr(){ ///returneaza vectorii st si dr
    for(int i=1; i<=n; i++){
        if(st[i-1]<q[i]) st[i]=q[i];
        else 		 st[i]=st[i-1];
        if(dr[n-i+2]<q[n-i+1]) dr[n-i+1]=q[n-i+1];
        else                   dr[n-i+1]=dr[n-i+2];
    }
    for(int i=1;i<=n;i++)
        cout<<st[i]<<' '<<dr[i]<<endl;


}

int rezolva(){ ///returneaza numarul de mililitri de apa
    int sum=0;
    for(int i=1; i<=n; i++)
        sum+=min(st[i], dr[i])-q[i];
    return sum;
}

int main()
{
    read();
    getMaxStDr();
    cout<<rezolva();
}
