#include <stdio.h>
#include <string.h>
#include <stdlib.h>
struct Link
{
    int Data;
    int Key;
};
typedef struct Link Hash;
Hash* ARR[25];
int Searching(int Key) {
    int i = Key % 19;
    while(ARR[i] != NULL) {
        if(ARR[i]->Key == Key)
            return i;
        i++;
        i %= 19;
    }
    return -1;
}

void Insert(int Key,int Data) {
    Hash* X = (Hash*)malloc(sizeof(struct Link));
    X->Data = Data;
    X->Key = Key;
    int i = Key % 19;
    while(ARR[i] != NULL) {
        i++;
        i %= 19;
    }
    ARR[i] = X;
}



/*
int Searching(int Key) {
    int i = Key % 19;
    while(ARR[i] != NULL) {
        if(ARR[i]->Key == Key)
            return i;
        i*=i;
        i %= 19;
    }
    return -1;
}

void Insert(int Key,int Data) {
    Hash* X = (Hash*)malloc(sizeof(struct Link));
    X->Data = Data;
    X->Key = Key;
    int i = Key % 19;
    while(ARR[i] != NULL) {
        i*=i;
        i %= 19;
    }
    ARR[i] = X;
}
*/





int main()
{
    Insert(1,2);
    printf("%d,%d\n",ARR[1]->Key,ARR[1]->Data);
}
