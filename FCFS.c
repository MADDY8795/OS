#include <stdio.h>

int main() {
    int nof, nor, ref[50], frm[50] = {-1}, pf = 0, victim = -1;

    printf("\n\t\t\tFIFO PAGE REPLACEMENT ALGORITHM");
    printf("\n Enter number of frames: ");
    scanf("%d", &nof);
    printf("Enter number of pages: ");
    scanf("%d", &nor);
    printf("\n Enter the page numbers: ");
    for (int i = 0; i < nor; i++)
        scanf("%d", &ref[i]);

    printf("\nThe given pages are:");
    for (int i = 0; i < nor; i++)
        printf("%4d", ref[i]);

    for (int i = 0; i < nor; i++) {
        int flag = 0;
        printf("\n\tPage number %d ->\t", ref[i]);
        for (int j = 0; j < nof; j++) {
            if (frm[j] == ref[i]) {
                flag = 1;
                break;
            }
        }
        if (!flag) {
            pf++;
            frm[victim = (victim + 1) % nof] = ref[i];
            for (int j = 0; j < nof; j++)
                printf("%4d", frm[j]);
        }
    }
    printf("\n\n\t\tNumber of page faults: %d", pf);

    return 0;
}