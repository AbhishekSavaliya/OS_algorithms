#include<stdio.h>
typedef struct process
{
	int pid,at,bt,ct,tat,wt;
}process;
void insertionSort(process arr[], int n)
{
    int i, key, j, t1,t2,t3;
    for (i = 1; i < n; i++) {
        key = arr[i].at;
        j = i - 1;


        while (j >= 0 && arr[j].at > key) {
         		t1= arr[j].pid;
         		t2= arr[j].at;
         		t3= arr[j].bt;

            arr[j + 1].pid = t1;
            arr[j + 1].at = t2;
            arr[j + 1].bt = t3;
            j = j - 1;
        }
        arr[j + 1].at = key;
    }
}
void main()
{
	int n,cur_ct,total_wt;
	printf("Enter the number of Process :");
	scanf("%d",&n);
	printf("Enter the Dtails of process...\n");
	process list[n];
	for(int i=0;i<n;i++)
	{
		list[i].pid = (i+1);
		printf("Enter the AT time of Process %d : ",i);
		scanf("%d",&list[i].at);
		printf("Enter the BT time of Process %d : ",i);
		scanf("%d",&list[i].bt);
	}
	insertionSort(list,n);
	cur_ct=0;
	total_wt=0;
	for(int i = 0;i < n; i++)
	{
		cur_ct = cur_ct + list[i].bt;
		list[i].ct = cur_ct;
		list[i].tat = list[i].ct - list[i].at;
		list[i].wt = list[i].tat - list[i].bt;
		total_wt += list[i].wt;
	}
	printf("AT\t");
	printf("BT\t");
	printf("CT\t");
	printf("TAT\t");
	printf("WT \n");
	for(int i = 0;i < n; i++)
	{
		printf("%d \t",list[i].at);
		printf("%d \t",list[i].bt);
		printf("%d \t",list[i].ct);
		printf("%d \t",list[i].tat);
		printf("%d",list[i].wt);
		printf("\n");
	}
	printf("Avg Waiting Time : %.2f \n",((double)total_wt/n));
	printf("Efficiency : %.2f \n",((double)n/(cur_ct-list[0].at)));
}
