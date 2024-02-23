#include<stdio.h>
int main()
{
	int n,i;
	int waiting_time=0;
	float avg_wt=0,avg_tat=0;
	printf("enter the number of processes");
	scanf("%d",&n);
	printf("enter the burst time");
	for(i=1;i<n;i++)
	{
		int burst_time=0;
		printf("P%d",i);
		scanf("%d",burst_time);
		int turnaround_time= waiting_time+burst_time;
		printf("P%d\t%d\t%d\t%d\t",i,waiting_time,burst_time,turnaround_time);
		avg_wt+=waiting_time;
		avg_tat+=turnaround_time;
		waiting_time+=burst_time;
		
	}
	avg_wt/=n;
	avg_tat/=n;
	
	printf("average waiting time=%2f",avg_wt);
	printf("average turnaround_time=%2f",avg_tat);
}
