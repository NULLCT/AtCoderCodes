n=int(input())
a = list(map(int,input().split()))
ans=1
for i in range(n):
    ans*=a[i]
    if ans > 1000000000000000000:
        for q in range(n-i):
            if a[i+q] == 0:
                print(0)
                exit()
        print(-1)
        exit()
else:
    print(ans)

