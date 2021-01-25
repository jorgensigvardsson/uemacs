#include	"def.h"
#include    "echo.h"
#include    "spawn.h"

extern "C" {
int spawncli(int f, int n, int k)
{
	eprintf("Not in wasm");
	return (FALSE);
}
}