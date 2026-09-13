#
# This Makefile is to generate ASCII text, HTML, and PostScript versions
# of the SGML source of the TkDesk User's Guide.  You will need the 
# LinuxDoc-SGML tools to run this yourself (linuxdoc*.rpm, or something
# similar).
#

OUTS = guide.txt guide.html guide.ps

all: $(OUTS)

guide.txt: guide.sgml
	sgml2txt -f guide.sgml

guide.html: guide.sgml
	sgml2html guide.sgml

guide.ps: guide.sgml
	sgml2latex --output=ps --papersize=a4 guide.sgml

clean:
	rm -f $(OUTS)
