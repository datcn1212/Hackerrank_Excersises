// cho 1 array, tìm xem có bộ 3 tạo thành cấp số cộng ko, nếu có in ra bộ ba nhỏ nhất theo alphabet
// ứng dụng binary search
#include<iostream>
using namespace std;

void selectionSort(int a[], int n){ // sap xep chon
    int min,temp;
    for( int i = 0; i< n; i++){
        min = i;
        for(int j = i+1; j < n; j++){
            if(a[j] < a[min]) min = j;
        }
        if(min != i){
            temp = a[min];
            a[min] = a[i];
            a[i] = temp;
        }
    }
}

int main(){
    int arr[] = {3,1,5,0,-7,2,-1};
    int n = 7;
    selectionSort(arr,n);
    bool have = false;
    for(int i = 0; i < n; i++){
        if(have == true) break;
        for(int j = i+1; j < n; j++){
            if(have == true) break;
            int temp = 2*arr[j] - arr[i];
            for(int k = j+1; k < n; k++){
                if(arr[k] == temp){
                    cout << arr[i] << " " << arr[j] << " " << arr[k] << endl;
                    have = true;
                    break;
                }
            }
        }
    }
    if(have == false) cout << "khong ton tai bo ba la cap so cong tang";
}