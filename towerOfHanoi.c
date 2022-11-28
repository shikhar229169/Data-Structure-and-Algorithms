#include<stdio.h>
#include<conio.h>

int TowerOfHanoi(int N, int src, int helper, int dest) {
    if (N==1) {
        printf("Tranfer Disk %d from rod %d to rod %d\n", N, src, dest);
        return 1;
    }
    int curr=0;
    curr=TowerOfHanoi(N-1, src, dest, helper);
    printf("Tranfer Disk %d from rod %d to rod %d\n", N, src, dest);
    curr+=TowerOfHanoi(N-1, helper, src, dest);
    return curr+1;
}

void main() {
    int N;
    printf("Enter the number of disks: ");
    scanf("%d", &N);
    int moves=TowerOfHanoi(N, 1, 2, 3);
    printf("Total moves done are %d\n", moves);
    getch();
}