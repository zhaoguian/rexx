#include <vector>

#include "test/gtest-typed-test_test.h"
#include "gtest/gtest.h"

#if GTEST_HAS_TYPED_TEST_P

// Tests that the same type-parameterized test case can be
// instantiated in different translation units linked together.
// (ContainerTest is also instantiated in gtest-typed-test_test.cc.)
INSTANTIATE_TYPED_TEST_CASE_P(Vector, ContainerTest,
                              testing::Types<std::vector<int> >);

#endif  // GTEST_HAS_TYPED_TEST_P
