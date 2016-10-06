project('libdnf', 'c',
        version : '0.8.0',
        license : 'LGPL-2.1+',
        default_options : ['b_asneeded=True', 'b_lundef=True'],
        meson_version : '>=0.35.0')

pkg_libdir = '@0@/@1@/dnf'.format(
    get_option('prefix'),
    get_option('libdir'))
pkg_datadir = '@0@/@1@/dnf'.format(
    get_option('prefix'),
    get_option('datadir'))

gnome = import('gnome')
gobject = dependency('gobject-2.0', version : '>=2.44')
libpeas = dependency('libpeas-1.0')

subdir('libdnf')
subdir('dnf')
