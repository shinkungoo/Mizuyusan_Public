#include <stdio.h>

int main(void)
{
	int rank[1001], coe[1001];
	int i = 0, n;
	for(i = 0 ; i < 1001; i ++){
		scanf("%d %d", &coe[i], &rank[i]);
		if(rank[i] == 0){
			break;
		}
		
	}
	n = i;
	if(n == 0){
		printf("0 0");
	}else{
		for(i = 0; i < n ; i ++){
			coe[i] = rank[i] * coe[i];
			rank[i] = rank[i] - 1;
			printf("%d %d%s", coe[i], rank[i], (i == n - 1) ? "":" ");
		}
	}

	
	return 0;
}
