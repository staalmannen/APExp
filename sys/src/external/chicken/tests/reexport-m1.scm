;;;; module re-exporting from core module

(module reexport-m1 ()
  (import (chicken module))
  (reexport (only srfi-4 u8vector)))
