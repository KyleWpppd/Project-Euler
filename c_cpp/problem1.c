/*
Project Euler Problem 1.

Problem 1
05 October 2001

If we list all the natural numbers below 10 that are multiples of 3 or 5, 
we get 3, 5, 6 and 9. The sum of these multiples is 23.

Find the sum of all the multiples of 3 or 5 below 1000.

*/

/* Ideas: The pattern of 3s and 5s will repeat every 30. So it may be possible
   To divide the number by 30, add the sum of 3s and 5s from 0-30 and then just
   do the multiplication on the modulo of the number by 30. 
*/

#include<stdio.h>

using namespace std; 

#define MAX 1000

int main()
{
	int sum = 0, i = 0;
	
	for(i = 0; i <= MAX; i++)
	{
		if(i % 3 == 0)
			sum += i;
		else if(i % 5 == 0)
			sum += i;
		printf("%d  |  %d\n", i, sum);
	}	
	printf("The sum of 0 to %d is %d\n", MAX, sum);
	return 0;
}