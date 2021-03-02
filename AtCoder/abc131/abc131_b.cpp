n,l=map(int,input().split())
r=l+n-1
print((l+r)*n//2-l*(l>0)-r*(r<0))
