#include<iostream>
using namespace std;

void firstfit(int blockSize[], int b, int processSize[], int p){

    int allocate[p];

    for(int i=0; i<p; i++){
        allocate[i] = -1;
    }

    for(int i=0; i<p; i++){
        for(int j=0; j<b; j++){
            if(processSize[i] <= blockSize[j]){
                allocate[i] = j;
                blockSize[j] -= processSize[i];
                break;
            }
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

    int p = 4; //processSize size
    int b = 5; //blockSize ki size

    firstfit(blockSize, b, processSize, p);

    return 0;
}