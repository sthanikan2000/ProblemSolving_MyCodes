#!/bin/python3

import math
import os
import random
import re
import sys

from heapq import heappush,heappop,heapify
from math import inf as INFINITY

def SynShopping():
    (n,m,k) = map(int,input().split())

    shops = [0]*n

    for _ in range(n):
        temp = list(map(int,input().split()))
        for j in temp[1:]:
            shops[_] |= 1<<(j-1)
            
    graph = [list() for _ in range(n)]
    for _ in range(m):
        (u,v,w) = map(int,input().split())
        graph[u-1].append((v-1,w))
        graph[v-1].append((u-1,w))
        
    k_mask = 1<<k
    dis = [[INFINITY]*k_mask for _ in range(n)]
    que = [(0,0,shops[0])]  #min heap priority queue
    while que:
        (d,s,f) = heappop(que)
        if dis[s][f] < 0: continue
        for i,e in graph[s]:
            g = f|shops[i]
            a,b = dis[i][g],d+e
            if b < a:
                dis[i][g] = b
                heappush(que,(b,i,g))
        dis[s][f] = -dis[s][f]
    dis = [-d if d < 0 else d for d in dis[n-1]]

    time_min = INFINITY
    for i in range(k_mask):
        if dis[i] >= time_min: 
            continue
        for j in range(k_mask):
            if i|j != k_mask-1: 
                continue
            if dis[j] >= time_min: 
                continue
            time_min= max(dis[i],dis[j])
    return (time_min)
    



if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    res=SynShopping()

    fptr.write(str(res) + '\n')

    fptr.close()
