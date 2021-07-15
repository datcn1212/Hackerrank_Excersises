#include <iostream>
#include <vector>
using namespace std;

vector<int> climbingLeaderboard(vector<int> ranked, vector<int> player)
{
    vector<int> temp;
    for (int i = 0; i < player.size(); i++)
    {
        int at = 2;
        if (player.at(i) >= ranked.at(0))
            at = 1;
        else
        {
            for (int j = 1; j < ranked.size(); j++)
            {
                if (ranked.at(j - 1) != ranked.at(j) && player.at(i) < ranked.at(j))
                    at++;
            }
        }
        temp.push_back(at);
    }
    return temp;
}

int main()
{
    int n, m;
    vector<int> ranked, player;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        ranked.push_back(temp);
    }
    cin >> m;
    for (int j = 0; j < m; j++)
    {
        int temp;
        cin >> temp;
        player.push_back(temp);
    }
    for (int k = 0; k < climbingLeaderboard(ranked, player).size(); k++)
    {
        cout << climbingLeaderboard(ranked, player).at(k) << endl;
    }
}