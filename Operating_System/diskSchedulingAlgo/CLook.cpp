#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int size = 8;
int disk_size = 200;

void CLook(int arr[], int head, string direction){

    int seekcount = 0;
    int curr_head;
    vector<int> left, right;
    vector<int> seek_sequence;

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
        if(direction=="right"){
            for(int i=0; i<right.size(); i++){
                curr_head = right[i];
                seekcount += abs(curr_head - head);
                seek_sequence.push_back(right[i]);
                head = curr_head;
            }
            direction = "left";
        }
        else if(direction=="left"){
            for(int i=0; i<left.size(); i++){
                curr_head = left[i];
                seekcount += abs(curr_head - head);
                seek_sequence.push_back(left[i]);
                head = curr_head;
            }
            direction = "right";
        }
    }

    cout<<"Total no of seek operations: "<<seekcount<<endl;
    cout<<"Seek Sequence is "<<endl;
    for(int i=0; i<=seek_sequence.size()-1; i++){
        cout<<seek_sequence[i]<<endl;
    }
}

int main(){

    int arr[size] = {176, 79, 34, 60, 92, 11, 41, 114};
    int head = 50;
    string direction = "right";

    CLook(arr, head, direction);

    return 0;
}