# include<stdio.h>
# include <stdlib.h>

void pretty_print(int *frames, int n, int h) {
    printf("\n");
    for (int i = 0; i < n; i++) {
        if (frames[i] != -1) {
            printf("|%d|", frames[i]);
        }
        printf("\n");
    }
    if (h) {
        printf("Hit");
    } else {
        printf("Miss");
    }
    printf("\n");

}

int main() {
    int frame_count;
    int page_string_length;
    int max_page_count;
    int *pages;
    printf("Enter the number of frames: ");
    scanf("%d", &frame_count);

    printf("Enter the length of page string: ");
    scanf("%d", &page_string_length);

    pages = (int *) malloc(sizeof(int) * page_string_length);
    printf("Enter the page string: ");
    for (int i = 0; i < page_string_length; i++) {
        scanf("%d", pages + i);
    }

    int *frames = (int *) malloc(sizeof(int) * frame_count);
    for (int i = 0; i < frame_count; i++) {
        frames[i] = -1;
    }

    int in = 0;
    int hits = 0;
    int flag = 0;
    for (int i = 0; i < page_string_length; i++) {
        flag = 0;
        for (int j = 0; j < frame_count; j++) {
            if (frames[j] == pages[i]) {
                hits++;
                pretty_print(frames, frame_count, 1);
                flag = 1;
                break;
            }
        }
        if (flag) {
            continue;
        }
        frames[in] = pages[i];
        in = (in + 1) % frame_count;
        pretty_print(frames, frame_count, 0);
    }
    printf("\nNumber of Page Faults = %d\n", page_string_length - hits);
    return 0;
}
