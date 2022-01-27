#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(void) {
    long long cNumber;

    do {
        scanf("%lld", &cNumber);
    } while (cNumber < 0);

    long long n = cNumber;
    int dCount = 0;

    while (n > 0) {
        n /= 10;
        dCount += 1;
    }

    if ((dCount < 13 || dCount > 16) || dCount == 14) {
        printf("INVALID\n");
    }

    int nFirst = cNumber / pow(10, dCount - 2);
    n = cNumber;
    long long grade = pow(10, dCount);

    //long long test = n - (n / 10 * 10);

    // Получаем удвоенные цифры номера карты со 2 в обратном порядке
    // TODO подумать, как сделать через цикл for
    int cnum_1, cnum_3, cnum_5, cnum_7, cnum_9, cnum_11, cnum_13, cnum_15;
    cnum_1 = 2 * (n / 10 - (n / 100 * 10));
    cnum_3 = 2 * (n / 1000 - (n / 10000 * 10));
    cnum_5 = 2 * (n / 100000 - (n / 1000000 * 10));
    cnum_7 = 2 * (n / 10000000 - (n / 100000000 * 10));
    cnum_9 = 2 * (n / 1000000000 - (n / 10000000000 * 10));
    cnum_11 = 2 * (n / 100000000000 - (n / 1000000000000 * 10));
    cnum_13 = 2 * (n / 10000000000000 - (n / 100000000000000 * 10));
    cnum_15 = 2 * (n / 1000000000000000 - (n / 10000000000000000 * 10));

    // Получаем сумму удвоенных цифр
    int sumCnums = cnum_1 + cnum_3 + cnum_5 + cnum_7 + cnum_9 + cnum_11 + cnum_13 + cnum_15;

    // Получаем

    printf("%d", sumCnums);


    /* Test cases:
     * 4212123423451234
     * 22233214423122
     * 5512231212345
     */

    return 0;
}