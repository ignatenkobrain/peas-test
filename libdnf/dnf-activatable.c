#include "dnf-activatable.h"

/**
 * SECTION:dnf-activatable
 * @short_description: Interface for activatable plugins.
 * @see_also: #DnfContext.
 *
 * TODO: write some docs.
 */

G_DEFINE_INTERFACE (DnfActivatable, dnf_activatable, G_TYPE_OBJECT)

static void
dnf_activatable_default_init (DnfActivatableInterface *iface)
{
}

/**
 * dnf_activatable_activate:
 * @activatable: a #DnfActivatable
 *
 * Activates the extension. This is the starting point where
 * the implementation does everything it needs to do. Avoid
 * doing it earlier than this call.
 *
 * This function is called after the extension is loaded and
 * the signals are connected. If you want to do anything before
 * that, the _init function should be used instead.
 */
void
dnf_activatable_activate (DnfActivatable *activatable)
{
    g_return_if_fail (DNF_IS_ACTIVATABLE (activatable));

    DnfActivatableInterface *iface = DNF_ACTIVATABLE_GET_IFACE (activatable);
    g_return_if_fail (iface->activate);
    iface->activate (activatable);
}

/**
 * dnf_activatable_deactivate:
 * @activatable: a #DnfActivatable
 *
 * Deactivates the extension.
 */
void
dnf_activatable_deactivate (DnfActivatable *activatable)
{
    g_return_if_fail (DNF_IS_ACTIVATABLE (activatable));

    DnfActivatableInterface *iface = DNF_ACTIVATABLE_GET_IFACE (activatable);
    g_return_if_fail (iface->deactivate);
    iface->deactivate (activatable);
}

/**
 * dnf_activatable_run:
 * @activatable: a #DnfActivatable
 * @ctx: a #DnfContext
 *
 * Execute run() method from extension.
 */
void
dnf_activatable_run (DnfActivatable *activatable,
                     DnfContext     *ctx)
{
    g_return_if_fail (DNF_IS_ACTIVATABLE (activatable));

    DnfActivatableInterface *iface = DNF_ACTIVATABLE_GET_IFACE (activatable);
    g_return_if_fail (iface->run);
    iface->run (activatable, ctx);
}
