#pragma once

#include <gtk/gtk.h>
#include <libpeas/peas.h>

G_BEGIN_DECLS

#define MANUL_TYPE_PLUGIN (manul_plugin_get_type())
G_DECLARE_FINAL_TYPE(ManulPlugin, manul_plugin, MANUL, PLUGIN, GObject)





G_END_DECLS
