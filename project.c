//code to determine wheather the given system is in safe state or not
#include<stdlib.h>
int main()
{  // P0, P1, P2, P3, P4 these are process names  
	int p,q,r,s,t;
	p=5; // process we have 
	q=4; // resources we have 
	int assign[5] [4]= {{0,0,1,2},   //p0   Resources Allocate
	                   {1,0,0,0},   //p1
					   {1,3,5,4},   //p2
					   {0,6,3,2},   //p3
					   {0,0,1,4}};  //p4
	
	int high[5] [4]= {{0,0,1,2},     //p0 max need
	                 {1,7,5,0},     //p1
					 {2,3,5,6},     //p2 
					 {0,6,5,2},     //p3
					 {0,6,5,6}};    //p4
    
	int use[4]= {1,5,2,0};       // Available  
    int g[p],sol[p],sta=0;
    for(t =0;t<p;t++)
    {
    	g[t]=0;
	}
	int require[p] [q];
	for(r=0;r<p;r++)
	{
		for(s=0;s<q;s++)
		require[r][s]=high[r][s]-assign[r][s];    //finding the remaining need
	}
	int y=0;
	for(t=0;t<5;t++)   //traversing of all the process
	{
		for(r=0;r<p;r++)
		{
			if(g[r]==0)
			{
				int flag=0;
				for(s=0;s<q;s++)
				{
					if(require[r][s]>use[s])      // remaining need are comparing with available processes
					{
						flag=1;
						break;
					}
				}
				if(flag==0)
				{                 
					sol[sta++]=r;   //  when  the required comparision  is found increments the index of  sequence 
					for(y=0;y<q;y++)
					use[y]+=assign[r][y];
					g[r]=1;
				}
			}
		}
	}
	    printf("this following sequence is SAFE Sequence:\n");
	for(r=0;r<p-1;r++)
	{
		printf("p%d->",sol[r]);
	}
	printf("p%d\n",sol[p-1]);
	system("pause");
	return(0);
}
