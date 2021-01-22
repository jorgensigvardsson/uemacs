#ifndef __FILE_H__
#define __FILE_H__

int fileread(int f, int n, int k);
int filevisit(int f, int n, int k);
int readin(char fname[]);
void makename(char bname[], char fname[]);
int filewrite(int f, int n, int k);
int filesave(int f, int n, int k);
int filename(int f, int n, int k);

#endif /* __FILE_H__ */