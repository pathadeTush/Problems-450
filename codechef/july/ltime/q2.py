try:
    t = int(input())
    for i in range(t):
        n, d, h = input().split(' ')
        n = int(n)
        d = int(d)
        h = int(h)

        s = input()
        arr = list(s.split(' '))
        level = 0
        for j in range(len(arr)):
          #  print(arr[i])
            if(int(arr[i]) > 0):
                level += int(arr[i])
            else:
                if(level < d):
                    level = 0
                else:
                    level -= d
            
            if(level > h):
                print("YES")
                break
        else:
            print("NO")

except:
    pass
