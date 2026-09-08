project('foo', 'c')

if meson.is_cross_build()
    error('MESON_SKIP_TEST Test does not make sense for cross builds')
endif

dep_zlib = dependency('zlib', required: false)
if not dep_zlib.found()
    error('MESON_SKIP_TEST Test requires zlib')
endif
dependency('zlib', native: true, required: false)
dependency('zlib', native: false)

# `native: true` should not make a difference when doing a native build.
meson.override_dependency('dingbat', declare_dependency())
dependency('dingbat')
# different than meson: native: true does make a difference when doing a native
# build.
dingbat_native = dependency('dingbat', native: true, required: false)
assert(not dingbat_native.found())
dependency('dingbat', native: false)
