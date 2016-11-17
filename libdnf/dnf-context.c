#include "dnf-context.h"
#include "dnf-activatable.h"

#include <libpeas/peas.h>

/**
 * SECTION:dnf-context
 * @short_description: the DNF Context
 * @title: Context
 * @stability: Unstable
 * @include: dnf-context.h
 */

struct _DnfContext
{
    GObject parent_instance;

    PeasExtensionSet *extension_set;
};

G_DEFINE_TYPE (DnfContext, dnf_context, G_TYPE_OBJECT)

static void
on_extension_added (G_GNUC_UNUSED PeasExtensionSet *set,
                    G_GNUC_UNUSED PeasPluginInfo   *info,
                                  DnfActivatable   *activatable,
                    G_GNUC_UNUSED DnfContext       *ctx)
{
    dnf_activatable_activate (activatable);
}

static void
on_extension_removed (G_GNUC_UNUSED PeasExtensionSet *set,
                      G_GNUC_UNUSED PeasPluginInfo   *info,
                                    DnfActivatable   *activatable,
                      G_GNUC_UNUSED DnfContext       *ctx)
{
    dnf_activatable_deactivate (activatable);
}

static void
on_run_executed (G_GNUC_UNUSED PeasExtensionSet *set,
                 G_GNUC_UNUSED PeasPluginInfo   *info,
                               DnfActivatable   *activatable,
                               DnfContext       *ctx)
{
    dnf_activatable_run (activatable, ctx);
}

/**
 * dnf_context_new:
 *
 * Returns: a #DnfContext.
 */
DnfContext *
dnf_context_new (void)
{
    return g_object_new (DNF_TYPE_CONTEXT, NULL);
}

static void
dnf_context_finalize (GObject *object)
{
    DnfContext *ctx = (DnfContext *)object;

    g_clear_object (&ctx->extension_set);

    G_OBJECT_CLASS (dnf_context_parent_class)->finalize (object);
}

static void
dnf_context_class_init (DnfContextClass *klass)
{
    GObjectClass *object_class = G_OBJECT_CLASS (klass);

    object_class->finalize = dnf_context_finalize;
}

static void
dnf_context_init (DnfContext *ctx)
{
    g_autoptr(PeasEngine) engine = peas_engine_get_default ();

    /* Enable Python 3 plugins */
    peas_engine_enable_loader (engine, "python3");

    if (g_getenv ("DNF_IN_TREE_PLUGINS") != NULL) {
        g_autoptr(GError) error = NULL;
        g_irepository_require_private (g_irepository_get_default (),
                                       BUILDDIR,
                                       "Dnf", "2.0", 0, &error);
        g_assert_no_error (error);
        peas_engine_prepend_search_path (engine,
                                         BUILDDIR"/plugins",
                                         SRCDIR"/plugins");
    } else {
        peas_engine_prepend_search_path (engine,
                                         PACKAGE_LIBDIR"/plugins",
                                         PACKAGE_DATADIR"/plugins");
    }

    peas_engine_prepend_search_path (engine,
                                     "resource:///org/fedoraproject/dnf/plugins",
                                     NULL);

    g_autofree gchar *path = g_build_filename (g_get_user_data_dir (),
                                               "dnf",
                                               "plugins",
                                               NULL);
    peas_engine_prepend_search_path (engine, path, NULL);

    ctx->extension_set = peas_extension_set_new (engine,
                                                 DNF_TYPE_ACTIVATABLE,
                                                 NULL);

    peas_extension_set_foreach (ctx->extension_set,
                                (PeasExtensionSetForeachFunc)on_extension_added,
                                ctx);
    g_signal_connect (ctx->extension_set, "extension-added", G_CALLBACK (on_extension_added), ctx);
    g_signal_connect (ctx->extension_set, "extension-removed", G_CALLBACK (on_extension_removed), ctx);

    /* Load all plugins */
    for (const GList *plugin = peas_engine_get_plugin_list (engine);
         plugin != NULL;
         plugin = plugin->next)
        peas_engine_load_plugin (engine, (PeasPluginInfo *)plugin->data);
}

/**
 * dnf_context_run:
 * @ctx: a #DnfContext
 *
 * Run actions.
 *
 * Returns: %TRUE if successful run, %FALSE otherwise.
 */
gboolean
dnf_context_run (DnfContext *ctx)
{
    g_return_val_if_fail (DNF_IS_CONTEXT (ctx), FALSE);

    g_print ("Worked: ctx!\n");
    peas_extension_set_foreach (ctx->extension_set,
                                (PeasExtensionSetForeachFunc)on_run_executed,
                                ctx);

    return TRUE;
}
