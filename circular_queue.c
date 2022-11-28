#include<stdio.h>

const int MAX=6;

int data[6];
int front, rear;
int size;


int is_empty() {
    return front==-1;
}

int is_full() {
    return ((rear+1)%MAX)==front;
}

int push(int item) {
    if (is_full()) {
        return 0;
    }
    if (is_empty()) front=0;
    data[(++rear)%MAX]=item;
    size++;
    return 1;
}

int pop() {
    if (is_empty()) {
        return -1;
    }

    int removed=data[front];
    if (rear==front) {
        rear=-1;
        front=-1;
    }
    else {
        front=(front+1)%MAX;
    }
    size--;
    return removed;
}

int peek() {
    if (is_empty()) {
        return -1;
    }
    return data[front];
}

int len() {
    return size;
}

void display() {
    if (is_empty()) {
        printf("Queue is empty\n");
        return;
    }
    int i=front;
    int N=size;
    while (N--) {
        printf("%d ", data[i]);
        i=(i+1)%MAX;
    }
    printf("\n\n");
}

int main() {
    front=-1;
    rear=-1;
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