n = int(input())

for i in range(0, n):
    a, b, c, d = input().split()
    if int(a) * int(b) > int(c) * int(d):
        print("TelecomParisTech")
    elif int(a) * int(b) == int(c) * int(d):
        print("Tie")
    else:
        print("Eurecom")

