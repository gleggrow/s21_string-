#include "s21_check.h"

START_TEST(test1) {
  char a[30] = "good boy";
  char b[30] = "\0";
  char c[30] = "boy";
  char d[30] = "od";
  char e[30] = "bad";
  char f[30] = "\0";
  ck_assert(s21_strstr(a, c) == strstr(a, c));
  ck_assert(s21_strstr(a, d) == strstr(a, d));
  ck_assert(s21_strstr(a, e) == strstr(a, e));
  ck_assert(s21_strstr(a, f) == strstr(a, f));
  ck_assert(s21_strstr(b, c) == strstr(b, c));
  ck_assert(s21_strstr(b, d) == strstr(b, d));
  ck_assert(s21_strstr(b, e) == strstr(b, e));
  ck_assert(s21_strstr(b, f) == strstr(b, f));
}
END_TEST

Suite *s21_strstr_suite(void) {
  Suite *suite = suite_create("strstr");
  TCase *tcase_core = tcase_create("strstr");
  tcase_add_test(tcase_core, test1);
  suite_add_tcase(suite, tcase_core);
  return suite;
}
