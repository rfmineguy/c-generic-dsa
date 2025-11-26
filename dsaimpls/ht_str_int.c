#define type_key_type const char*
#define type_key_name str
#define type_value_type int
#define type_value_name int
#define ALLOW_DIRECT_INCLUDE
#include <string.h>
#include <stdio.h>

int ht_str_int_hash(void* key, int len) {
  const char* s = *(const char**)key;
  int hash = 0;
  for (int i = 0; i < strlen(s); i++) {
    char c = *(char*)(s + i);
    hash += c * 3 * i;
  }
  return hash < 0 ? -hash : hash;
}
int ht_str_int_ext_keycmp(const char* key1, const char* key2) {
  return strcmp(key1, key2);
}
#include "../dsalib/hashtable.c"
