#ifndef __TCZERO_H
#define __TCZERO_H

#include <stdint.h>


#define HALF_BLOCK_SIZE 64 /* Half of the block size; valid values are 1 <= m <= 64 */
#define RN2 64 /* Number of rounds/2; valid values are 1 <= r <= 64 (for 8-blocks, a value of ~40+ is necessary for good statistical behaviour) */



/*
 * The plaintext is represented as two quadwords, with only the HALF_BLOCK_SIZE
 * least significant bits of each being taken into account
 */
void tc0_encrypt(uint64_t x[2], uint64_t k[2]);

void tc0_decrypt(uint64_t x[2], uint64_t k[2]);

#endif
