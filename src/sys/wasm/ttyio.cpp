#include	"def.h"
#include    "tty.h"

extern "C" {
/*
 * This function gets called once, to set up
 * the terminal channel. On Ultrix is's tricky, since
 * we want flow control, but we don't want any characters
 * stolen to send signals. Use CBREAK mode, and set all
 * characters but start and stop to 0xFF.
 */
void ttopen(void)
{
    /* TODO: Implement me */
}

/*
 * This function gets called just
 * before we go back home to the shell. Put all of
 * the terminal parameters back.
 */
void ttclose(void)
{
	ttflush();
}

/*
 * Write character to the display.
 * Characters are buffered up, to make things
 * a little bit more efficient.
 */
void ttputc(char c)
{
    /* TODO: Implement me */
}

/*
 * Flush output.
 */
void ttflush(void)
{
    /* TODO: Implement me */
}

/*
 * Read character from terminal.
 * All 8 bits are returned, so that you can use
 * a multi-national terminal.
 */
char ttgetc(void)
{
    /* TODO: Implement me */
    return 'a';
}
}