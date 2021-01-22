#ifndef __ECHO_H__
#define __ECHO_H__

int writemsg(char *sp);
int readmsg(void);
void eerase(void);
int ereply(char* fp, char* buf, int nbuf, ...);
int eyesno(char *sp);
int ereply(char* fp, char* buf, int nbuf, ...);
int eread(char* fp, char *buf, int nbuf, int flag, ...);
void eprintf(char* fp, ...);
void eputs(char *s);
void eputc(int c);

#endif /* __ECHO_H__ */