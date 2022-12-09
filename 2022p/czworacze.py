A= [True] * 200001

A[0], A[1] = False, False
i =2
while i<=200000:
    if A[i]:
        j=i+i
        while j<=200000:
            A[j]=False
            j+=i
        
    i+=1

i=1
while i<=2000000-8:
    if A[i] and A[i+2] and A[i+6] and A[i+8]:
        print(i,i+2,i+6,i+8)
    i+=1
'''
for i, v in enumerate(A):
    if v==True:
        print(i)
'''
print(A[:100])
