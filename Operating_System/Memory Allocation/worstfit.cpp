#include<iostream>
using namespace std;

void worstfit(int blockSize[], int b, int processSize[], int p){

    int allocate[p];

    for(int i=0; i<p; i++){
        allocate[i] = -1;
    }

    for(int i=0; i<p; i++){
        int worstIndex = -1;
        for(int j=0; j<b; j++){
            if(processSize[i] <= blockSize[j]){
                if(worstIndex == -1){
                    worstIndex = j;
                }
                else if(blockSize[j] > blockSize[worstIndex]){
                    worstIndex = j;
                }
                
            }
        }
        if(worstIndex!=-1){
            allocate[i] = worstIndex;
            blockSize[worstIndex] -= processSize[i];
        }
    }

    cout << "\nProcess No.\tProcess Size\tBlock no.\n";
	for (int i = 0; i < p; i++)
	{
		cout << " " << i+1 << "\t\t" << processSize[i] << "\t\t";
		if (allocate[i] != -1)
			cout << allocate[i] + 1;
		else
			cout << "Not Allocated";
		cout << endl;
	}
}

int main(){

    int blockSize[] = {100, 500, 200, 300, 600};
    int processSize[] = {212, 417, 112, 426};

    int b = 5;
    int p = 4;

    worstfit(blockSize, b, processSize, p);

    return 0;
}