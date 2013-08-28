#include <iostream>
#include <vector>

using namespace std;

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef unsigned long int number;

bool is_prime(number test, vector<number> previous_primes)
{
	number sqrt_of_test = (number)sqrt(test);
	bool ret = true;

	for(number c = 0; c < previous_primes.size(); c += 1) {
		if(test % previous_primes[c] == 0) {
			ret = false;
			break;
		}
	}
	
	return ret;
}

vector<number> get_n_primes(number cap)
{
	vector<number> ret;

	number test = 2;

	while(ret.size() < cap) {
		if(is_prime(test, ret)) {
			printf("Pushing %lu\n", test);
			ret.push_back(test);
		}
		test += 1;
	}

	return ret;
}

int main(int argc, char *argv[])
{
	vector<number> primes = get_n_primes(2000000);

	printf("%lu\n", primes[0]);

	return 0;
}
