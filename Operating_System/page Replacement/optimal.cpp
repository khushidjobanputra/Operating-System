#include<iostream>
#include<unordered_set>
using namespace std;

int index(int pages[], int n, int num, int i){

    for(int j=i+1; j<n; j++){
        if(num==pages[j]){
            return j;
        }
    }
}

int pageFaults(int pages[], int n, int capacity){

    unordered_set<int> s;
    int page_faults = 0;

    for(int i=0; i<n; i++){
        for(auto it: s){
            cout<<it<<" ";
        }
        cout<<endl;
        if(s.size()<capacity){
            if(s.find(pages[i])==s.end()){
                s.insert(pages[i]);
                page_faults++;
            }
        }
        else{
            if(s.find(pages[i])==s.end()){
                int fartest=0;
                int val = -1;
                for(auto it: s){
                    int ind = index(pages, n, it, i);
                    if(ind > fartest){
                        fartest = ind;
                        val = it;
                    }
                }
                s.erase(val);
                s.insert(pages[i]);
                page_faults++;
            }
        }
    }
    return page_faults;
}

int main(){

    int pages[] = {1, 2, 3, 4, 2, 1, 5, 3, 2, 4, 6};
    int n = 11;
    int capacity = 3;

    int faults = pageFaults(pages, n, capacity);
    cout<<"No. of page faults: ";
    cout<<(faults)<<endl;

    cout<<"No. of Hits: ";
    cout<<(n-faults)<<endl;

    return 0;
}