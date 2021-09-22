# include<stdio.h>
# include <stdlib.h>

typedef struct {
    int page;
    int tor;
} frames;

void pretty_print(frames *table, int n, int h) {
    printf("\n");
    for (int i = 0; i < n; i++) {
        if (table[i].page != -1) {
            printf("|%d|", table[i].page);
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

int non_recently_used(frames *table, int n) {
    int min = table[0].tor;
    int index = 0;
    for (int i = 1; i < n; i++) {
        if (min <= table[i].tor)
            continue;
        min = table[i].tor;
        index = i;
    }
    return index;
}

int main() {
    int frame_count;
    int page_string_length;
    int max_page_count;
    int *pages;
    int *tor;

    printf("Enter the number of frames: ");
    scanf("%d", &frame_count);

    printf("Enter the length of page string: ");
    scanf("%d", &page_string_length);

    pages = (int *) malloc(sizeof(int) * page_string_length);
    printf("Enter the page string: ");
    for (int i = 0; i < page_string_length; i++) {
        scanf("%d", pages + i);
    }

    frames *table = (frames *) malloc(sizeof(frames) * frame_count);
    for (int i = 0; i < frame_count; i++) {
        table[i].page = -1;
        table[i].tor = -1;
    }


    int hits = 0;
    int flag;
    int in;
    for (int i = 0; i < page_string_length; i++) {
        flag = 0;
        for (int j = 0; j < frame_count; j++) {
            if (table[j].page == pages[i]) {
                hits++;
                pretty_print(table, frame_count, 1);
                flag = 1;
                table[j].tor = i;
                break;
            }
        }
        if (flag)
            continue;
        in = non_recently_used(table, frame_count);
        table[in].page = pages[i];
        table[in].tor = i;
        pretty_print(table, frame_count, 0);
    }

    printf("\nNumber of Page Faults = %d\n", page_string_length - hits);
    return 0;
}