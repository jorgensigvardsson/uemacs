#ifndef __MAIN_H__
#define __MAIN_H__

#ifdef __cplusplus
extern "C" {
#endif

int execute(int c, int f, int n);
int quit(int f, int n, int k);
int ctlxlp(int f, int n, int k);
int ctlxrp(int f, int n, int k);
int ctlxe(int f, int n, int k);
int ctrlg(int f, int n, int k);
int showversion(int f, int n, int k);
int jeffexit(int f, int n, int k);

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H__ */