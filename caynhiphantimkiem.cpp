/*
    cay nhi phan tim kiem la gi?
    - la cay nhi phan
    - moi nut tren cay co 4 phan: left, right, key, parent
    - tat ca cac key cua cay con trai cua nut bat ky luon nho hon ben phai
*/
#include<iostream>
using namespace std;

typedef struct Node{
    Node* left;
    Node* right;
    Node* parent;
    int key;
}Node;

Node* Search(Node* head, int target){
    if(head->key == target) return head;
    else if(head->key < target) return Search(head->right, target);
    else return Search(head->left, target);
}

Node* Findmax(Node* head){
    if(head == NULL) return NULL;
    while(head->right != NULL) head = head->right;
    return head;
}

Node* Findmin(Node* head){
    if(head == NULL) return NULL;
    if(head->left == NULL) return head;
    else return Findmin(head->left);
}

void Insert(Node* head, int data){
    Node* temp = new Node;
    temp->key = data;
    if(head == NULL){
        head = temp;
    }
    while(head != NULL){
        if(head->key < data) Insert(head->right, data);
        else Insert(head->left, data);
    }

}

void Delete(Node* head){
    if(head->left == NULL && head->right == NULL){
        // nút lá
        Node* temp = head->parent;
        if(temp->left == head) temp->left = NULL;
        else temp->right = NULL;
    }
    else if(head->left != NULL && head->right == NULL){
        // nút có cây con trái nhưng không có cây con phải
        Node* x = head->parent;
        Node* y = head->left;
        x->left = y;
    }
    else if(head->left == NULL && head->right != NULL){
        // nút có cây con phải nhưng không có cây con trái
        Node* x = head->parent;
        Node* y = head->right;
        x->right = y;
    }
    else{
        // nút có cả con trái và con phải -> di chuyển nút kế cận sau lên thay thế
        Node* temp = Findmin(head->right);
        // xoa nut temp
        Node* x = temp->parent;
        Node* y = temp->right;
        x->right = y;
        
        if(head->parent->left == head) head->parent->left = temp;
        else head->parent->right = temp;      
    }
}

void Postorder(Node* head){

}

void Inorder(Node* head){
    // inorder se duoc cac key theo thu tu tang dan
    if(head != NULL){
        Inorder(head->left);
        cout<< head->key << " ";
        Inorder(head->right);
    }
}

void Preorder(Node* head){

}

Node* Predecessor(Node* x){
    // tim kế cận trước: node y co key lon nhat nho hon key_x
    Node* temp;
    if(x->left == NULL){
    //truong hop x là nút lá thì tìm tổ tiên gần nhất có x thuộc cây con phải
        temp = x->parent;
        while(temp != NULL && temp->left == x){
            x = temp;
            temp = temp->parent;
        }
    }
    else temp = x->left;
    // Findmax
    while(temp->right != NULL) temp = temp->right;
    return temp;
}

Node* Successor(Node* x){
    // tim kế cận sau
    Node* temp;
    if(x->right == NULL){
        temp = x->parent;
        while(temp != NULL && temp->right == x){
            x = temp;
            temp = temp->parent;
        }
    }
    else temp = x->right;
    // Findmin
    while(temp->left != NULL) temp = temp->left;
    return temp;
}

int main(){
    Node* head = new Node;
    head->key = 1;
    Insert(head,3);
    Insert(head,2);
    Insert(head,4);
    Insert(head,7);
    Insert(head,0);
    Inorder(head);
}