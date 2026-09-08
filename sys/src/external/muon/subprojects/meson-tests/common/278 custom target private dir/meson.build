project('277 custom target private dir')

python = find_program('python', 'python3', required: true)

custom_target(
    'check-private-dir',
    command: [
        # works with python2 or python3
        python,
        '-c', 'import os, sys; os.chdir(sys.argv[1]); open(sys.argv[2], "w")',
        '@PRIVATE_DIR@',
        '@OUTPUT@',
    ],
    output: 'check-private-dir',
    build_by_default: true,
)
