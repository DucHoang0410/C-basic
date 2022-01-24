#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct link
{
    char number[30];
    char name[30];
    char gmail[30];
    struct link *next;
};
typedef struct link *node;
node crt(){
    node a;
    a = (node)malloc(sizeof(struct link));
    a->next = NULL;
    printf("phone number: ");
    fflush(stdin);
    scanf("%s",a->number);
    printf("name : ");
    fflush(stdin);
    scanf("%s",a->name);
    printf("gmail : ");
    fflush(stdin);
    scanf("%s",a->gmail);
    return a;
}
node ahead(){
    node head;
    head = NULL;
    return head;
}

node them(node head){
    node a,p;
    a = crt();
    if(head == NULL){
        head = a;
    }
    else{
        p  = head;
        while(p->next != NULL){
            p = p->next;
        }
        p->next = a;
    }
    return head;
}
void in(node head){
    printf("\nDanh sach:\n");
    for(node p = head; p != NULL; p = p->next){
        printf("%s\n",p->number);
        printf("%s\n",p->name);
        printf("%s\n",p->gmail);
    }
}
node AddHead(node head){
    node temp = crt();
    if(head == NULL){
        head = temp;
    }else{
        temp->next = head;
        head = temp;
    }
    return head;
}
node input(){
    node head = ahead();
    int n;
    do{
        printf("Nhap so luong dia chi n = ");
        scanf("%d", &n);
    }while(n <= 0);
    for(int i = 0; i < n; ++i){
        head = them(head);
    }
    return head;
}

node tim(node head)
{
    char s[30];
    printf("nhap ten muon tim kiem : ");
    fflush(stdin);
    scanf("%s",s);
    for(node p = head; p != NULL; p = p->next){
        if(strcmp(p->next->name,s)==0){
            node q=p->next;
            p->next=p->next->next;
            q->next=head;
            head=q;
            return head;
        }
    }
    return head;
}


int main()
{
    node head = input();
    in(head);
    in(tim(head));
    return 0;
}
