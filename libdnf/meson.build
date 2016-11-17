plugin_path = '@0@/plugins'.format(pkg_libdir)
plugin_data_path = '@0@/plugins'.format(pkg_datadir)

srcs = files(
    'dnf-context.h', 'dnf-context.c',
    'dnf-activatable.h', 'dnf-activatable.c',
)

plugin_srcs = []
subdir('plugins/embedded')

_libdnf = shared_library('dnf', srcs, plugin_srcs,
                         c_args : [
                             '-DBUILDDIR="@0@"'.format(meson.current_build_dir()),
                             '-DSRCDIR="@0@"'.format(meson.current_source_dir()),
                             '-DPACKAGE_LIBDIR="@0@"'.format(pkg_libdir),
                             '-DPACKAGE_DATADIR="@0@"'.format(pkg_datadir),
                         ],
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
