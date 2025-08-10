import math
import sys
sys.set_int_max_str_digits(20000)

[w,h,n,k]=input().split()
w=int(w)
h=int(h)
n=int(n)
k=int(k)

points = []
f=[]

for i in range(n):
    [x,y] = input().split()
    x=int(x)
    y=int(y)
    
    if (x==0 and y==0) or (x==w-1 and y==h-1):
        print(-1)
        exit(0)
    
    points.append((x,y))
    f.append(0)

points.append((0,0))
f.append(0)

points.append((w-1,h-1))
f.append(0)

points.sort()

# for t in points:
#     print(t)

f[0]=1

M=0
for i in range(1,n+2):
    (X,Y)=points[i]
    for j in range(i):
        (x,y)=points[j]
        if x<=X and y<=Y:
            f[i] = f[i]-f[j]*math.comb(X-x+Y-y,X-x)
    
    # print(points[i],f[i])

M=-f[n+1]
# print(M)

if M==0 or M<k:
    print(-1)
else:
    # p = math.pow(k/M,1/(w+h-1))
    pp=(math.log2(k)-math.log2(M))/(w+h-1)
    p=math.exp2(pp)
    print(p)