def printMan(man):
    for i in man:
        for j in i:
            print(j,end="")
        print("")

def action(lst,man,manHandToBe,manLegToBe,left,right):
    if len(lst)==4:
        if lst[3]=="head":
            man[0][right]=manHandToBe[left][0]
            man[1][right]=" "
            printMan(man)
        elif lst[3]=="hip":
            man[1][right]=manHandToBe[left][1]
            man[0][right]=" "
            printMan(man)
        else:
            man[1][right]=manHandToBe[left][2]
            man[0][right]=" "
            printMan(man)
    elif len(lst)==3:
        if lst[2]=="in":
            man[2][right]=manLegToBe[left][0]
            printMan(man)
        else:
            man[2][right]=manLegToBe[left][1]
            printMan(man)


#for turning
pos=[")","("," ","<",">","/","\\"]
MirrPos=["(",")"," ",">","<","\\","/"]


#facing forward 
manHandToBe=[ [")",">","\\"] , ["(","<","/"] ]
manLegToBe=[ [">","\\"] , ["<","/"] ]



t=int(input())
for _ in range(t):
    man=[[" ", "o", " "],["/","|","\\"],["/"," ","\\"]]
    # for forward 
    left=0
    right=-1

    d=int(input())
    for __ in range(d):
        lst=input().split()
        
        if lst[0]=="say":
            for i in range(1,len(lst)):
                print(lst[i],end=" ")
            print("")
            continue
        
        if lst[0]=="turn":
            (left,right)=(right,left)
            for j in range(3):
                tem=man[j][:]
                for k in [0,2]:      
                    ind=pos.index(man[j][k])
                    tem[2-k]=MirrPos[ind]
                man[j]=tem
            printMan(man)
            continue
        
        if  lst[0]=="left":
            action(lst,man,manHandToBe,manLegToBe,left,right)
        else:
            action(lst,man,manHandToBe,manLegToBe,right,left)
            
                
        
        
        