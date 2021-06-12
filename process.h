# include <stdio.h>
# include <stdlib.h>
#include<string.h>

typedef struct {
    int pid;
    int bt;
    int at;
    int ct;
    int tat;
    int wt;
} process;

void sort(process **, int, int, const char *, char, const char *);

void merge(process **, int, int,int, const char *, char, const char *);

void sort(process **collection, int start, int end, const char *var, char order, const char *type) {
    if (start < end) {
        int mid = start + (end-start)/2;
        sort(collection, start, mid, var, order, type);
        sort(collection, mid + 1, end, var, order, type);
        merge(collection,start,mid,end,var,order,type);
    }
}



void merge(process **collection, int start, int mid,int end, const char *var, char order, const char *sort) {

    int flag = 0;
    int type = 0;
    if (strcmp(var, "at") == 0) {
        flag = 1;
    }
    if (strcmp(sort, "sjf") == 0) {
        type = 1;
    }

    int n1 = mid - start + 1;
    int n2 = end - mid;

    process * L[n1];
    process  * R[n2];

    for (int i = 0; i < n1; ++i) {
        L[i] = collection[start + i];
    }
    for (int i = 0; i < n2; ++i) {
        R[i] = collection[mid+1+i];
    }

    int i = 0,j=0,k=0;
    while (i<n1 && j<n2){
        if(flag == 1) {
            if(order == 'a') {
                if (L[i]->at < R[j]->at) {
                    collection[k] = L[i];
                    i++;
                } else if (L[i]->at > R[j]->at) {
                    collection[k] = R[j];
                    j++;
                }else{
                    if(type == 1){
                        if(L[i]->bt <= R[j]->bt){
                            collection[k] = L[i];
                            i++;
                        }else{
                            collection[k] = R[j];
                            j++;
                        }
                    } else{
                        collection[k] = L[i];
                        i++;
                    }
                }
            }else{
                if (L[i]->at >= R[j]->at) {
                    collection[k] = L[i];
                    i++;
                } else {
                    collection[k] = R[j];
                    j++;
                }
            }
        }else{
            break;
        }
        k++;
    }

    while (i<n1){
        collection[k] = L[i];
        i++,k++;
    }

    while (j<n2){
        collection[k] = R[j];
        j++,k++;
    }
}
