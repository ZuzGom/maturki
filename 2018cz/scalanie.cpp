#include <bits/stdc++.h>
using namespace std;
int main(){
    fstream in1("maturki/2018cz/Dane/dane1.txt");
    fstream in2("maturki/2018cz/Dane/dane2.txt");
    ofstream out("maturki/2018cz/wyniki4_1.txt");
    ofstream out2("maturki/2018cz/wyniki4_4.txt");
    int c1=0,c2=0,c3=0;
    vector <int> c;
    for (int t=0;t<1000;t++){
        vector <int> one;
        vector <int> two;
        set <int> first;
        set <int> second;
        int p1=0,p2=0;
        for (int i=0;i<10;i++){
            int a;
            in1>>a;
            if (a%2==0)p1++;
            one.push_back(a);
            first.insert(a);
        }
        for (int i=0;i<10;i++){
            int b;
            in2>>b;
            if (b%2==0)p2++;
            one.push_back(b);
            second.insert(b);

        }
        if (one[9]==one[19]) c1++;
        sort(one.begin(),one.end());
        for (auto x:one) out2<<x<<" ";
        out2<<endl;
        if (p1==5&&p2==5) c2++;
        if (first==second){
            c3++;
            c.push_back(t+1);
        } 
    }
    out<<c1<<endl<<c2<<endl;
    out<<c3<<endl;
    for(auto x:c) out<<x<<" ";
    
    return 0;

}