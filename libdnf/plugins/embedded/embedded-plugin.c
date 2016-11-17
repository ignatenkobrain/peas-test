#include "embedded-plugin.h"

struct _EmbeddedPlugin
{
    PeasExtensionBase parent_instance;
};

static void embedded_plugin_iface_init (DnfActivatableInterface *iface);

G_DEFINE_DYNAMIC_TYPE_EXTENDED (EmbeddedPlugin,
                                embedded_plugin,
                                PEAS_TYPE_EXTENSION_BASE,
                                0,
                                G_IMPLEMENT_INTERFACE (DNF_TYPE_ACTIVATABLE,
                                                       embedded_plugin_iface_init))

static void
embedded_plugin_init (EmbeddedPlugin *plugin)
{
}

static void
embedded_plugin_finalize (GObject *object)
{
    G_GNUC_UNUSED EmbeddedPlugin *plugin = (EmbeddedPlugin *)object;

    G_OBJECT_CLASS (embedded_plugin_parent_class)->finalize (object);
}

static void
embedded_plugin_activate (DnfActivatable *activatable)
{
    G_GNUC_UNUSED EmbeddedPlugin *plugin = (EmbeddedPlugin *)activatable;

    g_print ("[plugin_activate]: C\n");
}

static void
embedded_plugin_deactivate (DnfActivatable *activatable)
{
    G_GNUC_UNUSED EmbeddedPlugin *plugin = (EmbeddedPlugin *)activatable;

    g_print ("[plugin_deactivate]: C\n");
}

static void
embedded_plugin_run (DnfActivatable *activatable,
                    DnfContext     *ctx)
{
    G_GNUC_UNUSED EmbeddedPlugin *plugin = (EmbeddedPlugin *)activatable;

    g_print ("Worked: C!\n");
}

static void
embedded_plugin_class_init (EmbeddedPluginClass *klass)
{
    GObjectClass *object_class = G_OBJECT_CLASS (klass);

    object_class->finalize = embedded_plugin_finalize;
}

static void
embedded_plugin_iface_init (DnfActivatableInterface *iface)
{
    iface->activate = embedded_plugin_activate;
    iface->deactivate = embedded_plugin_deactivate;

    iface->run = embedded_plugin_run;
}

static void
embedded_plugin_class_finalize (EmbeddedPluginClass *klass)
{
}

G_MODULE_EXPORT void
embedded_plugin_register_types (PeasObjectModule *module)
{
    embedded_plugin_register_type (G_TYPE_MODULE (module));

    peas_object_module_register_extension_type (module,
                                                DNF_TYPE_ACTIVATABLE,
                                                EMBEDDED_TYPE_PLUGIN);
}
