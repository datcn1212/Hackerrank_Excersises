def git(a):
    n = len(a)
    lst = [a[x] for x in range(n)]
    while n > 0:
        n -= 1
        s = lst.pop()
        print(str(s),end="")
git("StrinG")  