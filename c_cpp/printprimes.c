// from http://en.wikipedia.org/wiki/Sieve_of_Eratosthenes

#include <stdlib.h>
#include <stdio.h>



// prints prime numbers below pceiling 
void printPrimes(size_t pceiling, size_t maxprimesfound)
{
	char *array=(char*) malloc(pceiling+1); // allocate an array of n+1 size
	size_t i=0, j=0, count=0;
	unsigned long long sumofprimes=0, p=2;
	
	// initialize all items of the array to remain
	for(i=0; i<pceiling+1; i++)
	{
			array[i]='r';//'r' denotes remain
	}
	
	array[0]='d';//'d' denotes delete
	array[1]='d';// 0 and 1 are defined as unprime
	
	
	while(p*p<=pceiling) // the sieve of eratosthenes begins with the square of the possible prime
	{
		if(array[p]=='r'){
			for(j=2; j*p<=pceiling; j++)	
			{
				array[j*p]='d';
			}
		}
		p++;
	}
	
	
	for(p=2; p<=pceiling; p++)
		if(array[p]=='r'){
			//printf("%d->%d\t",++count, p);
			sumofprimes += p;
			printf("%llu\t",sumofprimes);
			if(maxprimesfound != 0 && count >=maxprimesfound)
				break;
			}
			printf("sum of primes=%d\n", sumofprimes);
        free(array);
 
};


int main(int argc, char **argv)
{
	size_t pri=2000000, count=0;
	printPrimes(pri, count);
	return 0;
}