#include "s21_check.h"

START_TEST(test1) {
  char a[30] = "good";
  char c = '\0';
  ck_assert(s21_strchr(a, c) == strchr(a, c));
}
END_TEST

START_TEST(test2) {
  char a[30] = "good";
  char d = 'o';
  ck_assert(s21_strchr(a, d) == strchr(a, d));
}
END_TEST

START_TEST(test3) {
  char a[30] = "good\0";
  char e = 'G';
  ck_assert(s21_strchr(a, e) == strchr(a, e));
  ck_assert(1);
}
END_TEST

START_TEST(test4) {
  char a[30] = "good";
  char f = 'z';
  ck_assert(s21_strchr(a, f) == strchr(a, f));
}
END_TEST

START_TEST(test5) {
  char b[30] = "\0";
  char c = '\0';
  ck_assert(s21_strchr(b, c) == strchr(b, c));
}
END_TEST

START_TEST(test6) {
  char b[30] = "\0";
  char d = 'o';
  ck_assert(s21_strchr(b, d) == strchr(b, d));
}
END_TEST

START_TEST(test7) {
  char b[30] = "\0";
  char e = 'G';
  ck_assert(s21_strchr(b, e) == strchr(b, e));
}
END_TEST

START_TEST(test8) {
  char b[30] = "\0";
  char f = 'z';
  ck_assert(s21_strchr(b, f) == strchr(b, f));
}
END_TEST

Suite *s21_strchr_suite() {
  Suite *suite = suite_create("strchr");
  TCase *tcase_core = tcase_create("strchr");
  tcase_add_test(tcase_core, test1);
  tcase_add_test(tcase_core, test2);
  tcase_add_test(tcase_core, test3);
  tcase_add_test(tcase_core, test4);
  tcase_add_test(tcase_core, test5);
  tcase_add_test(tcase_core, test6);
  tcase_add_test(tcase_core, test7);
  tcase_add_test(tcase_core, test8);
  suite_add_tcase(suite, tcase_core);
  return suite;
}
