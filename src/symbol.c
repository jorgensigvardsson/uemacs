/*
 * Name:	MicroEMACS
 *		Symbol table stuff.
 * Version:	29
 * Last edit:	05-Feb-86
 * By:		rex::conroy
 *		decvax!decwrl!dec-rhea!dec-rex!conroy
 *
 * Symbol tables, and keymap setup.
 * The terminal specific parts of building the
 * keymap has been moved to a better place.
 */
#include	"def.h"
#include    "echo.h"
#include    "basic.h"
#include    "buffer.h"
#include    "extend.h"
#include    "file.h"
#include    "main.h"
#include    "random.h"
#include    "region.h"
#include    "search.h"
#include    "window.h"
#include    "word.h"

#define	DIRLIST	0			/* Disarmed!			*/

#if	DIRLIST
/*
 * Defined by "dirlist.c".
 */
extern	int	dirlist();		/* Directory list.		*/
#endif

/*
 * Defined by "spawn.c".
 */
extern	int	spawncli();		/* Run CLI in a subjob.		*/

static int symhash(char *cp);
static void keyadd(int new, int (*funcp)(), char *name);

typedef	struct	{
	short	k_key;			/* Key to bind.			*/
	int	(*k_funcp)();		/* Function.			*/
	char	*k_name;		/* Function name string.	*/
}	KEY;

/*
 * Default key binding table. This contains
 * the function names, the symbol table name, and (possibly)
 * a key binding for the builtin functions. There are no
 * bindings for C-U or C-X. These are done with special
 * code, but should be done normally.
 */
KEY	key[] = {
	KCTRL|'@',	setmark,	"set-mark",
	KCTRL|'A',	gotobol,	"goto-bol",
	KCTRL|'B',	backchar,	"back-char",
	KCTRL|'C',	spawncli,	"spawn-cli",
	KCTRL|'D',	forwdel,	"forw-del-char",
	KCTRL|'E',	gotoeol,	"goto-eol",
	KCTRL|'F',	forwchar,	"forw-char",
	KCTRL|'G',	ctrlg,		"abort",
	KCTRL|'H',	backdel,	"back-del-char",
	KCTRL|'I',	selfinsert,	"ins-self",
	KCTRL|'J',	indent,		"ins-nl-and-indent",
	KCTRL|'K',	killline,	"kill-line",
	KCTRL|'L',	refresh,	"refresh",
	KCTRL|'M',	newline,	"ins-nl",
	KCTRL|'N',	forwline,	"forw-line",
	KCTRL|'O',	openline,	"ins-nl-and-backup",
	KCTRL|'P',	backline,	"back-line",
	KCTRL|'Q',	quote,		"quote",
	KCTRL|'R',	backisearch,	"back-i-search",
	KCTRL|'S',	forwisearch,	"forw-i-search",
	KCTRL|'T',	twiddle,	"twiddle",
	KCTRL|'V',	forwpage,	"forw-page",
	KCTRL|'W',	killregion,	"kill-region",
	KCTRL|'Y',	yank,		"yank",
	KCTRL|'Z',	jeffexit,	"jeff-exit",
	KCTLX|KCTRL|'B',listbuffers,	"display-buffers",
	KCTLX|KCTRL|'C',quit,		"quit",
#if	DIRLIST
	KCTLX|KCTRL|'D',dirlist,	"display-directory",
#endif
	KCTLX|KCTRL|'F',filename,	"set-file-name",
	KCTLX|KCTRL|'L',lowerregion,	"lower-region",
	KCTLX|KCTRL|'N',mvdnwind,	"down-window",
	KCTLX|KCTRL|'O',deblank,	"del-blank-lines",
	KCTLX|KCTRL|'P',mvupwind,	"up-window",
	KCTLX|KCTRL|'R',fileread,	"file-read",
	KCTLX|KCTRL|'S',filesave,	"file-save",
	KCTLX|KCTRL|'U',upperregion,	"upper-region",
	KCTLX|KCTRL|'V',filevisit,	"file-visit",
	KCTLX|KCTRL|'W',filewrite,	"file-write",
	KCTLX|KCTRL|'X',swapmark,	"swap-dot-and-mark",
	KCTLX|KCTRL|'Z',shrinkwind,	"shrink-window",
	KCTLX|'=',	showcpos,	"display-position",
	KCTLX|'(',	ctlxlp,		"start-macro",
	KCTLX|')',	ctlxrp,		"end-macro",
	KCTLX|'1',	onlywind,	"only-window",
	KCTLX|'2',	splitwind,	"split-window",
	KCTLX|'B',	usebuffer,	"use-buffer",
	KCTLX|'E',	ctlxe,		"execute-macro",
	KCTLX|'G',	gotoline,	"goto-line",
	KCTLX|'K',	killbuffer,	"kill-buffer",
	KCTLX|'N',	nextwind,	"forw-window",
	KCTLX|'P',	prevwind,	"back-window",
	KCTLX|'Z',	enlargewind,	"enlarge-window",
	KMETA|KCTRL|'H',delbword,	"back-del-word",
	KMETA|KCTRL|'R',readmsg,	"display-message",
	KMETA|KCTRL|'V',showversion,	"display-version",
	KMETA|'!',	reposition,	"reposition-window",
	KMETA|'>',	gotoeob,	"goto-eob",
	KMETA|'<',	gotobob,	"goto-bob",
	KMETA|'%',	queryrepl,	"query-replace",
	KMETA|'B',	backword,	"back-word",
	KMETA|'C',	capword,	"cap-word",
	KMETA|'D',	delfword,	"forw-del-word",
	KMETA|'F',	forwword,	"forw-word",
	KMETA|'L',	lowerword,	"lower-word",
	KMETA|'R',	backsearch,	"back-search",
	KMETA|'S',	forwsearch,	"forw-search",
	KMETA|'U',	upperword,	"upper-word",
	KMETA|'V',	backpage,	"back-page",
	KMETA|'W',	copyregion,	"copy-region",
	KMETA|'X',	extend,		"extended-command",
	-1,		searchagain,	"search-again",
	-1,		help,		"help",
	-1,		wallchart,	"display-bindings",
	-1,		bindtokey,	"bind-to-key"
};

#define	NKEY	(sizeof(key) / sizeof(key[0]))

/*
 * Symbol table lookup.
 * Return a pointer to the SYMBOL node, or NULL if
 * the symbol is not found.
 */
SYMBOL	*
symlookup(char *cp)
{
	register SYMBOL	*sp;

	sp = symbol[symhash(cp)];
	while (sp != NULL) {
		if (strcmp(cp, sp->s_name) == 0)
			return (sp);
		sp = sp->s_symp;
	}
	return (NULL);
}

/*
 * Take a string, and compute the symbol table
 * bucket number. This is done by adding all of the characters
 * together, and taking the sum mod NSHASH. The string probably
 * should not contain any GR characters; if it does the "*cp"
 * may get a nagative number on some machines, and the "%"
 * will return a negative number!
 */
static int symhash(char *cp)
{
	register int	c;
	register int	n;

	n = 0;
	while ((c = *cp++) != 0)
		n += c;
	return (n % NSHASH);
}

/*
 * Build initial keymap. The funny keys
 * (commands, odd control characters) are mapped using
 * a big table and calls to "keyadd". The printing characters
 * are done with some do-it-yourself handwaving. The terminal
 * specific keymap initialization code is called at the
 * very end to finish up. All errors are fatal.
 */
void keymapinit(void)
{
	register SYMBOL	*sp;
	register KEY	*kp;
	register int	i;
	register int	hash;

	for (i=0; i<NKEYS; ++i)
		binding[i] = NULL;
	for (kp = &key[0]; kp < &key[NKEY]; ++kp)
		keyadd(kp->k_key, kp->k_funcp, kp->k_name);
	keydup(KCTLX|KCTRL|'G',	"abort");
	keydup(KMETA|KCTRL|'G',	"abort");
	keydup(0x7F,		"back-del-char");
	keydup(KCTLX|'R',	"back-i-search");
	keydup(KCTLX|'S',	"forw-i-search");
	keydup(KMETA|'.',	"set-mark");
	keydup(KMETA|'Q',	"quote");
	keydup(KMETA|0x7F,	"back-del-word");
	/*
	 * Should be bound by "tab" already.
	 */
	if ((sp=symlookup("ins-self")) == NULL)
		abort();
	for (i=0x20; i<0x7F; ++i) {
		if (binding[i] != NULL)
			abort();
		binding[i] = sp;
		++sp->s_nkey;
	}
	ttykeymapinit();
}

/*
 * Create a new builtin function "name"
 * with function "funcp". If the "new" is a real
 * key, bind it as a side effect. All errors
 * are fatal.
 */
static void keyadd(int new, int (*funcp)(), char *name)
{
	register SYMBOL	*sp;
	register int	hash;

	if ((sp=(SYMBOL *)malloc(sizeof(SYMBOL))) == NULL)
		abort();
	hash = symhash(name);
	sp->s_symp = symbol[hash];
	symbol[hash] = sp;
	sp->s_nkey = 0;
	sp->s_name = name;
	sp->s_funcp = funcp;
	if (new >= 0) {				/* Bind this key.	*/
		if (binding[new] != NULL)
			abort();
		binding[new] = sp;
		++sp->s_nkey;
	}
}

/*
 * Bind key "new" to the existing
 * routine "name". If the name cannot be found,
 * or the key is already bound, abort.
 */
void keydup(int new, char *name)
{
	register SYMBOL	*sp;

	if (binding[new]!=NULL || (sp=symlookup(name))==NULL)
		abort();
	binding[new] = sp;
	++sp->s_nkey;
}
