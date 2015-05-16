/// Small constant-time core implementation of GCM mult.
/// (I.e. multiplication by a constant in F_{2^128})
/// Just for fun
/// W/o. SSE
/// But not fast compared to w. (cf. e.g. Käsper & Schwave, CHES2009)
///
/// PK 2015

#include <stdint.h>

// input in x, result in y
// h is the precomputed matrix of the multiplication by a field element
// with proper interleaving of rows to accomodate the one used
// in the loop, blah blah blah
void htimes(const uint64_t h[128][2], uint64_t x[2], uint64_t y[2])
{
	uint64_t mask0, mask1;

	y[0] = 0;
	y[1] = 0;

	// to avoid complementing every time during the broadcast
	x[0] = ~x[0];
	x[1] = ~x[1];

	for (int i = 0; i < 64; i++)
	{
		mask0 = (x[0] & 1) - 1ull;
		mask1 = (x[1] & 1) - 1ull;
		x[0] >>= 1;
		x[1] >>= 1;
		y[0] ^= h[2 * i][0] & mask0;
		y[1] ^= h[2 * i][1] & mask0;
		y[0] ^= h[2 * i + 1][0] & mask1;
		y[1] ^= h[2 * i + 1][1] & mask1;
	}

	return;
}
