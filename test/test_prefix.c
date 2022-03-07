#include <textproc.h>
#include <unitytest/unity.h>

void setUp() {}
void tearDown() {}

void test_prefix_1()
{
  char out[5];
  textproc_common_prefix_2strings("arch", "archive", out, 5);

  TEST_ASSERT_EQUAL_STRING("arch", out);
}

int main(int argc, char* argv[])
{
  UNITY_BEGIN();
  RUN_TEST(test_prefix_1);
  return UNITY_END();
}
