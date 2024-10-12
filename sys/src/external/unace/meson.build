project('unace',
	'c',
	version: '2.7w'
)

add_project_arguments('-DHAVE_CONFIG_H=1', language: 'c')

if host_machine.system() == 'haiku'
	# haiku: strsep is in libbsd
	add_project_link_arguments('-lbsd', language: 'c')
endif

cc = meson.get_compiler('c')
config = configuration_data()

config.set_quoted('VERSION', meson.project_version())
config.set_quoted('PACKAGE_PREFIX', get_option('prefix'))

configure_file(output : 'config.h',
               configuration : config)

#===========================================================================

#subdir('src')

cfiles = files(
	'src/acefuncs.c',
	'src/base/all.c',
	'src/base/unused.c',
	'src/base/arcblk.c',
	'src/base/archives/ace.c',
	'src/base/archives/read.c',
	'src/base/archives/test.c',
	'src/base/bitwidth.c',
	'src/base/bufread.c',
	'src/base/comments.c',
	'src/base/convert.c',
	'src/base/cprdcpr/cprdcpr.c',
	'src/base/crc.c',
	'src/base/crypt.c',
	'src/base/dcpr/comments.c',
	'src/base/dcpr/dcpr.c',
	'src/base/dcpr/huff.c',
	'src/base/dcpr/lz77.c',
	'src/base/dcpr/pic.c',
	'src/base/dcpr/sound.c',
	'src/base/dosfuncs.c',
	'src/base/error.c',
	'src/base/errorout.c',
	'src/base/extract.c',
	'src/base/filelist.c',
	'src/base/funcs.c',
	'src/base/lfn.c',
	'src/base/memory.c',
	'src/base/msgout.c',
	'src/base/options.c',
	'src/base/pathfunc.c',
	'src/base/qsort.c',
	'src/base/state.c',
	'src/base/uninorm/unincore.c',
	'src/base/uninorm/uninorm.c',
	'src/base/volume.c',
	'src/commline.c',
	'src/convert.c',
	'src/input.c',
	'src/main.c',
	'src/messages/messages.c',
	'src/output.c',
	'src/state.c',
	)

unace1 = executable('unace1',
	cfiles,
	include_directories: ['.', 'src', 'lib'],
	#c_args: ['-DHAVE_CONFIG_H'],
	install: true)

#===========================================================================
#tests

## broken paths in meson..
#run_tests_sh = find_program('scripts/run-tests.sh', required: true)
#test('test script', run_tests_sh, workdir: meson.global_source_root())

tests = {
	'tests.ace.v1/out_of_bounds.ace': false,
	'tests.ace.v1/onefile.ace': false,
#	'tests.ace.v1/passwd.ace': false,
	'tests.ace.v1/ZGFX2.ace': false,
	'tests.ace.v1/zdir.ace': false,
	'tests.ace.v1/multivolume.ace': false,
	'tests.ace.v1/ALCHT.ACE': false,
	'tests.ace.v1/Patch.ace': false,
	'tests.ace.v1/trps.ace': false,
	'tests.ace.v2/dir2.ace': false,
	'tests.ace.v2/multivol2.ace': false,
#	'tests.ace.v2/passwd2.ace': false,
}

foreach name, should_fail: tests
	test('test',
		unace1,
		args: ['x', '-y', '../@0@'.format(name)],
		should_fail: should_fail
	)
endforeach

#test('test', unace1, args: ['x', '-y', '-p1234', '../tests.ace.v1/passwd.ace'])
test('test', unace1, args: ['x', '-y', '-p1234', '../tests.ace.v2/passwd2.ace'])
