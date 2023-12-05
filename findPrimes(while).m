function nthPrime = findPrimes(n) 
    primes = 1;
    i = 3; 
    
    if n == 1
        nthPrime = 2;
    else
        while primes < n
            if isprime(i)
                primes = primes + 1;
                if primes == n
                    nthPrime = i;
                    return;
                end
            end
            i = i + 2; % Move to the next odd number
        end
    end
end
