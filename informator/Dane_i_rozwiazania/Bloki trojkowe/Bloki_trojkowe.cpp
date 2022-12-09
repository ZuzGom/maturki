//Bloki Trójkowe

#include <iostream>
#include <algorithm>

using namespace std;

int najdluzszy_blok()
{
  int poczatki[3] = {0, -1, -1}; 
  //poczatki[w] - pierwsza pozycja dla której suma s jest równa w
  // -1 oznacza, ze odpowiedniej pozycji jeszcze nie 
  // znaleziono
  int suma_mod_3 = 0; 
  int liczba_wczytanych = 0; 
  int element; 
  int najdluzszy = 0;

  while (cin >> element) {
    liczba_wczytanych++;  
    suma_mod_3 = (suma_mod_3 + element) % 3; //(*)
    if (poczatki[suma_mod_3] == -1)
      poczatki[suma_mod_3] = liczba_wczytanych;
    else
      najdluzszy = max(najdluzszy, liczba_wczytanych - poczatki[suma_mod_3]);
  }
  return najdluzszy;
}

int main()
{
  cout << "Dl bloku: " << najdluzszy_blok() << endl; 
  return 0;
}
