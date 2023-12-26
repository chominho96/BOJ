while True:
    try:
        s, n = map(int, input().split())
        print(n // (s + 1))
    except EOFError:
        break