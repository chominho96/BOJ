N = int(input())
s = list(map(int, input().split()))
t = sum(s) + (8 * (N-1))

print(t // 24, t % 24)