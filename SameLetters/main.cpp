#include <iostream>
#include <cstring>
using namespace std;

int main()
{   char F1[]="Acesta UN TfEXT. Este un Text oarecare."; ///cele 2 fraze initiale
    char F2[]="Acesta este un text oarecare text          F.";

    int VA1[26]={0};    ///cei doi vectori de aparitie pentru cele 26 de litere
    int VA2[26]={0};

    for(int i=0;i<strlen(F1);i++)
      { if(F1[i]>='A' && F1[i]<='Z') VA1[F1[i]-'A']=1;          ///daca F1[i] este litera mare
        else  if(F1[i]>='a' && F1[i]<='z') VA1[F1[i]-'a']=1;    ///daca F1[i] este litera mica
      }

    for(int i=0;i<strlen(F2);i++)
      { if(F2[i]>='A' && F2[i]<='Z') VA2[F2[i]-'A']=1;          ///daca F2[i] este litera mare
        else  if(F2[i]>='a' && F2[i]<='z') VA2[F2[i]-'a']=1;    ///daca F2[i] este litera mica
      }

    int i=0;
    while(i<26 && VA1[i]==VA2[i])
        i++;
    if(i==26) cout<<"Da";
    else      cout<<"Nu";


    cout << "\nHello world!" << endl;
    return 0;
}
