#pragma once

#include "dnf-activatable.h"

#include <libpeas/peas.h>

G_BEGIN_DECLS

#define EMBEDDED_TYPE_PLUGIN embedded_plugin_get_type ()

G_DECLARE_FINAL_TYPE (EmbeddedPlugin, embedded_plugin, EMBEDDED, PLUGIN, PeasExtensionBase)

G_MODULE_EXPORT void embedded_plugin_register_types (PeasObjectModule *module);

G_END_DECLS
