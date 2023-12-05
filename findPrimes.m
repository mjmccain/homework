function nthPrime = findPrimes(n) 
    primes = 1;
    i = 3;
    %set a condition for 2, since 2 is the only even prime number
    if n == 1
        nthPrime = 2;
    else
    %loop over odd numbers and test if they are prime.
    %looping over only odds makes the code more efficient.
      for i = 3:1:inf
          if isprime(i)
            primes = primes + 1;
            nthPrime = i;
          end
          if primes == n
             break
          end
      end
    
      end
    
end
