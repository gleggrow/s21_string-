#include "s21_string.h"

#include "s21_error.h"

int s21_strcmp(const char *str1, const char *str2) {
  s21_size_t i = 0;
  for (; str1[i] && str2[i] == str1[i]; i++) {
  }
  return str1[i] - str2[i];
}
int s21_strncmp(const char *str1, const char *str2, s21_size_t n) {
  s21_size_t i = 0;
  for (; str1[i] && str2[i] == str1[i] && n - 1; i++, n--) {
  }
  return str1[i] - str2[i];
}
char *s21_strcpy(char *dest, const char *src) {
  s21_size_t i = 0;
  for (; src[i]; i++) {
    dest[i] = src[i];
  }
  dest[i] = 0;
  return dest;
}
char *s21_strncpy(char *dest, const char *src, s21_size_t n) {
  s21_size_t i = 0;
  for (; n; i++, n--) {
    if (src[i]) {
      dest[i] = src[i];
    } else {
      dest[i] = 0;
    }
  }
  dest[i] = 0;
  return dest;
}
char *s21_strncat(char *dest, const char *src, s21_size_t n) {
  s21_size_t k = s21_strlen(dest);
  s21_size_t i = 0;
  for (; n; i++, n--) {
    dest[i + k] = src[i];
  }
  dest[i + k] = 0;
  return dest;
}
char *s21_strchr(const char *str, int c) {
  char *ret = s21_NULL;
  char *tmp = (char *)str;
  s21_size_t i = 0;
  for (; tmp[i] && tmp[i] != c; i++) {
  }
  if (tmp[i] == c) {
    ret = tmp + i;
  }
  return ret;
}
char *s21_strstr(const char *haystack, const char *needle) {
  char *ret = s21_NULL;
  s21_size_t length = s21_strlen(needle);
  s21_size_t i = 0;
  for (; haystack[i] && s21_strncmp(haystack + i, needle, length); i++) {
  }
  if (s21_strncmp(haystack + i, needle, length) == 0) {
    ret = (char *)haystack;
    if (needle[0]) ret += i;
  }
  return ret;
}
void *s21_insert(const char *src, const char *str, s21_size_t start_index) {
  char *new_str = s21_NULL;
  s21_size_t length_src = 0;
  s21_size_t length_str = 0;
  if (src != s21_NULL && str != s21_NULL) {
    length_src = s21_strlen(src);
    length_str = s21_strlen(str);
  }
  if (start_index < (length_src + 1) && (long long int)start_index >= 0) {
    new_str = malloc(sizeof(char) * (length_src + length_str + 1));
    for (s21_size_t i = 0, j = 0, k = 0; i < length_src + length_str; i++) {
      if (i == start_index && k < length_str) {
        new_str[i] = str[k];
        k++;
        start_index++;
      } else {
        new_str[i] = src[j];
        j++;
      }
    }
    new_str[length_src + length_str] = '\0';
  }
  return new_str;
}
void *s21_to_upper(const char *str) {
  char *new_str = s21_NULL;
  if (str != s21_NULL) {
    s21_size_t length_str = s21_strlen(str);
    new_str = malloc(sizeof(char) * (length_str + 1));
    for (s21_size_t i = 0; i < length_str; i++) {
      if (str[i] >= 'a' && str[i] <= 'z') {
        new_str[i] = str[i] - 'a' + 'A';
      } else {
        new_str[i] = str[i];
      }
    }
    new_str[length_str] = '\0';
  }
  return new_str;
}
void *s21_to_lower(const char *str) {
  char *new_str = s21_NULL;
  if (str != s21_NULL) {
    s21_size_t length_str = s21_strlen(str);
    new_str = malloc(sizeof(char) * (length_str + 1));
    for (s21_size_t i = 0; i < length_str; i++) {
      if (str[i] >= 'A' && str[i] <= 'Z') {
        new_str[i] = str[i] - 'A' + 'a';
      } else {
        new_str[i] = str[i];
      }
    }
    new_str[length_str] = '\0';
  }
  return new_str;
}
void *trim(const char *src, const char *trim_chars) {
  char *new_str = s21_NULL;
  if (src != s21_NULL && trim_chars != s21_NULL) {
    s21_size_t length_src = s21_strlen(src);
    s21_size_t length_trim_chars = s21_strlen(trim_chars);
    while ((new_str = malloc(sizeof(char) * (length_src + 1))) == 0)
      ;
    s21_size_t k = 0;
    for (int match = 1; src[k] && match; k++) {
      new_str[0] = src[k];
      match = 0;
      for (s21_size_t i = 0; trim_chars[i] && match == 0; i++)
        if (new_str[0] == trim_chars[i]) match = 1;
    }
    for (s21_size_t i = 0; src[i + k]; i++) new_str[i + 1] = src[i + k];
    if (k) k--;
    if (length_trim_chars) {
      new_str[length_src - k] = '\0';
      s21_size_t length_new_str = s21_strlen(new_str);
      for (int match = 1; length_new_str && match; length_new_str--) {
        match = 0;
        for (s21_size_t i = 0; trim_chars[i] && match == 0; i++)
          if (new_str[length_new_str - 1] == trim_chars[i]) match = 1;
      }
      if (length_new_str) length_new_str++;
      new_str[length_new_str] = '\0';
    }
  }
  return new_str;
}
int s21_memcmp(const void *str1, const void *str2, s21_size_t n) {
  // Сравнивает первые n байтов str1 и str2
  unsigned char *s1 = (unsigned char *)str1;
  unsigned char *s2 = (unsigned char *)str2;
  int result = 0;
  s21_size_t i;
  for (i = 0; i < n; i++) {
    result = *s1 - *s2;
    if (*s1 != *s2) break;
    s1++;
    s2++;
  }
  return result;
}
void *s21_memmove(void *dest, const void *src, s21_size_t n) {
  // Функция для копирования n символов из src в dest
  unsigned char *to = (unsigned char *)dest;
  unsigned char *from = (unsigned char *)src;
  s21_size_t i;
  if (to < from) {
    for (i = 0; i < n; i++) {
      to[i] = from[i];
    }
  } else if (to > from) {
    for (i = n; i > 0; i--) {
      to[i - 1] = from[i - 1];
    }
  }
  return dest;
}
char *s21_strcat(char *dest, const char *src) {
  // Добавляет строку, на которую указывает src, в конец строки, на которую
  // указывает dest
  s21_size_t dest_strlen = s21_strlen(dest);
  s21_size_t i;
  for (i = 0; src[i] != '\0'; i++) {
    dest[dest_strlen + i] = src[i];
    break;
  }
  dest[dest_strlen + i] = '\0';
  return dest;
}
s21_size_t s21_strlen(const char *str) {
  // Вычисляет длину строки str, не включая завершающий нулевой символ
  int result = 0;
  s21_size_t i;
  for (i = 0; str[i] != '\0'; i++) {
    result++;
  }
  return result;
}
char *s21_strpbrk(const char *str1, const char *str2) {
  // Находит первый символ в строке str1, который соответствует любому символу,
  // указанному в str2
  s21_size_t tmp = -1;
  char *fir = (char *)str1;
  char *sec = (char *)str2;
  for (s21_size_t i = 0; fir[i] && tmp == (s21_size_t)-1; i++) {
    for (s21_size_t j = 0; sec[j] && tmp == (s21_size_t)-1; j++) {
      if (fir[i] == sec[j]) tmp = i;
    }
  }
  if (tmp == (s21_size_t)-1) {
    fir = s21_NULL;
  } else {
    fir += tmp;
  }
  return fir;
}
s21_size_t s21_strspn(const char *str1, const char *str2) {
  // Вычисляет длину начального сегмента str1, который полностью состоит из
  // символов str2
  s21_size_t length = 0;
  while (*str1 && s21_strchr(str2, *str1++)) {
    length++;
  }
  return length;
}
char *s21_strerror(int errnum) {
  char *errors[ERR_LEN] = {ERRORS};
  static char res[51];
  if (errnum >= 0 && errnum < ERR_LEN) {
    s21_sprintf(res, "%s", errors[errnum]);
  } else {
    s21_sprintf(res, "%s %d", UNKNOWN_ERROR, errnum);
  }
  return res;
}
void *s21_memchr(const void *str, int c, s21_size_t n) {
  unsigned char *result = s21_NULL;
  s21_size_t i = 0;
  unsigned char *a = (unsigned char *)str;
  while (i != n) {
    if (a[i] == (unsigned char)c) {
      result = (&a[i]);
      break;
    }
    i++;
  }
  return result;
}
char *s21_strrchr(const char *str, int c) {
  char *result = s21_NULL;
  int i = s21_strlen(str);
  while (i != -1) {
    if (str[i] == c) {
      result = (char *)(&str[i]);
      break;
    }
    i--;
  }
  return result;
}
void *s21_memset(void *str, int c, s21_size_t n) {
  s21_size_t k = 0;
  char *h = (char *)str;
  while (k != n) {
    h[k] = c;
    k++;
  }
  return str;
}
void *s21_memcpy(void *dest, const void *src, s21_size_t n) {
  s21_size_t i = 0;
  if (!(!n && src == dest)) {
    while (i != n) {
      ((char *)dest)[i] = ((char *)src)[i];
      i++;
    }
  }
  return dest;
}
s21_size_t s21_strcspn(const char *str1, const char *str2) {
  s21_size_t length = 0;
  while (*str1 && s21_strchr(str2, *str1++) == 0) {
    length++;
  }
  return length;
}
char *s21_strtok(char *str, const char *delim) {
  static char *line;
  char *result = s21_NULL;
  if (str != s21_NULL) line = str;
  if (line && s21_strspn(line, delim) < s21_strlen(line)) {
    result = line + s21_strspn(line, delim);
    line = s21_strpbrk(result, delim);
    if (line && *line) {
      *line = '\0';
      line++;
    }
  }
  return result;
}