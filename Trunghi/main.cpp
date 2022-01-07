#include <iostream>
#include <iomanip>
using namespace std;

void CitirePuncte(int& n, int Fx[], int Fy[]){
    int x,y;
    cout<<"da nr puncte:";
    cin >>n;
    for(int i=1;i<=n;i++){
        cout<<"x=";
        cin >>x;
        Fx[x]++;
        cout<<"y=";
        cin >>y;
        Fy[y]++;
    }
}
int RezolvA(int n, int Fx[]){
    int Max=Fx[1];
    for(int i=2;i<1000;i++)
        if(Fx[i]>Max) Max = Fx[i];
    return Max;
}

int RezobaB(int n, int Fx[], int Fy[]){

}

int main(){
    int n;
    int Fx[1000]={0};
    int Fy[1000]={0};
    CitirePuncte(n,Fx,Fy);
    int Max=RezolvA(n,Fx);
    if(Max>1) cout<<"sunt "<<Max<<" abscise egale";
    else      cout<<"nu exista punce cu aceeasi abscisa";
    cout<<RezolvaB(n,Fx,Fy);
    cout << "\nHello world!" << endl;
    return 0;
}
