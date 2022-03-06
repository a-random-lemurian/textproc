#include <textproc.h>
#include <unitytest/unity.h>

void setUp() {}
void tearDown() {}


void test_upper_to_lower()
{
  char* str = "UPPER";
  char out[6];

  textproc_lower_string(str, out, 6);
  TEST_ASSERT_EQUAL_STRING("upper", out);
}

void test_lower_to_upper()
{
  char* str = "lower";
  char out[6];

  textproc_upper_string(str, out, 6);
  TEST_ASSERT_EQUAL_STRING("LOWER", out);
}


int main(int argc, char** argv)
{
  UNITY_BEGIN();
  RUN_TEST(test_lower_to_upper);
  RUN_TEST(test_upper_to_lower);
  return UNITY_END();
}
