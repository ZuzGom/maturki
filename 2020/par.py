input = open("maturki/2020/Dane_PR2/pary.txt")
wynik = open("maturki/2020/wynik.txt","w")



def czy_pierwsza(n):
    if n==1: return False
    for i in range(2,int(n**0.5)+1):
        if(n%i==0): return False
    return True


for _ in range(100):
    linia = input.readline().split()

    liczba=int(linia[0])
    guwno=linia[1]
    #print(liczba,guwno)
    if liczba%2==0:
        for i in range(1,liczba):
            if czy_pierwsza(i) and czy_pierwsza(liczba-i):
                print(liczba, i,liczba-i)
                break


