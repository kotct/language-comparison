#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

/*#define USE_DEPRECATED*/
#define USE_IMPROVED

typedef unsigned long int number;

#ifdef USE_IMPROVED
bool is_prime(number test, number *primes_to)
#endif
#ifdef USE_DEPRECATED
bool is_prime(number test)
#endif
{
	number sqrttest = (number)sqrt(test);
	bool ret = true;
#ifdef USE_IMPROVED
	for(number c = 0; primes_to[c + 1] != '\0' && primes_to[c + 1] < sqrttest; c += 1) {
		if(test % primes_to[c] == 0) {
#endif
#ifdef USE_DEPRECATED
	for(number c = 2; c < sqrttest; c += 1) {
		if(test % c == 0) {
#endif
			ret = false;
			break;
		}
	}
	return ret;
}

number *get_n_primes(number cap)
{
	number retlen = 0;
	number *ret = (number *)malloc(sizeof(number) * cap);
	
	for(number i = 2; retlen < cap; i += 1) {
#ifdef USE_IMPROVED
		if(is_prime(i, ret)) {
#endif
#ifdef USE_DEPRECATED
		if(is_prime(i)) {
#endif
			retlen += 1;
			ret[retlen - 1] = i;
			ret[retlen - 0] = 0;
		}
	}

	return ret;
}

int main(int argc, char *argv[])
{
	number *primes = get_n_primes(10000);

	printf("%lu\n", primes[0]);
	
	free(primes);

	return 0;
}
