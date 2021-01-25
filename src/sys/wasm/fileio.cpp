#include	"def.h"
#include    "echo.h"
#include    "fileio.h"

extern "C" {
/*
 * Open a file for reading.
 */
int ffropen(char *fn)
{
    /* TODO: Implement me */
    return FIOFNF;
}

/*
 * Open a file for writing.
 * Return TRUE if all is well, and
 * FALSE on error (cannot create).
 */
int ffwopen(char *fn)
{
    /* TODO: Implement me */
    return FIOERR;
}

/*
 * Close a file.
 * Should look at the status.
 */
int ffclose(void)
{
    /* TODO: Implement me */
	return (FIOSUC);
}

/*
 * Write a line to the already
 * opened file. The "buf" points to the
 * buffer, and the "nbuf" is its length, less
 * the free newline. Return the status.
 * Check only at the newline.
 */
int ffputline(char buf[], int nbuf)
{
    /* TODO: Implement me */
	return FIOERR;
}

/*
 * Read a line from a file, and store the bytes
 * in the supplied buffer. Stop on end of file or end of
 * line. Don't get upset by files that don't have an end of
 * line on the last line; this seem to be common on CP/M-86 and
 * MS-DOS (the suspected culprit is VAX/VMS kermit, but this
 * has not been confirmed. If this is sufficiently researched
 * it may be possible to pull this kludge). Delete any CR
 * followed by an LF. This is mainly for runoff documents,
 * both on VMS and on Ultrix (they get copied over from
 * VMS systems with DECnet).
 */
int ffgetline(char buf[], int nbuf)
{
    /* TODO: Implement me */
    return FIOERR; 
}

/*
 * Rename the file "fname" into a backup
 * copy. On Unix the backup has the same name as the
 * original file, with a "~" on the end; this seems to
 * be newest of the new-speak. The error handling is
 * all in "file.c". The "unlink" is perhaps not the
 * right thing here; I don't care that much as
 * I don't enable backups myself.
 */
int fbackupfile(char *fname)
{
    /* TODO: Implement me */
	return (FALSE);
}

/*
 * The string "fn" is a file name.
 * Perform any required case adjustments. All sustems
 * we deal with so far have case insensitive file systems.
 * We zap everything to lower case. The problem we are trying
 * to solve is getting 2 buffers holding the same file if
 * you visit one of them with the "caps lock" key down.
 * On UNIX file names are dual case, so we leave
 * everything alone.
 */
void adjustcase(char *fn)
{
#if	0
	register int	c;

	while ((c = *fn) != 0) {
		if (c>='A' && c<='Z')
			*fn = c + 'a' - 'A';
		++fn;
	}
#endif
}
}