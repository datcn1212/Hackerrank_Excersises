#https://www.hackerrank.com/challenges/validating-uid/problem?h_r=next-challenge&h_v=zen&h_r=next-challenge&h_v=zen&h_r=next-challenge&h_v=zen
def valid(n):
    if(len(n) != 10): return "Invalid"
    else:
        up = 0
        digit = 0
        for i in n: 
            if n.count(i) > 1: return "Invalid"
            if ord(i) < 48 or (58 <= ord(i) <= 64) or (91 <= ord(i) <= 96) or ord(i) > 122 : return "Invalid"
            if 65 <= ord(i)  <= 90 : up+= 1
            if 48 <= ord(i)  <= 57 : digit+= 1
        if up < 2: return "Invalid"
        if digit <3: return "Invalid"
    return "Valid"
        
n = int(input())
lst = []
for i in range(n): lst.append(str(input())) 
for j in lst:
    print(valid(j))