#ifndef DSA_H
#define DSA_H

#define JOIN2(a, b, sep) a##sep##b
#define join2(a, b, sep) JOIN2(a,b,sep)

#define JOIN3(a, b, c, sep) a##sep##b##sep##c
#define join3(a, b, c, sep) JOIN3(a,b,c,sep)

#define JOIN4(a, b, c, d, sep) a##sep##b##sep##c##sep##d
#define join4(a, b, c, d, sep) JOIN4(a,b,c,d,sep)

#define func_paste3(a, b, c) a##_##b##_##c
#define func_expand3(a, b, c) func_paste3(a, b, c)

#define func_paste4(a, b, c, d) a##_##b##_##c##_##d
#define func_expand4(a, b, c, d) func_paste4(a, b, c, d)

#define var(namespace, name) join2(namespace, name, _)

#endif
