project('TP2', 'cpp')

incdir = include_directories('include')
executable('main', 'src/main.cpp', include_directories : incdir)

testslist = ['tests/test-main.cpp']
t = executable('test_all', sources: testslist, include_directories: incdir)
test('All', t)