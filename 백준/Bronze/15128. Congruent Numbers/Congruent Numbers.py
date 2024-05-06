p1, q1, p2, q2 = map(int, input().split())
res = p1 / q1 * p2 / q2 / 2
print(1 if int(res) == res else 0)