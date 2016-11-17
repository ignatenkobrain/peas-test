to_copy = ['example.plugin', 'example.py']
foreach f : to_copy
    configure_file(
        input : f,
        output : f,
        configuration : configuration_data(),
        install : true,
        install_dir : plugin_path)
endforeach
