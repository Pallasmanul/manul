
#ifndef _MANUL_DND_H
#define _MANUL_DND_H

#include <gtk/gtk.h>
#include "manul-drag.h"

G_BEGIN_DECLS

typedef struct STRUCT_DND_TYPE {

  GtkDragSource *src;
  GdkContentProvider *content;

}dnd_type;


G_END_DECLS

#endif

