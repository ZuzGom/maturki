#include <bits/stdc++.h>
using namespace std;

int osto10(string bin){
        int wyn=0;
for(int i=1;i<=bin.size();i++){
wyn += (bin[bin.size()-i] - 48) * pow(8,i-1);
}
return wyn;
}

bool podc(string s){
    char y = s[0];
    for(auto x:s) {
        if (x<y) return false;
        y = x;
    }
    return true;
}

int main(){
    fstream input("maturki/2013/Dane/dane.txt");
    ofstream output("maturki/2013/wyniki6.txt");
    int s1=0,s2=0,s3=0,max=0, min = 2147483647;
    string maxi,mini;

    for(int p=0;p<5000;p++){
        string liczba;
        input>>liczba;
        int os = osto10(liczba);
        if(liczba[0]==liczba[liczba.size()-1]) s1++;
        string oss = to_string(os);
        if(oss[0]==oss[oss.size()-1]) s2++;
        if(podc(liczba)){
            if(max<os){
                max=os;
                maxi=liczba;
            }
            if(min>os){
                min=os;
                mini=liczba;
            }
            s3++;
        } 


    }
    output<<s1<<endl<<s2<<endl;
    output<<s3<<endl<<"max: "<<max<<" "<<maxi<<endl;
    output<<"min: "<<min<<" "<<mini<<endl;
    return 0;
    }