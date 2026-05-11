(module reexport-m10 ()
  (import (only reexport-m9 define) (chicken module))
  (reexport (only reexport-m9 define)))
