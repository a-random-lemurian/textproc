#include <textproc.h>
#include <unitytest/unity.h>


void setUp() {}
void tearDown() {}


void test_levenshtein()
{
  char* str1 = "distance";
  char* str2 = "distancc";

  TEST_ASSERT_EQUAL_INT(1, textproc_levenshtein(str1, str2));
}


int main(int argc, char** argv)
{
  UNITY_BEGIN();
  RUN_TEST(test_levenshtein);
  return UNITY_END();
}
