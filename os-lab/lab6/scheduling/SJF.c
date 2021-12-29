/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include<stdio.h>
#include<malloc.h>

void main()
{
	int n, i, j, pos, temp, *bt, *wt, *tat, *p ,*st ,*at ;
	float avgwt = 0, avgtat = 0;
	printf("\n Enter the number of processes : ");
    scanf("%d", &n);

    p = (int*)malloc(n*sizeof(int));
    bt = (int*)malloc(n*sizeof(int));
    wt = (int*)malloc(n*sizeof(int));
    tat = (int*)malloc(n*sizeof(int));
    st = (int*)malloc(n*sizeof(int));
    at = (int*)malloc(n*sizeof(int));
 	
 	printf("\n Enter the burst time for each process \n");
    for(i=0; i<n; i++)
    {
        printf(" Burst time for P%d : ", i);
        scanf("%d", &bt[i]);
        p[i] = i;
    }
    printf("\n Enter the arrival time for each process \n");
    for(i=0; i<n; i++)
    {
        printf(" Burst arrival for P%d : ", i);
        scanf("%d", &at[i]);
        p[i] = i;
    }

for(i=0;i<n;i++)
{
for(j=1;j<n-i-1;j++)
{
if(bt[j]> bt[j+1])
{
temp=p[j];
p[j]=p[j+1];
p[j+1]=temp;

temp=at[j];
at[j]=at[j+1];
at[j+1]=temp;

temp=bt[j];
bt[j]=bt[j+1];
bt[j+1]=temp;
}
}
}
for(i=0; i<n; i++)
    {
        printf(" P %d \t\t Burst: %d \t\t arrival: %d \t\t  \n", p[i], bt[i], at[i]);
    }

/********************************************************************************************/
    //st[0] =0;
	st[0]= 0;
    wt[0] = 0;
    tat[0] = bt[0];
    avgwt += wt[0];
    avgtat += tat[0]; 
    for(i=1; i<n; i++)
    {
		st[i] = st[i-1] + bt [i-1];
		wt[i] = st[i] - at[i];  //waiting time[p] = waiting time[p-1] + Burst Time[p-1]
        tat[i] = wt[i] + bt[i];     //Turnaround Time = Waiting Time + Burst Time
        
         avgwt += wt[i];
        avgtat += tat[i]; 
    }
  

    
    avgwt = avgwt/n;
    avgtat = avgtat/n;

    printf("\n PROCESS \t BURST TIME \t WAITING TIME \t TURNAROUND TIME \n");
    printf("--------------------------------------------------------------\n");
    for(i=0; i<n; i++)
    {
        printf(" P%d \t\t %d \t\t %d \t\t %d \n", p[i], bt[i], wt[i], tat[i]);
    }

    printf("\n Average Waiting Time = %f \n Average Turnaround Time = %f \n", avgwt, avgtat);

    printf("\n \tGAANT CHART \n");
    printf("-------------------------\n");
    for(i=0; i<n; i++)
    {
        printf(" %d\t|| P%d ||\t%d\n", wt[i], p[i], tat[i]);
    }
}

