#include<iostream>
using namespace std;

void fcfs(int arrival[], int burst[], int N){
    
    int completion[N];
    int turnAround[N];
    int waitingTime[N];

    completion[0] = burst[0];
    for(int i=0; i<N; i++){
        if(i>0){
            completion[i] = completion[i-1] + burst[i];
        }
        turnAround[i] = completion[i] - arrival[i];
        waitingTime[i] = turnAround[i] - burst[i];
    }

    cout<<"Process\t\tArrival\t\tBurst\t\tCompletion\tTurnAround\tWaiting"<<endl;
    float avgWaiting = 0;
    for(int i=0; i<N; i++){
        cout<<i+1<<"\t\t"<<arrival[i]<<"\t\t"<<burst[i]<<"\t\t"<<completion[i]<<"\t\t"<<turnAround[i]<<"\t\t"<<waitingTime[i]<<endl;
        avgWaiting += waitingTime[i];
    }

    cout<<"Average Waiting time is: "<<(avgWaiting/N)<<endl;
}

int main(){

    int N = 4;
 
    int arrival[N] = {0,1,2,3};
 
    int burst[N] = {5,3,8,6};

    fcfs(arrival, burst, N);

    return 0;
}