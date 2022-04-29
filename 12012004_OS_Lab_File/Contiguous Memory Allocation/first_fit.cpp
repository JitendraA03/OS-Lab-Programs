// C++ implementation of First - Fit algorithm
#include<bits/stdc++.h>
using namespace std;


void firstFit(int blockSize[], int m,
			int processSize[], int n)
{
	
	int allocation[n];

	memset(allocation, -1, sizeof(allocation));

	// here we assume the os info is stored in first block of the blockSize
    // hence blockSize for processes is reduced to m-1
	for (int i = 0; i < n; i++)
	{
		for (int j = 1; j < m; j++)
		{
			if (blockSize[j] >= processSize[i])
			{
				
				allocation[i] = j;

				blockSize[j] -= processSize[i];

				break;
			}
		}
	}

	cout << "\nProcess No.\tProcess Size\tBlock no.\n";
	for (int i = 0; i < n; i++)
	{
		cout << " " << i+1 << "\t\t"
			<< processSize[i] << "\t\t";
		if (allocation[i] != -1)
			cout << allocation[i] + 1;
		else
			cout << "Not Allocated";
		cout << endl;
	}
}

int main()
{
	//int blockSize[] = {100, 200, 100, 100, 700};
	//int processSize[] = {212, 417, 112, 426};
    int blockSize[5];
    int processSize[4];
    for (int i = 0; i < 5; i++)
    {
        /* code */
        cin>>blockSize[i];
    }
    for (int i = 0; i < 4; i++)
    {
        /* code */
        cin>>processSize[i];
    }
	int m = sizeof(blockSize) / sizeof(blockSize[0]);
	int n = sizeof(processSize) / sizeof(processSize[0]);

	firstFit(blockSize, m, processSize, n);

	return 0 ;
}
