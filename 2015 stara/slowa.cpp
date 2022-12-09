#include <bits/stdc++.h>
using namespace std;



int main(){
    unordered_map <string,int> slowa;
    fstream input("maturki/2015 stara/Dane_PR2/slowa.txt");
    ofstream out("maturki/2015 stara/wynik4.txt");
    int s1=0,s2=0,max=0;
    for (int t=0;t<1000;t++){
        string slowo;
        input>>slowo;
        int o=0,z=0;
        char p=' ';
        int c=0;
        int m=1, l=0;
        for(auto s:slowo){

        if (s!=p){
            c++;
            if (max<m) max=m;
            
            m=1;
        } 
        else if (s=='0') m++;
        if (l<m) l=m;
        p=s;
        

        if (s=='1') o++;
        else z++;
        }
        if (c==2){
            s2++;
        } 

        slowa[slowo]=l;

        if (z>o) s1++;

    }
    out<<s1<<endl;
    out<<s2<<endl;
    out<<max<<endl;
    for(auto x:slowa){
        if(x.second==max) out<<x.first<<endl;
    }
    
    return 0;
    }