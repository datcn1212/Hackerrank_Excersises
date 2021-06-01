#include<iostream>
using namespace std;

void LinearSearch(int arr[], int n, int k){
    for(int i =  0; i < n; i++){
        if(arr[i] == k){
            cout << "Phan tu " << k <<" o vi tri thu " << i+1 << endl;
            break;
        }
        if(arr[n-1] != k) cout << "khong tim thay "<< k << endl;
    }
}
// chu y Binary_search mang phai sap xep tang dan truoc
void BinarySearch(int arr[], int begin, int end, int k){
    if(begin == end){
        if(arr[begin] == k) cout << "Phan tu " << k << " o vi tri thu " << begin+1 << endl;
        else cout << "khong tim thay phan tu " << k;
    }
    else{
        int mid = (begin + end)/2;
        if(k == arr[mid]) cout << "Phan tu " << k <<" o vi tri thu " << mid+1 << endl;
        else if(k < arr[mid]) BinarySearch(arr, begin, mid-1, k);
        else BinarySearch(arr, mid+1, end, k);
    }
   
}

int main(){
    int arr[] = {-10,-6,1,2,3,6,8};
    BinarySearch(arr,0,6,-6);
    LinearSearch(arr,7,-10);
}