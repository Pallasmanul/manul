#ifndef _MANUL_DRAG_H_
#define _MANUL_DRAG_H_

#include <gtk/gtk.h>


G_BEGIN_DECLS

#define MANUL_TYPE_DRAG _manul_drag_get_type()
G_DECLARE_INTERFACE (_ManulDrag, _Manul_drag, MANUL, DRAG, GObject);

struct __ManulDragInterface
{
  GTypeInterface parent_instance;
  gboolean (*can_drag) ( _ManulDrag *source);
  gboolean (*can_drop) (_ManulDrag *dest, gint x, gint y, GObject *data);
  gboolean (*drop)     (_ManulDrag *dest, gint x, gint y, GObject *data);
  gboolean (*highlight)(_ManulDrag *dest, gint x, gint y);
};

gboolean _manul_drag_can_drag (_ManulDrag *source);
gboolean _manul_drag_can_drop (_ManulDrag *dest, gint x, gint y, GObject *data);
gboolean _manul_drag_drop     (_ManulDrag *dest, gint x, gint y, GObject *data);
void _manul_drag_highlight    (_ManulDrag *dest, gint x, gint y);


G_END_DECLS

#endif /* _MANUL_DRAG_H_ */
