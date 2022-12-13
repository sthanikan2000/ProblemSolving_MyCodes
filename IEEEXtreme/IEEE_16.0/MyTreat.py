t=int(input())
for _ in range(t):
    m=int(input())
    din={}
    
    for __ in range(m):
        inp=input().split()
        if inp[0] in din:
            din[inp[0]]+=int(inp[1])
        else:
            din[inp[0]]=int(inp[1])
        for i in range(2,len(inp)):
            if inp[i] in din:
                din[inp[i]]-=1
            else:
                din[inp[i]]=-1
    lstPos=[]
    lstNeg=[]
    for j in din:
        if din[j]>0:
            lstPos.append(din[j])
    print("%i %i"%(sum(lstPos),max(lstPos)))
        