#include<bits/stdc++.h>
using namespace std;

void SRTF(int arrival[], int burst[], int n){

    int complete = 0; // no of processes completed
    int t = 0; //current time
    int shortest = 0;
    int min = INT_MAX;
    bool check = false;
    int finish_time;
    int waiting[n];
    int turnAround[n];

    int rt[n];
    for(int i=0; i<n; i++){
        rt[i] = burst[i];
    }

    while(complete != n){

        //find the process with minimum remaining time arrived at time t
        for(int j=0; j<n; j++){
            if(arrival[j]<=t && rt[j]<min &&rt[j]>0){
                min = rt[j];
                shortest = j;
                check = true;
            }
        }

        if(check==false){
            t++;
            continue;
        }

        rt[shortest]--;
        min = rt[shortest];

        if(min==0){
            min = INT_MAX;
        }

        if(rt[shortest] == 0){

            complete++;
            check = false;

            //completion time of this process
            finish_time = t+1;

            waiting[shortest] = finish_time - burst[shortest] - arrival[shortest];

            if(waiting[shortest]<0){
                waiting[shortest] = 0;
            }

        }
        t++;
    }

    for(int i=0; i<n; i++){
        turnAround[i] = burst[i] + waiting[i];
    }

    cout<<"Process\t\tArrival\t\tBurst\tTurnAround\tWaiting"<<endl;
    float avgWaiting = 0;
    for(int i=0; i<n; i++){
        cout<<i+1<<"\t\t"<<arrival[i]<<"\t\t"<<burst[i]<<"\t\t"<<turnAround[i]<<"\t\t"<<waiting[i]<<endl;
        avgWaiting += waiting[i];
    }

    cout<<"Average Waiting time is: "<<(avgWaiting/n)<<endl;
    
}

int main(){

    int n = 5;
    int arrival[n] = {2,1,4,0,2};
    int burst[n] = {1,5,1,6,3};

    SRTF(arrival, burst, n);

    return 0;
}