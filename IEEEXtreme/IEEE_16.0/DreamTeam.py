def getPlayer():
    x=int(input())
    lstPlayer=[]
    for _ in range(x):
        temp=input().split()
        temp[1]=int(temp[1])
        lstPlayer.append(temp)
    return (lstPlayer,x)
        

# get inputs
B=int(input())
(lstP,P)=getPlayer()
(lstG,G)=getPlayer()
(lstS,S)=getPlayer()
(lstF,F)=getPlayer()
(lstC,C)=getPlayer()

maxSal=0
dreamTeams=[]


for p in lstP:
    dreamTeam=[p[0],"","","",""]
    dreamSal=p[1]
    
    if dreamSal>B:
        dreamSal-=p[1]
        continue
    
    for g in lstG:
        dreamTeam[1]=g[0]
        dreamSal+=g[1]
        
        if dreamSal>B:
            dreamSal-=g[1]
            continue
        
        for s in lstS:
            dreamTeam[2]=s[0]
            dreamSal+=s[1]
            
            if dreamSal>B:
                dreamSal-=s[1]
                continue
            
            for f in lstF:
                dreamTeam[3]=f[0]
                dreamSal+=f[1]
                
                if dreamSal>B:
                    dreamSal-=f[1]
                    continue
                for c in lstC:
                    dreamTeam[4]=c[0]
                    dreamSal+=c[1]
                    if dreamSal>=maxSal and dreamSal<=B:
                        if dreamSal==maxSal:
                            dreamTeams.append(dreamTeam[:])
                        else:
                            dreamTeams=[dreamTeam[:]]
                        maxSal=dreamSal
                    dreamSal-=c[1]
                dreamSal-=f[1]
            dreamSal-=s[1]
        dreamSal-=g[1]
    dreamSal-=p[1]

Teams=[]
for team in dreamTeams:
    t=""
    for mem in team:
        t+=(mem+" ")
    Teams.append(t)
Teams.sort()
lst=Teams[0].split()
for i in lst:
    print(i)
        
        
        
        
        
        
        