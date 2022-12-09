#include <iostream>
#include <string>
using namespace std;

int reszta(string b, int p){
    const char zero = '0';
    
    int dl = b.length(); //obliczenie d³ugoœci zapisu liczby b
    int d = 0; //po zakoñczeniu obliczeñ wartoœci¹ d bêdzie wartoœæ dziesiêtna
               //liczby b modulo p
    
    // schemat Hornera modulo p
    for (int j = 0; j < dl; j++){
        int cyfra = b[j] - zero; //odzyskanie kolejnej cyfry liczby b
                                 //poczynaj¹c od najbardziej znacz¹cej
        d = (d * 2 + cyfra) % p; //% jest operatorem modulo w C++
    }
    return d;      
}

int main(){
    string liczba;
    const int n = 1000; //rozmiar danych
    int podz_2 = 0, podz_3 = 0, podz_5 = 0; // podz_p - liczba liczb 
                                            // podzielnych przez p    
    for (int i = 0; i < n; i++){        
        cin >> liczba; //wczytanie kolejnej liczby;

        if (reszta(liczba, 2) == 0) podz_2++;
        if (reszta(liczba, 3) == 0) podz_3++;
        if (reszta(liczba, 5) == 0) podz_5++;
    }
        
    cout << "podzielne przez " << 2 << " : " << podz_2 << endl;
    cout << "podzielne przez " << 3 << " : " << podz_3 << endl;
    cout << "podzielne przez " << 5 << " : " << podz_5 << endl;
    
    return 0;
}



