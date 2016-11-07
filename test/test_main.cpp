#include <unity.h>

#ifdef UNIT_TEST

// void setUp(void) {
// // set stuff up here
// }

// void tearDown(void) {
// // clean stuff up here
// }

void test_test(void) {
    TEST_ASSERT_EQUAL(0,0);
}

int main(int argc, char **argv) {
  UNITY_BEGIN(); // Important! Must appear before any tests run!
  RUN_TEST(test_test);
  UNITY_END(); // Important! Must occur at end of test file

  return 0;
}

#endif
