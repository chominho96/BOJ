input = [int(input()) for _ in range(4)]
if input[0] in [8,9] and input[-1] in [8, 9] and input[1] == input[2]:
    print("ignore")
else:
    print("answer")