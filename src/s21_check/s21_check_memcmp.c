#include "s21_check.h"

START_TEST(test1) {
  char src[] = "верониканиколаевна";
  char dest[] = "123456789105645";
  ck_assert(memcmp(dest, src, 7) == s21_memcmp(dest, src, 7));
}
END_TEST

START_TEST(test2) {
  char src[] = "верониканиколаевна";
  char dest[] = "123456789105645";
  ck_assert(memcmp(src, dest, 7) == s21_memcmp(src, dest, 7));
}
END_TEST

START_TEST(test3) {
  char src[] = "123456789105645";
  char dest[] = "123456789105645";
  ck_assert(memcmp(src, dest, 7) == s21_memcmp(src, dest, 7));
}
END_TEST

Suite *s21_memcmp_suite() {
  Suite *suite = suite_create("memcmp");
  TCase *tcase_core = tcase_create("memcmp");

  tcase_add_test(tcase_core, test1);
  tcase_add_test(tcase_core, test2);
  tcase_add_test(tcase_core, test3);
  suite_add_tcase(suite, tcase_core);

  return suite;
}
