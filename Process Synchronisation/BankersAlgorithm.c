#include<stdio.h>

int need[15][7],availble[15][7],allocated[15][7],max[15][7],flag[15],safeSeq[15];
int inputs[2];//1-need  2-allocated  3-max
int n,rsc,i,j,idx=0,idx2=0;

void findAvailable(int process_number)
{
    int k=0;
    printf("\nindex : %d , pro_id : %d\n",idx,process_number);
    for(k=0;k<rsc;k++)
    {
        availble[idx][k]=availble[idx-1][k]+allocated[process_number][k];
        printf("%d\t",availble[idx][k]);
    }
    idx++;
}

int canDone(int x)
{
    int temp,ans=0;
    printf("\ncheck flag %d -> %d",x,flag[x]);
    for(temp=0;temp<rsc;temp++)
    {
        if(need[x][temp]<=availble[idx-1][temp])
        {
            ans++;
        }
    }
    if(ans==rsc)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void safeSequence()
{
    int done=0;
    for(int j=0;j<n;j++)
    {
        for(int i=0;i<n;i++)
        {
            if(flag[i]==1)
            {
                if(canDone(i))
                {   
                    printf("\ni value brfore%d ",i);
                    findAvailable(i);
                    printf("\ni value after%d ",i);
                    printf("\nidx2 :  %d",idx2);
                    flag[i]=0;
                    printf("\nflag : %d",flag[i]);
                    safeSeq[idx2]=i+1;
                    printf("\nsafe%d :  %d",idx2+1,safeSeq[idx2]);
                    idx2++;
                }
            }
            printf("\n\n");
        }
    }
}

void findNeed()
{
    for(i=0;i<n;i++)
    {
        for(j=0;j<rsc;j++)
        {
            need[i][j]=max[i][j]-allocated[i][j];
        }
    }    
}

void findAllocated()
{
    for(i=0;i<n;i++)
    {
        for(j=0;j<rsc;j++)
        {
            allocated[i][j]=max[i][j]-need[i][j];
        }
    }    
}
void findmax()
{
    for(i=0;i<n;i++)
    {
        for(j=0;j<rsc;j++)
        {
            max[i][j]=allocated[i][j]+need[i][j];
        }
    }
}

void calculateOtherMatrix()
{
    int x=inputs[0]+inputs[1];
    if(x==3)
    {
        findmax();
    }
    else if (x==4)
    {
        findAllocated();
    }
    else if (x==5)
    {
        findNeed();
    }
}

void takeinput(int x)
{
    if(x==1)
    {
        printf("Enter need matrix : \n");
        for(i=0;i<n;i++)
        {
            for(j=0;j<rsc;j++)
            {
                scanf("%d",&need[i][j]);
            }
        }        
    }
    else if (x==2)
    {
        printf("Enter allocated matrix : \n");
        for(i=0;i<n;i++)
        {
            for(j=0;j<rsc;j++)
            {
                scanf("%d",&allocated[i][j]);
            }
        }
    }
    else if(x==3)
    {
        printf("Enter max matrix : \n");
        for(i=0;i<n;i++)
        {
            for(j=0;j<rsc;j++)
            {
                scanf("%d",&max[i][j]);
            }
        }
    }
}

int main()
{
    int i,j;

    printf("Enter the total number of processes : ");
    scanf("%d",&n);
    printf("Enter the total number of resources : ");
    scanf("%d",&rsc);

    printf("Enter any 2 number with their inputs\n");
    printf("\n1 for need\n2 for allocated\n3 for max\n");
    
    printf("\nEnter first choise : ");
    scanf("%d",&inputs[0]);
    takeinput(inputs[0]);

    printf("\nEnter second choise : ");    
    scanf("%d",&inputs[1]);
    takeinput(inputs[1]);

    printf("Enter the available matrix : ");
    for(i=0;i<rsc;i++)
    {
        scanf("%d",&availble[idx][i]);
    }
    idx+=1;
    for(i=0;i<n;i++)
    {
        flag[i]=1;
    }

    calculateOtherMatrix();

    safeSequence();

    printf("\nThe final safe sequence :");
    for(i=0;i<n;i++)
    {
        printf("\nP%d",safeSeq[i]);
    }
    return 0;
}
