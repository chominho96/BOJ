a, b, c = map(int, input().split())

if (a == 1 and b == c == 0) or (a == 0 and b == c == 1):
    print("A")
elif (b == 1 and a == c == 0) or (b == 0 and a == c == 1):
    print("B")
elif (c == 1 and a == b == 0) or (c == 0 and a == b == 1):
    print("C")
else:
    print("*")