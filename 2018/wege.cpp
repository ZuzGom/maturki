#include <bits/stdc++.h>
using namespace std;


bool czy_odd(string s){

}

int main(){
    fstream input("maturki/2018/Dane/sygnaly.txt");
    ofstream out("maturki/2018/wyniki4.txt");
    vector <pair<string,int>> sygnaly;  
    string wyn="";
    int max=0;
    for(int t=0;t<1000;t++){
        unordered_map <char,int> ascii;
        string sygnal;
        input>>sygnal;
        for(auto s:sygnal) ascii[s]++;
        if(ascii.size()>max) max = ascii.size();
        sygnaly.push_back({sygnal,ascii.size()});

        if ((t+1)%40==0) wyn+=sygnal[9];
        string s = sygnal;
        sort(s.begin(),s.end());
        if(s[s.size()-1]-s[0]<=10) out<<sygnal<<endl;
    }
    out<<wyn<<endl;
    for(auto x:sygnaly){
        if(x.second==max){
            out<<x.first<<" "<<x.second<<endl;
            break;
        }
    } 

    return 0;
    }