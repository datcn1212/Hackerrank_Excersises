#include <iostream> 
#include<queue>
#include<string.h>
using namespace std ;
int main() {
    char str[] = "MADAM";
    queue<char> Q;
    for(int i = 0; i < sizeof(str)-1; i++){
        Q.push(str[i]);
    }
    cout << sizeof(str);
    int q = 0;
    for(int i = sizeof(str)-2; i >= 0; i--){
        if(Q.front() == str[i]) Q.pop();
        else{
            q = 1;
            break;
        }
    }
    if (q==0) cout<< "true";
    else cout << "false";
}