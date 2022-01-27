#include <stdio.h>

int main(void) {
	int pHeight = 0;

	while (pHeight < 1 || pHeight > 8) {
		printf("Enter pyramid height (from 1 to 8 inclusive): ");
		scanf("%d", &pHeight);
	}

	int nRows = 0;

	for(int i = 0; i < pHeight; ++i) {
	    for (int j = pHeight - i - 1; j > 0; --j) {
	        printf(" ");
	    }

	    for (int k = 0; k < i + 1; ++k) {
	        printf("#");
	    }

	    printf("  ");

	    for (int l = 0; l < i + 1; ++l) {
	        printf("#");
	    }

	    printf("\n");
	}


	return 0;
}
