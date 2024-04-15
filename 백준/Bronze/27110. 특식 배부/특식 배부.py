n = int(input())
chi = list(map(int, input().split()))
r = 0

for i in range(3):
    if chi[i] <= n:
        r += chi[i]
    else:
        r += n

print(r)