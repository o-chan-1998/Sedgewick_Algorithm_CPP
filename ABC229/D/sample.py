#しゃくとり法
s="XX...X.X.X."
n=len(s)
k=3
left=0
ans=0
for right in range(n):
    if s[right]=='X':
        pass
    # 与えられた文字列が「.」である場合
    else:
        if k>0:
            k-=1
        else:
            print(left,right,ans,k)
            input("-"*30)
            while k<=0:
                if s[left]=='X':
                    left+=1
                else:
                    left+=1
                    k+=1
            k-=1
    ans=max(ans,right-left+1)

print(ans)