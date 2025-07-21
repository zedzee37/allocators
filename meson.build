project('allocators', 'c')

subdir('src')
subdir('test')

install_headers(['include/allocator.h', 'include/gpa.h', 'include/arena.h'], subdir: 'allocators')

pkg_mod = import('pkgconfig')
pkg_mod.generate(
  libraries: [allocators_lib_shared],
  version: '1.0',
  name: 'liballocators',
  filebase: 'allocators',
  description: 'a library containing allocators',
)

