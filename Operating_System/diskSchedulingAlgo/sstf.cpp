#include<iostream>
#include<vector>
#include<climits>
#include<map>
using namespace std;

map<int, bool> m;

int bubblesort(int proc[], int n, int head, vector<int> &sorted){

    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            if(proc[i]>proc[j]){
                swap(proc[i], proc[j]);
            }
        }
    }
    int ans;
    for(int i=0; i<n; i++){
        sorted.push_back(proc[i]);
        if(head>proc[i] && head<proc[i+1]){
            sorted.push_back(head);
            ans = i+1;
        }
    }

    return ans;
}

int findMin(int proc[], int n, int currHead){

    int dist = INT_MAX;
    int val;
    for(int i=0; i<n; i++){
        if(abs(currHead-proc[i]) < dist && currHead!=proc[i] && m[proc[i]]==false){
            dist = abs(currHead-proc[i]);
            val = proc[i];
        }
    }
    return val;
}

void shortestSeekTimeFirst(int proc[], int head, int n){

    vector<int> sorted;
    int index = bubblesort(proc,n, head, sorted);

    int curHead = head;
    int seekcount = 0;
    int seekSequence[n+1] = {0};
    int val;
    seekSequence[0] = head;
    m[head] = true;
    
    for(int i=0; i<n; i++){
        val = findMin(proc, n, curHead);
        seekcount += abs(curHead - val);
        curHead = val;
        m[val] = true;
        seekSequence[i+1] = val;
    }

    cout<<"Total no of seek operations: "<<seekcount<<endl;
    cout<<"Seek Sequence is ";
    for(int i=0; i<=n; i++){
        cout<<seekSequence[i]<<endl;
    }
}

int main(){

    int n = 8;
    int proc[n] = { 176, 79, 34, 60, 92, 11, 41, 114 };
     
    shortestSeekTimeFirst(proc, 50, n);

    return 0;
}