// Copyright 2025 NNTU-CS
#include <cstdint>
#include "alg.h"

uint64_t collatzMaxValue(uint64_t num) {
    uint64_t maxVal = num;
    while (num != 1) {
        if (num % 2 == 0) {
            num /= 2;
        } else {
            num = 3 * num + 1;
        }
        if (num > maxVal) {
            maxVal = num;
        }
    }
    return maxVal;
}

unsigned int collatzLen(uint64_t num) {
    unsigned int len = 1;
    while (num != 1) {
        if (num % 2 == 0) {
            num /= 2;
        } else {
            num = 3 * num + 1;
        }
        ++len;
    }
    return len;
}

unsigned int seqCollatz(unsigned int *maxlen, uint64_t lbound, uint64_t rbound) {
    if (lbound > rbound) {
        if (maxlen) *maxlen = 0;
        return 0;
    }

    unsigned int bestLen = 0;
    uint64_t bestNum = lbound;

    for (uint64_t i = lbound; i <= rbound; ++i) {
        unsigned int len = collatzLen(i);
        if (len > bestLen) {
            bestLen = len;
            bestNum = i;
        }
    }

    if (maxlen) *maxlen = bestLen;
    return static_cast<unsigned int>(bestNum);
}
