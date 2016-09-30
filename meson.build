project('libdnf', 'c',
        version : '0.8.0',
        license : 'LGPL-2.1+',
        default_options : ['b_asneeded=True', 'b_lundef=True'],
        meson_version : '>=0.34.0')

gnome = import('gnome')
gobject = dependency('gobject-2.0', version : '>=2.44')
libpeas = dependency('libpeas-1.0')

subdir('libdnf')
subdir('dnf')
