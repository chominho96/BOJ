mimm = ["Never gonna give you up", "Never gonna let you down", "Never gonna run around and desert you", "Never gonna make you cry", "Never gonna say goodbye", "Never gonna tell a lie and hurt you", "Never gonna stop"]

N = int(input())
ok = False

for i in range(N):
    p = input()
    if p not in mimm:
        ok = True
        break
        
if ok:
    print("Yes")
else:
    print("No")