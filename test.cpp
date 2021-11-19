#include<stdio.h>
int main()
{
	int k,N,d,i,j;
	scanf("%d %d %d",&N,&i,&j);
	for(k=1; k<=N; k++)
	{
		printf("(%d,%d)",i,k);
		if(k!=N)
			printf(" ");
	}
	printf("\n");
	for(k=1; k<=N; k++)
	{
		printf("(%d,%d)",k,j);
		if(k!=N)
			printf(" ");
	}
	printf("\n");
    k=i,d=j;
    while(k>1 && d>1){
        k--; d--;
    }
    for(;k<=N&&d<=N;k++,d++){
        printf("(%d,%d)",k,d);
        if(k!=N&&d!=N)
            printf(" ");
    }
	printf("\n");
    k=i,d=j;
    while(k<N && d>1){
        k++; d--;
    }
	for(;k>=1&&d<=N;k--,d++){
        printf("(%d,%d)",k,d);
        if(k!=1&&d!=N)
            printf(" ");
    }
	return 0;
}