(defun divisible-by (number x)
  (= (floor number x) (/ number x)))

(defun prime? (number primes-to)
  (dolist (prime primes-to)
    (if (>= prime (sqrt number))
        (return t))
    (if (divisible-by number prime)
        (return f)))
  t)

(defun get-n-primes (cap)
  (let ((primes nil)
        (count 2)) ; the number we're testing
    (loop while (> cap (length primes)) ; loop while we don't still have enough primes
          do (when (prime? count primes)
               (setf primes (cons count primes)))
          do (incf count))
    primes))

(get-n-primes 2000000)
