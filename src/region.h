#ifndef __REGION_H__
#define __REGION_H__

#ifdef __cplusplus
extern "C" {
#endif

int killregion(int f, int n, int k);
int copyregion(int f, int n, int k);
int lowerregion(int f, int n, int k);
int upperregion(int f, int n, int k);

#ifdef __cplusplus
}
#endif

#endif /* __REGION_H__ */