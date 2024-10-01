with open("logs.txt", "r") as f:
    a = [line for line in f]
    s = 0
    for k in range(10):
        for i in range(1 + 5 * k, 5 + 5 * k):
            for j in range(i, len(a), 5 * 10):
                s += int(a[j].split()[-2])
            print(s // (len(a) // 50), end=" ")
            s = 0
        print()
