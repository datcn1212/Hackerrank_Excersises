#include<iostream>
using namespace std;

 void swap(int &x, int &y){
     int temp = y;
     y = x;
     x = temp;
 }

 void max_heapify(int a[], int n, int i){
     int max = i;
     if(2*i <= n && a[2*i] > a[max]) max = 2*i;
     if(2*i+1 <= n && a[2*i+1] > a[max]) max = 2*i + 1;
     if(max != i){
         swap(a[i], a[max]);
         max_heapify(a,n,max);
     }
 }

 void build_max_heap(int a[], int n){
     int x = n/2;
     for(int i = x; i >= 1; i--)
        max_heapify(a,n,i);
 }

 void heap_sort(int a[], int n){
     build_max_heap(a,n);
     for(int i = n; i > 1; i--){
         swap(a[1], a[i]);
         max_heapify(a,i-1,1);
     }
 }

 int main(){
     int a[] = {0,8,3,10,5,7,9}; // sort from a[1] to a[n]
     heap_sort(a,6);
     // tang dan
     for(int i = 1; i <= 6; i++){
         cout << a[i] << " ";
     }
     cout << endl;
     // giam dan
     for(int i = 6; i >= 1; i--){
         cout << a[i] << " ";
     }
 }