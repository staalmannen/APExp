/* for the vax*/

typedef struct Label	Label;

/* this must have a sp */
struct Label
{
	unsigned long	pc;
	unsigned long	sp;
	unsigned long	fp;
	unsigned long	ap;
	unsigned long	r[6];	/* registers 6-11, r6 == r[0] */
};

extern "C" {	/* like setjmp and longjmp */
	int	setlabel(Label *);
	void	gotolabel(long, Label *);	/* doesn't return */
	Label	upframe(Label);
	unsigned long	*argbase(Label);
	Label	movelabel(Label, unsigned long newsp);
	unsigned long	*stackbase(Label);
	void	printlabel(Label);
}
