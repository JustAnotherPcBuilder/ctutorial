#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	char buffer[64] = {0};
	double nums[3] = {0};
	double temp;

	int max = 0;
	printf("Enter 3 sides to check if pythagorean triple!\n");
	for(int i = 0; i < 3; i++){
		fgets(buffer, sizeof buffer, stdin);
		nums[i] = atof(buffer);
		memset(buffer, 0, sizeof buffer);

		// Make sure largest is at end
		if(max != i){
			if(nums[i] < nums[max]){
				temp = nums[i];
				nums[i] = nums[max];
				nums[max] = temp;
				max = i;
			}
		}
	}
	
	if(nums[0] * nums[0] + nums[1] * nums[1] == nums[2] * nums [2]){
		printf("These are a triple!\n");
	}else{
		printf("These are not a triple...\n");
	}

	return 0;
}
