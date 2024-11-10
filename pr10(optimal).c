#include <stdio.h>

int main() {
    int n, nf;
    printf("Enter length of page reference sequence: ");
    scanf("%d", &n);
    printf("Enter no of frames: ");
    scanf("%d", &nf);
    int in[n], p[nf];
    for (int i = 0; i < n; i++) {
        scanf("%d", &in[i]);
    }
    int pgfaultcnt = 0;
    for (int i = 0; i < n; i++) {
        if (!in[i]) {
            pgfaultcnt++;
            p[i / nf] = 1;
        }
    }
    printf("\nTotal no of page faults:%d", pgfaultcnt);
    return 0;
}
