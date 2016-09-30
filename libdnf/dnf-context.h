#pragma once

#include <glib-object.h>

G_BEGIN_DECLS

#define DNF_TYPE_CONTEXT dnf_context_get_type ()

G_DECLARE_FINAL_TYPE (DnfContext, dnf_context, DNF, CONTEXT, GObject)

DnfContext *dnf_context_new (void);
gboolean    dnf_context_run (DnfContext *ctx);

G_END_DECLS
