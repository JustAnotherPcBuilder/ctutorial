#include <stdio.h>
#include <string.h>

char *bottle(int n, char *s);
int main(){

	int n = 99;
	char b[8];
	char *chorus =	"%d %s of beer on the wall, %d %s of beer!\n"
					"Take one down, pass it around, %d %s of beer on the wall!\n\n";
	char *p = chorus;

	while(n > 0)
	{
		printf( chorus, n, bottle(n, b), n, bottle(n, b), --n, bottle(n, b));
	}

	printf( "No more bottles of beer on the wall, no more bottles of beer!\n"
			"We've taken them down and passed them around; now we're drunk and passed out!\n\n");

	return 0;
}

char *bottle(int n, char *s)
{
	if(n == 1){
		strcpy(s, "bottle");
	}else{
		strcpy(s, "bottles");
	}

	return s;
}
