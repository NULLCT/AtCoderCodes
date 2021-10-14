s = input()

res0 = 0

for i in range(len(s)):
    if s[i] != str(i % 2):
        res0+=1

res1 = 0

for i in range(len(s)):
    if s[i] != str((i+1) % 2):
        res1+=1

print(min(res0,res1))
