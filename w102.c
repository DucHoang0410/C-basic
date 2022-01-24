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
void merge(Address A[], int l, int m, int r)
{
    int n1 = m - l + 1;
    int n2 = r - m;
    Address L[n1], R[n2];
    int i = 0, j = 0;
    for( i = 0; i < n1; i++)
        L[i] = A[l + i];
    for(j = 0; j < n2; j++)
        R[j] = A[m + 1 + j];
   
    int k = l;
    while (i < n1 && j < n2)
    {
        if (strcmp(L[i].ten,R[j].ten)<=0)
        {
            A[k] = L[i];
            i++;
        }
        else
        {
            A[k] = R[j];
            j++;
        }
        k++;
    }
    while (i < n1)
    {
        A[k] = L[i];
        i++;
        k++;
    }
    while (j < n2)
    {
        A[k] = R[j];
        j++;
        k++;
    }
}
void mergeSort(Address A[], int l, int r)
{
    if (l < r)
    {
        int m = l + (r - l) / 2;
        mergeSort(A, l, m);
        mergeSort(A, m + 1, r);
        merge(A, l, m, r);
    }
}


void main()
{
    input();
    mergeSort(A,0,9);
    output();
}
