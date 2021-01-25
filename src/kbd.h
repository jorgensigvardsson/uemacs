#ifndef __KBD_H__
#define __KBD_H__

#ifdef __cplusplus
extern "C" {
#endif

void keyname(char *cp, int k);
int getkey(void);
int getkbd(void);

#ifdef __cplusplus
}
#endif

#endif /* __KBD_H__ */