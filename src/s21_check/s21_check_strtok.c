#include "s21_check.h"

START_TEST(test1) {
  char str[24] = "test1/test2/test3/test4";
  char s21_str[24] = "test1/test2/test3/test4";
  char sep[10] = "/";
  char *istr, *s21_istr;
  istr = strtok(str, sep);
  s21_istr = s21_strtok(s21_str, sep);
  if (istr) {
    ck_assert_str_eq(istr, s21_istr);
  } else {
    ck_assert(s21_istr == s21_NULL);
  }
  while (istr != NULL && s21_istr != NULL) {
    istr = strtok(NULL, sep);
    s21_istr = s21_strtok(NULL, sep);
    if (istr) {
      ck_assert_str_eq(istr, s21_istr);
    } else {
      ck_assert(s21_istr == s21_NULL);
    }
  }
  if (str) {
    ck_assert_str_eq(str, s21_str);
  } else {
    ck_assert(s21_str == s21_NULL);
  }
}
END_TEST

START_TEST(test2) {
  char str[24] = "batest1/test2/test3";
  char s21_str[24] = "batest1/test2/test3";
  char sep[10] = "/ab";
  char *istr, *s21_istr;
  istr = strtok(str, sep);
  s21_istr = s21_strtok(s21_str, sep);
  if (istr) {
    ck_assert_str_eq(istr, s21_istr);
  } else {
    ck_assert(s21_istr == s21_NULL);
  }
  while (istr != NULL && s21_istr != NULL) {
    istr = strtok(NULL, sep);
    s21_istr = s21_strtok(NULL, sep);
    if (istr) {
      ck_assert_str_eq(istr, s21_istr);
    } else {
      ck_assert(s21_istr == s21_NULL);
    }
  }
  if (str) {
    ck_assert_str_eq(str, s21_str);
  } else {
    ck_assert(s21_str == s21_NULL);
  }
}
END_TEST

START_TEST(test3) {
  char str[24] = "test1abtest2/test3/test";
  char s21_str[24] = "test1abtest2/test3/test";
  char sep[10] = "/ab";
  char *istr, *s21_istr;
  istr = strtok(str, sep);
  s21_istr = s21_strtok(s21_str, sep);
  if (istr) {
    ck_assert_str_eq(istr, s21_istr);
  } else {
    ck_assert(s21_istr == s21_NULL);
  }
  while (istr != NULL && s21_istr != NULL) {
    istr = strtok(NULL, sep);
    s21_istr = s21_strtok(NULL, sep);
    if (istr) {
      ck_assert_str_eq(istr, s21_istr);
    } else {
      ck_assert(s21_istr == s21_NULL);
    }
  }
  if (str) {
    ck_assert_str_eq(str, s21_str);
  } else {
    ck_assert(s21_str == s21_NULL);
  }
}
END_TEST

START_TEST(test4) {
  char str[24] = "test1";
  char s21_str[24] = "test1";
  char sep[10] = "/ab";
  char *istr, *s21_istr;
  istr = strtok(str, sep);
  s21_istr = s21_strtok(s21_str, sep);
  if (istr) {
    ck_assert_str_eq(istr, s21_istr);
  } else {
    ck_assert(s21_istr == s21_NULL);
  }
  while (istr != NULL && s21_istr != NULL) {
    istr = strtok(NULL, sep);
    s21_istr = s21_strtok(NULL, sep);
    if (istr) {
      ck_assert_str_eq(istr, s21_istr);
    } else {
      ck_assert(s21_istr == s21_NULL);
    }
  }
  if (str) {
    ck_assert_str_eq(str, s21_str);
  } else {
    ck_assert(s21_str == s21_NULL);
  }
}
END_TEST

START_TEST(test5) {
  char str[24] = "nma";
  char s21_str[24] = "nma";
  char sep[10] = "/abnm";
  char *istr, *s21_istr;
  istr = strtok(str, sep);
  s21_istr = s21_strtok(s21_str, sep);
  if (istr) {
    ck_assert_str_eq(istr, s21_istr);
  } else {
    ck_assert(s21_istr == s21_NULL);
  }
  while (istr != NULL && s21_istr != NULL) {
    istr = strtok(NULL, sep);
    s21_istr = s21_strtok(NULL, sep);
    if (istr) {
      ck_assert_str_eq(istr, s21_istr);
    } else {
      ck_assert(s21_istr == s21_NULL);
    }
  }
  if (str) {
    ck_assert_str_eq(str, s21_str);
  } else {
    ck_assert(s21_str == s21_NULL);
  }
}
END_TEST

START_TEST(test6) {
  char str[24] = "nmah";
  char s21_str[24] = "nmah";
  char sep[10] = "/abnm";
  char *istr, *s21_istr;
  istr = strtok(str, sep);
  s21_istr = s21_strtok(s21_str, sep);
  if (istr) {
    ck_assert_str_eq(istr, s21_istr);
  } else {
    ck_assert(s21_istr == s21_NULL);
  }
  while (istr != NULL && s21_istr != NULL) {
    istr = strtok(NULL, sep);
    s21_istr = s21_strtok(NULL, sep);
    if (istr) {
      ck_assert_str_eq(istr, s21_istr);
    } else {
      ck_assert(s21_istr == s21_NULL);
    }
  }
  if (str) {
    ck_assert_str_eq(str, s21_str);
  } else {
    ck_assert(s21_str == s21_NULL);
  }
}
END_TEST

START_TEST(test7) {
  char str[24] = "\0";
  char s21_str[24] = "\0";
  char sep[10] = "/abnm";
  char *istr, *s21_istr;
  istr = strtok(str, sep);
  s21_istr = s21_strtok(s21_str, sep);
  if (istr) {
    ck_assert_str_eq(istr, s21_istr);
  } else {
    ck_assert(s21_istr == s21_NULL);
  }
  while (istr != NULL && s21_istr != NULL) {
    istr = strtok(NULL, sep);
    s21_istr = s21_strtok(NULL, sep);
    if (istr) {
      ck_assert_str_eq(istr, s21_istr);
    } else {
      ck_assert(s21_istr == s21_NULL);
    }
  }
  if (str) {
    ck_assert_str_eq(str, s21_str);
  } else {
    ck_assert(s21_str == s21_NULL);
  }
}
END_TEST

START_TEST(test8) {
  char str[24] = "agaa";
  char s21_str[24] = "agaa";
  char sep[10] = "\0";
  char *istr, *s21_istr;
  istr = strtok(str, sep);
  s21_istr = s21_strtok(s21_str, sep);
  if (istr) {
    ck_assert_str_eq(istr, s21_istr);
  } else {
    ck_assert(s21_istr == s21_NULL);
  }
  while (istr != NULL && s21_istr != NULL) {
    istr = strtok(NULL, sep);
    s21_istr = s21_strtok(NULL, sep);
    if (istr) {
      ck_assert_str_eq(istr, s21_istr);
    } else {
      ck_assert(s21_istr == s21_NULL);
    }
  }
  if (str) {
    ck_assert_str_eq(str, s21_str);
  } else {
    ck_assert(s21_str == s21_NULL);
  }
}
END_TEST

START_TEST(test9) {
  char str[24] = "test1/test2/test3/b";
  char s21_str[24] = "test1/test2/test3/b";
  char sep[10] = "/ab";
  char *istr, *s21_istr;
  istr = strtok(str, sep);
  s21_istr = s21_strtok(s21_str, sep);
  if (istr) {
    ck_assert_str_eq(istr, s21_istr);
  } else {
    ck_assert(s21_istr == s21_NULL);
  }
  while (istr != NULL && s21_istr != NULL) {
    istr = strtok(NULL, sep);
    s21_istr = s21_strtok(NULL, sep);
    if (istr) {
      ck_assert_str_eq(istr, s21_istr);
    } else {
      ck_assert(s21_istr == s21_NULL);
    }
  }
  if (str) {
    ck_assert_str_eq(str, s21_str);
  } else {
    ck_assert(s21_str == s21_NULL);
  }
}
END_TEST

START_TEST(test10) {
  char str[24] = "test1/test2/test3/";
  char s21_str[24] = "test1/test2/test3/";
  char sep[10] = "/ab";
  char *istr, *s21_istr;
  istr = strtok(str, sep);
  s21_istr = s21_strtok(s21_str, sep);
  if (istr) {
    ck_assert_str_eq(istr, s21_istr);
  } else {
    ck_assert(s21_istr == s21_NULL);
  }
  while (istr != NULL && s21_istr != NULL) {
    istr = strtok(NULL, sep);
    s21_istr = s21_strtok(NULL, sep);
    if (istr) {
      ck_assert_str_eq(istr, s21_istr);
    } else {
      ck_assert(s21_istr == s21_NULL);
    }
  }
  if (str) {
    ck_assert_str_eq(str, s21_str);
  } else {
    ck_assert(s21_str == s21_NULL);
  }
}
END_TEST

Suite *s21_strtok_suite() {
  Suite *suite = suite_create("strtok");
  TCase *tcase_core = tcase_create("strtok");
  tcase_add_test(tcase_core, test1);
  tcase_add_test(tcase_core, test2);
  tcase_add_test(tcase_core, test3);
  tcase_add_test(tcase_core, test4);
  tcase_add_test(tcase_core, test5);
  tcase_add_test(tcase_core, test6);
  tcase_add_test(tcase_core, test7);
  tcase_add_test(tcase_core, test8);
  tcase_add_test(tcase_core, test9);
  tcase_add_test(tcase_core, test10);
  suite_add_tcase(suite, tcase_core);
  return suite;
}
