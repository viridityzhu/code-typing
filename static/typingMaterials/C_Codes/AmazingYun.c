#include<stdio.h>

int a[50][50];
int main() {
    int n, i, j, m = 1;
    scanf("%d", & n);
    for (j = 1; j <= n / 2 + 1; j++) {
        for (i = j; i <= n - j + 1; i++) {
            a[j][i] = m++;
            printf("a[%d][%d]=%d\n", j, i, m - 1);
        }
        printf(" \n");
        for (i = j + 1; i <= n - j + 1; i++) {
            a[i][n - j + 1] = m++;
            printf("a[%d][%d]=%d\n", i, n - j + 1, m - 1);
        }
        printf(" \n");
        for (i = n - j; i >= j; i--) {
            a[n - j + 1][i] = m++;
            printf("a[%d][%d]=%d\n", n - j + 1, i, m - 1);
        }
        printf(" \n");
        for (i = n - j; i >= j + 1; i--) {
            a[i][j] = m++;
            printf("a[%d][%d]=%d\n", i, j, m - 1);
        }
        printf(" \n");
    }
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++)
            printf("%3d", a[i][j]);
        printf("\n");
    }
    return 0;
}