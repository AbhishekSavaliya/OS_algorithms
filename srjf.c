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
    for(int i = 0 ; i < n ; i++)
    {
        if(a[i].bt < a[m].bt)
            m = i;
    }
    return(a[m].pid);
}
int main()
{
    printf("Enter the quantum time:\n");
    int q_time,no_of_process,total_wt = 0,temp_index = 0,ans,done_process=0;
    scanf("%d",&q_time);
    printf("Enter the total no of process:\n");
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
    process temp_list[no_of_process];
    for(int cur_time = list[0].at ; cur_time >= 0 ;)
    {
        for(int i=0;i<no_of_process;i++)
        {
            if(list[i].at <= cur_time && list[i].done == 0)
            {
                temp_list[temp_index].at = list[i].at;
                temp_list[temp_index].bt = list[i].bt;
                temp_list[temp_index].pid = list[i].pid;
                temp_index++;
            }
            if(cur_time > 1 && temp_index == 0 && done_process == no_of_process)
                goto finish;
        }
        ans = min(temp_list,temp_index);
        if(list[ans-1].bt <= q_time)
        {
            cur_time+=list[ans-1].bt;
            list[ans-1].done = 1;
            list[ans-1].ct = cur_time;
            list[ans-1].tat = list[ans-1].ct-list[ans-1].at;
            list[ans-1].wt = list[ans-1].ct-list[ans-1].tat;
            total_wt+=list[ans-1].wt;
            done_process++;
        }
        else
        {
            cur_time+=q_time;
            list[ans-1].bt-=q_time;
        }
        temp_index=0;
    }
    finish:
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
    return(0);
}
