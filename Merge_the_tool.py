# https://www.hackerrank.com/challenges/merge-the-tools/problem
def merge_the_tools(string, k):
    # your code goes here
    lst = []
    result = []
    for i in range(int(len(string)/k)):
        lst.append(string[k*i:k*i+k])
    for s in lst:
        temp = []
        for i in s: 
            if i not in temp: temp.append(i)
        result.append(''.join(temp))
    for x in result:
        print(x)
if __name__ == '__main__':
    string, k = input(), int(input())
    merge_the_tools(string, k)