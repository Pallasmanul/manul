
#include "manul-dnd.h"

void _manul_dnd_set_content(dnd_type dnd, GType type, ...) {

  GValue value;
  GType xter;

  dnd.src = gtk_drag_source_new();
  va_list args;

  va_start(args, type);
  xter = va_arg(args, int);

  dnd.content = gdk_content_provider_new_typed(type,xter);
  gtk_drag_source_set_content(dnd.src, dnd.content);

}

