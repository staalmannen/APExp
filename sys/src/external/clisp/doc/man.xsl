<!-- CLISP man page driver -->
<xsl:stylesheet xmlns:xsl="http://www.w3.org/1999/XSL/Transform" version="1.0">
<xsl:import href="http://docbook.sourceforge.net/release/xsl/current/manpages/docbook.xsl"/>
<!-- "common.xsl" is far too HTML-specific, so we cannot include it -->
<!-- and have to repeat some settings here explicitly: -->
<xsl:param name="variablelist.term.break.after" select="1"/>
<xsl:param name="variablelist.term.separator" select="''"/>

<xsl:template match="filename[@role='clisp-cvs']">
 <xsl:apply-imports/> (file in the CLISP sources)
</xsl:template>

<!-- ==================================================================== -->

<!-- here we just convert comments into < ! - - ... - - >
  for further processing with sed(1) (see Makefile) -->
<xsl:template match="comment()">
 <xsl:text>&#60;!--</xsl:text> <!-- #\< ! - - -->
 <xsl:variable name="content">
  <xsl:call-template name="string.subst">
   <xsl:with-param name="string"><xsl:value-of select="."/></xsl:with-param>
   <xsl:with-param name="target" select="'&#10;'"/>
   <xsl:with-param name="replacement" select="'--&#62;&#10;&#60;!--'"/>
  </xsl:call-template>
 </xsl:variable>
 <xsl:value-of select="normalize-space($content)"/>
 <xsl:text>--&#62;</xsl:text> <!-- - - #\> -->
</xsl:template>

<!-- the following tries to preserve the comments
  it does not work because para|simpara|remark in list mode
  calls normalize-space() and removes the whitespace around comments
  <http://article.gmane.org/gmane.text.docbook.apps/6461> -->
<!--
<xsl:template match="comment()">
 <xsl:text>&#10;.&#92;&#34;</xsl:text> <!- - #\Newline . \ " - ->
 <xsl:variable name="content">
  <xsl:call-template name="string.subst">
   <xsl:with-param name="string"><xsl:value-of select="."/></xsl:with-param>
   <xsl:with-param name="target" select="'&#10;'"/>
   <xsl:with-param name="replacement" select="'&#10;.&#92;&#34;'"/>
  </xsl:call-template>
 </xsl:variable>
 <xsl:value-of select="normalize-space($content)"/>
 <xsl:if test="not(following-sibling::comment())">
  <xsl:text>&#10;</xsl:text></xsl:if>
</xsl:template>
-->

<!-- the following two templates make synonym options appear on
  separate lines (like we do in XHTML)
  it is not clear whether this is a good idea: ".TP" does not guarantee
  a new line, so the alternatives are:
       -h, -/-help
              Displays a help message on how to use clisp.
  and
       -h
       -/-help Displays a help message on how to use CLISP.
  it appears that the former is at least no worse than the latter,
  so we disable these templates -->
<!--
<xsl:template match="varlistentry/term|glossterm">
 <xsl:variable name="content"><xsl:apply-templates/></xsl:variable>
 <xsl:value-of select="normalize-space($content)"/>
 <xsl:text>&#10;.PD 0&#10;.TP&#10;</xsl:text>
</xsl:template>

<xsl:template
  match="varlistentry/term[position()=last()]|glossterm[position()=last()]"
  priority="2">
 <xsl:variable name="content"><xsl:apply-templates/></xsl:variable>
 <xsl:value-of select="normalize-space($content)"/>
</xsl:template>
-->

</xsl:stylesheet>
