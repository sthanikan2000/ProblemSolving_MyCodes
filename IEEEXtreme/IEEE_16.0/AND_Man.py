T=int(input())
for _ in range(T):
    N=int(input())
    
    W=list(map(int,input().split()))
    
    E=[list() for ____ in range(N)]
    # parent_E=[-1 for i in range(N)]
    
    for __ in range(N-1):
        edge=list(map(int,input().split()))
        E[edge[0]-1].append(edge[1]-1)
        E[edge[1]-1].append(edge[0]-1)
        
    # print(E)
    # print(parent_E)

    Q=int(input())
    for ___ in range(Q):
        (t,u,v)=map(int,input().split())
        
        if t==1:
            W[u-1]=v
            continue
        
        visited=[False for k in range(N)]
        visited[u-1]=True
        path=[u-1]
        mul=W[u-1]
        while path[-1]!=v-1:
            lst=E[path[-1]]
            inserted=False
            for i in lst:
                if not(visited[i]):
                    path.append(i)
                    mul*=W[i]
                    visited[i]=True
                    inserted=True
                    break
            if not(inserted):
                x=path.pop()
                mul//=W[x]
        # print(path)
        # mul=1
        # for j in path:
        #     mul*=W[j]
        print(mul%(1000000007))
        
    
    
    