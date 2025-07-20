# test_exe = executable('test_test', 'test.c', dependencies: [allocators_dep])
# test('test test', test_exe)

deps = [allocators_dep]

gpa_exe = executable('gpa_test', 'gpa_test.c', dependencies: deps)
test('gpatest', gpa_exe)

arena_exe = executable('arena_test', 'arena_test.c', dependencies: deps)
test('arenatest', arena_exe)

