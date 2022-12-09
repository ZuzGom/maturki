#include <bits/stdc++.h>
using namespace std;


int main(){
    fstream tj("maturki/2012/Dane_PR/tj.txt"),k1("maturki/2012/Dane_PR/klucze1.txt");
    fstream sz("maturki/2012/Dane_PR/sz.txt"),k2("maturki/2012/Dane_PR/klucze2.txt");
    ofstream out1("maturki/2012/zadanie4a.txt"), out2("maturki/2012/zadanie4b.txt");
    for (int t=0;t<120;t++){
        string tekst,klucz,wyn="";
        tj>>tekst;
        k1>>klucz;
        //cout<<tekst<<" "<<klucz<<endl;
        int i=0;
        while (i<tekst.size()){
            for(int j=0;j<klucz.size();j++){
                if (i>tekst.size()-1) break;
                int l = tekst[i] + klucz[j] - 64; 
                if(l>90) l-=26;
                out1<<(char)(l);
                i++;                
            }
            
        }
        out1<<endl;
        sz>>tekst;
        k2>>klucz;
        i=0;

        while (i<tekst.size()){
            for(int j=0;j<klucz.size();j++){
                if (i>tekst.size()-1) break;
                int l = tekst[i] - klucz[j] + 64; 
                if(l<65) l+=26;
                out2<<(char)(l);
                i++;                
            }
            
        }
        out2<<endl;
    }
    return 0;
    }