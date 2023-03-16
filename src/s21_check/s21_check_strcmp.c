#include "s21_check.h"

START_TEST(test1) {
  char a[30] = "good";
  char b[30] = "good";
  char c[30] = "bad";
  char d[30] = "goodbad";
  char e[30] = "\0";
  ck_assert(s21_strcmp(a, b) == strcmp(a, b));
  ck_assert((s21_strcmp(a, c) / s21_strcmp(a, c)) ==
            (strcmp(a, c) / strcmp(a, c)));
  ck_assert((s21_strcmp(a, d) / s21_strcmp(a, d)) ==
            (strcmp(a, d)) / strcmp(a, d));
  ck_assert((s21_strcmp(a, e) / s21_strcmp(a, e)) ==
            (strcmp(a, e)) / strcmp(a, e));
  ck_assert((s21_strcmp(e, b) / s21_strcmp(e, b)) ==
            (strcmp(e, b) / strcmp(e, b)));
}
END_TEST

Suite *s21_strcmp_suite() {
  Suite *suite = suite_create("strcmp");
  TCase *tcase_core = tcase_create("strcmp");
  tcase_add_test(tcase_core, test1);
  suite_add_tcase(suite, tcase_core);
  return suite;
}
