import sys
out=sys.stdout.write
S=list(sys.stdin.readline().rstrip())
ansk=""
ansy=""
for i in S:
    if i=='K' and ansk=='':ansk+=i
    elif i=='O'and ansk=='K':ansk+=i
    elif i=='R'and ansk=='KO':ansk+=i
    elif i=='E'and ansk=='KOR':ansk+=i
    elif i=='A'and ansk=='KORE':ansk+=i

    if i=='Y'and ansy=='':ansy+=i
    elif i=='O'and ansy=='Y':ansy+=i
    elif i=='N'and ansy=='YO':ansy+=i
    elif i=='S'and ansy=='YON':ansy+=i
    elif i=='E'and ansy=='YONS':ansy+=i
    elif i=='I'and ansy=='YONSE':ansy+=i

    if ansk=="KOREA":out(ansk);break
    elif ansy=="YONSEI":out(ansy);break