plugins = [
    ['example_c',      'example-c.plugin',      'c',      ['example-plugin.c'],  []],
    ['example_python', 'example-python.plugin', 'python', ['example_python.py'], []],
]
foreach l : plugins
    plugin_info = l.get(1)
    install_data(plugin_info,
                 install_dir : plugin_path)

    plugin_name = l.get(0)
    plugin_lang = l.get(2)
    plugin_sources = l.get(3)
    to_copy = [plugin_info]
    if plugin_lang == 'c'
        shared_library(plugin_name,
                       sources : plugin_sources,
                       dependencies : [libdnf, libpeas],
                       install : true,
                       install_dir : plugin_path)
    elif plugin_lang == 'python'
        to_copy += plugin_sources
    else
        error('Unknown language: @0@'.format(plugin_lang))
    endif
    foreach f : to_copy
        configure_file(
            input : f,
            output : f,
            configuration : configuration_data(),
            install_dir : plugin_path)
    endforeach

    install_data(l.get(1),
                 install_dir : plugin_data_path)
endforeach
