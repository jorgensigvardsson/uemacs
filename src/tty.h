#ifndef __TTY_H__
#define __TTY_H__

void ttinit(void);
void tttidy(void);
void ttopen(void);
void ttclose(void);
void ttflush(void);
void ttputc(char c);
char ttgetc(void);
void ttmove(int row, int col);
void ttcolor(int color);
void ttnowindow(void);
void tteeop(void);
void tteeol(void);
void ttbeep(void);
void asciiparm(int n);
void ttinsl(int row, int bot, int nchunk);
void ttdell(int row, int bot, int nchunk);
void ttwindow(int top, int bot);
void ttresize();
void ttykeymapinit(void);

#endif /* __TTY_H__ */