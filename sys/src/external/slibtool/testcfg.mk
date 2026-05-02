.PHONY: check

check:
	@echo 'make check info: TESTCFGDIR  = $(TESTCFGDIR)'                    >&2
	@echo 'make check info: TESTDATADIR = $(TESTDATADIR)'                   >&2
	@echo                                                                   >&2
	@echo 'make check info: the test configuration directory was'           >&2
	@echo '                   either not set or not accessible'             >&2
	@echo '                   at the time of ./configure.'                  >&2
	@echo                                                                   >&2
	@echo 'make check info: project-relative locations may be specified'    >&2
	@echo '                   by setting the mb_testcfgdir, and optionally' >&2
	@echo '                   also the mb_testdatadir variables'            >&2
	@echo '                   in the top-level config.project file.'        >&2
	@echo                                                                   >&2
	@echo 'make check info: the corresponding absolute locations may be '   >&2
	@echo '                   specified by setting the TESTCFGDIR and'      >&2
	@echo '                   TESTDATADIR shell environment variables'      >&2
	@echo '                   prior to the invocation of ./configure.'      >&2
	@echo                                                                   >&2
	@echo 'make check info: finally, the above absolute locations may'      >&2
	@echo '                   likewise be specified at the time of'         >&2
	@echo '                   build configuration via the --testcfgdir'     >&2
	@echo '                   and --testdatadir ./configure switches.'      >&2
