#include "s21_check.h"

START_TEST(test1) {
  char src[] = "верониканиколаевна";
  char dest[] = "123456789105645";
  ck_assert(memmove(dest, src, 5) == s21_memmove(dest, src, 5));
}
END_TEST

START_TEST(test2) {
  char src[] = "верониканиколаевна";
  char dest[] = "123456789105645";
  ck_assert(memmove(src, dest, 7) == s21_memmove(src, dest, 7));
}
END_TEST

START_TEST(test3) {
  char src[] = "123456789105645";
  char dest[] = "123456789105645";
  ck_assert(memmove(src, dest, 7) == s21_memmove(src, dest, 7));
}
END_TEST

Suite *s21_memmove_suite() {
  Suite *suite = suite_create("memmove");
  TCase *tcase_core = tcase_create("memmove");

  tcase_add_test(tcase_core, test1);
  tcase_add_test(tcase_core, test2);
  tcase_add_test(tcase_core, test3);
  suite_add_tcase(suite, tcase_core);

  return suite;
}
