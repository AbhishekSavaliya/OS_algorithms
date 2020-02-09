#include<stdio.h>
#include<stdlib.h>
typedef struct process
{
    int at,bt,ct,tat,wt,pid,done;
    struct process* next;
}process;
void display(process*h)
{
    printf("\n---------------------------------------------------------------------\n");
    process*temp=h;
    if(h==NULL)
    {
        printf("linked list is empty.\n ");
    }
    else
    {
        while(temp->next != h)
        {
            printf("%d\n",temp->pid);
            temp=temp->next;
        }
        printf("%d\n",temp->pid);
    }
}
process * InsertAtTail(process*h,process element)
{
    process*newprocess=(process*)malloc(sizeof(process));
    if(newprocess==NULL)
        printf("malloc error!!!\n");
    newprocess->at=element.at;
    newprocess->bt=element.bt;
    newprocess->pid=element.pid;
    if(h==NULL)
    {
        h=newprocess;
    }
    else
    {
        process*temp=h;
        while(temp->next != NULL)
            temp=temp->next;
        temp->next=newprocess;
    }
    newprocess->next=NULL;
    return h;
}
int main()
{
    int q_time;
    printf("Enter the quantam time:\n");
    scanf("%d",&q_time);
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
    process* head = NULL;
    head = InsertAtTail(head,list[0]);
    list[0].done=1;
    process * exe_index = head;
    int total_wt = 0;
    while(exe_index!=NULL)
    {
        if(exe_index->bt > q_time)
        {
            //printf("%d   %d   %d\n",cur_time,exe_index->pid,cur_time+q_time);
            exe_index->bt-=q_time;
            cur_time+=q_time;
            for(int i = 0 ; i<no_of_process;i++)
            {
                if(cur_time >= list[i].at && list[i].done == 0)
                {
                    head = InsertAtTail(head,list[i]);
                    list[i].done=1;
                }
            }
            process temp;
            temp.at = exe_index->at;
            temp.bt = exe_index->bt;
            temp.pid = exe_index->pid;
            head = InsertAtTail(head,temp);
        }
        else
        {
            //printf("%d   %d   %d\n",cur_time,exe_index->pid,cur_time+exe_index->bt);
            cur_time+=exe_index->bt;
            list[exe_index->pid-1].ct=cur_time;
            list[exe_index->pid-1].tat=list[exe_index->pid-1].ct-list[exe_index->pid-1].at;
            list[exe_index->pid-1].wt=list[exe_index->pid-1].tat-list[exe_index->pid-1].bt;
            total_wt+=list[exe_index->pid-1].wt;
            for(int i = 0 ; i<no_of_process;i++)
            {
                if(cur_time >= list[i].at && list[i].done == 0)
                {
                    head = InsertAtTail(head,list[i]);
                    list[i].done=1;
                }
            }
        }
        exe_index=exe_index->next;
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
    return(0);
}
