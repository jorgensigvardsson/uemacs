#ifndef __SEARCH_H__
#define __SEARCH_H__

#ifdef __cplusplus
extern "C" {
#endif

int forwsearch(int f, int n, int k);
int backsearch(int f, int n, int k);
int searchagain(int f, int n, int k);
int forwisearch(int f, int n, int k);
int backisearch(int f, int n, int k);
int queryrepl(int f, int n, int k);

#ifdef __cplusplus
}
#endif

#endif /* __SEARCH_H__ */