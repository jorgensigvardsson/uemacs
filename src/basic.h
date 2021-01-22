#ifndef __BASIC_H__
#define __BASIC_H__

int gotobol(int f, int n, int k);
int backchar(int f, int n, int k);
int gotoeol(int f, int n, int k);
int forwchar(int f, int n, int k);
int gotobob(int f, int n, int k);
int gotoeob(int f, int n, int k);
int forwline(int f, int n, int k);
int backline(int f, int n, int k);
int forwpage(int f, int n, int k);
int backpage(int f, int n, int k);
int setmark(int f, int n, int k);
int swapmark(int f, int n, int k);
int gotoline(int f, int n, int k);

#endif /* __BASIC_H__ */