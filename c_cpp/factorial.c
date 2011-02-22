#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <gmp.h>

void bigfactorial(uint32_t x, mpz_t fsum)
{
	if(x > 1)	
	{
		if(fsum == 0){
			fsum += x--;
			printf("%d! = %d * ",x+1,x+1);
		}
		else{
			fsum *= x--;
			printf("%d * ",x+1);
		}
		factorial(x, fsum);
	}
	else if(x == 1)
	{
		printf("1 = %d\n",*fsum);
		return;
	}
}

void factorial(uint32_t x, uint64_t *fsum)
{
	if(x > 1)	
	{
		if(*fsum == 0){
			*fsum += x--;
			printf("%d! = %d * ",x+1,x+1);
		}
		else{
			*fsum *= x--;
			printf("%d * ",x+1);
		}
		factorial(x, fsum);
	}
	else if(x == 1)
	{
		printf("1 = %d\n",*fsum);
		return;
	}
}

uint32_t sumofdigits(mpz_t sample)
{
	uint64_t digitsum =0;
	uint32_t i = 0;
	for(; sample > 1; sample /= 10)
	{
		
		digitsum += sample % 10;
		printf("s=%llu, pop=%llu\n",digitsum, sample % 10);
	}
	mpz_clear(sample);
	return digitsum;
}

int main(int argc, char **argv)
{
	uint32_t fact = 10;
	uint64_t sum = 0;
	factorial(fact, &sum);
	
	printf("%d! = %llu\n",fact,sum);
	sumofdigits(sum);
	return EXIT_SUCCESS;
}