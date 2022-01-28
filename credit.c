#include <stdio.h>
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

    // Получаем удвоенные цифры номера карты со 2 через 1 в обратном порядке
    // TODO подумать, как сделать через цикл for
    int cnum_1, cnum_3, cnum_5, cnum_7, cnum_9, cnum_11, cnum_13, cnum_15,
        cnum_2, cnum_4, cnum_6, cnum_8, cnum_10, cnum_12, cnum_14, cnum_16;
    cnum_1 = 2 * (n / 10 - (n / 100 * 10));
    cnum_3 = 2 * (n / 1000 - (n / 10000 * 10));
    cnum_5 = 2 * (n / 100000 - (n / 1000000 * 10));
    cnum_7 = 2 * (n / 10000000 - (n / 100000000 * 10));
    cnum_9 = 2 * (n / 1000000000 - (n / 10000000000 * 10));
    cnum_11 = 2 * (n / 100000000000 - (n / 1000000000000 * 10));
    cnum_13 = 2 * (n / 10000000000000 - (n / 100000000000000 * 10));
    cnum_15 = 2 * (n / 1000000000000000 - (n / 10000000000000000 * 10));

    // Получаем сумму цифр чисел, удвоенных ранее
    cnum_1 = cnum_1 % 10 + cnum_1 % 100 / 10;
    cnum_3 = cnum_3 % 10 + cnum_3 % 100 / 10;
    cnum_5 = cnum_5 % 10 + cnum_5 % 100 / 10;
    cnum_7 = cnum_7 % 10 + cnum_7 % 100 / 10;
    cnum_9 = cnum_9 % 10 + cnum_9 % 100 / 10;
    cnum_11 = cnum_11 % 10 + cnum_11 % 100 / 10;
    cnum_13 = cnum_13 % 10 + cnum_13 % 100 / 10;
    cnum_15 = cnum_15 % 10 + cnum_15 % 100 / 10;

    // Получаем цифры номера с 1 через 1 в обратном порядке

    cnum_2 = n - (n / 10 * 10);
    cnum_4 = n / 100 - (n / 1000 * 10);
    cnum_6 = n / 10000 - (n / 100000 * 10);
    cnum_8 = n / 1000000 - (n / 10000000 * 10);
    cnum_10 = n / 100000000 - (n / 1000000000 * 10);
    cnum_12 = n / 10000000000 - (n / 100000000000 * 10);
    cnum_14 = n / 1000000000000 - (n / 10000000000000 * 10);
    cnum_16 = n / 100000000000000 - (n / 1000000000000000 * 10);

    // Получаем сумму удвоенных цифр
    int checkSum = cnum_1 + cnum_3 + cnum_5 + cnum_7 + cnum_9 + cnum_11 + cnum_13 + cnum_15 +
            cnum_2 + cnum_4 + cnum_6 + cnum_8 + cnum_10 + cnum_12 + cnum_14 + cnum_16;

    if (checkSum % 10 != 0) {
        printf("INVALID\n");
    } else {
        if (dCount == 16) {
            if (nFirst >= 51 && nFirst <= 55) {
                printf("MASTERCARD\n");
            } else if (nFirst / 10 == 4) {
                printf("VISA\n");
            }
        } else if (dCount == 15 && (nFirst == 34 || nFirst == 37)) {
            printf("AMEX\n");
        } else if (dCount == 13 && nFirst / 10 == 4) {
            printf("VISA\n");
        }
    }


    /* Test cases:
     * 4212123423451234
     * 22233214423122
     * 5512231212345
     */

    return 0;
}