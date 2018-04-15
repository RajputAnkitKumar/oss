#include<stdio.h>
#include<stdlib.h>
#define MAX 50
int k,j,q,i,n,ts,temp;
int aw;                      
float awt,totalt=0.0;
int qname[MAX],bt[MAX],wt[MAX],te[MAX],rt[MAX],at[MAX];
int n1=0; 
void studentinput()
{
	printf("Enter total no of Student Queries:");
    scanf("%d",&n);
    n1+=n;
    for(i=0;i<n;i++)
	{
		qname[i]=i+1;
	}
    printf("\nEnter burst  time and arriavl time of every student query\n");
    for(i=0;i<n;i++)
    {
        printf("SQ%d  burst time: ",i+1);
        scanf("%d",&bt[i]);
        printf("\nariavl time :  ");
        scanf("%d",&at[i]);
        te[i]=0;     
		wt[i]=0;
		printf("\n\n");
    }
    printf("\nStudent Query\t burst time\tArrival time\n");
	for(i=0;i<n;i++)
	{
		printf("\nSQ%d\t\t%d\t\t%d",i+1,bt[i],at[i]);
		rt[i]=bt[i];
	}
    for(i=0;i<n;i++)
    {
    	totalt+=bt[i];
	}
    for(i=0;i<n;i++)
    {
        for(j=i+1;j<n;j++)
        {
            if(at[i]>at[j])
            {
            	temp=qname[i];
            	qname[i]=qname[j];
            	qname[j]=temp;
                temp=at[i];                                          //sorting according to arrival time
                at[i]=at[j];
                at[j]=temp;
                temp=bt[i];
                bt[i]=bt[j];
                bt[j]=temp;
            }
        }
    }
    printf("\n Enter comman time slot for every studen quere:");
    scanf("%d",&ts);
	q=ts;
}
void studentqueries()
{
    printf("\n -----------Students Qureies ------------------ \n");
    j=0;
    printf("\nQuery Number\tSolved Time\n");
    while(j<=n)
    {
        j++;
        for(i=0;i<n;i++)
        {
            if(rt[i]==0)  continue;
            if(rt[i]>ts)
           {
                printf("SQ%d\t\t%d\n",qname[i],q);
                q=q+ts;
                rt[i]=rt[i]-ts;
                te[i]=te[i]+1;
            }
            else
            {
                printf("SQ%d\t\t%d\n",qname[i],q);
                wt[i]=q-te[i]*ts;
                q=q+rt[i]; 
                rt[i]=rt[i]-rt[i];
            }
        }
    }                                    
}
void teacherinput()
{
	printf("Enter total no of Teachers Queries:");
    scanf("%d",&n);
    n1+=n;
    for(i=0;i<n;i++)
	{
		qname[i]=i+1;
	}
    printf("\nEnter burst  time and arriavl time of every teacher query\n");
    for(i=0;i<n;i++)
    {
        printf("TQ%d  burst time: ",i+1);
        scanf("%d",&bt[i]);
        printf("\nariavl time :  ");
        scanf("%d",&at[i]);
        te[i]=0;     
		wt[i]=0;
		printf("\n\n");
    }
    printf("\nTeachers Query\t burst time\tArrival time\n");
	for(i=0;i<n;i++)
	{
		printf("\nTQ%d\t\t%d\t\t%d",i+1,bt[i],at[i]);
		rt[i]=bt[i];
	}
    for(i=0;i<n;i++)
    {
    	totalt+=bt[i];
	}
    for(i=0;i<n;i++)
    {
        for(j=i+1;j<n;j++)
        {
            if(at[i]>at[j])
            {
            	temp=qname[i];
            	qname[i]=qname[j];
            	qname[j]=temp;
                temp=at[i];                                          //sorting according to arrival time
                at[i]=at[j];
                at[j]=temp;
                temp=bt[i];
                bt[i]=bt[j];
                bt[j]=temp;
            }
        }
    }
    printf("\n Enter comman time slot for every Teacher query:");
    scanf("%d",&ts);
	q=ts;
}
void teacherqueries()
{
    printf("\n -----------Teachers Qureies ------------------ \n");
    j=0;
    printf("\nQuery Number\tSolved Time\n");
    while(j<=n)
    {
        j++;
        for(i=0;i<n;i++)
        {
            if(rt[i]==0)  continue;
            if(rt[i]>ts)
           {
                printf("TQ%d\t\t%d\n",qname[i],q);
                q=q+ts;
                rt[i]=rt[i]-ts;
                te[i]=te[i]+1;
            }
            else
            {
                printf("TQ%d\t\t%d\n",qname[i],q);
                wt[i]=q-te[i]*ts;
                q=q+rt[i]; 
                rt[i]=rt[i]-rt[i];
            }
        }
    }                                    
}
void owner()
{
	printf("Total time spend on handling all Queries=%.2f\n\n",totalt);
	printf("Average query time=%.2f",totalt/n1);
	
}
int main()
{
	int ch;
	char ch1;
	printf("\t\t\t\t\tWELCOME\t\t\t\t\t\t\n");
	printf("-----------------------------------------------------------------------------------------------------------\n");
	printf("Are you a faculty or a student????\n");
	printf("1.Press 1 to enter your query as faculty\n");
	printf("2.Press 2 to enter your query as student\n");
	printf("Enter your choice:");
	scanf("%d",&ch);
	if(ch==1)
	{
		studentinput();
		studentqueries();
		owner();
	}
	if(ch==2)
	{
		teacherinput();
		teacherqueries();
		owner();
	}	
    return 0;
 }
