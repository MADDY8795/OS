#include <stdio.h>

int main() {
    int rs[25], m[10] = {-1}, count[10] = {0}, flag[25] = {0};
    int n, f, pf = 0, next = 1;

    printf("Enter the length of reference string -- ");
    scanf("%d", &n);

    printf("Enter the reference string -- ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &rs[i]);
    }

    printf("Enter the number of frames -- ");
    scanf("%d", &f);

    printf("\nThe Page Replacement process is -- \n");

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < f; j++) {
            if (m[j] == rs[i]) {
                flag[i] = 1;
                count[j] = next++;
            }
        }

        if (!flag[i]) {
            int min = 0;
            for (int j = 1; j < f; j++) {
                if (count[min] > count[j]) {
                    min = j;
                }
            }
            m[min] = rs[i];
            count[min] = next++;
            pf++;
        }

        for (int j = 0; j < f; j++) {
            printf("%d\t", m[j]);
        }

        if (!flag[i]) {
            printf("PF No. -- %d", pf);
        }

        printf("\n");
    }

    printf("\nThe number of page faults using LRU is %d\n", pf);

    return 0;
}
