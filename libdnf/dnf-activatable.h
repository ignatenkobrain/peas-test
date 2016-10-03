#pragma once

#include <glib-object.h>

#include "dnf-context.h"

G_BEGIN_DECLS

#define DNF_TYPE_ACTIVATABLE dnf_activatable_get_type ()

G_DECLARE_INTERFACE (DnfActivatable, dnf_activatable, DNF, ACTIVATABLE, GObject)

struct _DnfActivatableInterface
{
    GTypeInterface parent_iface;

    void (*activate)   (DnfActivatable *activatable);
    void (*deactivate) (DnfActivatable *activatable);

    void (*run)        (DnfActivatable *activatable,
                        DnfContext     *ctx);
};

void dnf_activatable_activate   (DnfActivatable *activatable);
void dnf_activatable_deactivate (DnfActivatable *activatable);
void dnf_activatable_run        (DnfActivatable *activatable,
                                 DnfContext     *ctx);

G_END_DECLS
