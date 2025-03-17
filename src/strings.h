#ifndef STRINGS_H
#define STRINGS_H

int strlength(const char *str);
void revstr(char *str);
char *revstr_copy(const char *str);
char *str_slice(const char *str, int start, int end);
int str_starts_with(const char *str, const char *starts);
int str_ends_with(const char *str, const char *ends);
int char_index(const char *str, const char target);
int streql(const char *str, const char *query);
int str_index(const char *str, const char *query);
char *str_trim(const char *str);
char *str_trim_start(const char *str);
char *str_trim_end(const char *str);
void str_lower(char *str);
void str_upper(char *str);
char *str_append(const char *str, const char *new);
char *str_prepend(const char *str, const char *new);
char *str_pad_start(const char *str, int amount, const char *padding);
char *str_pad_end(const char *str, int amount, const char *padding);

#endif
