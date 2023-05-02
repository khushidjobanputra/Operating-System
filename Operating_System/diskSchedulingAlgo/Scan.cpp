#include<iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;

int disk_size = 200;
int size = 8;

void SCAN(int arr[], int head, string direction){

    int seekcount = 0;
    vector<int> seekSequence;
    vector<int> left, right;
    int curr_head;

    if(direction=="left"){
        left.push_back(0);
    }
    else if(direction == "right"){
        right.push_back(disk_size-1);
    }

    for(int i=0; i<size; i++){
        if(arr[i]<head){
            left.push_back(arr[i]);
        }
        if(arr[i]>head){
            right.push_back(arr[i]);
        }
    }

    sort(left.begin(), left.end());
    sort(right.begin(), right.end());

    int run = 2;
    while(run--){
        if(direction=="left"){
            for(int i=left.size()-1; i>=0; i--){
                curr_head = left[i];
                seekSequence.push_back(left[i]);
                seekcount += abs(curr_head - head);
                head = curr_head;
            }
            direction="right";
        }
        else if(direction =="right"){
            for(int i=0; i<right.size(); i++){
                curr_head = right[i];
                seekSequence.push_back(right[i]);
                seekcount += abs(curr_head - head);
                head = curr_head;
            }
            direction="left";
        }
    }
   cout<<"Total no of seek operations: "<<seekcount<<endl;
    cout<<"Seek Sequence is "<<endl;
    for(int i=0; i<=seekSequence.size(); i++){
        cout<<seekSequence[i]<<endl;
    }
}

int main(){

    int arr[size] = {176, 79, 34, 60, 92, 11, 41, 114};
    int head = 50;
    string direction = "left";

    SCAN(arr, head, direction);

    return 0;
}