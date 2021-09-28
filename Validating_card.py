# https://www.hackerrank.com/challenges/validating-credit-card-number/problem?h_r=next-challenge&h_v=zen&h_r=next-challenge&h_v=zen&h_r=next-challenge&h_v=zen&h_r=next-challenge&h_v=zen
def valid(n):
    #kiem tra dieu kien 1
    if(n[0] != '4' and n[0] != '5' and n[0] != '6'): return "Invalid"
    
    #kiem tra dieu kien 2,3,5
    num = 0
    for i in n: 
        if (ord(i) < 48 or ord(i) > 57) and ord(i) != 45: return "Invalid" #ham ord chuyen ASCII ve int
        else: 
            if ord(i) != 45: num += 1
    if num != 16: return "Invalid" 
    
    #kiem tra dieu kien 4
    yes = True
    if '-' in n:
        for j in range(len(n)):
             if(j in [4,9,14]): 
                 if n[j] != '-': yes = False
             else:
                 if n[j] == '-': yes = False
    if yes == False: return 'Invalid'
    
    #kiem tra dieu kien 6
    repeat = 1
    Max = 1
    N = n.replace('-','') # ham str.repace(str1,str2): thay the str1 bang str2 trong str
    for m in range(1,len(N)):
        if N[m] == N[m-1]: repeat += 1
        else: repeat = 1
        if repeat > Max: Max = repeat
    if Max > 3: return 'Invalid'
    
    return "Valid"
        
n = int(input())
lst = []
for i in range(n): lst.append(str(input())) 
for k in lst:
    print(valid(k))