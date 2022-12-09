from math import sqrt

def czy_pierwsza(x):
	if x<2:
		return False
	for i in range(1,int(sqrt(x))):
		if x%(i+1) == 0:
			return False
	return True

def superB(a,b):
	liczby=[]
	for i in range(a,b+1):
		if czy_pierwsza(i):
			suma=0
			sumaB=0
			for x in str(i):
				suma+=int(x)
			for x in str(bin(i))[2:]:	
				sumaB+=int(x)
				
			if czy_pierwsza(suma) and czy_pierwsza(sumaB):
				liczby.append(i)
	return len(liczby), liczby
	
print("przedzial 2,1000:",superB(2,1000))
print("przedzial 100,10000:",superB(100,10000))
print("przedzial 1000,100000:",superB(1000,100000))

licznik=0
for i in range(100,10001):
	suma=0
	for x in(str(i)):
		suma+=int(x)
	if czy_pierwsza(suma):
		licznik+=1
print("w przedziale 100,10000 jest",licznik,"liczb ktorych suma jest liczba pierwsza")
		

print(czy_pierwsza(sum(superB(100,10000)[1])))