project('276 generator custom_tgt subdir')

python = find_program('python', 'python3', required: true)
args = [
    # works with python2 or python3
    '-c', 'import sys; open(sys.argv[1], "w")',
    '@OUTPUT0@',
]

subdir('include')

gen = generator(
    python,
    arguments: args + ['@OUTPUT@'],
    output: '@PLAINNAME@.t',
)

custom_target(
    'check-headers.stamp',
    command: [python, args, '@INPUT@'],
    input: gen.process(test_header),
    output: 'check-headers.stamp',
    build_by_default: true,
)
