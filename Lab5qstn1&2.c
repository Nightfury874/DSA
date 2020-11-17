#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next;
}*first=NULL,*last=NULL;

void createld(int a[],int n){
    struct node *t,*lst;
    first=(struct node*) (malloc(sizeof(struct node)));
    first->data=a[0];
    first->next=NULL;
    lst=first;
    for(int i=1;i<n;i++){
        t= (struct node*) (malloc(sizeof(struct node)));
        t->data=a[i];
        t->next=NULL;
        lst->next=t;
        lst=t;
    }
}

int Size(struct node *p){
    int i=0;
    while(p!=NULL){
        i+=1;
        p=p->next;
    }
   return i;
}
void Insert(struct node *p,int ind,int data){
    if(ind<0 || ind>Size(first)) return;
    struct node *t;
    t=(struct node *)(malloc(sizeof(struct node)));
    t->data=data;
    t->next=NULL;
    if(ind == 0){
        t->next=first;
        first=t;
    }
    else{
        for(int j=0;j<ind-1;j++) p=p->next;
        t->next = p->next;
        p->next=t;
    }
}
int Delete(int ind){
    int x=-1;
    struct node *p,*q;
    p=first;
    if(ind<1 || ind>Size(p)) return x;
    if(ind ==1){
        q=first;
        x=first->data;
        first=first->next;
        free(q);
        return x;
    }
    else{
        for(int j=0;j<ind-1;j++){
            q=p;
            p=p->next;
        }
        q->next=p->next;
        x=p->data;
        free(p);
        return x;
    }
}
void Display(struct node *p){
    while(p!=NULL){
        printf("%d ",p->data);
        p=p->next;
    }
    printf("\n");
}



int main(){
    int A[]={1,2,3,4,5,6,7,8,12,23};
    int n= sizeof(A)/sizeof(0);
    createld(A,n);
    printf("The linked list is:\n");
    Display(first);
    printf("Inserting before the first node:\n");
    Insert(first,0,156);
    Display(first);
    printf("Inserting before the second node:\n");
    Insert(first,1,999);
    Display(first);
    printf("Inserting after the second node:\n");
    Insert(first,2,1000);
    Display(first);
    printf("Inserting at the last node:\n");
    Insert(first,Size(first),3000);
    Display(first);
    printf("Deleting at index 4:\n");
    printf("Element was %d \n",Delete(4));
    Display(first);
}
