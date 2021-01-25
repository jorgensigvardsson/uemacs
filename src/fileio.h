#ifndef __FILEIO_H__
#define __FILEIO_H__

#ifdef __cplusplus
extern "C" {
#endif

void adjustcase(char *fn);
int ffropen(char *fn);
int ffclose(void);
int ffwopen(char *fn);
int ffputline(char buf[], int nbuf);
int ffgetline(char buf[], int nbuf);

#ifdef __cplusplus
}
#endif

#endif /* __FILEIO_H__*/