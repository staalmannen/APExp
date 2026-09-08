sc = run_command(grabber, check: true)
subsources = sc.stdout().strip().splitlines()

se = executable('subprog', subsources)
test('subgrabtest', se)
