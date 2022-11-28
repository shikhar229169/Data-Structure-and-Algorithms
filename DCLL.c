#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
    int val;
    struct Node* prev;
    struct Node* next;
} Node;

Node* getNode(int data) {
    Node* newNode=(Node*)malloc(sizeof(Node));
    newNode->val=data;
    newNode->prev=NULL;
    newNode->next=NULL;
    return newNode;
}

Node* insertAtTail(Node* tail, int data) {
    Node* newNode=getNode(data);
    if (tail==NULL) {
        tail=newNode;
        tail->next=tail;
        tail->prev=tail;
        return tail;
    }

    newNode->next=tail->next;
    tail->next=newNode;
    newNode->prev=tail;
    newNode->next->prev=newNode;
    tail=newNode;

    return tail;
}

Node* insertAtHead(Node* tail, int data) {
    Node* newNode=getNode(data);
    if (tail==NULL) {
        tail=newNode;
        tail->next=tail;
        tail->prev=tail;
        return tail;
    }

    newNode->next=tail->next;
    tail->next=newNode;
    newNode->prev=tail;
    newNode->next->prev=newNode;

    return tail;
}

Node* deleteAtTail(Node* tail) {
    if (tail==NULL) {
        printf("LL is empty\n");
        exit(1);
    }
    Node* removed=tail;
    if (tail->next==tail) {
        tail=NULL;
    }
    else {
        tail->prev->next=tail->next;
        tail=tail->prev;
    }

    printf("Data removed is %d\n", removed->val);
    free(removed);
    return tail;
}

Node* deleteAtHead(Node* tail) {
    if (tail==NULL) {
        printf("LL is empty\n");
        exit(1);
    }
    Node* removed=tail->next;
    if (tail->next==tail) {
        tail=NULL;
    }
    else {
        tail->next=removed->next;
        removed->next->prev=tail;
    }

    printf("Data removed is %d\n", removed->val);
    free(removed);
    return tail;
}

void display(Node* tail) {
    if (tail==NULL) {
        printf("NULL\n");
    }
    Node* curr=tail->next;
    do {
        printf("%d -> ", curr->val);
        curr=curr->next;
    } while (curr!=tail->next);
    printf("NULL\n");
}

Node* insertAfterPos(Node* tail, int val, int pos) {
    Node* newNode=getNode(val);

    if (tail==NULL) {
        tail=newNode;
        tail->next=tail;
        tail->prev=tail;
    }
    else {
        Node* curr=tail;
        while (pos--) {
            curr=curr->next;
        }
        newNode->next=curr->next;
        curr->next=newNode;
        newNode->prev=curr;
        newNode->next->prev=newNode;
        if (curr==tail) tail=newNode;
    }
    
    return tail;
}

Node* insertAtPos(Node* tail, int val, int pos) {
    Node* newNode=getNode(val);

    if (tail==NULL) {
        tail=newNode;
        tail->next=tail;
        tail->prev=tail;
    }
    else {
        Node* curr=tail;
        while (--pos) {
            curr=curr->next;
        }
        newNode->next=curr->next;
        curr->next=newNode;
        newNode->prev=curr;
        newNode->next->prev=newNode;
    }

    return tail;
}

Node* deleteAtPos(Node* tail, int pos) {
    if (tail==NULL) {
        printf("Linked List is empty\n");
        exit(1);
    }

    Node* removed;
    Node* curr=tail;

    while (--pos) {
        curr=curr->next;
    }

    removed=curr->next;

    if (curr->next==curr) {
        tail=NULL;
    }
    else {
        curr->next=removed->next;
        removed->next->prev=curr;
        if (removed==tail) {
            tail=curr;
        }
    }

    printf("Data removed is %d\n", removed->val);
    free(removed);

    return tail;
}

void display_reverse(Node* tail) {
    if (tail==NULL) {
        printf("Linked List is empty\n");
        return;
    }
    
    Node* curr=tail;

    do {
        printf("%d <- ", curr->val);
        curr=curr->prev;
    } while (curr!=tail);

    printf("\n\n");
}

Node* createLL() {
    Node* tail=NULL;
    Node* temp=NULL;
    Node* newNode=NULL;

    int N, x;
    printf("Enter the size: ");
    scanf("%d", &N);

    while (N--) {
        scanf("%d", &x);
        newNode=getNode(x);
        if (temp==NULL) temp=newNode;
        else {
            tail->next=newNode;
            newNode->prev=tail;
        }
        tail=newNode;
    }

    tail->next=temp;
    temp->prev=tail;
    return tail;
}

int main() {
    Node* tail=createLL();
    // display(tail);
    // display_reverse(tail);
    
    tail=insertAtTail(tail, 12);
    // display(tail);
    // display_reverse(tail);
    tail=insertAfterPos(tail, 44, 6);
    // display(tail);
    // display_reverse(tail);
    tail=insertAtPos(tail, 78, 7);
    display(tail);
    display_reverse(tail);

    tail=deleteAtPos(tail, 1);
    display(tail);
    display_reverse(tail);
    tail=deleteAtPos(tail, 7);
    display(tail);
    display_reverse(tail);
    return 0;
}