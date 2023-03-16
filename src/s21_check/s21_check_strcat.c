#include "s21_check.h"

START_TEST(test1) {
  char abc[1024] = "верониканиколаевна";
  char def[1024] = "123456789105645";
  ck_assert(strcat(def, abc) == s21_strcat(def, abc));
}
END_TEST

Suite *s21_strcat_suite() {
  Suite *suite = suite_create("strcat");
  TCase *tcase_core = tcase_create("strcat");

  tcase_add_test(tcase_core, test1);
  suite_add_tcase(suite, tcase_core);

  return suite;
}
