T = int(input())
A, B, C, D, E = map(int, input().split())

r = 0
for i in [A, B, C, D, E]:
    if i == T:
        r += 1
print(r)