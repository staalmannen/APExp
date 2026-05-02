%option debug nodefault noinput nounput noyywrap never-interactive
%x SC_CONF_TEST
%%
a { BEGIN SC_CONF_TEST; }
