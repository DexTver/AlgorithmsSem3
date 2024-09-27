array_time = [0 for i in range(10)]
list_time = [0 for i in range(10)]
bits_time = [0 for i in range(10)]
mword_time = [0 for i in range(10)]

mode = 1

with open("cmake-build-debug/logs.txt", mode="r", encoding="utf-8") as f:
    a = list(f.readlines())
    for s in a:
        x = s.split()
        if len(x) == 1:
            mode = int(x[0])
        else:
            if x[0] == "Array":
                if array_time[mode - 1] == 0:
                    array_time[mode - 1] = int(x[-2])
                else:
                    array_time[mode - 1] = (int(x[-2]) + array_time[mode - 1]) // 2
            if x[0] == "List":
                if list_time[mode - 1] == 0:
                    list_time[mode - 1] = int(x[-2])
                else:
                    list_time[mode - 1] = (int(x[-2]) + list_time[mode - 1]) // 2
            if x[0] == "Bits":
                if bits_time[mode - 1] == 0:
                    bits_time[mode - 1] = int(x[-2])
                else:
                    bits_time[mode - 1] = (int(x[-2]) + bits_time[mode - 1]) // 2
            if x[0] == "MWord":
                if mword_time[mode - 1] == 0:
                    mword_time[mode - 1] = int(x[-2])
                else:
                    mword_time[mode - 1] = (int(x[-2]) + mword_time[mode - 1]) // 2

for x in array_time:
    print(x, end='\t')
print()

for x in list_time:
    print(x, end='\t')
print()

for x in bits_time:
    print(x, end='\t')
print()

for x in mword_time:
    print(x, end='\t')
print()
