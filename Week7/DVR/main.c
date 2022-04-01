#include<stdio.h>
struct router
{
    unsigned dis[20];
    unsigned from[20];
}rout[10];
int main()
{
    int costmatrix[20][20];
    int routers,i,j,k;
    printf("\nEnter the number of routers: ");
    scanf("%d",&routers);
    printf("\nEnter the cost matrix :\n");
    for(i=0;i<routers;i++)
    {
        for(j=0;j<routers;j++)
        {
            scanf("%d",&costmatrix[i][j]);
            costmatrix[i][i]=0;
            rout[i].dis[j]=costmatrix[i][j];
            rout[i].from[j]=j;
        }
    }
        
            
            for(i=0;i<routers;i++)
            for(j=0;j<routers;j++)
            for(k=0;k<routers;k++)
                if(rout[i].dis[j]>costmatrix[i][k]+rout[k].dis[j])
                {
                    rout[i].dis[j]=rout[i].dis[k]+rout[k].dis[j];
                    rout[i].from[j]=k;
                }
        
        for(i=0;i<routers;i++)
        {
            printf("\n\n For router %d\n",i+1);
            for(j=0;j<routers;j++)
            {
                printf("\t\nrouter %d via %d Distance %d ",j+1,rout[i].from[j]+1,rout[i].dis[j]);
            }
        }
    printf("\n\n");
   
}
