#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

void accept(int n, int A[])
{
    int i;
    for(i=0;i<n;i++)
    scanf("%d",&A[i]);
}

void display(int n ,int A[])
{
    int i;
    for(i=0;i<n;i++){
    printf("%d ",A[i]);
}
    printf("\n");

}

int main()
{
    int n;
    printf("Enter the number of elements:");
    scanf("%d",&n);
    int A[n];
    accept(n,A);
    int p_id=fork();
    
    if(p_id>0)
    {
        printf("Ascending order:");
        int i,j,temp;
        for(i=1;i<=n-1;i++)
        {
            for(j=0;j<=n-2;j++)
            {
                if(A[j]>A[j+1])
                {
                    temp=A[j];
                    A[j]=A[j+1];
                    A[j+1]=temp;
                }
            }
        }
        display(n,A);
       // wait(NULL);
    }
      
    else if(p_id==0)
    {
        printf("Descending order:");
        int i,j,temp;
        for(i=1;i<=n-1;i++)
        {
            for(j=0;j<=n-2;j++)
            {
                if(A[j]<A[j+1])
                {
                    temp=A[j];
                    A[j]=A[j+1];
                    A[j+1]=temp;
                }
            }
        }
        display(n,A);
        //wait(NULL);
    }
    
    else
    {
        printf("Failed to create child process!!!");
    }
 
    return 0;
}