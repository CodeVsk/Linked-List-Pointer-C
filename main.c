#include <stdio.h>
#include <malloc.h>

// Simply Linked List
typedef struct reg{
    int content;
    int key;
    struct reg *next;
} ptr;

struct reg *head = NULL;

ptr* initialized (void){
    return NULL;
}

void insertData(int k, int v){
    struct  reg *ptr = (struct reg*) malloc(sizeof(struct reg*)),*p,*b;
    ptr->key = k;
    ptr->content = v;
    ptr->next = head;
    if(head==NULL){
        head = ptr;
    }else{
        p=head;
        if(head->content > ptr->content){
            head=ptr;
            ptr->next=p;
        }else{
            p=head;
            while(p!=NULL && (p->content < ptr->content)){
                b=p;
                p=p->next;
            }
            if(b!=p){
                ptr->next=b->next;
                b->next=ptr;
            }
        }
    }
};

int findData(int k){
    struct reg *ptr = head;
    while(ptr != NULL){
        if(ptr->key == k){
            printf("Pointer is: %p\n\n",ptr);
            return 0;
        }
        ptr=ptr->next;
    }
    printf("Key not found!\n\n");
    return 0;
}

void removeData(int k){
    struct reg *ptr = head,*p=head,*b;
    if(head==NULL){
        printf("List is empty\n\n");
        return;
    }else{
        if(ptr->key == k){
            head=ptr->next;
            free(ptr);
        }else{
            while((p->next != NULL) && p->key != k){
                b=p;
                p=p->next;
            }
            if(b!=p){
                b->next = p->next;
                free(p);
            }
        }
    }
}

void inverseList(){
    struct reg *ptr=head,*p,*b=NULL;
    if(head==NULL){
        printf("List is empty!\n\n");
    }else{
        while(ptr!=NULL){
            p = ptr->next;
            ptr->next = b;
            b = ptr;
            ptr = p;
        }
        head=b;
    }
}

void printList () {
    struct reg *ptr = head;
    while(ptr != NULL){
        printf("Content: %d | Key: %d | Memory: %p | Next:%p\n",ptr->content,ptr->key,ptr,ptr->next);
        ptr=ptr->next;
    }
    printf("\n");
}

//Doubly Linked List

typedef struct doubly{
    int content;
    int key;
    struct doubly *next,*before;
} ptrd;

struct doubly *headd=NULL;

void insertDoubly(int k, int v){
    struct  doubly *ptrd = (struct doubly*) malloc(sizeof(struct doubly*)),*p,*b;
    ptrd->key = k;
    ptrd->content = v;
    ptrd->next = headd;
    if(headd==NULL){
        headd = ptrd;
    }else{
        p=headd;
        if(headd->content > ptrd->content){
            headd=ptrd;
            ptrd->next=p;
        }else{
            p=headd;
            while(p!=NULL && (p->content < ptrd->content)){
                b=p;
                p=p->next;
            }
            if(b!=p){
                ptrd->next=b->next;
                if(ptrd->next == NULL){
                    ptrd->before=b;
                }
                b->next=ptrd;
            }
        }
    }
};

void removeDoubly(int k){
    struct doubly *ptrd = headd,*p=headd,*b,*t;
    if(headd==NULL){
        printf("List is empty\n\n");
        return;
    }else{
        if(ptrd->key == k){
            headd=ptrd->next;
            headd->before=NULL;
            free(ptrd);
        }else{
            while((p->next != NULL) && p->key != k){
                b=p;
                p=p->next;
                t=p->next;
            }
            if(b!=p){
                b->next = p->next;
                b->before = b->before;
                t->before = p->before;
                free(p);
            }
        }
    }
}

void printDoubly () {
    struct doubly *ptrd = headd;
    while(ptrd != NULL){
        printf("Content: %d | Key: %d | Memory: %p | Next:%p | Before:%p\n",ptrd->content,ptrd->key,ptrd,ptrd->next,ptrd->before);
        ptrd=ptrd->next;
    }
    printf("\n");
}

//Main function

int main(void) {
    printf("\n=================|Lista Simplesmente Ligada|=================\n\n");
    initialized();
    insertData(1,1);
    insertData(2,2);
    insertData(3,3);
    insertData(4,4);
    printList();
    printf("|=============================================================|\n\n");

    printf("===========|Lista Simplesmente Ligada Item Buscado|===========\n\n");
    findData(2);
    printf("|============================================================|\n\n");

    printf("==========|Lista Simplesmente Ligada Item Removido|==========\n\n");
    removeData(3);
    printList();
    printf("|============================================================|\n\n");

    printf("============|Lista Simplesmente Ligada Invertida|============\n\n");
    inverseList();
    printList();
    printf("|============================================================|\n\n");

    printf("==================|Lista Duplamente Ligada|==================\n\n");
    insertDoubly(1,1);
    insertDoubly(2,2);
    insertDoubly(3,3);
    insertDoubly(4,4);
    printDoubly();
    printf("|===========================================================|\n\n");

    printf("=======|Lista Duplamente Ligada após Remoção do Item|=======\n\n");
    removeDoubly(3);
    printDoubly();
    printf("|===========================================================|\n\n");
    return 0;
}