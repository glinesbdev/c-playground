#include "strings.h"
#include "unity.h"

void setUp(void) {}

void tearDown(void) {}

void string_reverse_test(void) {
  char reversed[] = "something";
  revstr(reversed);
  TEST_ASSERT_EQUAL_CHAR_ARRAY(reversed, "gnihtemos", 9);
}

void string_reverse_copy_test(void) {
  char str[] = "another something";
  char *reversed = revstr_copy(str);
  TEST_ASSERT_EQUAL_CHAR_ARRAY(reversed, "gnihtemos rehtona", 18);
  TEST_ASSERT_EQUAL_CHAR_ARRAY(str, "another something", 9);
}

void string_length_test(void) {
  TEST_ASSERT_EQUAL_INT(strlength("something"), 9);
  TEST_ASSERT_EQUAL_INT(strlength("hello"), 5);
}

void string_substring_test(void) {
  char str[] = "Hello, World";
  TEST_ASSERT_EQUAL_CHAR_ARRAY(substr(str, 0, 5), "Hello", 5);
}

void string_ends_with_test(void) {
  TEST_ASSERT_EQUAL_INT(str_ends_with("Ice Cream", "ream"), 1);
  TEST_ASSERT_EQUAL_INT(str_ends_with("Superman", "uper"), 0);
}

void string_index_test(void) {
  TEST_ASSERT_EQUAL_INT(str_index("Hello", "ell"), 1);
}

void string_includes_test(void) {
  TEST_ASSERT_EQUAL_INT(str_includes("Hello", "ell"), 1);
}

void string_char_index(void) {
  TEST_ASSERT_EQUAL_INT(char_index("Anybody?", 'o'), 4);
  TEST_ASSERT_EQUAL_INT(char_index("Anybody?", 'h'), -1);
  TEST_ASSERT_EQUAL_INT(char_index(NULL, 'o'), -1);
}

void string_equal_test(void) {
  TEST_ASSERT_EQUAL_INT(streql("yoyo", "yoyo"), 1);
  TEST_ASSERT_EQUAL_INT(streql(NULL, NULL), 0);
  TEST_ASSERT_EQUAL_INT(streql("banana", NULL), 0);
  TEST_ASSERT_EQUAL_INT(streql(NULL, "water"), 0);
}

int main(void) {
  UNITY_BEGIN();
  RUN_TEST(string_reverse_test);
  RUN_TEST(string_reverse_copy_test);
  RUN_TEST(string_length_test);
  RUN_TEST(string_substring_test);
  RUN_TEST(string_ends_with_test);
  RUN_TEST(string_index_test);
  RUN_TEST(string_includes_test);
  RUN_TEST(string_char_index);
  RUN_TEST(string_equal_test);
  return UNITY_END();
}
