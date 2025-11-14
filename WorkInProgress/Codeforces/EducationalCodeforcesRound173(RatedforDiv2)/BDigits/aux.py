for i in range(1, 100000):
    s = str(i*7)
    print(s[0])
    flag = True
    for x in s:
        if x != s[0]:
            flag = False
            break
        if flag:
            print(f"{s} {i}")
