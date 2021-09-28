// https://www.hackerrank.com/challenges/non-divisible-subset/problem
#include <bits/stdc++.h>
#include <vector>
using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'nonDivisibleSubset' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER k
 *  2. INTEGER_ARRAY s
 */

int nonDivisibleSubset(int k, vector<int> s) {
    vector<int> re;
    for(int i = 0; i < s.size(); i++){
        re.push_back(s.at(i) % k);
    }
    int sum = 0;
    for (int j = 1; j < (float)k/2; j++){
        int x1 = 0;
        int x2 = 0;
        for (int t = 0; t < re.size(); t++){
            if(re.at(t) == j) x1++;
            if(re.at(t) == k-j) x2++;
        }
        sum += ((x1>x2)?x1:x2);
    }
    if(k%2==0)
        for (int t = 0; t < re.size(); t++){
            if(re.at(t) == k/2){
                sum += 1;
                break;
            }
        }
    for (int l = 0; l < s.size(); l++){
        if(re.at(l) == 0){
            sum += 1;
            break;
        }
    }
    return sum;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string first_multiple_input_temp;
    getline(cin, first_multiple_input_temp);

    vector<string> first_multiple_input = split(rtrim(first_multiple_input_temp));

    int n = stoi(first_multiple_input[0]);

    int k = stoi(first_multiple_input[1]);

    string s_temp_temp;
    getline(cin, s_temp_temp);

    vector<string> s_temp = split(rtrim(s_temp_temp));

    vector<int> s(n);

    for (int i = 0; i < n; i++) {
        int s_item = stoi(s_temp[i]);

        s[i] = s_item;
    }

    int result = nonDivisibleSubset(k, s);

    fout << result << "\n";

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}

vector<string> split(const string &str) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}
