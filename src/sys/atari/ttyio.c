/*
 * Name:	MicroEMACS
 *		Atari 520ST terminal I/O.
 * Version:	30
 * Last edit:	05-Feb-86
 * By:		rex::conroy
 *		decvax!decwrl!dec-rhea!dec-rex!conroy
 */
#include	"def.h"
#include	<osbind.h>
#include    "tty.h"

int	nrow;				/* Terminal size, rows.		*/
int	ncol;				/* Terminal size, columns.	*/

/*
 * Open. Determine the size of
 * the display by calling the assembly
 * language "getnrow" and "getncol"
 * routines.
 */
void ttopen(void)
{
	nrow = getnrow();
	if (nrow > NROW)
		nrow = NROW;
	ncol = getncol();
	if (ncol > NCOL)
		ncol = NCOL;
}
/*
 * No-op.
 */
void ttclose(void)
{
}

/*
 * Put character.
 */
void ttputc(char c)
{
	Crawio(c & 0x7F);
}

/*
 * No-op.
 */
void ttflush(void)
{
}

/*
 * Get characters.
 */
char ttgetc(void)
{
	return (Crawcin() & 0x7F);
}
