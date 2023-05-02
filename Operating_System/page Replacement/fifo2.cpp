#include<iostream>
#include<deque>
#include<bits/stdc++.h>
using namespace std;

int pageFaults(int pages[], int n, int capacity){

    deque<int> indexes;
    int page_faults = 0;

    for(int i=0; i<n; i++){

        if(indexes.size() < capacity){
            cout<<"hii"<<endl;
            deque<int>::iterator itr;
            itr = find(indexes.begin(), indexes.end(), 2);
            if(itr != indexes.end()){
                cout<<"hii"<<endl;
                indexes.push_back(pages[i]);
                page_faults++;
                cout<<page_faults<<endl;
            }
        }
        else{
            deque<int>::iterator itr;
            itr = find(indexes.begin(), indexes.end(), 2);
            cout<<"hii"<<endl;
            if(itr != indexes.end()){
                cout<<"hii"<<endl;
                int value = indexes.front();
                indexes.pop_front();
                indexes.push_back(pages[i]);
                page_faults++;
                cout<<page_faults<<endl;
            }
        }
        cout<<page_faults<<endl;
    }
    return page_faults;
}

int main(){

    int pages[] = {7, 0, 1, 2, 0, 3, 0, 4, 2, 3, 0, 3, 2};
    int n = 13;
    int capacity = 4;
    cout<<pageFaults(pages, n, capacity)<<endl;

    return 0;
}