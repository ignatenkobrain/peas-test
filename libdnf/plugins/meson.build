plugin_path = '@0@/libdnf/plugins'.format(get_option('libdir'))
install_data('example-c.plugin', 'example-python.plugin',
             install_dir : plugin_path)

shared_library('example_c',
               sources : 'example-plugin.c',
               dependencies : [libdnf, libpeas],
               install : true,
               install_dir : plugin_path)
install_data('example_python.py',
             install_dir : plugin_path)
