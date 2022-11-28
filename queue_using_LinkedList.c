#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
    int val;
    struct Node* next;
} Node;

Node* front=NULL;
Node* rear=NULL;
int size=0;

Node* getNode(int item) {
    Node* newNode=(Node*)malloc(sizeof(Node));
    newNode->val=item;
    newNode->next=NULL;
    return newNode;
}

int is_empty() {
    return front==NULL;
}

int push(int item) {
    Node* newNode=getNode(item);
    if (newNode==NULL) {
        printf("Queue is full\n");
        return 0;
    }

    if (is_empty()) {
        front=newNode;
        rear=newNode;
    }
    else {
        rear->next=newNode;
        rear=newNode;
    }
    size++;
    return 1;
}

int pop() {
    if (is_empty()) {
        return -1;
    }

    Node* removed=front;
    int data=removed->val;

    front=front->next;
    if (front==NULL) {
        rear=NULL;
    }

    free(removed);
    size--;

    return data;
}

int peek() {
    if (is_empty()) {
        return -1;
    }

    return front->val;
}

void display() {
    if (front==NULL) {
        printf("Queue is empty\n\n");
        return;
    }

    Node* curr=front;

    while (curr!=NULL) {
        printf("%d ", curr->val);
        curr=curr->next;
    }
    printf("\n\n");
}

int main() {
    size=0;

    int ch;
    int item;
    int res;

    while (1) {
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Peek\n");
        printf("4. Display\n");
        printf("5. Exit\n");
        printf("Select an option: ");
        scanf("%d", &ch);


        if (ch==1) {
            printf("Enter the data: ");
            scanf("%d", &item);
            res=push(item);

            if (res==0) printf("Queue is full\n");
            else printf("Sucessfully inserted\n");
        }
        else if (ch==2) {
            res=pop();

            if (res==-1) printf("Cannot pop from an empty queue\n");
            else printf("Data removed is %d\n", res);
        }
        else if (ch==3) {
            res=peek();
            if (res==-1) printf("Cannot peek in an empty queue\n");
            else printf("Data present at front is %d\n", res);
        }
        else if (ch==4) {
            display();
        }
        else if (ch==5) {
            break;
        }
        else {
            printf("Please enter a valid option\n\n");
        }
    }
    return 0;
}