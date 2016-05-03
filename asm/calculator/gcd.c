#include <stdio.h>
#include <inttypes.h>

int64_t gcd( int64_t, int64_t );

int main() {
    printf("%ld\n", gcd( 10, 15 ) );
    return 0;
}