#include<iostream>
#include<unordered_map>
#include<unordered_set>
#include<climits>
using namespace std;

int pageFaults(int pages[], int n, int capacity){

    unordered_set<int> s;
    unordered_map<int, int> m; // it is used to keep track of least recently used indexes of pages
    int page_faults = 0;

    for(int i=0; i<n; i++){
        for(auto it: s){
            cout<<it<<" ";
        }
        cout<<endl;
        if(s.size()<capacity){
            //if this page is not found in set then insert it
            if(s.find(pages[i])==s.end()){
                s.insert(pages[i]);
                page_faults++;
            }
            m[pages[i]] = i;
        }
        else{
            // if this page is not found in set but the set size is full 
            //then need to remove lru page and insert new page
            if(s.find(pages[i])==s.end()){
                int lru = INT_MAX, val;
                for(auto it: s){
                    if(m[it] < lru){
                        lru = m[it];
                        val = it;
                    }
                }
                s.erase(val);
                s.insert(pages[i]);
                page_faults++;
            }
            m[pages[i]] = i;
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