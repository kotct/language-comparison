(defun divisible-by (number x)
  (= (floor number x) (/ number x)))

(defun prime? (number primes-to)
  (dolist (prime primes-to)
    (if (> prime (sqrt number))
        (return-from prime? t))
    (if (divisible-by number prime)
        (return-from prime? nil)))
  t)

(defun get-n-primes (cap)
  (let ((primes nil)
        (count 2)) ; the number we're testing
    (loop while (> cap (length primes)) ; loop while we don't still have enough primes
          do (when (prime? count primes)
               (setf primes (append primes (list count))))
          do (incf count))
    primes))

(time (get-n-primes (2000000))
