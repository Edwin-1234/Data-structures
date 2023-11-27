#include <stdio.h>

struct poly
{
    int coeff;
    int exp;
};

int main()
{
    int i, j = 0, k = 0, m, n, coeff, exp;
    struct poly p[10], q[10], r[20];

    printf("Enter the number of terms of first and second polynomial: ");
    scanf("%d %d", &m, &n);

    printf("Enter the coefficient and exponent of terms first polynomial:\n");
    for (i = 0; i < m; i++) {
        scanf("%d %d", &coeff, &exp);
        p[i].coeff = coeff;
        p[i].exp = exp;
    }

    printf("Enter the coefficient and exponent of terms second polynomial:\n");
    for (i = 0; i < n; i++) {
        scanf("%d %d", &coeff, &exp);
        q[i].coeff = coeff;
        q[i].exp = exp;
    }

    i = 0;
    while (i < m && j < n) {
        if (p[i].exp == q[j].exp) {
            r[k].coeff = p[i].coeff + q[j].coeff;
            r[k].exp = p[i].exp;
            k++;
            i++;
            j++;
        } else if (p[i].exp > q[j].exp) {
            r[k].coeff = p[i].coeff;
            r[k].exp = p[i].exp;
            k++;
            i++;
        } else {
            r[k].coeff = q[j].coeff;
            r[k].exp = q[j].exp;
            k++;
            j++;
        }
    }

    while (i < m) {
        r[k].coeff = p[i].coeff;
        r[k].exp = p[i].exp;
        k++;
        i++;
    }

    while (j < n) {
        r[k].coeff = q[j].coeff;
        r[k].exp = q[j].exp;
        k++;
        j++;
    }

    printf("First polynomial: ");
    for (j = 0; j < m; j++) {
        printf("%dx^%d", p[j].coeff, p[j].exp);
        if (j < m - 1) {
            printf(" + ");
        }
    }

    printf("\nSecond polynomial: ");
    for (i = 0; i < n; i++) {
        printf("%dx^%d", q[i].coeff, q[i].exp);
        if (i < n - 1) {
            printf(" + ");
        }
    }

    printf("\nSum: ");
    for (i = 0; i < k; i++) {
        printf("%dx^%d", r[i].coeff, r[i].exp);
        if (i < k - 1) {
            printf(" + ");
        }
    }

    return 0;
}
