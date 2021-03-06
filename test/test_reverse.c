#include <unitytest/unity.h>
#include <textproc.h>

void setUp() {}
void tearDown() {}

void test_reverse_numbers_in_string()
{
  char* input = "69420";
  char out[6];

  textproc_reverse_string(input, out, 6);

  TEST_ASSERT_EQUAL_STRING("02496", out);
}

void test_reverse_text()
{
  char* input = "text";
  char out[5];

  textproc_reverse_string(input, out, 5);

  TEST_ASSERT_EQUAL_STRING("txet", out);
}

void test_palindrome()
{
  char* input = "racecar";
  char out[8];

  textproc_reverse_string(input, out, 8);

  TEST_ASSERT_EQUAL_STRING("racecar", out);
}

int main(int argc, char** argv)
{
  UNITY_BEGIN();
  RUN_TEST(test_reverse_text);
  RUN_TEST(test_reverse_numbers_in_string);
  RUN_TEST(test_palindrome);
  return UNITY_END();
}
