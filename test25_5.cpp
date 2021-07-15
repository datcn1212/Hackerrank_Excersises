#include<iostream>
using namespace std;

void selectionSort(int a[], int n){
    int min,temp;
    int number = 0;
    for( int i = 0; i< n; i++){
        number++;
        min = i;
        for(int j = i+1; j < n; j++){
            if(a[j] < a[min]) min = j;
        }
        if(min != i){
            temp = a[min];
            a[min] = a[i];
            a[i] = temp;
        }
        cout << number << ")" << " ";
        for(int k = 0; k< n; k++){
            cout << a[k] << " ";
        }
        cout <<endl;
    }
}
int main(){
    int a[] = {5,8,4,23,2,41,89};
    selectionSort(a,7);
}