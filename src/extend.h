#ifndef __EXTEND_H__
#define __EXTEND_H__

#ifdef __cplusplus
extern "C" {
#endif

int bindtokey(int f, int n, int k);
int help(int f, int n, int k);
int wallchart(int f, int n, int k);
int extend(int f, int n, int k);

#ifdef __cplusplus
}
#endif

#endif /* __EXTEND_H__ */