#include "s21_check.h"

START_TEST(test1) {
  char a[30] = "good";
  char b[30] = "cat";
  char c[30] = "\0";
  char d[30] = "\0";
  ck_assert_str_eq(s21_strncat(a, b, 2), strncat(a, b, 2));
  ck_assert_str_eq(s21_strncat(a, c, 2), strncat(a, c, 2));
  ck_assert_str_eq(s21_strncat(d, b, 2), strncat(d, b, 2));
  ck_assert_str_eq(s21_strncat(a, b, 0), strncat(a, b, 0));
  ck_assert_str_eq(s21_strncat(a, c, 0), strncat(a, c, 0));
  ck_assert_str_eq(s21_strncat(d, b, 0), strncat(d, b, 0));
}
END_TEST

Suite *s21_strncat_suite() {
  Suite *suite = suite_create("strncat");
  TCase *tcase_core = tcase_create("strncat");
  tcase_add_test(tcase_core, test1);
  suite_add_tcase(suite, tcase_core);
  return suite;
}
