from heapq import heappush,heappop,heapify

(n,m)=map(int,input().split())
task=list(map(int,input().split()))
task.sort()
w_t=[0 for i in range(m)]
min_time=0
if m==1:
    for i in task:
        w_t[0]+=1<<i
        
elif len(task)<=m :
    w_t[0]=1<<task.pop()
    
else:
    while task:
        #t=pow(2,task.pop()) #int(pow(2, p))
        t=1<<(task.pop())
        heappush(w_t,heappop(w_t)+t)
        # for i in range(m):
        #     if w_t[i]==min_time:
        #         w_t[i]+=t
        #         break
        # min_time=min(w_t)
        #print(w_t)
        
print(max(w_t)%(10**9+7))
        
                