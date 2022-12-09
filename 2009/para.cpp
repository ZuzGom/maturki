#include <bits/stdc++.h>
using namespace std;

bool czy_pali(string s){
    int d= s.size() -1;
    for (int i=0;i<d/2;i++){
        if (s[i]!=s[d]) return false;
        d--;
    }
    return true;
}

int main(){
    fstream input("maturki/2009/Dane/dane.txt");
    ofstream output("maturki/2009/slowa.txt");
    ofstream o2("maturki/2009/zad_5.txt");
    string A, B; 
    int s1=0,s2=0,s3=0;
    for (int t=0;t<200;t++){
        input>>A>>B; 
        if(czy_pali(A)) s1++;
        if(czy_pali(B)) s1++;
        int i=0;
        int e=0;
        for(int j=0;j<A.size();j++){
            if(i==B.size()-1){
                e=j;
                break;
            } 
            if(A[j]==B[i]) i++;
            else i=0;
            
        }

        if (e>0) {
            s2++;
            output<<A<<endl;

        }
        
        else{

        i=0;
        int j=B.size()-1;
        string w1="",w2="";
        while(j>=0){
            if (A[i]!=B[j]) break;
            j--;
            i++;
        }
        for(int i=0;i<=j;i++){
            w1+=B[i];
        }
        w1+=A;


        i=0;
        j=A.size()-1;
        while(j>=0){
            if (A[j]!=B[i]) break;
            j--;
            i++;
        }
        for(int i=0;i<=j;i++){
            w2+=A[i];
        }

        w2+=B;

        //cout<<w1<<endl;
        //cout<<w2<<endl<<endl;
        if(w2.size()<w1.size()) {
            output<<w2<<endl;
            if (w2.size()==A.size()+B.size()) s3++;
        }
        else{
            output<<w1<<endl;
            if (w1.size()==A.size()+B.size()) s3++;
        } 
        }

    }
    o2<<s1<<endl<<s2<<endl<<s3<<endl;
    return 0;
}