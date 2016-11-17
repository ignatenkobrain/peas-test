#include "example-plugin.h"

struct _ExamplePlugin
{
    PeasExtensionBase parent_instance;
};

static void example_plugin_iface_init (DnfActivatableInterface *iface);

G_DEFINE_DYNAMIC_TYPE_EXTENDED (ExamplePlugin,
                                example_plugin,
                                PEAS_TYPE_EXTENSION_BASE,
                                0,
                                G_IMPLEMENT_INTERFACE (DNF_TYPE_ACTIVATABLE,
                                                       example_plugin_iface_init))

static void
example_plugin_init (ExamplePlugin *plugin)
{
}

static void
example_plugin_finalize (GObject *object)
{
    G_GNUC_UNUSED ExamplePlugin *plugin = (ExamplePlugin *)object;

    G_OBJECT_CLASS (example_plugin_parent_class)->finalize (object);
}

static void
example_plugin_activate (DnfActivatable *activatable)
{
    G_GNUC_UNUSED ExamplePlugin *plugin = (ExamplePlugin *)activatable;

    g_print ("[plugin_activate]: C\n");
}

static void
example_plugin_deactivate (DnfActivatable *activatable)
{
    G_GNUC_UNUSED ExamplePlugin *plugin = (ExamplePlugin *)activatable;

    g_print ("[plugin_deactivate]: C\n");
}

static void
example_plugin_run (DnfActivatable *activatable,
                    DnfContext     *ctx)
{
    G_GNUC_UNUSED ExamplePlugin *plugin = (ExamplePlugin *)activatable;

    g_print ("Worked: C!\n");
}

static void
example_plugin_class_init (ExamplePluginClass *klass)
{
    GObjectClass *object_class = G_OBJECT_CLASS (klass);

    object_class->finalize = example_plugin_finalize;
}

static void
example_plugin_iface_init (DnfActivatableInterface *iface)
{
    iface->activate = example_plugin_activate;
    iface->deactivate = example_plugin_deactivate;

    iface->run = example_plugin_run;
}

static void
example_plugin_class_finalize (ExamplePluginClass *klass)
{
}

G_MODULE_EXPORT void
peas_register_types (PeasObjectModule *module)
{
    example_plugin_register_type (G_TYPE_MODULE (module));

    peas_object_module_register_extension_type (module,
                                                DNF_TYPE_ACTIVATABLE,
                                                EXAMPLE_TYPE_PLUGIN);
}
