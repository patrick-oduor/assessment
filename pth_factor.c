
/*
  We're dealing with N up to 10^15, so a linear O(N) scan is out of the question.
  I've optimized this to O(sqrt(N)) by exploiting factor symmetry.

 
  We capture all factors below the square root first, then mathematically 
  derive their partners to find the p-th value. This keeps the execution 
  sub-second even for quadrillion-scale inputs.

*/


#include <stdio.h>
#include <math.h>

long pthFactor(long n, long p) {
    long small_factors [5000]; // Buffer to cache factors <= sqrt(n).
    int count = 0; 
    long sqrt_n = (long)sqrt(n);

    // Grab small factors and check if we hit 'p' early.
    for(long i = 1; i <= sqrt_n; i++) {
        if (n % i == 0) {
            count++;
            if (count == p) return i; // Found p-th factor early.
            small_factors[count - 1] = i;


        }
    }


    // Calculate large 'partner' factors in reverse.
    // We check if n is a perfect square to avoid double-counting the middle factor.

    int total_small = count;
    if(sqrt_n * sqrt_n == n) {
        count--; // The square root partner has no unique partner.

    }

    // If P is within range of the large partner factors.
    if(p <= total_small + count) {

        // If p lies in the upper half, we derive the partner from our cache.
        long target_small_factor = small_factors[total_small - (p - total_small)];

        return n / target_small_factor;

    }

    return 0; // p-th factor exceeds total nummber of factors
}