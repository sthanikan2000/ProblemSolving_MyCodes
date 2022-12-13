(n,p)=map(int,input().split())
new_dis=0
dis=[-1]*n  #district number for each students
stu_grp={}  #Students grouped with respect to districts
dup_dis=[]
for _ in range(p):
    (st1,st2)=map(int,input().split())
    if (dis[st1]==-1 and dis[st2]==-1):
        dis[st1]=dis[st2]=new_dis
        stu_grp[new_dis]=[st1,st2]
        new_dis+=1
    elif(dis[st1]!=-1 and dis[st2]==-1):
        dis[st2]=dis[st1]
        stu_grp[dis[st1]].append(st2)
    elif(dis[st2]!=-1 and dis[st1]==-1):
        dis[st1]=dis[st2]
        stu_grp[dis[st2]].append(st1)
    elif(dis[st1]!=dis[st2]):
        dup_dis.append(dis[st2])
        stu_grp[dis[st1]]=stu_grp[dis[st1]]+stu_grp[dis[st2]]
        for j in stu_grp[dis[st2]]:
            dis[j]=dis[st1]
#print(stu_grp)
#print(dis)
#print(dup_dis)
dis_stu_cou=[]#student counts of different districts           
for i in range(new_dis):
    if i in dup_dis:
        continue
    dis_stu_cou.append(len(stu_grp[i]))
for j in dis:
    if j==-1:
        dis_stu_cou.append(1)
total=0
key=dis_stu_cou.pop()
while dis_stu_cou:
    for x in dis_stu_cou:
        total+=key*x
    key=dis_stu_cou.pop()
print(total)
