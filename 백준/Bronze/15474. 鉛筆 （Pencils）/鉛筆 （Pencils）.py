n, a, b, c, d = map(int, input().split())
X = n // a
if n % a != 0:
    X += 1
Y = n // c
if n % c != 0:
    Y += 1

print(min(X * b, Y * d))