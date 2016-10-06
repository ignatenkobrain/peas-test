#pragma once

#include "dnf-activatable.h"

#include <libpeas/peas.h>

G_BEGIN_DECLS

#define EXAMPLE_TYPE_PLUGIN example_plugin_get_type ()

G_DECLARE_FINAL_TYPE (ExamplePlugin, example_plugin, EXAMPLE, PLUGIN, PeasExtensionBase)

G_MODULE_EXPORT void peas_register_types (PeasObjectModule *module);

G_END_DECLS
