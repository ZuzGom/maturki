#include <bits/stdc++.h>
using namespace std;

unordered_map <string, int> licz;

bool czy_pierwsza(int l){
    if (l<2) return false;
    for (int i=2;i<sqrt(l)+1;i++){
        if(l%i==0) return false;
    }
    return true;
}

bool czy_wieksza(string s){
    char c = s[0];
    for(int i=1;i<s.size();i++){
        if (s[i]<c) return false;
        c = s[i];
    }
    return true;
}

int main(){
    fstream input("maturki/2014/dane_PR/NAPIS.TXT");
    ofstream output("maturki/2014/ZADANIE5.TXT");
    int s1=0, s2=0;
    output<<"2."<<endl;
    for(int t=0;t<1000;t++){
        string napis;
        input>>napis;
        licz[napis]++;
        int suma = 0;
        for (auto x:napis) suma += x;
        if (czy_pierwsza(suma)) s1++;
        if (czy_wieksza(napis)) output<<napis<<endl;


    }
    output<<"1. "<<endl<<s1<<endl;
    output<<"3. "<<endl;
    for(auto& x:licz){
        if(x.second>1) output<<x.first<<endl;
    }
    
    return 0;
    }