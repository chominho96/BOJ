N, X = map(int, input().split())
socks = list(map(int, input().split()))
price = []

for i in range(N - 1):
    price.append((socks[i] + socks[i + 1]) * X)

print(min(price))