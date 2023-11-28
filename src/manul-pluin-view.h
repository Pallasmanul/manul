
#pragma once

#include <gtk/gtk.h>

G_BEGIN_DECLS

#define MANUL_TYPE_PLUGIN_VIEW (manul_plugin_view_get_type())

G_DECLARE_FINAL_TYPE(ManulPluginView, manul_plugin_view, MANUL, PLUGIN_VIEW, GtkWidget)


GtkWidget *manul_plugin_view_new();


G_END_DECLS
