#include <bits/stdc++.h>

using namespace std;

bool czy_pierwsza(int l){
    if (l<2) return false;
    for (int i=2;i<sqrt(l)+1;i++){
        if(l%i==0) return false;
    }
    return true;
}
int main(){
    
    return 0;
}