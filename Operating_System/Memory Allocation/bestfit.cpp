#include<iostream>
using namespace std;

void allocation(int blockSize[], int processSize[], int n, int m){

    int allocate[m];

    for(int i=0; i<m; i++){
        allocate[i] = -1;
    }

    for(int i=0; i<m; i++){
        //allocate block to each process
        int blockindex = -1;
        for(int j=0; j<n; j++){

           if(processSize[i] <= blockSize[j]){
            if(blockindex == -1){
                blockindex = j;
            }
            else if(blockSize[j] < blockSize[blockindex]){
                blockindex = j;
            }
           }
        }
        if(blockindex != -1){
             allocate[i] = blockindex;
             blockSize[blockindex] -= processSize[i]; 
        }
    }
   cout << "\nProcess No.\tProcess Size\tBlock no.\n";
	for (int i = 0; i < m; i++)
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

    int n = 5;
    int m = 4;

    allocation(blockSize, processSize, n, m);

    return 0;
}