#include "s21_check.h"

START_TEST(sprintf_c_check) {
  char str[5100];
  char str2[5100];
  sprintf(str, "%11c %c", 'A', 'b');
  s21_sprintf(str2, "%11c %c", 'A', 'b');
  ck_assert_str_eq(str, str2);
  sprintf(str, "%c %97c", 'n', 'j');
  s21_sprintf(str2, "%c %97c", 'n', 'j');
  ck_assert_str_eq(str, str2);
  sprintf(str, "%-c %-3c", 'j', 'z');
  s21_sprintf(str2, "%-c %-3c", 'j', 'z');
  ck_assert_str_eq(str, str2);
  sprintf(str, "%-c %-3c %c %c %c %c", 'j', 'z', 'z', 'z', 'z', 'z');
  s21_sprintf(str2, "%-c %-3c %c %c %c %c", 'j', 'z', 'z', 'z', 'z', 'z');
  ck_assert_str_eq(str, str2);
  sprintf(str, "%c", 'A');
  s21_sprintf(str2, "%c", 'A');
  ck_assert_str_eq(str, str2);
}
END_TEST

START_TEST(sprintf_s_check) {
  char str[100];
  char str2[100];
  sprintf(str, "%s", "abcde");
  s21_sprintf(str2, "%s", "abcde");
  ck_assert_str_eq(str, str2);
  sprintf(str, "%.1s", "abcde");
  s21_sprintf(str2, "%.1s", "abcde");
  ck_assert_str_eq(str, str2);
  sprintf(str, "%.20s", "abcde");
  s21_sprintf(str2, "%.20s", "abcde");
  ck_assert_str_eq(str, str2);
  sprintf(str, "%-s", "abcdefg");
  s21_sprintf(str2, "%-s", "abcdefg");
  ck_assert_str_eq(str, str2);
  sprintf(str, "%15s", "abcde");
  s21_sprintf(str2, "%15s", "abcde");
  ck_assert_str_eq(str, str2);
  sprintf(str, "%15.2s", "abcde");
  s21_sprintf(str2, "%15.2s", "abcde");
  ck_assert_str_eq(str, str2);
  sprintf(str, "%-10s", "abcde");
  s21_sprintf(str2, "%-10s", "abcde");
  ck_assert_str_eq(str, str2);
}
END_TEST

START_TEST(sprintf_u_check) {
  char str[100];
  char str2[100];
  sprintf(str, "%hu", (unsigned short)4);
  s21_sprintf(str2, "%hu", (unsigned short)4);
  ck_assert_str_eq(str, str2);
  sprintf(str, "%2u", (unsigned int)4);
  s21_sprintf(str2, "%2u", 4);
  ck_assert_str_eq(str, str2);
  sprintf(str, "%-u", (unsigned int)6);
  s21_sprintf(str2, "%-u", 6);
  ck_assert_str_eq(str, str2);
}
END_TEST

START_TEST(sprintf_d_check) {
  char str[100];
  char str2[100];
  sprintf(str, "%d", 0);
  s21_sprintf(str2, "%d", 0);
  ck_assert_str_eq(str, str2);
  sprintf(str, "%d", 4);
  s21_sprintf(str2, "%d", 4);
  ck_assert_str_eq(str, str2);
  sprintf(str, "%d", -4);
  s21_sprintf(str2, "%d", -4);
  ck_assert_str_eq(str, str2);
  sprintf(str, "%d%%\n", 4000000);
  s21_sprintf(str2, "%d%%\n", 4000000);
  ck_assert_str_eq(str, str2);
  sprintf(str, "%-d%%\n", 4000000);
  s21_sprintf(str2, "%-d%%\n", 4000000);
  ck_assert_str_eq(str, str2);
  sprintf(str, "%-.2d", 4000000);
  s21_sprintf(str2, "%-.2d", 4000000);
  ck_assert_str_eq(str, str2);
  sprintf(str, "%-2d", 4000000);
  s21_sprintf(str2, "%-2d", 4000000);
  ck_assert_str_eq(str, str2);
  sprintf(str, "%-1d", 4000000);
  s21_sprintf(str2, "%-1d", 4000000);
  ck_assert_str_eq(str, str2);
  sprintf(str, "%+-2d", 4000000);
  s21_sprintf(str2, "%+-2d", 4000000);
  ck_assert_str_eq(str, str2);
  sprintf(str, "%+-13d", 4000000);
  s21_sprintf(str2, "%+-13d", 4000000);
  ck_assert_str_eq(str, str2);
  sprintf(str, "%+-11d", -4000000);
  s21_sprintf(str2, "%+-11d", -4000000);
  ck_assert_str_eq(str, str2);
  sprintf(str, "%+5d", -4000000);
  s21_sprintf(str2, "%+5d", -4000000);
  ck_assert_str_eq(str, str2);
  sprintf(str, "%u", (unsigned int)-4000000);
  s21_sprintf(str2, "%u", -4000000);
  ck_assert_str_eq(str, str2);
  ck_assert_str_eq(str, str2);
}
END_TEST

START_TEST(sprintf_f_check) {
  char str[100];
  char str2[100];
  sprintf(str, "%.2f", 4000.1);
  s21_sprintf(str2, "%.2f", 4000.1);
  ck_assert_str_eq(str, str2);
  sprintf(str, "%.2f", -4000.1);
  s21_sprintf(str2, "%.2f", -4000.1);
  ck_assert_str_eq(str, str2);
  sprintf(str, "%f", 4000.1);
  s21_sprintf(str2, "%f", 4000.1);
  ck_assert_str_eq(str, str2);
  sprintf(str, "%f", -4000.1);
  s21_sprintf(str2, "%f", -4000.1);
  ck_assert_str_eq(str, str2);
  sprintf(str, "%2f", -4000.1);
  s21_sprintf(str2, "%2f", -4000.1);
  ck_assert_str_eq(str, str2);
  sprintf(str, "%2f", 4000.1);
  s21_sprintf(str2, "%2f", 4000.1);
  ck_assert_str_eq(str, str2);
  sprintf(str, "% 2f", 4000.1);
  s21_sprintf(str2, "% 2f", 4000.1);
  ck_assert_str_eq(str, str2);
  sprintf(str, "%- 2f", 4000.1);
  s21_sprintf(str2, "%- 2f", 4000.1);
  ck_assert_str_eq(str, str2);
  sprintf(str, "%.0f", 4000.6);
  s21_sprintf(str2, "%.0f", 4000.6);
  ck_assert_str_eq(str, str2);
  sprintf(str, "%.0f", 0.9);
  s21_sprintf(str2, "%.0f", 0.99);
  ck_assert_str_eq(str, str2);
  sprintf(str, "%0f", 4000.1);
  s21_sprintf(str2, "%0f", 4000.1);
  ck_assert_str_eq(str, str2);
  sprintf(str, "%0f", -4000.1);
  s21_sprintf(str2, "%0f", -4000.1);
  ck_assert_str_eq(str, str2);
  sprintf(str, "%+f %+f", 4000.1, 30.9);
  s21_sprintf(str2, "%+f %+f", 4000.1, 30.9);
  ck_assert_str_eq(str, str2);
  sprintf(str, "%-15f", 4000.1);
  s21_sprintf(str2, "%-15f", 4000.1);
  ck_assert_str_eq(str, str2);
  sprintf(str, "%+15f", 4000.1);
  s21_sprintf(str2, "%+15f", 4000.1);
  ck_assert_str_eq(str, str2);
  sprintf(str, "%-15f", -4000.1);
  s21_sprintf(str2, "%-15f", -4000.1);
  ck_assert_str_eq(str, str2);
  sprintf(str, "%+15f", -4000.1);
  s21_sprintf(str2, "%+15f", -4000.1);
  ck_assert_str_eq(str, str2);
  sprintf(str, "%+-15f", 4000.1);
  s21_sprintf(str2, "%+-15f", 4000.1);
  ck_assert_str_eq(str, str2);
  sprintf(str, "%+-15f", -4000.1);
  s21_sprintf(str2, "%+-15f", -4000.1);
  ck_assert_str_eq(str, str2);
  sprintf(str, "%8.2f", 4000.1);
  s21_sprintf(str2, "%8.2f", 4000.1);
  ck_assert_str_eq(str, str2);
  sprintf(str, "%8.2f", -4000.1);
  s21_sprintf(str2, "%8.2f", -4000.1);
  ck_assert_str_eq(str, str2);
  sprintf(str, "%2.8f", 4000.1);
  s21_sprintf(str2, "%2.8f", 4000.1);
  ck_assert_str_eq(str, str2);
  sprintf(str, "%2.8f", 4000.1);
  s21_sprintf(str2, "%2.8f", 4000.1);
  ck_assert_str_eq(str, str2);
  sprintf(str, "%2.8f", -4000.1);
  s21_sprintf(str2, "%2.8f", -4000.1);
  ck_assert_str_eq(str, str2);
  sprintf(str, "%8.8f", -4000.1);
  s21_sprintf(str2, "%8.8f", -4000.1);
  ck_assert_str_eq(str, str2);
  sprintf(str, "%8.8f", 4000.1);
  s21_sprintf(str2, "%8.8f", 4000.1);
  ck_assert_str_eq(str, str2);
  sprintf(str, "%-8.2f", 4000.1);
  s21_sprintf(str2, "%-8.2f", 4000.1);
  ck_assert_str_eq(str, str2);
  sprintf(str, "%-8.2f", -4000.1);
  s21_sprintf(str2, "%-8.2f", -4000.1);
  ck_assert_str_eq(str, str2);
  sprintf(str, "%-2.8f", 4000.1);
  s21_sprintf(str2, "%-2.8f", 4000.1);
  ck_assert_str_eq(str, str2);
  sprintf(str, "%-2.8f", 4000.1);
  s21_sprintf(str2, "%-2.8f", 4000.1);
  ck_assert_str_eq(str, str2);
  sprintf(str, "%-2.8f", -4000.1);
  s21_sprintf(str2, "%-2.8f", -4000.1);
  ck_assert_str_eq(str, str2);
  sprintf(str, "%-8.8f", -4000.1);
  s21_sprintf(str2, "%-8.8f", -4000.1);
  ck_assert_str_eq(str, str2);
  sprintf(str, "%-8.8f", 4000.1);
  s21_sprintf(str2, "%-8.8f", 4000.1);
  ck_assert_str_eq(str, str2);
  sprintf(str, "%9.0f", 4000.1);
  s21_sprintf(str2, "%9.0f", 4000.1);
  ck_assert_str_eq(str, str2);
  sprintf(str, "%.1f", 5.99);
  s21_sprintf(str2, "%.1f", 5.99);
  ck_assert_str_eq(str, str2);
  sprintf(str, "%.6f", 5.99);
  s21_sprintf(str2, "%.6f", 5.99);
  ck_assert_str_eq(str, str2);
}
END_TEST

START_TEST(sprintf_i_check) {
  char str[100];
  char str2[100];
  sprintf(str, "%i", 4);
  s21_sprintf(str2, "%i", 4);
  ck_assert_str_eq(str, str2);
  sprintf(str, "%10i", 4);
  s21_sprintf(str2, "%10i", 4);
  ck_assert_str_eq(str, str2);
  sprintf(str, "%+-10i", 4);
  s21_sprintf(str2, "%-+10i", 4);
  ck_assert_str_eq(str, str2);
  sprintf(str, "%-10i", 4);
  s21_sprintf(str2, "%-10i", 4);
  ck_assert_str_eq(str, str2);
}
END_TEST

START_TEST(sprintf_lhidu_check) {
  char str[100];
  char str2[100];
  long int s = 4;
  sprintf(str, "%ld", s);
  s21_sprintf(str2, "%ld", s);
  ck_assert_str_eq(str, str2);
  long unsigned f = 10;
  sprintf(str, "%lu", f);
  s21_sprintf(str2, "%lu", f);
  ck_assert_str_eq(str, str2);
  sprintf(str, "%hd", (short int)4);
  s21_sprintf(str2, "%hd", 4);
  ck_assert_str_eq(str, str2);
  sprintf(str, "%hd", (short int)4);
  s21_sprintf(str2, "%hd", 4);
  ck_assert_str_eq(str, str2);
}
END_TEST

Suite *s21_sprintf_suite2() {
  Suite *s;
  TCase *tc_core;

  s = suite_create("S21 sprint");
  tc_core = tcase_create("Core");

  tcase_add_test(tc_core, sprintf_c_check);
  tcase_add_test(tc_core, sprintf_s_check);
  tcase_add_test(tc_core, sprintf_u_check);
  tcase_add_test(tc_core, sprintf_d_check);
  tcase_add_test(tc_core, sprintf_f_check);
  tcase_add_test(tc_core, sprintf_i_check);
  tcase_add_test(tc_core, sprintf_lhidu_check);

  suite_add_tcase(s, tc_core);

  return s;
}