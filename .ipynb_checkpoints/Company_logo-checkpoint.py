# https://www.hackerrank.com/challenges/most-commons/problem
#!/bin/python3

import math
import os
import random
import re
import sys



if __name__ == '__main__':
    s = input()
dic = {}
lst = []
for i in s:
    if i not in dic:
        dic[i] = s.count(i)
        lst.append(s.count(i))
max1 = max(lst)
tmp = 127
so1 = ' '
for d in dic:
    if dic[d] == max1 and ord(d) < tmp: 
        tmp = ord(d)
        so1 = d
print(so1 + ' ' + str(dic[so1]))
lst.remove(dic[so1])
dic.pop(so1)

max2 = max(lst)
tmp = 127
so1 = ' '
for d in dic:
    if dic[d] == max2 and ord(d) < tmp: 
        tmp = ord(d)
        so1 = d
print(so1 + ' ' + str(dic[so1]))
lst.remove(dic[so1])
dic.pop(so1)

max3 = max(lst)
tmp = 127
so1 = ' '
for d in dic:
    if dic[d] == max3 and ord(d) < tmp: 
        tmp = ord(d)
        so1 = d
print(so1 + ' ' + str(dic[so1]))
lst.remove(dic[so1])
dic.pop(so1)





