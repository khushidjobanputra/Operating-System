#include<bits/stdc++.h>
using namespace std;

void priority(int arrival[], int burst[], int pri[], int n){

    int complete = 0;
    int t = 0; // current time
    int startTime[n] = {-1};
    int completion[n];
    int turnAround[n];
    int waitingTime[n];

    while(complete != n){
        cout<<"hiii"<<endl;
        int priorityTemp = INT_MIN;
        bool isFound = false;
        int index;
        for(int i=0; i<n; i++){
            if(arrival[i]<=t && pri[i]>priorityTemp){
                priorityTemp = pri[i];
                isFound = true;
                index = i;
            }
        }

        if(isFound){
            if(startTime[index] == -1){
                startTime[index] = t;
            }
            burst[index] = burst[index] - 1;
            t++;
            if(burst[index]==0){
                completion[index] = t;
                turnAround[index] = completion[index] - arrival[index];
                waitingTime[index] = turnAround[index] - burst[index];

                complete++;
            }
        }
        else{
            t++;
            continue;
        }
    }

    cout<<"Process\t\tArrival\t\tBurst\t\tCompletion\tTurnAround\tWaiting"<<endl;
    float avgWaiting = 0;
    for(int i=0; i<n; i++){
        cout<<i+1<<"\t\t"<<arrival[i]<<"\t\t"<<burst[i]<<"\t\t"<<completion[i]<<"\t\t"<<turnAround[i]<<"\t\t"<<waitingTime[i]<<endl;
        avgWaiting += waitingTime[i];
    }

    cout<<"Average Waiting time is: "<<(avgWaiting/n)<<endl;
}

int main(){

    int n = 7;
    int arrival[n] = {0,1,2,3,4,5,6};
    int burst[n] = {4,2,3,5,1,4,6};
    int pri[n] = {2,4,6,10,8,12,9};

    priority(arrival, burst, pri, n);

    return 0;
}