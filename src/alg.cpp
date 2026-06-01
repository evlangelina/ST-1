// Copyright 2025 UNN-CS
#include <cstdint>
#include <vector>
#include "alg.h"

namespace {

bool isPrimeCandidate(uint64_t num) {
  if (num < 2) {
    return false;
  }
  if (num == 2 || num == 3) {
    return true;
  }
  if (num % 2 == 0 || num % 3 == 0) {
    return false;
  }

  uint64_t step = 5;
  while (step * step <= num) {
    if (num % step == 0 || num % (step + 2) == 0) {
      return false;
    }
    step += 6;
  }
  return true;
}

uint64_t accumulatePrimeSum(uint64_t limit) {
  if (limit <= 2) {
    return 0;
  }

  std::vector<bool> marked(limit, false);
  uint64_t total = 0;

  for (uint64_t value = 2; value < limit; ++value) {
    if (marked[value]) {
      continue;
    }
    total += value;
    if (value * value >= limit) {
      continue;
    }
    for (uint64_t multiple = value * value; multiple < limit; multiple += value) {
      marked[multiple] = true;
    }
  }
  return total;
}

}  // namespace

bool checkPrime(uint64_t value) {
  return isPrimeCandidate(value);
}

uint64_t nPrime(uint64_t n) {
  if (n == 0) {
    return 0;
  }

  uint64_t ordinal = 0;
  for (uint64_t value = 2; ordinal < n; ++value) {
    if (isPrimeCandidate(value)) {
      ++ordinal;
      if (ordinal == n) {
        return value;
      }
    }
  }
  return 0;
}

uint64_t nextPrime(uint64_t value) {
  uint64_t probe = value;
  do {
    ++probe;
  } while (!isPrimeCandidate(probe));
  return probe;
}

uint64_t sumPrime(uint64_t hbound) {
  return accumulatePrimeSum(hbound);
}
