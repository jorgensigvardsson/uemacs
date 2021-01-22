#ifndef __RANDOM_H__
#define __RANDOM_H__

int showcpos(int f, int n, int k);
int twiddle(int f, int n, int k);
int quote(int f, int n, int k);
int selfinsert(int f, int n, int k);
int openline(int f, int n, int k);
int newline(int f, int n, int k);
int deblank(int f, int n, int k);
int indent(int f, int n, int k);
int backdel(int f, int n, int k);
int killline(int f, int n, int k);
int yank(int f, int n, int k);
int forwdel(int f, int n, int k);

#endif /* __RANDOM_H__ */