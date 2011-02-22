/*
The sum of the squares of the first ten natural numbers is,

12 + 22 + ... + 102 = 385
The square of the sum of the first ten natural numbers is,

(1 + 2 + ... + 10)2 = 552 = 3025
Hence the difference between the sum of the squares of the first ten natural numbers and the square of the sum is 3025  385 = 2640.

Find the difference between the sum of the squares of the first one hundred natural numbers and the square of the sum.
*/

/*
IDEAS----

KISS... Just do the bizness...& make sure there is enough room for the sums
*/

#include <stdio.h>
#include <stdlib.h>

uint64_t sumofsquares(int, int);
uint64_t sumnaturalnums(int, int);

int main(){
	uint64_t ssquares = 0l, snatnums = 0l, ans;
	ssquares = sumofsquares(1, 100);
	snatnums = sumnaturalnums(1, 100);
	snatnums *= snatnums; // square the sum of natural numbers
	printf("S nat nums^2 = %llu\n", snatnums);
	ans = (snatnums-ssquares);
	ans *= ans;
	
	printf("Snatnums %llu - %llu Ssquares = %llu\n", snatnums, ssquares, snatnums-ssquares);
	printf("Sqaured = %llu\n", ans);

	return 0;	
}

uint64_t sumofsquares(int start, int finish)
{
	int i;
	uint64_t sum = 0;
	for(i = start ; i <= finish; i++)
	{
		sum += i * i;
	}
	printf("Sum of squares %d\n", sum);
	return sum;
}

uint64_t sumnaturalnums(int start, int finish)
{
	int i;
	uint64_t sum = 0;
	for(i = start; i <= finish; i++)
	{
		sum += i;
	}
	printf("Sum of natural numbers %d\n", sum);
	return sum;
}