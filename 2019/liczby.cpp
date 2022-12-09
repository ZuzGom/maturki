#include <bits/stdc++.h>
using namespace std;


int NWD(int a, int b)
{
   if(a!=b)
     return NWD(a>b?a-b:a,b>a?b-a:b);
   return a;
}

int silnia(int x){
    int s=1;
    for(int i=1;i<=x;i++) s*=i;
    return s;
}

bool czy_3(int x){
    while(x>1){
        if(x%3!=0) return false;
        else x/=3;
    }
    return true;
}
bool czy_silnia(int x){
    int p = 0;
    string s = to_string(x);
    for(auto ch:s) p += silnia((int)ch-48);
    if (p==x) return true;
    else return false;
}

int main(){

    fstream input("maturki/2019/Dane_PR/przyklad.txt");
    ofstream out("maturki/2019/wyniki4.txt");
    int s1=0, nwd=1, p=0, wyn=0,k=0,max=0;
    for(int t=0;t<500;t++){
        int liczba;
        input>>liczba;
        if(czy_3(liczba)) s1++; 
        if(czy_silnia(liczba)) cout<<liczba<<endl;

        /*
        if (NWD(nwd,liczba)<2){          
            if(max<t-p){
                max = p-t;
                wyn = nwd;
                k=p;
            } 
            nwd=liczba;
            p=t;
        };
        nwd=NWD(nwd,liczba);
        */

    }
    cout<<s1<<endl;
    cout<<k<<" "<<wyn<<" "<<max<<endl;
    return 0;
    }