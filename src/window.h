#ifndef __WINDOW_H__
#define __WINDOW_H__

int reposition(int f, int n, int k);
int refresh(int f, int n, int k);
int nextwind(int f, int n, int k);
int prevwind(int f, int n, int k);
int mvdnwind(int f, int n, int k);
int mvupwind(int f, int n, int k);
int onlywind(int f, int n, int k);
int splitwind(int f, int n, int k);
int enlargewind(int f, int n, int k);
int shrinkwind(int f, int n, int k);
WINDOW *wpopup(void);


#endif /* __WINDOW_H__ */