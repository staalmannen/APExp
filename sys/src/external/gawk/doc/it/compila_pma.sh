
#
# builds the PDF version of the pm-gawk manual,
# in the current directory
#
echo "Building the pdf version of the pm-gawk manual"
echo "in directory:"
pwd
# just in case, drop previous work files
rm -f pm-gawk.aux pm-gawk.toc pm-gawk.log
texi2pdf  pm-gawk.texi 
