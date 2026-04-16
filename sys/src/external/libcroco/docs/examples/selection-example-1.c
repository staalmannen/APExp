/**
 * This example looks up a node from a document with an
 * xpath expression, then reports all properties that apply
 * from a given stylesheet.
 *
 * To compile it using gcc, type
 *
 * gcc -g -Wall `croco-0.6-config --cflags`  `croco-0.6-config --libs` -o selection-example-1 selection-example-1.c
 *
 * Initial author: Stefan Seefeld.
 */

#include <libcroco/libcroco.h>
#include <libxml/tree.h>
#include <libxml/xpath.h>

void 
usage_and_exit (char *progname)
{
	fprintf (stderr, 
		 "Usage: %s <xml doc> <stylesheet> <xpath>\n", 
		 progname);
	exit(-1);
}

struct workspace
{
	xmlDoc *document;
	xmlXPathContext *xpath; 
	xmlXPathObject *result; 
	CRStyleSheet *stylesheet;
	CRCascade *cascade;
	CRSelEng *selector;
};

/** 
 *construct workspace members in order...
 * return 0 on success and -1 on error
 */
int 
init (struct workspace *ws, char **args)
{
	enum CRStatus status = CR_OK;

	ws->document = 0;
	ws->xpath = 0;
	ws->result = 0;
	ws->stylesheet = 0;
	ws->cascade = 0;
	ws->selector = 0;


	ws->document = xmlParseFile(args[0]);
	if (!ws->document)
	{
		fprintf(stderr, "could not parse the document %s", args[0]);
		return -1;
	}
	ws->xpath = xmlXPathNewContext(ws->document);
	if (!ws->xpath)
	{
		fprintf(stderr, "Error: unable to create new XPath context\n");
		return -1;
	}
	ws->result = xmlXPathEvalExpression((xmlChar *)args[2], ws->xpath);
	if (!ws->result)
	{
		fprintf(stderr, "Error: unable to evaluate xpath expression\n");
		return -1;
	}
	if (ws->result->type != XPATH_NODESET || !ws->result->nodesetval)
	{
		fprintf(stderr, "Error: xpath does not evaluate to a node set\n");
		return -1;
	}

	status = cr_om_parser_simply_parse_file((const guchar*)args[1] /*sheet*/,
						CR_ASCII /*the encoding*/,
						&ws->stylesheet);
	if (status != CR_OK || !ws->stylesheet)
	{
		fprintf(stderr, "could not parse the stylesheet %s", args[1]);
		return -1;
	}
	ws->cascade = cr_cascade_new(ws->stylesheet, 0, 0);
	ws->selector = cr_sel_eng_new();
	return 1 ;
}

/* ...and destruct in reverse order*/
void 
fini(struct workspace *ws)
{
	if (ws->selector) 
	{
		cr_sel_eng_destroy(ws->selector);
		ws->selector = NULL ;
	}
	if (ws->cascade) 
	{
		cr_cascade_destroy(ws->cascade);
		ws->cascade = NULL ;
	}

	if (ws->result) 
	{	  
		xmlXPathFreeObject(ws->result);
		ws->result = NULL ;
	}
	if (ws->xpath)
	{
		xmlXPathFreeContext(ws->xpath); 
		ws->xpath = NULL ;
	}
	if (ws->document) 
	{
		xmlFreeDoc(ws->document);
		ws->document = NULL ;
	}
	xmlCleanupParser () ;
}

void 
print_properties_real (CRPropList *proplist)
{
	CRDeclaration *decl = NULL ;	
	CRPropList *cur_pair = NULL ;
	
	for (cur_pair = proplist ; cur_pair ;
	     cur_pair= cr_prop_list_get_next (cur_pair)) {
		gchar *str = NULL ;
		decl = NULL ;

		cr_prop_list_get_decl (cur_pair, &decl) ;
		if (decl) {
			str = cr_declaration_to_string (decl, 0) ;
			if (str) {
				printf ("%s\n", str) ;
				g_free (str);
				str = NULL ;
			}
		}
	}
}

void 
print_properties (struct workspace *ws)
{
	enum CRStatus status;
	CRPropList *prop_list = NULL;
	xmlNode *node = ws->result->nodesetval->nodeTab[0];

	status = cr_sel_eng_get_matched_properties_from_cascade
		(ws->selector, ws->cascade,
		 node, &prop_list);

	if (status != CR_OK)
		fprintf(stderr, "Error retrieving properties\n");
	else
	{
		xmlChar *prop = NULL ;
		prop = xmlGetNodePath(node) ;
		if (prop) {
			printf("properties for node %s :\n", prop);
			xmlFree (prop) ;
			prop = NULL ;
		}
		print_properties_real (prop_list) ;
	}
	cr_prop_list_destroy (prop_list) ;
}

int 
main(int argc, char **argv)
{
	struct workspace ws;
	if (argc != 4) usage_and_exit(argv[0]);
	if (!init(&ws, argv + 1)) {
		fini(&ws);
		return -1 ;
	}

	if (ws.result->nodesetval->nodeNr == 0)
		printf("no matching nodes found\n");
	else
		print_properties(&ws);

	fini(&ws);
	return 0;
}
