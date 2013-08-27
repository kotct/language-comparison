def is_prime(number, primes_to)
	# loop through all of the previously-generated primes
	primes_to.each do |prime|
		# if the number is divisible by any of the previously-
		# generated primes, it's not prime, so stop
		if number % prime == 0
			return false
		end
	end

	return true
end

def get_n_primes(cap)
	# initialize an empty array
	primes = []

	# the numbers we're testing
	count = 2

	# loop until we have n primes
	while primes.length < cap
		# if it's prime
		if is_prime(count, primes)
			# push the number to the back of the primes array
			primes << count
		end
		
		# increment to the next number
		count += 1
	end

	# return the array
	return primes
end

primes = get_n_primes(2000000)
