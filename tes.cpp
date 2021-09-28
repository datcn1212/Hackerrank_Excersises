#include <iostream>
#include <math.h>
#include <vector>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        int n; cin >> n;
        int a[n], b[n];
        for(int i = 0; i < n; i++){
            cin >> a[i];
        }
        for(int j = 0; j < n; j++){
            cin >> b[j];
        }
        int start = 0;
        int minn = 2*n;
        while(start <= minn){
            int s = a[start];
            for(int k = 0; k < n; k++){
                if(b[k] > s) {
                    minn = min(minn, start+k); 
                    break;
                }
            }
            start++;
        }
        cout << minn << endl;
    }
}