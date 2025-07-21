src = [
  'allocator.c',
  'gpa.c',
  'arena.c',
]

allocators_library = static_library(
  'allocators',
  src,
  include_directories: include_directories('../include')
)

allocators_lib_shared = shared_library(
  'allocators',
  src,
  include_directories: include_directories('../include'),
  install: true,
)

allocators_dep = declare_dependency(
  link_with: allocators_library,
  include_directories: include_directories('../include'),
)
