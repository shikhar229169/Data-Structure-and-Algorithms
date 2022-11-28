#include<stdio.h>
#include<math.h>

int reverse(int N) {
    if (N%10==N) return N;

    int rem=N%10;
    return rem*(pow(10, (int)log10(N))) + reverse(N/10);
}

void main() {
    int N=123456;
    printf("%d\n", reverse(N));
}