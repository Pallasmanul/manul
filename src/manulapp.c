/**
 * @file      manulapp.c
 * @brief     Header of ManulApp Class
 * @date      Tue Oct 31 16:11:40 2023
 * @author    pallasmanul
 * @copyright GPL-3.0
 *
 * This module
 */

#include "manulapp.h"
#include <gtk/gtk.h>
#include <gtksourceview/gtksource.h>
#include <libadwaita-1/adwaita.h>
#include <libpeas-2/peas-object-module.h>
/*
 *   |__________|Window Title|_________|
 *   ||Menu|___________________________|
 *   |__|WorkBench1|_|__|WorkBench2|___|
 *   |_________________________________|
 *   |_________________________________|
 *   |_________________________________|
 *   |_________________________________|
 *   |_________________________________|
 */

/*
 *  Variable
 */

struct _ManulApp {
  GtkApplication parent_instance;
  GMenuModel *toolmenu;
};

G_DEFINE_TYPE(ManulApp, manul_app, GTK_TYPE_APPLICATION);

static char *get_untitled(void) {
  static int c = -1;
  if (++c == 0)
    return g_strdup_printf("Untitled");
  else
    return g_strdup_printf("Untitled%u",c);
}

static void activate_new(GSimpleAction *action, GVariant *parameter,
                         gpointer user_data) {}

static void activate_open(GSimpleAction *action, GVariant *parameter,
                          gpointer user_data) {}

static void activate_action(GSimpleAction *action, GVariant *parameter,
                            gpointer user_data) {}

static void activate_save(GSimpleAction *action, GVariant *parameter,
                          gpointer user_data) {}

static void activate_quit(GSimpleAction *action, GVariant *parameter,
                          gpointer user_data) {}

static void status_message(GtkWidget *status, const char *text) {
  guint id;

}

static void not_implemented(GSimpleAction *action, GVariant *parameter,
                            gpointer user_data) {
  GtkWidget *status;
  char *text;

  text = g_strdup_printf("Action %s not implemented",
                         g_action_get_name(G_ACTION(action)));
  status = GTK_WIDGET(g_object_get_data(G_OBJECT(user_data), "status"));
}

static GActionEntry app_entries[] = {
    {"new", activate_new, NULL, NULL, NULL},
    {"open", activate_open, NULL, NULL, NULL},
    {"save", activate_action, NULL, NULL, NULL},
    {"save-as", activate_save, NULL, NULL, NULL},
    {"quit", activate_quit, NULL, NULL, NULL},
};

static void manul_app_activate(GApplication *application) {}

static void manul_app_class_init(ManulAppClass *class) {
  GApplicationClass *app_class = G_APPLICATION_CLASS(class);
  GtkWidgetClass *app_widget_class = GTK_WIDGET_CLASS(class);

  GtkBuilder *menu_builder;
  GtkBuilder *manul_app_builder;

  menu_builder = gtk_builder_new_from_resource("/org/gtk/manul/app/menu.ui");
  manul_app_builder =
      gtk_builder_new_from_resource("org/gtk/manul/app/manulapp.ui");

  app_class->activate = manul_app_activate;
}

static void manul_app_init(ManulApp *manul_app) {
  GtkWidget *popover;
  popover = gtk_popover_menu_new_from_model(manul_app->toolmenu);
}

ManulApp *manul_app_new(void) {
  return g_object_new(MANUL_APP_TYPE, "application-id", "org.gtk.manulapp",
                      "flags", G_APPLICATION_HANDLES_OPEN, NULL);
}
