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

char *substr(const char *str, int start, int end) {
  int len = strlength(str);

  if (!len || len < end || start < 0 || (end > -1 && start > end))
    return NULL;
  else if (end == -1)
    end = len;

  char *result = malloc(sizeof(char) * (end - start) + 1);

  if (!result)
    return NULL;

  int i, j;
  for (i = start, j = 0; i <= end; i++, j++)
    result[j] = str[i];

  result[++j] = '\0';

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
      break;
  }

  return result;
}

int char_index(const char *str, const char target) {
  if (!str)
    return -1;

  int index = 0;

  while (*str != target) {
    str++;
    index++;

    if (*str == '\0') {
      return -1;
    }
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
      break;

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

  int index;

  while (*str != '\0') {
    index = char_index(str, *target);

    if (index == -1)
      return -1;

    char *sub = substr(str, index, tlen);
    int res = streql(sub, target);
    free(sub);

    if (!res)
      str++;
    else
      return index;
  }

  return -1;
}
