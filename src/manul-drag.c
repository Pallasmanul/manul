
#include "manul-drag.h"


static void _manul_drag_default_init(_ManulDragInterface *iface)
{}


gboolean _manul_drag_can_drag (_ManulDrag *source){
  _ManulDragInterface *iface;

  g_return_val_if_fail (MANUL_IS_DRAG(source), FALSE);
  iface = MANUL_DRAG_GET_IFACE(source);

  if (iface->can_drag)
    return iface->can_drag(source);
  else
    return FALSE;
}

gboolean _manul_drag_can_drop (_ManulDrag *dest, gint x, gint y, GObject *data)
{
  _ManulDragInterface *iface;

  g_return_val_if_fail (MANUL_IS_DRAG(dest),FALSE);
  iface = MANUL_DRAG_GET_IFACE (dest);
  if (iface->can_drop)
    return iface->can_drop (dest, x, y, data);
  else
    return FALSE;
}


gboolean _manul_drag_drop (_ManulDrag *dest, gint x, gint y, GObject *data)
{
  _ManulDragInterface *iface;

  g_return_val_if_fail (MANUL_IS_DRAG(dest),FALSE);
  return true;
}

