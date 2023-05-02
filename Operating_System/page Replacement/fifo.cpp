#include<iostream>
#include<queue>
#include<unordered_set>
using namespace std;

//here set is more like a queue that keeps track of current processes

int pageFaults(int pages[], int n, int capacity){

    queue<int> indexes; // to keep track of which process came in first 

    unordered_set<int> s; // to keep track of current processes
    int page_faults = 0;
    //{7, 0, 1, 2, 0, 3, 0, 4, 2, 3, 0, 3, 2}

    for(int i=0; i<n; i++){
        for(auto it: s){
            cout<<it<<" ";
        }
        cout<<endl;
        // cout<<s.size()<<" "<<page_faults<<endl;
        if(s.size() < capacity){
            //if page is not in the set and queue
            if(s.find(pages[i])==s.end()){
                s.insert(pages[i]);
                page_faults++;
                indexes.push(pages[i]);
            }
        }
        // if the set is full we need to remove the first process in queue n replace by new process
        else{
            if(s.find(pages[i]) == s.end()){
                int value = indexes.front();
                indexes.pop();
                s.erase(value);
                s.insert(pages[i]);
                page_faults++;
                indexes.push(pages[i]);
            }
        }
    }
    return page_faults;
}

int main(){

    int pages[] = {7, 0, 1, 2, 0, 3, 0, 4, 2, 3, 0, 3, 2};
    int n = 13;
    int capacity = 4;
    
    int faults = pageFaults(pages, n, capacity);
    cout<<"No. of page faults: ";
    cout<<(faults)<<endl;

    cout<<"No. of Hits: ";
    cout<<(n-faults)<<endl;

    return 0;
}