// https://www.hackerrank.com/challenges/repeated-string/problem?h_l=interview&playlist_slugs%5B%5D=interview-preparation-kit&playlist_slugs%5B%5D=warmup&h_r=next-challenge&h_v=zen
#include <iostream>

using namespace std;

long long repeatedString(string s, long long n)
{
    long long repeat = n / (s.length()), count1 = 0;
    int remainder = n % (s.length()), count2 = 0;
    for (int i = 0; i < s.length(); i++)
    {
        if (s.at(i) == 'a' && i < remainder)
        {
            count1++;
            count2++;
        }
        if (s.at(i) == 'a' && i >= remainder)
            count1++;
    }
    return repeat * count1 + count2;
}
int main()
{
    repeatedString("a", 1000000000000);
    repeatedString("aaba", 100000);
}