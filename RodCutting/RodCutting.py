p = []
p.append(0)#p의 index가 1부터 시작되도록 ,p[0]=0을 사용하면 안되고 append를 사용해야함
n = int(input())
for i in range(n):
    a= int(input())
    p.append(a)


r = [0 for i in range(11)] #r은 0부터 10까지 
s = [0 for i in range(11)] #s도 0부터 10까지

for j in range(1,n+1):
    q = float("-inf")
    for i in range(1,j+1):
        if q<p[i]+r[j-i]:
            q = p[i]+r[j-i]
            s[j]=i    
    r[j]=q
    
print(r[n]) 
while(n>0):
    print(s[n])
    n-=s[n]