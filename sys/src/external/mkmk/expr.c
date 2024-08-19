/* expr.c - constant expression evaluation */
#include <u.h>
#include <libc.h>
#include <ctype.h>
#include <bio.h>
#include "mkmk.h"

enum {
	Oeq,
	One,
	Ole,
	Olt,
	Oge,
	Ogt,

	/*
	 * I think this is a GCC-ism, #if NAME will behave
	 * as though the user had typed #if defined(NAME)
	 * if NAME is not defined. I.e. the result is false
	 * rather than an error (which is my reading of the specs).
	 */
	gpp_bodge = 1
};

static int ign;
static State *state;
static char *nxtch;
static jmp_buf expjump;

#define ungetch()       nxtch--
#define getch()         *nxtch++

static int factor(int ign);
static int query(int ign);

/* Skip white space and return terminating char. */
static int
skipws(void)
{
	char c;
	
	do{
		c = getch();
	}while(isspace(c));
	return c;
}

/*
 * resets environment to eval(ign), prints an error 
 * and forces eval to return FALSE.
 */
static void
experr(char *fmt, ...)
{
	va_list args;

	fprint(2, "%s: %s:%d ", argv0, state->file, state->line);
	va_start(args, fmt);
	vfprint(2, fmt, args);
	va_end(args);

	longjmp(expjump, -1);
}

static int
defined(char *request, int ign)
{
	int i;
	char c, match, name[64];

	match = skipws();
	if(match != '(')
		ungetch();

	skipws();
	ungetch();
	for(i = 0; i < nelem(name)-1; i++){
		name[i] = getch();
		if(! isalnum(name[i]) && name[i] != '_'){
			ungetch();
			break;
		}
	}
	name[i] = 0;

	if(match == '(' && (c = skipws()) != ')')
		experr("missing brace in #if %s()\n", request);

	if(ign)
		return 0;

	if(looksym(name, state->langincdirs) == nil)
		return 0;
	return 1;

}

static int
symbol(int ign)
{
	int i;
	char *val;
	char name[128];

	for(i = 0; i < nelem(name)-1; i++){
		name[i] = getch();
		if(! isalnum(name[i]) && name[i] != '_'){
			ungetch();
			break;
		}
	}
	name[i] = 0;

	if(strcmp(name, "defined") == 0)
		return defined(name, ign);
	if(strcmp(name, "__has_builtin") == 0)			/* the delights of GCC */
		return defined(name, ign);

	if(ign)
		return 0;
	if((val = looksym(name, state->langincdirs)) == nil){
		if(gpp_bodge)
			return 0;
		experr("%s - symbol not known\n", name);
	}
	return strtol(val, nil, 0);
}

/*
 * unary : factor | unop unary
 */
static int
unary(int ign)
{
	int val, c;

	if((c = skipws()) == '+' || c == '-' || c == '~'){
		val = unary(ign);

		switch (c){
		case '+':
			return val;
		case '-':
			return -val;
		case '~':
			return ~val;
		}
	}
	ungetch();
	return factor(ign);
}

/*
 * <term> := <unary> { <expop> <unary> }
 */
static int
expop(int ign)
{
	int vl, vr, n;

	vl = unary(ign);
	switch(skipws()){
	case '*':
		if(getch() != '*'){
			ungetch();
			break;
		}

	case '^':
		vr = expop(ign);
		n = 1;
		while(vr-- > 0)
			n *= vl;
		return n;
	}
	ungetch();
	return vl;
}

/*
 * <term> := <exp> { <mulop> <exp> }
 */
static int
term(int ign)
{
	int c, vl, vr;

	vl = expop(ign);
	while((c = skipws()) == '*' || c == '/' || c == '%'){
		vr = expop(ign);

		switch (c){
		case '*':
			vl *= vr;
			break;
		case '/':
			vl /= vr;
			break;
		case '%':
			vl %= vr;
			break;
		}
	}
	ungetch();
	return vl;
}

/*
 * primary : term { addop term }
 */
static int
primary(int ign)
{
	int c, vl, vr;

	vl = term(ign);
	while((c = skipws()) == '+' || c == '-'){
		vr = term(ign);

		if(c == '+')
			vl += vr;
		else
			vl -= vr;
	}
	ungetch();
	return vl;
}

/*
 * shift : primary { shop primary }
 */
static int
shift(int ign)
{
	int vl, vr, c;

	vl = primary(ign);
	while(((c = skipws()) == '<' || c == '>') && getch() == c){
		vr = primary(ign);

		if(c == '<')
			vl <<= vr;
		else
			vl >>= vr;
	}

	if(c == '<' || c == '>')
		ungetch();
	ungetch();
	return vl;
}

/*
 * num : digit | num digit
 */
static int
num(void)
{
	int n;

	/*
	 * I cheat and don't use getch() here, strtol()'s 
	 * parsing is correct and I make too many mistakes
	 */
	n = strtol(nxtch, &nxtch, 0);
	while(*nxtch == 'u' || *nxtch == 'l' || *nxtch == 'L')
		nxtch++;

	return n;
}

/*
 * constant: num | SYMBOL | 'char'
 * Note: constant(ign) handles multi-byte constants
 */
static int
constant(int ign)
{
	int i;
	int value;
	char c;
	int v[sizeof(int)];

	c = skipws();
	if(isdigit(c)){
		ungetch();
		return num();
	}

	if(isalpha(c) || c == '_'){
		ungetch();
		return symbol(ign);
	}
	if(c != '\'')
		experr("%c unknown character constant '%s'\n", c, nxtch);

	for (i = 0; i < sizeof(int); i++){
		if((c = getch()) == '\''){
			ungetch();
			break;
		}
		if(c == '\\'){
			switch (c = getch()){
			case '0':
			case '1':
			case '2':
			case '3':
			case '4':
			case '5':
			case '6':
			case '7':
				ungetch();
				c = num();
				break;
			case 'n':
				c = 012;
				break;
			case 'r':
				c = 015;
				break;
			case 't':
				c = 011;
				break;
			case 'b':
				c = 010;
				break;
			case 'f':
				c = 014;
				break;
			}
		}
		v[i] = c;
	}
	if(i == 0 || getch() != '\'')
		experr("unterminated character constant\n");
	for (value = 0; --i >= 0;){
		value <<= 8;
		value += v[i];
	}
	return value;
}

/*
 * factor : constant | '(' query ')'
 */
static int
factor(int ign)
{
	int val;

	if(skipws() == '('){
		val = query(ign);
		if(skipws() != ')')
			experr("')' missing\n");
		return val;
	}
	ungetch();
	return constant(ign);
}

/*
 * eqrel : '=' | '==' | '!=' | '<' | '>' | '<=' | '>='
 */
static int
geteqrel(void)
{
	int c1, c2;

	c1 = skipws();
	c2 = getch();

	switch (c1){
	case '=':
		if(c2 != '=')
			ungetch();
		return Oeq;
	case '!':
		if(c2 == '=')
			return One;
		ungetch();
		ungetch();
		return -1;
	case '<':
		if(c2 == '=')
			return Ole;
		ungetch();
		return Olt;
	case '>':
		if(c2 == '=')
			return Oge;
		ungetch();
		return Ogt;
	default:
		ungetch();
		ungetch();
		return -1;
	}
}

/*
 * eqrel : shift { eqrelop shift }
 */
static int
eqrel(int ign)
{
	int vl, vr, eqrel;

	vl = shift(ign);
	while((eqrel = geteqrel()) != -1){
		vr = shift(ign);

		switch (eqrel){
		case Oeq:
			vl = (vl == vr);
			break;
		case One:
			vl = (vl != vr);
			break;

		case Ole:
			vl = (vl <= vr);
			break;
		case Olt:
			vl = (vl < vr);
			break;
		case Ogt:
			vl = (vl > vr);
			break;
		case Oge:
			vl = (vl >= vr);
			break;
		}
	}
	return vl;
}
/*
 * not : eqrel | '!' not
 */
static int
not(int ign)
{
	int val, c;

	if((c = skipws()) == '!' && getch() != '='){
		ungetch();
		val = not(ign);
		return !val;
	}

	if(c == '!')
		ungetch();
	ungetch();
	return eqrel(ign);
}

/*
 * land : not { '&&' not }
 */
static int
land(int ign)
{
	int vl, vr;

	vl = not(ign);
	while(skipws() == '&'){
		if(getch() != '&')
			ungetch();
		if(! vl)
			ign++;
		vr = not(ign);
		vl = vl && vr;
	}
	ungetch();
	return vl;
}

/*
 * lor : land { '||' land }
 */
static int
lor(int ign)
{
	int vl, vr;

	vl = land(ign);
	while(skipws() == '|'){
		if(getch() != '|')
			ungetch();
		if(vl)
			ign++;
		vr = land(ign);
		vl = vl || vr;
	}

	ungetch();
	return vl;
}

/*
 * query : lor | lor '?' query ':' query
 */
static int
query(int ign)
{
	int tst, rc;

	tst = lor(ign);
	if(skipws() != '?'){
		ungetch();
		return tst;
	}

	if(tst){
		rc = query(ign);
		if(skipws() != ':')
			experr("':' not found in ternary conditional\n");

		query(ign+1);
	}
	else{
		query(ign+1);
		if(skipws() != ':')
			experr("':' not found in ternary conditional\n");
		rc = query(ign);
	}

	return rc;
}

int
expr(State *s, char *buf)
{
	int rc;
	char c;

	nxtch = buf;
	state = s;
	if(setjmp(expjump) != 0)
		return 0;

	rc = query(ign);
	if((c = skipws()) == 0)
		return rc;

	fprint(2, "%s: %s:%d '%c' '%s' trailing garbage after expression\n",
		argv0, s->file, s->line, c, nxtch);
	return rc;
}
