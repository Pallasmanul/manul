
#ifndef _MANUL_DND_H
#define _MANUL_DND_H

#include <gtk/gtk.h>
#include "manul-drag.h"

G_BEGIN_DECLS

GtkTargetEntry *_manul_dnd_get_target  (void);
void _manul_dnd_dest_set (GtkWidget *target);
void _manul_dnd_set_data (GtkSelectionData *selection, GObject  *data);
GObject *_manul_dnd_get_data (GdkDragContext *context, GtkSelectionData *selection, guint info);
void _manul_dnd_set_icon_widget (GdkDragContext *context, const gchar *icon_name, cont gchar *descriptor);



G_END_DECLS

#endif

