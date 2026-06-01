// Copyright 2025 UNN-CS

#include <gtest/gtest.h>
#include <cstdint>
#include "alg.h"

TEST(PrimeChecks, zeroAndOneAreNotPrime) {
  EXPECT_FALSE(checkPrime(0));
  EXPECT_FALSE(checkPrime(1));
}

TEST(PrimeChecks, twoIsTheSmallestPrime) {
  EXPECT_TRUE(checkPrime(2));
}

TEST(PrimeChecks, evenNumbersAboveTwoAreComposite) {
  EXPECT_FALSE(checkPrime(4));
  EXPECT_FALSE(checkPrime(6));
  EXPECT_FALSE(checkPrime(100));
}

TEST(PrimeChecks, oddCompositeNumbersAreRejected) {
  EXPECT_FALSE(checkPrime(9));
  EXPECT_FALSE(checkPrime(15));
  EXPECT_FALSE(checkPrime(21));
}

TEST(PrimeChecks, recognizesTypicalPrimes) {
  EXPECT_TRUE(checkPrime(3));
  EXPECT_TRUE(checkPrime(11));
  EXPECT_TRUE(checkPrime(97));
}

TEST(PrimeChecks, threeAndFiveArePrime) {
  EXPECT_TRUE(checkPrime(3));
  EXPECT_TRUE(checkPrime(5));
}

TEST(PrimeChecks, perfectSquaresAreComposite) {
  EXPECT_FALSE(checkPrime(25));
  EXPECT_FALSE(checkPrime(49));
  EXPECT_FALSE(checkPrime(121));
}

TEST(PrimeChecks, largerPrimesAreAccepted) {
  EXPECT_TRUE(checkPrime(101));
  EXPECT_TRUE(checkPrime(997));
  EXPECT_TRUE(checkPrime(104729));
}

TEST(PrimeChecks, largerCompositesAreRejected) {
  EXPECT_FALSE(checkPrime(999));
  EXPECT_FALSE(checkPrime(1000));
  EXPECT_FALSE(checkPrime(100001));
}

TEST(PrimeOrdinal, returnsNthPrimeInSequence) {
  EXPECT_EQ(2u, nPrime(1));
  EXPECT_EQ(3u, nPrime(2));
  EXPECT_EQ(5u, nPrime(3));
  EXPECT_EQ(11u, nPrime(5));
  EXPECT_EQ(29u, nPrime(10));
}

TEST(PrimeOrdinal, zeroIndexReturnsZero) {
  EXPECT_EQ(0u, nPrime(0));
}

TEST(PrimeOrdinal, fourthAndSixthPrimes) {
  EXPECT_EQ(7u, nPrime(4));
  EXPECT_EQ(13u, nPrime(6));
}

TEST(PrimeOrdinal, seventhAndTwentiethPrimes) {
  EXPECT_EQ(17u, nPrime(7));
  EXPECT_EQ(71u, nPrime(20));
}

TEST(PrimeOrdinal, twentyFifthPrimeIsNinetySeven) {
  EXPECT_EQ(97u, nPrime(25));
}

TEST(NextPrimeSearch, skipsCompositeValues) {
  EXPECT_EQ(5u, nextPrime(4));
  EXPECT_EQ(13u, nextPrime(11));
  EXPECT_EQ(101u, nextPrime(100));
}

TEST(NextPrimeSearch, valueIsNotIncludedInResult) {
  EXPECT_EQ(3u, nextPrime(2));
  EXPECT_EQ(7u, nextPrime(5));
  EXPECT_EQ(11u, nextPrime(10));
}

TEST(NextPrimeSearch, afterZeroAndOne) {
  EXPECT_EQ(2u, nextPrime(0));
  EXPECT_EQ(2u, nextPrime(1));
}

TEST(NextPrimeSearch, afterLargeComposite) {
  EXPECT_EQ(997u, nextPrime(996));
  EXPECT_EQ(1009u, nextPrime(1000));
}

TEST(NextPrimeSearch, afterPrimeReturnsNextOne) {
  EXPECT_EQ(5u, nextPrime(3));
  EXPECT_EQ(101u, nextPrime(97));
}

TEST(PrimeSum, emptyRangeBelowTwo) {
  EXPECT_EQ(0u, sumPrime(2));
}

TEST(PrimeSum, smallUpperBounds) {
  EXPECT_EQ(2u, sumPrime(3));
  EXPECT_EQ(5u, sumPrime(5));
  EXPECT_EQ(10u, sumPrime(7));
  EXPECT_EQ(1060u, sumPrime(100));
}

TEST(PrimeSum, zeroAndOneReturnZero) {
  EXPECT_EQ(0u, sumPrime(0));
  EXPECT_EQ(0u, sumPrime(1));
}

TEST(PrimeSum, upToTwenty) {
  EXPECT_EQ(58u, sumPrime(20));
}

TEST(PrimeSum, upToThirty) {
  EXPECT_EQ(129u, sumPrime(30));
}

TEST(PrimeSum, mediumUpperBound) {
  EXPECT_EQ(21536u, sumPrime(500));
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
