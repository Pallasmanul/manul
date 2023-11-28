
#include "manul-source-view.h"


struct _ManulSourceVIew
{
  GtkSourceView source_view;
  GtkCssProvider *css_provider;
  PangoFontDescription *font_desc;
  double line_height;
  int font_scale;
  GtkSourceSearchContext *search_context;

  GtkPopoverMenu *joined_menu;
  GtkPopover *popup_menu;


  double click_x;
  double click_y;

  guint highlight_current_line : 1;

};

