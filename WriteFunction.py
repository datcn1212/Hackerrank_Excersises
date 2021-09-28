#https://www.hackerrank.com/challenges/write-a-function/problem
def is_leap(year):
    # Write your logic here
    if year%4 != 0 :  return False
    else:
        if year % 400 == 0: return True
        else: 
            if(year % 100 == 0): return False
            else: return True
            
year = int(input())
print(is_leap(year))