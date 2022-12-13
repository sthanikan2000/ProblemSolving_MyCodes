n=int(input())
bestFriends={}
for i in range(n):
    (u,v)=map(int,input().split())
    bestFriends[u]=v
m=int(input())
inv=(map(int,input().split()))
s=set()

for j in inv:
    x=j
    s.add(x)
    for k in range(1,n):
        y=bestFriends[x]
        x=y
        s.add(y)
print(len(s))
        

        