// Copyright 2025 UNN-CS

#include <gtest/gtest.h>
#include <cstdint>
#include "alg.h"

TEST(st1, checkPrime_2_is_prime) {
  EXPECT_TRUE(checkPrime(2));
}
TEST(st1, checkPrime_3_is_prime) {
  EXPECT_TRUE(checkPrime(3));
}
TEST(st1, checkPrime_4_is_not_prime) {
  EXPECT_FALSE(checkPrime(4));
}
TEST(st1, checkPrime_1_is_not_prime) {
  EXPECT_FALSE(checkPrime(1));
}
TEST(st1, checkPrime_11_is_prime) {
  EXPECT_TRUE(checkPrime(11));
}
TEST(st1, checkPrime_0_is_not_prime) {
  EXPECT_FALSE(checkPrime(0));
}
TEST(st1, checkPrime_5_7_13_17_prime) {
  EXPECT_TRUE(checkPrime(5));
  EXPECT_TRUE(checkPrime(7));
  EXPECT_TRUE(checkPrime(13));
  EXPECT_TRUE(checkPrime(17));
}
TEST(st1, checkPrime_6_8_9_15_not_prime) {
  EXPECT_FALSE(checkPrime(6));
  EXPECT_FALSE(checkPrime(8));
  EXPECT_FALSE(checkPrime(9));
  EXPECT_FALSE(checkPrime(15));
}
TEST(st1, checkPrime_100_not_prime) {
  EXPECT_FALSE(checkPrime(100));
}
TEST(st1, checkPrime_97_prime) {
  EXPECT_TRUE(checkPrime(97));
}

TEST(st1, nPrime_1_is_2) {
  EXPECT_EQ(2u, nPrime(1));
}
TEST(st1, nPrime_5_is_11) {
  EXPECT_EQ(11u, nPrime(5));
}
TEST(st1, nPrime_4_is_7) {
  EXPECT_EQ(7u, nPrime(4));
}
TEST(st1, nPrime_2_is_3) {
  EXPECT_EQ(3u, nPrime(2));
}
TEST(st1, nPrime_3_is_5) {
  EXPECT_EQ(5u, nPrime(3));
}
TEST(st1, nPrime_6_is_13) {
  EXPECT_EQ(13u, nPrime(6));
}
TEST(st1, nPrime_10_is_29) {
  EXPECT_EQ(29u, nPrime(10));
}

TEST(st1, nextPrime_4_is_5) {
  EXPECT_EQ(5u, nextPrime(4));
}
TEST(st1, nextPrime_11_is_13) {
  EXPECT_EQ(13u, nextPrime(11));
}
TEST(st1, nextPrime_2_is_3) {
  EXPECT_EQ(3u, nextPrime(2));
}
TEST(st1, nextPrime_1_is_2) {
  EXPECT_EQ(2u, nextPrime(1));
}
TEST(st1, nextPrime_3_is_5) {
  EXPECT_EQ(5u, nextPrime(3));
}
TEST(st1, nextPrime_5_is_7) {
  EXPECT_EQ(7u, nextPrime(5));
}
TEST(st1, nextPrime_10_is_11) {
  EXPECT_EQ(11u, nextPrime(10));
}
TEST(st1, nextPrime_100_is_101) {
  EXPECT_EQ(101u, nextPrime(100));
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
TEST(st1, sumPrime_5_is_5) {
  uint64_t res = sumPrime(5);
  EXPECT_EQ(5u, res);
}
TEST(st1, sumPrime_3_is_2) {
  EXPECT_EQ(2u, sumPrime(3));
}
TEST(st1, sumPrime_7_is_10) {
  EXPECT_EQ(10u, sumPrime(7));
}
TEST(st1, sumPrime_100_is_1060) {
  EXPECT_EQ(1060u, sumPrime(100));
}
TEST(st1, sumPrime_2_is_0) {
  EXPECT_EQ(0u, sumPrime(2));
}
