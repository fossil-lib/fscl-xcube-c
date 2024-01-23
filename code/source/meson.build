code = files(
    'basic.c', 'button.c', 'checkbox.c',
    'label.c', 'radiobox.c', 'textbox.c',
    'panel.c', 'event.c')

lib = static_library('fscl-xcube-c',
    code,
    include_directories: dir)

fscl_xcube_c_dep = declare_dependency(
    link_with: lib,
    include_directories: dir)
