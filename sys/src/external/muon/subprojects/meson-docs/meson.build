project('meson')

python = import('python').find_installation('python3', modules: ['yaml'])

genrefman = [python, meson.project_source_root() / 'docs/genrefman.py']

meson_reference_3 = custom_target(
    'meson_reference.3',
    output: 'meson-reference.3',
    command: [
        genrefman,
        '-q',
        '-l', 'fastyaml',
        '-g', 'man',
        '-o', '@OUTPUT@',
        '--no-modules',
    ],
    install: true,
    install_dir: get_option('mandir') / 'man3',
)

signatures = custom_target(
    'signatures.txt',
    output: 'signatures.txt',
    command: [
        genrefman,
        '-q',
        '-l', 'fastyaml',
        '-g', 'types',
        '-o', '@OUTPUT@',
        '--no-modules',
    ],
)

meson_docs_h = custom_target(
    output: 'meson_docs.h',
    command: [
        genrefman,
        '-q',
        '-l', 'fastyaml',
        '-g', 'c',
        '-o', '@OUTPUT@',
        '--no-modules',
    ],
)
