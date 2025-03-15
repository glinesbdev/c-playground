#ifndef STRINGS_H
#define STRINGS_H

int strlength(const char *str);
void revstr(char *str);
char *revstr_copy(const char *str);
char *substr(const char *str, int start, int end);
int str_ends_with(const char *str, const char *ends);
int char_index(const char *str, const char target);
int streql(const char *str, const char *query);
int str_index(const char *str, const char *query);

#endif
