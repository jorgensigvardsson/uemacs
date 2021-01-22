#ifndef __FILEIO_H__
#define __FILEIO_H__

void adjustcase(char *fn);
int ffropen(char *fn);
int ffclose(void);
int ffwopen(char *fn);
int ffputline(char buf[], int nbuf);
int ffgetline(char buf[], int nbuf);

#endif /* __FILEIO_H__*/