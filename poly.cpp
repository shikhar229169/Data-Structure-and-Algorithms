#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
    int coeff;
    int pwr;
    struct Node* next;
} Node;

Node* getNode(int coeff, int pwr) {
    Node* newNode=(Node*) malloc (sizeof(Node));
    newNode->coeff=coeff;
    newNode->pwr=pwr;
    newNode->next=NULL;
    return newNode;
}

Node* createPolynomial() {
    Node* head=NULL;
    Node* newNode;
    Node* prev;
    int N, coeff, pwr;
    printf("Enter the size- ");
    scanf("%d", &N);

    while (N--) {
        scanf("%d%d", &coeff, &pwr);
        newNode=getNode(coeff, pwr);
        if (head==NULL) head=newNode;
        else prev->next=newNode;
        prev=newNode;
    }

    return head;
}

void display(Node* head) {
    if (head==NULL) {
        printf("NULL\n");
        return;
    }
    if (head->next==NULL) {
        printf("%dx^%d\n", head->coeff, head->pwr);
        return;
    }
    printf("%dx^%d + ", head->coeff, head->pwr);
    display(head->next);
}

Node* addTwoPolynomials(Node* head1, Node* head2) {
    Node* head=NULL;
    Node* prev=NULL;
    Node* newNode=NULL;

    while (head1 && head2) {
        if ((head1->pwr)>(head2->pwr)) {
            newNode=getNode(head1->coeff, head1->pwr);
            head1=head1->next;
        }
        else if ((head1->pwr)<(head2->pwr)) {
            newNode=getNode(head2->coeff, head2->pwr);
            head2=head2->next;
        }
        else {
            newNode=getNode(head1->coeff + head2->coeff, head1->pwr);
            head1=head1->next;
            head2=head2->next;
        }
        if (head==NULL) head=newNode;
        else prev->next=newNode;
        prev=newNode;
    }

    while (head1) {
        newNode=getNode(head1->coeff, head1->pwr);
        if (head==NULL) head=newNode;
        else prev->next=newNode;
        prev=newNode;
        head1=head1->next;
    }

    while (head2) {
        newNode=getNode(head2->coeff, head2->pwr);
        if (head==NULL) head=newNode;
        else prev->next=newNode;
        prev=newNode;
        head2=head2->next;
    }

    return head;
}

int main(){
    Node* head1=NULL;
    Node* head2=NULL;
    head1=createPolynomial();
    head2=createPolynomial();
    display(head1);
    display(head2);


    Node* resHead=addTwoPolynomials(head1, head2);
    display(resHead);
}