from heapq import heappop,heappush

(n,m)=map(int,input().split())

#create graph in adj list format
graph=[]
for i in range(n):
    x={}
    graph.append(x)   
#adding edges to graph    
for _ in range(m):
    (u,v,w)=map(int,input().split())
    #since lists are indexed from zero 
    #here ever input nodes index are reduced by one for reduce complexity
    
    #adj edges of a node will store in dictionaries in the index of that node 
    #as a list which like [weight,to(v),from(u)]
    if ((v-1) in graph[u-1]):
        if(graph[u-1][v-1][0]>w):
            graph[u-1][v-1]=[w,v-1,u-1]
            graph[v-1][u-1]=[w,u-1,v-1]
    else:
        graph[u-1][v-1]=[w,v-1,u-1]
        graph[v-1][u-1]=[w,u-1,v-1]
                        
s=int(input()) #start vertex

visited=[]#already added nodes to our MST
visited.append(s-1)

tot_w=0 #weight of MST

que=[]  #to maintain a minimum heap
#initialize minimum heap with adj edges of node s
for i in graph[s-1]:
    heappush(que,graph[s-1][i])

while que:
    edge=heappop(que)
    toNode=edge[1]
    
    if toNode in visited:
        continue
        
    visited.append(toNode)
    tot_w += edge[0]
    for j in graph[toNode]:
        heappush(que,graph[toNode][j])

print(tot_w)


    
