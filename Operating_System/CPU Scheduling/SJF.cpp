#include<iostream>
#include<climits>
#include<map>
#include<vector>
#include<bits/stdc++.h>
using namespace std;

void SJF(int arrival[], int burst[], int n){

    //to find which process is arrived first
    //find process with minimun arrival time

    int min = INT_MAX;
    int index;
    for(int i=0; i<n; i++){
        if(arrival[i]<min){
            min = arrival[i];
            index = i;
        }
    }

    int completion[n];
    int turnAround[n];
    int waitingTime[n];

    int completionSum = 0;
    completion[index] = burst[index] + arrival[index];
    completionSum += completion[index];

    //copying burst time array into another vector array
    vector<int> arr;
    for(int i=0; i<n; i++){
        arr.push_back(burst[i]);
    }
    burst[index] = -1;

    //sorting burstTime array
    map<int,int> m;
    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            if(burst[i]>burst[j]){
                swap(burst[i], burst[j]);
            }
        }
    }

    //finding completion time
    for(int i=1; i<n; i++){
        int index = find(arr.begin(), arr.end(), burst[i]) - arr.begin();
        completion[index] = completionSum + burst[i];
        completionSum += burst[i];
    }

    for(int i=0; i<n; i++){
        turnAround[i] = completion[i] - arrival[i];
        waitingTime[i] = turnAround[i] - arr[i];
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

    int n = 5;
    int arrival[n] = {1,2,3,4,5};
    int burst[n] = {7,5,1,2,8};

    SJF(arrival, burst, n);

    return 0;
}