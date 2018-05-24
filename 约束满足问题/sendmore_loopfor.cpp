// problem description:
// You’re supposed write a program to solve this puzzle:

//   s e n d
// + m o r e
// ---------
// m o n e y
// Each letter correspond to a different digit between 0 and 9.
// Before you continue reading this post, try to think about how 
// you would approach this problem.

#include<stdio.h>
long int ii = 0;
int main()
{
	int s,e,n,d,m,o,r,y;
	
	for(s=0;s<10;s++)
	for(e=0;e<10;e++)
	for(n=0;n<10;n++)
	for(d=0;d<10;d++)
	for(m=0;m<10;m++)
	for(o=0;o<10;o++)
	for(r=0;r<10;r++)
	for(y=0;y<10;y++)
	{{{{{{{{
	ii ++;
	if(s-e&&s-n&&s-d&&s-m&&s-o&&s-r&&s-y
	     &&e-n&&e-d&&e-m&&e-o&&e-r&&e-y
	 		  &&n-d&&n-m&&n-o&&n-r&&n-y
	 	 	   	    &&d-m&&d-o&&d-r&&d-y
	 	 	   			 &&m-o&&m-r&&m-y
	 	 	   			 	  &&o-r&&o-y
	 	 	   			 	  	   &&r-y&&m&&s)
	{
		
		if(s*1000+e*100+n*10+d+m*1000+o*100+r*10+e==m*10000+o*1000+n*100+e*10+y)
		{   printf("%d%d%d%d+%d%d%d%d=%d%d%d%d%d\n",s,e,n,d,m,o,r,e,m,o,n,e,y);
			printf("%d\n",ii);
			break;
		}
	}
	}}}}}}}}
	return 0;
}