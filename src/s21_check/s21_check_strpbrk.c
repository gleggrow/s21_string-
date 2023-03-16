#include "s21_check.h"

START_TEST(test1) {
  ck_assert(strpbrk("this is a test", "absj") ==
            s21_strpbrk("this is a test", "absj"));
}
END_TEST

START_TEST(test2) {
  ck_assert(strpbrk("this is a test", "kl") ==
            s21_strpbrk("this is a test", "kl"));
}
END_TEST

START_TEST(test3) {
  ck_assert(strpbrk("this is a test", "\0") ==
            s21_strpbrk("this is a test", "\0"));
}
END_TEST

START_TEST(test4) {
  ck_assert(strpbrk("this is a test", "this is a test") ==
            s21_strpbrk("this is a test", "this is a test"));
}
END_TEST

START_TEST(test5) {
  ck_assert(strpbrk("\0", "this is a test") ==
            s21_strpbrk("\0", "this is a test"));
}
END_TEST

Suite *s21_strpbrk_suite() {
  Suite *suite = suite_create("strpbrk");
  TCase *tcase_core = tcase_create("strpbrk");

  tcase_add_test(tcase_core, test1);
  tcase_add_test(tcase_core, test2);
  tcase_add_test(tcase_core, test3);
  tcase_add_test(tcase_core, test4);
  tcase_add_test(tcase_core, test5);
  suite_add_tcase(suite, tcase_core);

  return suite;
}
