#ifndef __WORD_H__
#define __WORD_H__

#ifdef __cplusplus
extern "C" {
#endif

int backword(int f, int n, int k);
int forwword(int f, int n, int k);
int upperword(int f, int n, int k);
int lowerword(int f, int n, int k);
int capword(int f, int n, int k);
int delfword(int f, int n, int k);
int delbword(int f, int n, int k);

#ifdef __cplusplus
}
#endif

#endif /* __WORD_H__ */