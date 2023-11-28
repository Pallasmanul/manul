#pragma once

#include <gtk/gtk.h>
#include <gtksourceview/gtksource.h>

G_BEGIN_DECLS

#define MANUL_TYPE_SOURCE_VIEW (manul_source_view_get_type)

G_DECLARE_FINAL_TYPE(ManulSourceView, manul_source_view, MANUL, SOURCE_VIEW, GtkSourceView)

GtkWidget *manul_source_view_new   (void);
void manul_source_view_add_controller (ManulSourceView *self, int priority, GtkEventController *controller);
void manul_source_view_remove_controller (ManulSourceView *self);
void manul_source_view_jump_to_insert (ManulSourceView *self);


G_END_DECLS

