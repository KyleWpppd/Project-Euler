/*
The prime factors of 13195 are 5, 7, 13 and 29.

What is the largest prime factor of the number 600851475143 ?
*/
#include<stdio.h>
#include<stdint.h>

// #define TARGET 600851475143

int prime(u64int_t, u64int_t);
int primedesc(int, int);

int main()
{
	prime(13195LL, 0);
	prime(600851475143LL, 0);
	return 0;
}


//recursive funtion to find primes
int prime(u64int_t number, u64int_t maxfactor){
	uint64_t factor = 2;
	
	// go through every factor until a prime is reached
	while(number % factor != 0 && factor < number)
	{
		factor++;
	}
	printf("n=%llu   f=%llu\n", number, factor);
	if( number == factor)
	{	return 0; }

	prime(number / factor, factor > maxfactor ? factor : maxfactor);
	return 0;
}