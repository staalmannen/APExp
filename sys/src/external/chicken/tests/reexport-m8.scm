(module reexport-m8 ()
  ;; NOTE: Reexport only works properly if m7 is imported here, when
  ;; the implementing library isn't required by the user of m8.
  (import reexport-m7
          (rename scheme (reverse reverse-og))
          (rename (chicken base) (identity reverse))
          (chicken module))
  (reexport reexport-m7))
