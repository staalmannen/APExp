project('test customtarget')

# different than meson: custom_target command needs absolute path

generator = find_program('generate.py')

ct1 = custom_target(
    command: [generator, '@OUTPUT@'],
    output: 'a.py',
)
ct2 = custom_target(
    command: [generator, '@OUTPUT@'],
    output: ['b.py', 'c.py'],
)

test('using_custom_target', ct1)
# different than meson: custom_target index doesn't add dependency
test('using_custom_target_index', ct2[0], depends: ct2)
test('using_custom_target_index_1', ct2[1], should_fail: true, depends: ct2)
