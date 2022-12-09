#include <bits/stdc++.h>
using namespace std;

bool sl(vector <string> s){
    int d=s[0].size();
    for (auto x:s) if (x.size()!=d) return false;
    return true;
}

bool ana(vector <string> s){
    
    for (auto& x:s){
        sort(x.begin(),x.end());
        if(x!=s[0]) return false;
    } 
    return true;
}

int main(){
    fstream input("maturki/2010/Dane_PR/anagram.txt");
    ofstream out1("maturki/2010/odp_4a.txt");
    ofstream out2("maturki/2010/odp_4b.txt");

    for (int t=0;t<200;t++){
        vector <string> slowa;
        for(int p=0;p<5;p++){
            string pom;
            input>>pom;
            slowa.push_back(pom);
        }
        if(sl(slowa)){
            for(auto x:slowa) out1<<x<<" ";
            out1<<endl;
        
        if(ana(slowa)){ 
        for(auto x:slowa)out2<<x<<" ";
            out2<<endl;
        }
        }
        
    }
    
    return 0;
    }