// Copyright 2025 UNN-CS

#include <gtest/gtest.h>
#include <cstdint>
#include "alg.h"

struct PrimalitySample {
  uint64_t number;
  bool is_prime;
};

struct OrdinalSample {
  uint64_t index;
  uint64_t prime_value;
};

struct NextPrimeSample {
  uint64_t from;
  uint64_t expected;
};

struct SumSample {
  uint64_t bound;
  uint64_t expected_sum;
};

class PrimalityParameterizedTest
    : public ::testing::TestWithParam<PrimalitySample> {};

TEST_P(PrimalityParameterizedTest, CheckPrimeMatchesExpected) {
  const PrimalitySample& sample = GetParam();
  EXPECT_EQ(sample.is_prime, checkPrime(sample.number));
}

INSTANTIATE_TEST_SUITE_P(
    BorderAndSmallValues,
    PrimalityParameterizedTest,
    ::testing::Values(
        PrimalitySample{0, false},
        PrimalitySample{1, false},
        PrimalitySample{2, true},
        PrimalitySample{3, true},
        PrimalitySample{4, false},
        PrimalitySample{5, true}));

INSTANTIATE_TEST_SUITE_P(
    CompositePatterns,
    PrimalityParameterizedTest,
    ::testing::Values(
        PrimalitySample{6, false},
        PrimalitySample{9, false},
        PrimalitySample{15, false},
        PrimalitySample{21, false},
        PrimalitySample{25, false},
        PrimalitySample{49, false},
        PrimalitySample{121, false}));

INSTANTIATE_TEST_SUITE_P(
    KnownPrimes,
    PrimalityParameterizedTest,
    ::testing::Values(
        PrimalitySample{7, true},
        PrimalitySample{11, true},
        PrimalitySample{17, true},
        PrimalitySample{97, true},
        PrimalitySample{101, true},
        PrimalitySample{997, true},
        PrimalitySample{104729, true}));

INSTANTIATE_TEST_SUITE_P(
    KnownComposites,
    PrimalityParameterizedTest,
    ::testing::Values(
        PrimalitySample{100, false},
        PrimalitySample{999, false},
        PrimalitySample{1000, false},
        PrimalitySample{100001, false}));

class NPrimeParameterizedTest
    : public ::testing::TestWithParam<OrdinalSample> {};

TEST_P(NPrimeParameterizedTest, ReturnsCorrectOrdinalPrime) {
  const OrdinalSample& sample = GetParam();
  EXPECT_EQ(sample.prime_value, nPrime(sample.index));
}

INSTANTIATE_TEST_SUITE_P(
    FirstTenPrimes,
    NPrimeParameterizedTest,
    ::testing::Values(
        OrdinalSample{1, 2},
        OrdinalSample{2, 3},
        OrdinalSample{3, 5},
        OrdinalSample{4, 7},
        OrdinalSample{5, 11},
        OrdinalSample{6, 13},
        OrdinalSample{7, 17},
        OrdinalSample{10, 29},
        OrdinalSample{20, 71},
        OrdinalSample{25, 97}));

class NextPrimeParameterizedTest
    : public ::testing::TestWithParam<NextPrimeSample> {};

TEST_P(NextPrimeParameterizedTest, FindsNearestGreaterPrime) {
  const NextPrimeSample& sample = GetParam();
  EXPECT_EQ(sample.expected, nextPrime(sample.from));
}

INSTANTIATE_TEST_SUITE_P(
    BasicTransitions,
    NextPrimeParameterizedTest,
    ::testing::Values(
        NextPrimeSample{0, 2},
        NextPrimeSample{1, 2},
        NextPrimeSample{2, 3},
        NextPrimeSample{3, 5},
        NextPrimeSample{4, 5},
        NextPrimeSample{5, 7},
        NextPrimeSample{10, 11},
        NextPrimeSample{11, 13}));

INSTANTIATE_TEST_SUITE_P(
    LargerTransitions,
    NextPrimeParameterizedTest,
    ::testing::Values(
        NextPrimeSample{97, 101},
        NextPrimeSample{100, 101},
        NextPrimeSample{996, 997},
        NextPrimeSample{1000, 1009}));

class SumPrimeParameterizedTest
    : public ::testing::TestWithParam<SumSample> {};

TEST_P(SumPrimeParameterizedTest, AccumulatesPrimesBelowBound) {
  const SumSample& sample = GetParam();
  EXPECT_EQ(sample.expected_sum, sumPrime(sample.bound));
}

INSTANTIATE_TEST_SUITE_P(
    LowBounds,
    SumPrimeParameterizedTest,
    ::testing::Values(
        SumSample{0, 0},
        SumSample{1, 0},
        SumSample{2, 0},
        SumSample{3, 2},
        SumSample{5, 5},
        SumSample{7, 10},
        SumSample{10, 17},
        SumSample{20, 77},
        SumSample{30, 129},
        SumSample{100, 1060},
        SumSample{500, 21536}));

class St1AssignmentFixture : public ::testing::Test {};

TEST_F(St1AssignmentFixture, nPrimeZeroIsZero) {
  EXPECT_EQ(0u, nPrime(0));
}

TEST_F(St1AssignmentFixture, sumPrimeTwoMillion) {
  const uint64_t result = sumPrime(2000000);
  const uint64_t expected = 142913828922;
  EXPECT_EQ(expected, result);
}

TEST_F(St1AssignmentFixture, sumPrimeTen) {
  const uint64_t result = sumPrime(10);
  const uint64_t expected = 17;
  EXPECT_EQ(expected, result);
}

TEST(st1, sumPrime1) {
  uint64_t res = sumPrime(2000000);
  uint64_t expected = 142913828922;
  EXPECT_EQ(expected, res);
}

TEST(st1, sumPrime2) {
  uint64_t res = sumPrime(10);
  uint64_t expected = 17;
  EXPECT_EQ(expected, res);
}
