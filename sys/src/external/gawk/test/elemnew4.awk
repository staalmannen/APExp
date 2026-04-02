BEGIN {

   a = "first"
   b = "second"
   c = "third"

   dump_array(array)
   print ""
   compare("Start", array, a, b)
   compare("Start", array, a, c)
   compare("Start", array, b, c)
   dump_array(array)

   print ""
   assign(array, a, "")
##  reference(array[a], a);
   reference(array[b], b);
   dump_array(array)

   print ""
   compare("Try 2", array, a, b)
   compare("Try 2", array, a, c)
   compare("Try 2", array, b, c)
   dump_array(array)
}

function compare(which, arr, ixa, ixb) {
   print which": arrayarg["ixa"] ("typeof(arr[ixa])") == arrayarg["ixb"] ("typeof(arr[ixb])")? " (arr[ixa] == arr[ixb]);

}

function reference(element, inx) {
   print "reference: arr["inx"] = '"element"' (type = "typeof(element)")"
}

function assign(arr, inx, value) {
   arr[inx] = value;
   print "assign: arr["inx"] = '"arr[inx]"' (type = "typeof(arr[inx])")"
}

function dump_array(a) {

   print ""
   print "Array dump: "
   for (ix in a) {
     print "  array["ix"] = '"a[ix]"' (type = " typeof(a[ix]) ")"
   }
}
