#include <stdlib.h>
#include <stdio.h>
#include <string.h>
int main()
{
	int m,p=0,n = 0,i = 0,j = 0,k,q=0 ;
	char c[100],c1[100],c2[100],max;
	gets(c);
	for(m=0;c[m]!='\0';m++)
	{
		if(c[m]=='.')
		{	
			q++;
			if(q==1)
			{
				for(n=0;n<=m;n++)
				{
					c1[n]=c[n];
				}
	            max = c1[0];
	            for(i=1;c1[i]!='.';i++)
				{
	                if(c1[i]>max)
					{
	                    max = c1[i];
	                    k=i+1;
					}
				} 
	            for(j=0;c1[j]!='.';j++)
	               c2[j]=c1[k+j];
	            strcpy(c1 + k ,"(max)");
	            strcat(c1,c2);
	            printf("%s",c1);
				p=m;
			}
			
			else
			{
				for(n=0;n<=m-p;n++)
			{   
				c1[n]=c[m-p+n];
			}
			    max = c1[0];
	            for(i=1;c1[i]!='.';i++)
				{
	                if(c1[i]>max)
					{
	                    max = c1[i];
	                    k=i+1;
					}
				} 
	            for(j=0;c1[j]!='.';j++)
	            {   
					c2[j]=c1[k+j];
				}
	            strcpy(c1 + k ,"(max)");
	            strcat(c1,c2);
	            printf("%s",c1);
				p=m;
			}
		}
		
	}
	system("pause"); 
	return 0;	
}