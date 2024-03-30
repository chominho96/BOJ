MOBIS = ['M', 'O', 'B', 'I', 'S']
word = input()
result = True

for i in MOBIS:
    if i not in word:
        result = False
        break

if result:
    print('YES')
else:
    print('NO')