#!python3
from numpy import poly1d

n, m = map(int, input().split())
a = list(map(int, input().split()))
c = list(map(int, input().split()))

# 多項式インスタンスの生成
pa = poly1d(list(reversed(a)))
pc = poly1d(list(reversed(c)))

# Bを求める
pb = pc / pa
# Bの係数
res = list(map(int, pb[0].c))

# 順番を逆にして出力
ans = list(reversed(res))
print(*ans)

