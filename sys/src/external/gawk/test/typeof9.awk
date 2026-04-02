func  _typeof( p ,f ) {
     f = "awk::typeof"
     return @f( p ) }

BEGIN{

     f = "awk::typeof"
     print "typeof: " @f( p )

     print "_typeof: " _typeof( p )
     }
