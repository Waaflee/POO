project('TP2', 'cpp')

srclist = [
'src/Triangle.cpp',
'src/Rectangle.cpp',
'src/Circle.cpp',
'src/Generador.cpp'
]
incdir = include_directories(['include', 'lib'])
executable('main',sources: ['src/main.cpp'] + srclist, include_directories : incdir)

testslist = [
  'tests/test-main.cpp',
  'tests/test-Triangle.cpp',
  'tests/test-Rectangle.cpp',
  'tests/test-Circle.cpp',
  'tests/test-geometricEntity.cpp',
  'tests/test-Generador.cpp'
  ]
t = executable('test_all', sources: srclist + testslist, include_directories: [incdir, 'tests'])
test('Full Tests', t)
