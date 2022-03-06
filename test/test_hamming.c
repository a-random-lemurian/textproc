#include <unitytest/unity.h>
#include <textproc.h>

void setUp() {}
void tearDown() {}

void test_hamming_distance_equal_len_str()
{
  char* str1 = "Hamming";
  char* str2 = "Hammmmm";

  TEST_ASSERT_EQUAL_size_t(3, textproc_hamming_distance(str1, str2));
}

void test_hamming_distance_equal_len_str_diff_case()
{
  char* str1 = "Hamming";
  char* str2 = "hammmmm";

  TEST_ASSERT_EQUAL_size_t(4, textproc_hamming_distance(str1, str2));
}

int main(int argc, char** argv)
{
  UNITY_BEGIN();
  RUN_TEST(test_hamming_distance_equal_len_str);
  RUN_TEST(test_hamming_distance_equal_len_str_diff_case);
  return UNITY_END();
}
