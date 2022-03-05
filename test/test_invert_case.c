#include <unitytest/unity.h>
#include <textproc.h>


void setUp() {}
void tearDown() {}

void test_invert_string()
{
  char* str = "lowerUPPER";
  char out[11];

  textproc_invert_string_case(str, out, 11);

  TEST_ASSERT_EQUAL_STRING("LOWERupper", out);
}

void test_invert_char()
{
  TEST_ASSERT_EQUAL_CHAR('C', textproc_invert_char_case('c'));
}

int main(int argc, char** argv)
{
  UNITY_BEGIN();
  RUN_TEST(test_invert_string);
  RUN_TEST(test_invert_char);
  UNITY_END();
  return 0;
}
