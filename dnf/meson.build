dnf = executable('dnf',
                 sources : ['main.c'],
                 dependencies : [libdnf, libpeas])

env = environment()
env.set('PEAS_DEBUG', '1')
env.set('DNF_IN_TREE_PLUGINS', '1')
env.set('GI_TYPELIB_PATH', libdnf_builddir)
test('exe', dnf, env : env, workdir : meson.current_source_dir())
