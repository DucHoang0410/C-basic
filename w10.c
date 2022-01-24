#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef struct
{
    char ten[100];
    char sdt[100];
    char gmail[100];
}Address;
Address A[100];
void input()
{
	int i;
    FILE *f = fopen("ip.txt", "r");
    if(f == NULL)
    {
        printf("Khong the mo file.\n");
    }
    else
    {
        for( i = 0; i < 10; i++)
        {
            fscanf(f,"%s %s %s\n", A[i].ten, A[i].sdt, A[i].gmail );
        }
        fclose(f);
    }
}
void output()
{
	int i;
    FILE *f = fopen("op.txt", "w+");

    for( i = 0; i < 10; i++)
    {
        fprintf(f,"%s %s %s\n", A[i].ten, A[i].sdt, A[i].gmail );
    }
    fclose(f);
}

int partition(int left, int right, Address pivot){
    int i = left;
    int j = right-1;
    while(1){
        while(strcmp(A[i].ten,pivot.ten)<0){
            i++;
        }
        while(j > 0 && strcmp(A[j].ten,pivot.ten)>0){
            j--;
        }
        if(i >= j)
            break;
        Address temp = A[i];
        A[i] = A[j];
        A[j] = temp;
        i++;
        j--;
    }
    Address temp1 = A[i];
    A[i] = A[right];
    A[right] = temp1;
    return i;
}
void quickSort(int left, int right) {
    if(right<=left){
        return;
    } else {
        Address pivot = A[right];
        int partitionPoint = partition(left, right, pivot);
        quickSort(left, partitionPoint-1);
        quickSort(partitionPoint+1, right);
    }
}



void main()
{
    input();
    quickSort(0,9);
    output();
}
