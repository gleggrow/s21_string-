#include "s21_check.h"

START_TEST(test_int) {
  char s21_hoh[40] = "1234567890";
  char hoh[40] = "1234567890";
  ck_assert(s21_sprintf(s21_hoh, "%5hd", 231) == sprintf(hoh, "%5hd", 231));
  ck_assert_str_eq(s21_hoh, hoh);
  ck_assert(s21_sprintf(s21_hoh, "% 5hd", 231) == sprintf(hoh, "% 5hd", 231));
  ck_assert_str_eq(s21_hoh, hoh);
  ck_assert(s21_sprintf(s21_hoh, "%% %+ld", (long int)12) ==
            sprintf(hoh, "%% %+ld", (long int)12));
  ck_assert_str_eq(s21_hoh, hoh);
  ck_assert(s21_sprintf(s21_hoh, "%% %+hd", (short int)12) ==
            sprintf(hoh, "%% %+hd", (short int)12));
  ck_assert_str_eq(s21_hoh, hoh);
  ck_assert(s21_sprintf(s21_hoh, "%% %-hd", (short int)-12) ==
            sprintf(hoh, "%% %-hd", (short int)-12));
  ck_assert_str_eq(s21_hoh, hoh);
  ck_assert(s21_sprintf(s21_hoh, "%% %hhd", 0) == sprintf(hoh, "%% %hhd", 0));
  ck_assert_str_eq(s21_hoh, hoh);
}
END_TEST

START_TEST(test_string) {
  char s21_hoh[40] = "1234567890";
  char hoh[40] = "1234567890";
  char lol[5] = "jojo";
  ck_assert(s21_sprintf(s21_hoh, "\\%5s \n\"hi\"", lol) ==
            sprintf(hoh, "\\%5s \n\"hi\"", lol));
  ck_assert_str_eq(s21_hoh, hoh);
  ck_assert(s21_sprintf(s21_hoh, "\\%-5s \n\"hi\"", lol) ==
            sprintf(hoh, "\\%-5s \n\"hi\"", lol));
  ck_assert_str_eq(s21_hoh, hoh);
}
END_TEST

START_TEST(test_double) {
  char s21_hoh[40] = "1234567890";
  char hoh[40] = "1234567890";
  ck_assert(s21_sprintf(s21_hoh, "%+10.2lf", 543.12357) ==
            sprintf(hoh, "%+10.2lf", 543.12357));
  ck_assert_str_eq(s21_hoh, hoh);
  ck_assert(s21_sprintf(s21_hoh, "%-20lf", -12342.5131) ==
            sprintf(hoh, "%-20lf", -12342.5131));
  ck_assert_str_eq(s21_hoh, hoh);
  ck_assert(s21_sprintf(s21_hoh, "%% %.f", 4.12345678) ==
            sprintf(hoh, "%% %.f", 4.12345678));
  ck_assert_str_eq(s21_hoh, hoh);
  ck_assert(s21_sprintf(s21_hoh, "%% % .f", 0.12345678) ==
            sprintf(hoh, "%% % .f", 0.12345678));
  ck_assert_str_eq(s21_hoh, hoh);
  ck_assert(s21_sprintf(s21_hoh, "% .11lf", 0.12345678) ==
            sprintf(hoh, "% .11lf", 0.12345678));
  ck_assert_str_eq(s21_hoh, hoh);
}
END_TEST

START_TEST(test_char) {
  char s21_hoh[40] = "1234567890";
  char hoh[40] = "1234567890";
  ck_assert(s21_sprintf(s21_hoh, "\\%8c", 'g') == sprintf(hoh, "\\%8c", 'g'));
  ck_assert_str_eq(s21_hoh, hoh);
  ck_assert(s21_sprintf(s21_hoh, "\\%-8c", 'g') == sprintf(hoh, "\\%-8c", 'g'));
  ck_assert_str_eq(s21_hoh, hoh);
}
END_TEST

START_TEST(test_dop) {
  char s21_hoh[40] = "1234567890";
  char hoh[40] = "1234567890";
  ck_assert(s21_sprintf(s21_hoh, "%% % -i", -4) == sprintf(hoh, "%% % -i", -4));
  ck_assert_str_eq(s21_hoh, hoh);
  ck_assert(s21_sprintf(s21_hoh, "%% %u", 4) == sprintf(hoh, "%% %u", 4));
  ck_assert_str_eq(s21_hoh, hoh);
}
END_TEST

Suite *s21_sprintf_suite() {
  Suite *suite = suite_create("sprintf");
  TCase *tcase_core = tcase_create("sprintf");

  tcase_add_test(tcase_core, test_int);
  tcase_add_test(tcase_core, test_string);
  tcase_add_test(tcase_core, test_double);
  tcase_add_test(tcase_core, test_char);
  tcase_add_test(tcase_core, test_dop);
  suite_add_tcase(suite, tcase_core);

  return suite;
}