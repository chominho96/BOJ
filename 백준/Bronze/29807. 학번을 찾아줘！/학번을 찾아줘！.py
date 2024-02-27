result = 0

t = int(input())
sub = list(map(int, input().split())) + [0] * (5 - t)

if sub[0] > sub[2]:
    result += (sub[0] - sub[2]) * 508
else:
    result += (sub[2] - sub[0]) * 108

if sub[1] > sub[3]:
    result += (sub[1] - sub[3]) * 212
else:
    result += (sub[3] - sub[1]) * 305

if sub[4] > 0:
    result += sub[4] * 707

result *= 4763

print(result)