#include <stdio.h>
int main()
{
	int n, M, max=M, min=M, temp;
	printf("Enter total number of elements: ");
	scanf("%d",&n);
	for (int i=1;i<n;i++)
	{
		printf("Enter value %d: ", i);
		scanf("%d", &M);
		if (M < min)
		{
			temp = M;
			M = max;
			min = temp;
		}
		else{
			temp = M;
			M = max;
			max = temp;
		}
	}
	printf("Maximum: %d\n", max);
	printf("Minimum: %d\n", min);
	return 0;
}
