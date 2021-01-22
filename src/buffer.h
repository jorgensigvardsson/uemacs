#ifndef __BUFFER_H__
#define __BUFFER_H__

int usebuffer(int f, int n, int k);
int killbuffer(int f, int n, int k);
int listbuffers(int f, int n, int k);
int popblist(void);
int addline(char *text);
int anycb(void);
BUFFER *bfind(char *bname, int cflag);
BUFFER *bcreate(char *bname);
int bclear(BUFFER *bp);

#endif /* __BUFFER_H__ */