
#include "manul-draw.h"


void manul_draw_rectangle(cairo_t *cr,gboolean filled, gint _x1, gint _y1, gint _w ,gint _h){
  //  cairo_set_source_rgba(cr,, color.r, color.g, color.g,color.a);
  if (filled) {
    cairo_rectangle(cr, _x1, _y1, _w, _h);
    cairo_fill(cr);
  } else {
    cairo_rectangle(cr, _x1, _y1, _w, _h);
    cairo_stroke(cr);
  }
}

void manul_draw_line(cairo_t *cr, gint _x1, gint _y1, gint _x2, gint _y2) {
  //cairo_set_source_rgba(cr, )
  cairo_move_to(cr,_x1, _y1);
  cairo_line_to(cr,_x2, _y2);

}
