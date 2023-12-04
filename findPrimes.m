
function nthPrime = findPrimes(n) 
    primes = 1;
    %set a condition for 2, since 2 is the only even prime number
    if n == 2
        nthPrime = 1;
    else
    %loop over odd numbers and test if they are prime.
      for i = 1:2:1000
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
