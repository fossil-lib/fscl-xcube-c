code = files('basic.c')

lib = static_library('fscl-xcube-c',
    code,
    include_directories: dir)

fscl_xcube_c_dep = declare_dependency(
    link_with: lib,
    include_directories: dir)
