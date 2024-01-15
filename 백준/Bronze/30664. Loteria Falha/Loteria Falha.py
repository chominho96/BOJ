while True:
    a = int(input())
    if a == 0:
        break
    if a % 42 == 0:
        print("PREMIADO")
    else:
        print("TENTE NOVAMENTE")