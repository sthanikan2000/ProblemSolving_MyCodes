#!/bin/python3

import math
import os
import random
import re
import sys

#
# Complete the 'minimumMoves' function below.
#
# The function is expected to return an INTEGER.
# The function accepts following parameters:
#  1. STRING_ARRAY grid
#  2. INTEGER startX
#  3. INTEGER startY
#  4. INTEGER goalX
#  5. INTEGER goalY
#

def minimumMoves(grid, startX, startY, goalX, goalY):
    goal = (goalX, goalY)
    q = [[(startX,startY)]] #2D queue which element is tuples
    v_cells = set() #visited cells
    while q:
        path = q.pop(0)
        current = path[-1]
        
        if current == goal:
            return len(path)-1 #final only return
        
        #modifying x results horizontal shifts
        #modifying y results vertical shifts\
        
        x = current[0]
        y = current[1]-1 #go up     

        while y>=0 and grid[x][y] != 'X':
            if (x, y) not in v_cells:
                q.append(path + [(x,y)])
                v_cells.add((x,y))
            y-=1 
            
        
        x = current[0]+1  #go right
        y = current[1]
        
        while x<len(grid[0]) and grid[x][y] != 'X': 
            if (x, y) not in v_cells:
                q.append(path + [(x, y)])
                v_cells.add((x,y))
            x+=1
            
        
        x = current[0] 
        y = current[1]+1   #go down   

        while y<len(grid) and grid[x][y] != 'X':
            if (x, y) not in v_cells:
                q.append(path + [(x,y)])
                v_cells.add((x,y))
            y+=1
        
        
        x = current[0]-1 #go left
        y = current[1]
        
        while x>=0 and grid[x][y] != 'X': 
            if (x, y) not in v_cells:
                q.append(path + [(x, y)])
                v_cells.add((x,y))
            x-=1

if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    n = int(input().strip())

    grid = []

    for _ in range(n):
        grid_item = input()
        grid.append(grid_item)

    first_multiple_input = input().rstrip().split()

    startX = int(first_multiple_input[0])

    startY = int(first_multiple_input[1])

    goalX = int(first_multiple_input[2])

    goalY = int(first_multiple_input[3])

    result = minimumMoves(grid, startX, startY, goalX, goalY)

    fptr.write(str(result) + '\n')

    fptr.close()
