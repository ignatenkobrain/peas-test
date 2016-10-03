srcs = [
    'dnf-context.h', 'dnf-context.c',
    'dnf-activatable.h', 'dnf-activatable.c',
]

_libdnf = shared_library('dnf',
                         sources : srcs,
                         dependencies : [gobject, libpeas],
                         install : true)

libdnf = declare_dependency(
    include_directories: [include_directories('.')],
    link_with : [_libdnf],
    dependencies : [gobject],
    version : meson.project_version())

gnome.generate_gir(_libdnf,
                   sources : srcs,
                   nsversion : '2.0',
                   namespace : 'Dnf',
                   symbol_prefix : 'dnf_',
                   identifier_prefix : 'Dnf',
                   includes : ['GObject-2.0'],
                   install : true)

subdir('plugins')
