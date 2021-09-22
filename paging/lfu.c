# include<stdio.h>
# include <stdlib.h>

typedef struct f {
    int page;
    int tor;
} frames;

void frequency(int *freq, int n) {
    for (int i = 0; i < n; i++)
        printf("%d", freq[i]);
}

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

void reset(int *freq, int loc) {
    if (loc != -1) {
        freq[loc] = 0;
    }
}


int get(int *freq, int loc) {
    if (loc == -1) {
        return 0;
    }
    //printf("%d\n",loc);
    return freq[loc];
}

int least_frequently_used(int *freq, frames *table, int n) {
    int min = get(freq, table[0].page);
    int index = 0;
    for (int i = 1; i < n; i++) {
        if (min < get(freq, table[i].page))
            continue;
        else if (min == get(freq, table[i].page)) {
            if (table[index].tor < table[i].tor) {
                index = i;
            }
        } else {
            min = get(freq, table[i].page);
            index = i;
        }
    }
    return index;
}

int main() {
    int frame_count;
    int page_string_length;
    int max_page_count;

    printf("Enter the number of frames: ");
    scanf("%d", &frame_count);

    printf("Enter the length of page string: ");
    scanf("%d", &page_string_length);

    int *pages = (int *) malloc(sizeof(int) * page_string_length);
    int *freq = (int *) malloc(sizeof(int) * page_string_length);

    frames *table = (frames *) malloc(sizeof(frames) * frame_count);
    for (int i = 0; i < frame_count; i++) {
        table[i].page = -1;
        table[i].tor = -1;
    }

    printf("Enter the page string: ");
    for (int i = 0; i < page_string_length; i++) {
        scanf("%d", pages + i);
        freq[i] = 0;
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
                //frequency(freq,page_string_length);
                flag = 1;
                freq[pages[i]]++;
                table[j].tor = i;
                break;
            }
        }
        if (flag)
            continue;
        in = least_frequently_used(freq, table, frame_count);
        reset(freq, table[in].page);
        //printf("%d %d %d",in,table[in].page,freq[table[in].page]);
        table[in].page = pages[i];
        table[in].tor = i;
        freq[pages[i]]++;
        pretty_print(table, frame_count, 0);
        //frequency(freq,page_string_length);
    }

    printf("\nNumber of Page Faults = %d\n", page_string_length - hits);
    return 0;
}