#include "s21_check.h"

START_TEST(test1) {
  char a[30] = "good";
  char b[30] = "cat";
  char c[30] = "\0";
  char d[30] = "\0";
  ck_assert_str_eq(s21_strncpy(a, b, 2), strncpy(a, b, 2));
  ck_assert_str_eq(s21_strncpy(a, c, 2), strncpy(a, c, 2));
  ck_assert_str_eq(s21_strncpy(d, b, 2), strncpy(d, b, 2));
}
END_TEST

Suite *s21_strncpy_suite() {
  Suite *suite = suite_create("strncpy");
  TCase *tcase_core = tcase_create("strncpy");
  tcase_add_test(tcase_core, test1);
  suite_add_tcase(suite, tcase_core);
  return suite;
}
