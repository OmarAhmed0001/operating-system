/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>

/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/
// CPU-Scheduling-Algorithm-In-C
// Non Pre-emptive Priority Scheduling Algorithm

#include<stdio.h>
#include<malloc.h>

void main()
{
	int n, i, j, pos, temp, *bt, *wt, *tat, *p, *pt, *art,*all,*st ,*ft;
	float avgwt = 0, avgtat = 0;
	printf("\n Enter the number of processes : ");
	scanf("%d", &n);
	art = (int*)malloc(n*sizeof(int));
	p = (int*)malloc(n*sizeof(int));
	bt = (int*)malloc(n*sizeof(int));
	pt = (int*)malloc(n*sizeof(int));
	wt = (int*)malloc(n*sizeof(int));
	tat = (int*)malloc(n*sizeof(int));
	all = (int*)malloc(n*sizeof(int));
	st = (int*)malloc(n*sizeof(int));
	ft = (int*)malloc(n*sizeof(int));


	printf("\n Enter the burst time and priority for each process ");
	for (i = 0; i<n; i++)
	{
		printf("\n Arrival time of P%d : ", i);
		scanf("%d", &art[i]);
		printf("\n Burst time of P%d : ", i);
		scanf("%d", &bt[i]);
		printf(" Priority of P%d : ", i);
		scanf("%d", &pt[i]);
		p[i] = i;
		
	}

	
	for (i = 0; i<n; i++)
	{
		pos = i;
		for (j = i + 1; j<n; j++)
		{
			if (art[j] < art[pos])
			{
				pos = j;
			}
		}
		temp = pt[i];
		pt[i] = pt[pos];
		pt[pos] = temp;

		temp = art[i];
		art[i] = art[pos];
		art[pos] = temp;

		temp = bt[i];
		bt[i] = bt[pos];
		bt[pos] = temp;

		temp = p[i];
		p[i] = p[pos];
		p[pos] = temp;
	}
	///// ALL
	for (int i = 0; i < n; i++)
	{
		if (i == 0){ all[0] = bt[0] + 0; }
		else { all[i] = all[i - 1] + bt[i]; }
	}
	////
	

	///
	for (i = 0; i<n; i++)
	{
		pos = i;
		for (j = i + 1; j<n; j++)
		{
			if (pt[j] < pt[pos] && art[j]<all[i-1])
			{
				pos = j;
			}
		}
		temp = pt[i];
		pt[i] = pt[pos];
		pt[pos] = temp;

		temp = art[i];
		art[i] = art[pos];
		art[pos] = temp;

		temp = bt[i];
		bt[i] = bt[pos];
		bt[pos] = temp;

		temp = p[i];
		p[i] = p[pos];
		p[pos] = temp;
	}

	wt[0] = 0;
	tat[0] = bt[0];

	avgwt += wt[0];
	avgtat += tat[0];
	/*
	for (i = 1; i<n; i++)
	{
		wt[i] = wt[i - 1] + bt[i - 1];  //waiting time[p] = waiting time[p-1] + Burst Time[p-1]
		tat[i] = wt[i] + bt[i];     //Turnaround Time = Waiting Time + Burst Time

		avgwt += wt[i];
		avgtat += tat[i];
	}
	*/
	float WT = 0;
	float TA = 0;
	for (i = 0; i<n; i++)

	{

		if (i == 0)
		{
			st[i] = art[i];
			wt[i] = st[i] - art[i];
			ft[i] = st[i] + bt[i];
			tat[i] = ft[i] - art[i];
		}
		else
		{
			st[i] = ft[i - 1];
			wt[i] = st[i] - art[i];
			ft[i] = st[i] + bt[i];
			tat[i] = ft[i] - art[i];
		}
		WT += wt[i];
		TA += tat[i];
	}

	WT = WT / n;
	TA = TA / n;

	printf("\n PROCESS \t PRIORITY \t BURST TIME \t WAITING TIME \t TURNAROUND TIME \t ARRIVAL TIME \n");
	printf("------------------------------------------------------------------------------------------------\n");
	for (i = 0; i<n; i++)
	{
		printf(" P%d \t\t %d \t\t %d \t\t %d \t\t %d  \t\t\t %d \n", p[i], pt[i], bt[i], wt[i], tat[i],art[i]);
	}

	printf("\n Average Waiting Time = %f \n Average Turnaround Time = %f \n", WT, TA);

	printf("\n \tGAANT CHART \n");
	printf("---------------------------\n");
	for (i = 0; i<n; i++)
	{
		printf(" %d\t|| P%d ||\t%d\n", wt[i], p[i], tat[i]);
	}
}
///////////////////////////////////////////////////////


