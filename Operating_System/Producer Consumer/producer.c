#include <stdio.h>
#define N 5

int buffer[N];
int empty=N, full=0, s=1;
int itemp, itemc, in=0, out=0, i=0;

void Down(int x){
    x = x-1;
    if(x<0){
        //put process in blocked queue;
    }
}

void Up(int x){
    x = x+1;
    if(x<=0){
        //select process from blocked queue and put in ready queue
    }
}

void Producer() {
    if(full!=N && s==1) {
                printf("Item %d produced", ++itemp);
                Down(empty);
                Down(s);
                buffer[in] = itemp;
                in = (in+1)%N;
                Up(s);
                Up(full);
            }
            else {
                printf("Buffer is full");
            }
}

void Consumer() {
    if(full!=0 && s==1) {
        Down(full);
        Down(s);
        itemc = buffer[out];
        printf("Item %d consumed", itemc);
        out = (out+1)%N;
        Up(s);
        Up(empty);
    }
    else {
        printf("Buffer is empty");
    }
    
}

int main()
{
    int choice;
    while(1) {
        printf("\nEmpty=%d, Full=%d", empty, full);
        printf("\nEnter the process no 1.Producer 2.Consumer: ");
        scanf("%d", &choice);
        if(choice == 1) {
            Producer();
        }
        else if(choice == 2) {
            Consumer();
        }
        else {
            break;
        }
    }
    return 0;
}