#include<iostream>
#include<math.h>
#include<vector>
using namespace std;

void swap(int &a, int &b)
{
    int t = a;
    a = b;
    b = t;
}
/* Hàm xuất mảng */
void printArray(int arr[], int size)
{
    int i;
    for (i=0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}
 
void insertionSort(int a[], int n){ //sap xep chen
    for(int i = 1; i<n ; i++){
        int temp = a[i];
        for(int j = i-1; j >= 0; j--){
            if(j == 0) a[0] = temp;
            if(a[j] > temp) a[j+1] = a[j];
            else{
                 a[j+1] = temp;
                 break;
            }        
        }
    }
}

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

void bubbleSort(int a[], int n){ //sap xep noi bot
    bool x = 0;
    for(int i = 1; i < n; i++){
        for(int j = 0; j < n-i; j++){
            if(a[j] > a[j+1]){
                x = 1;
                int temp = a[j+1];
                a[j+1] = a[j];
                a[j] = temp;
            }
            if(!x) break; // ko co buoc hoan doi nao xay ra thi ket thuc luon
        }
    }
}

void merge(int a[], int start, int end, int mid){
    int *b = a;
    int index = 0;
    while((start <= mid)&&(mid+1 <= end)){
        if(b[start] < b[mid+1]){
            a[index] = b[start];
            start++;
        }
        else {
            a[index] = b[mid+1];
            mid++;
        }
        index++;
    }
    //chep not nhung phan tu con lai cua nua trai vao a[]
    while(start <= mid){  
        a[index] = b[start];
        index++;
    }
    //chep not nhung phan tu con lai cua nua phai vao a[]
    while(mid+1 <= end){
        a[index] = b[mid+1];
        index++;
    }

}
//sap xep tron cho a[start] -> a[end] : chia de tri
void mergeSort(int a[], int start, int end){ 
    if(start < end){
        int mid = (start + end)/2;
        mergeSort(a,start,mid);
        mergeSort(a,mid+1,end);
        merge(a,start,end,mid);
    }
}

//dua pivot ve dung vi tri dong thoi chia mang thanh 2 nua: nua trai < pivot, nua phai > pivot
int partition (int arr[], int low, int high)
{
    int pivot = arr[high];    // pivot dc chon luon la phan tu cuoi cung cua mang
    int left = low;
    int right = high - 1;
    while(true){
        while(left <= right && arr[left] < pivot) left++;
        while(right >= left && arr[right] > pivot) right--;
        if (left >= right) break;
        swap(arr[left], arr[right]);
        left++;
        right--;
    }
    swap(arr[left], arr[high]);
    return left;
}
 
/* Hàm thực hiện giải thuật quick sort */
void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        /* pi là chỉ số nơi phần tử này đã đứng đúng vị trí
         và là phần tử chia mảng làm 2 mảng con trái & phải */
        int pi = partition(arr, low, high);
 
        // Gọi đệ quy sắp xếp 2 mảng con trái và phải
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}
 


void heapify(int arr[], int n, int i) 
{ 
    int largest = i; // Initialize largest as root 
    int l = 2*i + 1; // left = 2*i + 1 
    int r = 2*i + 2; // right = 2*i + 2 
  
    // If left child is larger than root 
    if (l < n && arr[l] > arr[largest]) 
        largest = l; 
  
    // If right child is larger than largest so far 
    if (r < n && arr[r] > arr[largest]) 
        largest = r; 
  
    // If largest is not root 
    if (largest != i) 
    { 
        swap(arr[i], arr[largest]); 
  
        // Recursively heapify the affected sub-tree 
        heapify(arr, n, largest); 
    } 
} 
  
// main function to do heap sort 
void heapSort(int arr[], int n) 
{ 
    // Build_max_heapify (rearrange array) 
    for (int i = n / 2 - 1; i >= 0; i--) 
        heapify(arr, n, i); 
  
    // One by one extract an element from heap 
    for (int i=n-1; i>0; i--) 
    { 
        // Move current root to end 
        swap(arr[0], arr[i]); 
  
        // call max heapify on the reduced heap 
        heapify(arr, i, 0); 
    } 
} 


int main(){
    int a[] = {20,12,43,566,7};
    quickSort(a,0,4);
    printArray(a,5);
}
