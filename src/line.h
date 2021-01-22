#ifndef __LINE_H__
#define __LINE_H__

LINE *lalloc(int used);
void lfree(LINE *lp);
void lchange(int flag);
int linsert(int n, int c);
int lnewline(void);
int ldelete(int n, int kflag);
int ldelnewline(void);
int lreplace(int plen, char *st, int f);
void kdelete(void);
int kinsert(int c);
int kremove(int n);

#endif /* __LINE_H__ */