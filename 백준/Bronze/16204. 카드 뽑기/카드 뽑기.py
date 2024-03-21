n, m, k = map(int, input().split())
a = min(m, k) + min(n - m, n - k)
print(a)