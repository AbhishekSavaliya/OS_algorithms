#include<stdio.h>
#include<stdlib.h>
typedef struct process
{
    int at,bt,ct,tat,wt,pid,done;
    struct process* next;
}process;
int min(process a[],int n)
{
    int m = 0;
    for(int i = 0;i<n;i++)
    {
        if(a[i].bt < a[m].bt)
        {
            m = i;
        }
    }
    return m;
}
void main()
{
    int total_wt = 0;
    printf("Enter the total no of process:\n");
    int no_of_process;
    scanf("%d",&no_of_process);
    process list[no_of_process];
    for(int i = 0 ; i < no_of_process ; i++)
    {
        list[i].done=0;
        list[i].pid=i+1;
        printf("Enter AT of process %d:",i+1);
        scanf("%d",&list[i].at);

        printf("Enter BT of process %d:",i+1);
        scanf("%d",&list[i].bt);
    }
    int cur_time = 0;
    if(list[0].at!=0)
    {
        //printf("0   -   %d\n",list[0].at);
        cur_time = list[0].at;
    }
    int cur_index = 0;
    process temp_list[no_of_process];
    int cur_len = 0;
    while(cur_index<no_of_process)
    {
        for(int i = 0 ; i<no_of_process;i++)
        {

            if(cur_time >= list[i].at && list[i].done == 0)
            {
                temp_list[cur_len].at = list[i].at;
                temp_list[cur_len].bt = list[i].bt;
                temp_list[cur_len].pid = list[i].pid;
                cur_len++;
            }

        }
        int ans = min(temp_list,cur_len);
        //printf("%d   %d   %d\n",cur_time,temp_list[ans].pid,cur_time+temp_list[ans].bt);
        cur_time+=temp_list[ans].bt;
        list[temp_list[ans].pid-1].ct=cur_time;
        list[temp_list[ans].pid-1].tat=cur_time-list[temp_list[ans].pid-1].at;
        list[temp_list[ans].pid-1].wt=list[temp_list[ans].pid-1].tat-list[temp_list[ans].pid-1].bt;
        total_wt+=list[temp_list[ans].pid-1].wt;
        list[temp_list[ans].pid-1].done=1;
        cur_index++;
        cur_len=0;
    }
    printf("AT\t");
	printf("BT\t");
	printf("CT\t");
	printf("TAT\t");
	printf("WT \n");
	for(int i = 0;i < no_of_process; i++)
	{
		printf("%d \t",list[i].at);
		printf("%d \t",list[i].bt);
		printf("%d \t",list[i].ct);
		printf("%d \t",list[i].tat);
		printf("%d",list[i].wt);
		printf("\n");
	}
	printf("Avg Waiting Time : %.2f \n",((double)total_wt/no_of_process));
	printf("Efficiency : %.2f \n",((double)no_of_process/(list[no_of_process-1].ct-list[0].at)));

}
