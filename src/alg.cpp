// Copyright 2025 UNN-CS
#include <cmath>
#include <cstdint>
#include <vector>
#include "alg.h"

namespace {

struct PrimeCalculator {
  static bool hasDivisor(uint64_t number, uint64_t divisor) {
    return number % divisor == 0;
  }

  static bool trialDivision(uint64_t number) {
    if (number < 2) {
      return false;
    }
    if (number == 2) {
      return true;
    }
    if (number % 2 == 0) {
      return false;
    }

    const uint64_t root =
        static_cast<uint64_t>(std::sqrt(static_cast<long double>(number)));
    for (uint64_t divisor = 3; divisor <= root; divisor += 2) {
      if (hasDivisor(number, divisor)) {
        return false;
      }
    }
    return true;
  }

  static uint64_t sieveSum(uint64_t upper) {
    if (upper <= 2) {
      return 0;
    }

    std::vector<uint8_t> crossed(upper, 0);
    for (uint64_t base = 2; base < upper; ++base) {
      if (crossed[base] != 0) {
        continue;
      }
      for (uint64_t mark = base + base; mark < upper; mark += base) {
        crossed[mark] = 1;
      }
    }

    uint64_t accumulated = 0;
    for (uint64_t value = 2; value < upper; ++value) {
      if (crossed[value] == 0) {
        accumulated += value;
      }
    }
    return accumulated;
  }
};

}  // namespace

bool checkPrime(uint64_t value) {
  return PrimeCalculator::trialDivision(value);
}

uint64_t nPrime(uint64_t n) {
  if (n == 0) {
    return 0;
  }

  uint64_t position = 0;
  uint64_t current = 1;
  while (position < n) {
    ++current;
    if (PrimeCalculator::trialDivision(current)) {
      ++position;
    }
  }
  return current;
}

uint64_t nextPrime(uint64_t value) {
  uint64_t current = value;
  while (true) {
    ++current;
    if (PrimeCalculator::trialDivision(current)) {
      return current;
    }
  }
}

uint64_t sumPrime(uint64_t hbound) {
  return PrimeCalculator::sieveSum(hbound);
}
