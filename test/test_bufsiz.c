#include <unitytest/unity.h>
#include <textproc.h>

void setUp() {}
void tearDown() {}

void test_low_bufsiz()
{
  char* str = "string";
  char out[7];

  textproc_reverse_string(str, out, 5);

  TEST_ASSERT_EQUAL_STRING_MESSAGE("gnirts", out, "todo known breakage");
}

void test_correct_bufsiz()
{
  char* str = "string";
  char out[7];

  textproc_reverse_string(str, out, 7);

  TEST_ASSERT_EQUAL_STRING("gnirts", out);
}

void test_high_bufsiz()
{
  char* str = "string";
  char out[7];

  textproc_reverse_string(str, out, 9);

  TEST_ASSERT_EQUAL_STRING_MESSAGE("gnirts", out, "todo known breakage");
}

<<<<<<< HEAD


=======
>>>>>>> b070e73 (feat(test): add dedicated tests for bufsiz)
int main(int argc, char** argv)
{
  UNITY_BEGIN();
  RUN_TEST(test_low_bufsiz);
  RUN_TEST(test_high_bufsiz);
<<<<<<< HEAD
=======
  RUN_TEST(test_correct_bufsiz);
>>>>>>> b070e73 (feat(test): add dedicated tests for bufsiz)
  return UNITY_END();
}
