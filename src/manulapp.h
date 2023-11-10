#ifndef _MANUL_H
#define _MANUL_H

#include "manul-workbench.h"
#include <gtk/gtk.h>
#include <libpeas/peas.h>

G_BEGIN_DECLS

#define MANUL_APP_TYPE (manul_app_get_type())

G_DECLARE_FINAL_TYPE(ManulApp, manul_app, MANUL, APP, GtkApplication)

ManulApp *manul_app_new(void);

gchar **manul_app_get_argv(ManulApp *self, GApplicationCommandLine *cmdline);
void manul_app_open_project_async(ManulApp *self, GType workpace_type,
                                  GCancellable *cancellable,
                                  GAsyncReadyCallback callback,
                                  gpointer user_data);

ManulWorkbench *manul_app_open_project_finish(ManulApp *self,
                                              GAsyncResult *result,
                                              GError **error);

void manul_app_add_workbench(ManulApp *self, ManulWorkbench *workbench);
void manul_app_remove_workbench(ManulApp *self, ManulWorkbench *workbench);
void manul_app_foreach_workbench(ManulApp *self, GFunc callbeck,
                                 gpointer user_data);

void manul_app_load_addins(ManulApp *self);
void manul_app_unload_addins(ManulApp *self);
void manul_app_load_plugin(ManulApp *self, PeasPluginInfo *plugin_info);

G_END_DECLS

#endif
