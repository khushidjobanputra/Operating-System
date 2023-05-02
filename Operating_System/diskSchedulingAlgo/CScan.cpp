#include<iostream>
#include<vector>
#include <bits/stdc++.h>
using namespace std;

void CSCAN(vector<int> arr, int head, int index){

    int seekcount = 0;
    cout<<arr[index]<<endl;
    int n = arr.size();
    int seekSequence[n+1] = {0};

    for(int i=index; i<(n-1); i++){
        seekcount += abs(arr[i+1] - arr[i]);
        seekSequence[i-index] = arr[i+1];
    }

    seekcount += arr[n-1] - arr[0];
    for(int i=0; i<(index-1); i++){
        seekcount += abs(arr[i+1] - arr[i]);
        seekSequence[n-index+i-1] = arr[i];
    }

    cout<<"Total no of seek operations: "<<seekcount<<endl;
    cout<<"Seek Sequence is "<<endl;
    for(int i=0; i<=n; i++){
        cout<<seekSequence[i]<<endl;
    }
}

int main(){

    int arr[8] = { 176, 79, 34, 60, 92, 11, 41, 114 };
    int head = 50;

    int index;
    vector<int> arr1;
    arr1.push_back(0);
    for(int i=0; i<8; i++){
        arr1.push_back(arr[i]);
        if(head>arr[i] && head<arr[i+1]){
            arr1.push_back(head);
            index = i;
        }
    }
    arr1.push_back(199);
    sort(arr1.begin(), arr1.end());
  
    cout << "Initial position of head: " << head << endl;
    CSCAN(arr1, head, index-1);

    return 0;
}