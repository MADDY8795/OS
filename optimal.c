#include <stdio.h>

int main() {
    int frames[10] = {-1}, pages[30], faults = 0;
    int no_of_frames, no_of_pages;

    printf("Enter number of frames: ");
    scanf("%d", &no_of_frames);

    printf("Enter number of pages: ");
    scanf("%d", &no_of_pages);

    printf("Enter page reference string: ");
    for (int i = 0; i < no_of_pages; ++i)
        scanf("%d", &pages[i]);

    for (int i = 0; i < no_of_pages; ++i) {
        int page = pages[i], found = 0;

        for (int j = 0; j < no_of_frames; ++j) {
            if (frames[j] == page) {
                found = 1;
                break;
            }
        }

        if (!found) {
            int replace_index = -1, farthest = -1;

            for (int j = 0; j < no_of_frames; ++j) {
                int current_page = frames[j];
                int farthest_index = -1;

                for (int k = i + 1; k < no_of_pages; ++k) {
                    if (current_page == pages[k]) {
                        farthest_index = k;
                        break;
                    }
                }

                if (farthest_index == -1) {
                    replace_index = j;
                    break;
                }

                if (farthest_index > farthest) {
                    farthest = farthest_index;
                    replace_index = j;
                }
            }

            frames[replace_index] = page;
            faults++;
        }

        printf("\n");
        for (int j = 0; j < no_of_frames; ++j)
            printf("%d\t", frames[j]);
    }

    printf("\n\nTotal Page Faults = %d\n", faults);

    return 0;
}
