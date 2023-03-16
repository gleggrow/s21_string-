#include "s21_check.h"

START_TEST(test1) {
  char a[30] = "good";
  char b[30] = "cat";
  char c[30] = "\0";
  char d[30] = "\0";
  ck_assert_str_eq(s21_strcpy(a, b), strcpy(a, b));
  ck_assert_str_eq(s21_strcpy(a, c), strcpy(a, c));
  ck_assert_str_eq(s21_strcpy(d, b), strcpy(d, b));
}
END_TEST

Suite *s21_strcpy_suite() {
  Suite *suite = suite_create("strcpy");
  TCase *tcase_core = tcase_create("strcpy");
  tcase_add_test(tcase_core, test1);
  suite_add_tcase(suite, tcase_core);
  return suite;
}
