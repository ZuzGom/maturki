#include <bits/stdc++.h>
using namespace std;


unsigned long long pot(long a,long b){
    unsigned long long wyn = 1;
    for (int i=0;i<b;i++){
        wyn*=a;
    }
    return wyn;
}

unsigned long long bto10 (string bin) {
    unsigned long long wyn=0;
for(int i=1;i<=bin.size();i++){
    //cout<<wyn<<endl;
wyn += (bin[bin.size()-i] - 48) * pot(2,i-1);
}
return wyn;
}

int main(){
    fstream input("maturki/2015 nowa/Dane_PR2_n/liczby.txt");
    ofstream output("maturki/2015 nowa/zadanie4.txt");
    unsigned long long max=0,min=2147483647,m,n;
    long s1=0,s2=0,s3=0;
    for (int t=0;t<1000;t++){
        string bin;
        input>>bin;
        int o=0,z=0;
        for(auto& x:bin){
            if (x=='0') z++ ;
            else o++;
        } 
        if (o>z) s1++;
        unsigned long long dec = bto10(bin);
        //cout<<bin<<endl;
        //cout<<dec<<endl;
        if (dec%2==0) s2++;
        if (dec%8==0) s3++;
        if (dec>max){
            max=dec;
            m=t+1;
        }
        if (dec<min){
            min=dec;
            n=t+1;
        }
    }
    output<<"1. "<<endl;
    output<<s1<<endl;
    output<<"2. "<<endl;
    output<<s2<<" "<<s3<<endl;
    output<<"3. "<<endl;
    output<<n<<" "<<m<<endl;
    output<<min<<" "<<max<<endl;
    return 0;
    }