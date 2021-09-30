#include<stdio.h>
#include<stdlib.h>

struct stack{
    int size;
    int top;
    int *arr;
};

int isEmpty(struct stack *ptr){
    if(ptr->top==-1){
        return 1;
    }
    else{
        return 0;
    }
}

int isFull(struct stack *ptr){
    if(ptr->top==ptr->size-1){
        return 1;
    }
    else{
        return 0;
    }
}

void push(struct stack *ptr,int value){
    if(isFull(ptr)){
        printf("Stack Overflow\n");
    }
    else{
        ptr->top++;
        ptr->arr[ptr->top]=value;
    }
}

int pop(struct stack *ptr){
    if(isEmpty(ptr)){
        printf("Stack underflow\n");
        return -1;
    }
    else{
        int val=ptr->arr[ptr->top];
        ptr->top--;
        return val;
    }
}

int peek(struct stack *ptr,int i){
    if(ptr->top-i+1<0){
        printf("Not a valid position of the stack\n");
        return -1;
    }
    else{
        return ptr->arr[ptr->top-i+1];
    }
}

int main(){
    struct stack *s=(struct stack *)malloc(sizeof(struct stack));
    s->size=6;
    s->top=-1;
    s->arr=(int *)malloc(s->size*sizeof(int));

    printf("Before pushing,Empty %d\n",isEmpty(s));
    printf("Before pushing,Full %d\n",isFull(s));
    push(s,1);
    push(s,2);
    push(s,3);
    push(s,4);
    push(s,5);
    push(s,6);
    // printf("Pop out element %d\n",pop(s));

    printf("After pushing,Empty %d\n",isEmpty(s));
    printf("After pushing,Full %d\n",isFull(s));

    for(int i=1;i<=s->top+1;i++){
        printf("The value at position %d is %d\n",i,peek(s,i));
    }
}
