(defun divisible-by (number x)
  (= (floor number x) (/ number x)))

(defun prime? (number primes-to)
  (not (some #'(lambda (x) (divisible-by number x))
			 primes-to)))

(defun get-n-primes (cap)
  (let ((primes nil)
		(count 2)) ; the number we're testing
	(loop while (> cap (length primes)) ; loop while we don't still have enough primes
		  do (when (prime? count primes)
			   (setf primes (cons count primes)))
		  do (incf count))
	primes))
