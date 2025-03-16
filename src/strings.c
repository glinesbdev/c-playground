#include "strings.h"
#include <stdlib.h>

int strlength(const char *str) {
  if (!str)
    return 0;

  int len = 0;

  while (str[len] != '\0')
    len++;

  return len;
}

void revstr(char *str) {
  if (!str)
    return;

  char *right = str + strlength(str) - 1;
  char tmp;

  while (right - str >= 1) {
    tmp = *str;
    *str = *right;
    *right = tmp;
    str++;
    right--;
  }
}

char *revstr_copy(const char *str) {
  if (!str)
    return NULL;

  int len = strlength(str);
  char *result = malloc(sizeof(char) + (len + 1));

  if (!result)
    return NULL;

  for (int i = 0; i < len; i++)
    result[i] = str[len - 1 - i];

  result[len] = '\0';

  return result;
}

char *str_slice(const char *str, int start, int end) {
  int strlen = strlength(str);

  if (!strlen || strlen < end || start < 0 || (end > -1 && start > end))
    return NULL;
  else if (end == -1)
    end = strlen;

  int slice_len = end - start;
  char *slice = malloc(sizeof(char) * (slice_len + 1));

  if (!slice)
    return NULL;

  int i, j;
  for (i = start, j = 0; j < slice_len; i++, j++)
    slice[j] = str[i];

  slice[slice_len] = '\0';

  return slice;
}

int str_starts_with(const char *str, const char *starts) {
  int strlen = strlength(str);
  int startlen = strlength(starts);

  if (!(strlen || startlen) || strlen < startlen)
    return 0;

  int result = 0;

  for (int i = 0; i < strlen; i++) {
    if ((result = (int)(str[i] == starts[i])) == 1)
      return result;
  }

  return result;
}

int str_ends_with(const char *str, const char *end) {
  int strlen = strlength(str);
  int endlen = strlength(end);

  if (!(strlen || endlen) || strlen < endlen)
    return 0;

  int startpos = strlen - endlen;
  int result = 0;

  int i, j;
  for (i = startpos, j = 0; i < strlen; i++, j++) {
    if ((result = (int)(str[i] == end[j])) == 1)
      return result;
  }

  return result;
}

int char_index(const char *str, const char target) {
  if (!str)
    return -1;

  int index = 0;

  while (*str != target) {
    str++;

    if (*str == '\0') {
      return -1;
    }

    index++;
  }

  return index;
}

int streql(const char *str, const char *query) {
  int strlen = strlength(str);
  int qlen = strlength(query);

  if (!(strlen || qlen) || strlen != qlen)
    return 0;

  int result = 0;

  do {
    if (!(result = (int)(*str == *query)))
      return 0;

    str++;
    query++;
  } while (*str != '\0');

  return result;
}

int str_index(const char *str, const char *target) {
  int strlen = strlength(str);
  int tlen = strlength(target);

  if (!(strlen || tlen) || strlen < tlen)
    return -1;

  int index, offset = 0;

  while (*str != '\0') {
    index = char_index(str, *target);

    if (index == -1)
      return -1;

    char *slice = str_slice(str, index, tlen);
    int equal = streql(slice, target);
    int slice_len = strlength(slice) - 1;
    free(slice);

    if (!equal) {
      offset += slice_len;
      str += slice_len;
    } else {
      return index + offset;
    }
  }

  return -1;
}

char *str_trim(const char *str) {
  if (!str)
    return NULL;

  int strlen = strlength(str);
  const char *left = str;
  const char *right = str + strlen - 1;
  int start = 0, end = 0;

  while (1) {
    if (*left == ' ') {
      left++;
      start++;
    }

    if (*right == ' ') {
      right--;
      end++;
    }

    if (*right != ' ' && *left != ' ')
      break;
  }

  char *result = str_slice(str, start, strlen - end);

  if (!result)
    return NULL;

  return result;
}

char *str_trim_start(const char *str) {
  if (!str)
    return NULL;

  const char *left = str;
  int start = 0;

  while (*left == ' ') {
    left++;
    start++;
  }

  char *result = str_slice(str, start, -1);

  if (!result)
    return NULL;

  return result;
}

char *str_trim_end(const char *str) {
  if (!str)
    return NULL;

  int strlen = strlength(str);
  const char *right = str + strlen - 1;
  int end = 0;

  while (*right == ' ') {
    right--;
    end++;
  }

  char *result = str_slice(str, 0, strlen - end);

  if (!result)
    return NULL;

  return result;
}

void str_lower(char *str) {
  if (!str)
    return;

  for (char *p = str; *p != '\0'; p++) {
    if (*p >= 'A' && *p <= 'Z') {
      *p += 32;
    }
  }
}

void str_upper(char *str) {
  if (!str)
    return;

  for (char *p = str; *p != '\0'; p++) {
    if (*p >= 'a' && *p <= 'z') {
      *p -= 32;
    }
  }
}
