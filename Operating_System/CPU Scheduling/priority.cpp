#include<bits/stdc++.h>
using namespace std;

void priority(int arrival[], int burst[], int pri[], int n){

    int t=0;
    int complete=0;
    int completion[n] = {0};
    int completionSum = 0;
    int priorityTemp = INT_MIN;
    int turnAround[n];
    int waitingTime[n];

    vector<int> Pri2;
    map<int, bool> m;

    for(int i=0; i<n; i++){
        Pri2.push_back(pri[i]);
    }

    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            if(pri[i]>pri[j]){
                swap(pri[i], pri[j]);
            }
        }
    }

    int N = Pri2.size();

    while(complete != n){

        if(priorityTemp != pri[n-1]){
            int index;
            for(int i=0; i<n; i++){
                if(arrival[i]<=t && priorityTemp<Pri2[i]){
                    priorityTemp = Pri2[i];
                    index = i;
                }
            }
            completion[index] = completionSum + burst[index];
            // cout<<index<<" "<<completion[index]<<endl;
            completionSum += burst[index];
            t += burst[index];
            complete++;
            m[Pri2[index]] = true;
        }
        else{
            for(int i=n-1; i>=0; i--){
                if(m[pri[i]] == false){
                    int index = find(Pri2.begin(), Pri2.end(), pri[i]) - Pri2.begin();
                    completion[index] = completionSum + burst[index];
                    // cout<<index<<" "<<completion[index]<<endl;
                    completionSum += burst[index];
                    complete++;
                    m[pri[i]] == true;
                }
            }
        }
    } 

    for(int i=0; i<n; i++){
        turnAround[i] = completion[i] - arrival[i];
        waitingTime[i] = turnAround[i] - burst[i];
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