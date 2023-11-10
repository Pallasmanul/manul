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
#include <libpeas/peas-autocleanups.h>

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
  GPtrArray *workbenches; // Array for all workbench instances (load application
                          // windows)
  GHashTable *plugin_settings; // a hashtable of GSettings for each of the
                               // loadded plugins
  PeasExtensionSet *addins;    // Addins created and destroyed bu application in
                               // ::startup() and ::shutdown()
  GSettings *settings;
  GHashTable *plugin_gresources; // track the Gresource files loaded for plugins
};

G_DEFINE_TYPE(ManulApp, manul_app, GTK_TYPE_APPLICATION);

const GActionEntry _manul_app_entries[] = {{"save", NULL, NULL, NULL},
                                           {"saveas", NULL, NULL, NULL},
                                           {"preference", NULL, NULL, NULL},
                                           {"quit", NULL, NULL, NULL}

};

/*
 * Private Function
 */

gchar **ide_application_get_argv(ManulApp *self,
                                 GApplicationCommandLine *cmdline) {

  return NULL;
}

static GtkCssProvider *provider = NULL;
static const char *format =
    "label {padding: 20px;} label#red {background: red;} "
    "label#green {background: green;} label#blue {background: blue;} "
    "label#canvas {color: %s; font-weight: bold; font-size: 72pt;}";

static gboolean drop_cb(GtkDropTarget *self, const GValue *value, gdouble x,
                        gdouble y, gpointer user_data) {

  char *s;

  s = g_strdup_printf(format, g_value_get_string(value));
  gtk_css_provider_load_from_data(provider, s, -1);
  g_free(s);

  return TRUE;
}

static void manul_app_activate(GApplication *app) {
  g_print("Manul App Activate\n");
  g_message("This is debug aplication");

  GtkApplication *app_class = GTK_APPLICATION(app);
  GtkBuilder *build;
  GtkWindow *win;
  GtkLabel *src_labels[3];
  int i;
  GtkLabel *canvas;
  GtkDragSource *src;
  GdkContentProvider *content;
  GtkDropTarget *tgt;
  GdkDisplay *display;
  char *s;

  build = gtk_builder_new_from_resource("/org/gtk/manul/app/dnd.ui");
  win = GTK_WINDOW(gtk_builder_get_object(build, "win"));
  src_labels[0] = GTK_LABEL(gtk_builder_get_object(build, "red"));
  src_labels[1] = GTK_LABEL(gtk_builder_get_object(build, "green"));
  src_labels[2] = GTK_LABEL(gtk_builder_get_object(build, "blue"));
  canvas = GTK_LABEL(gtk_builder_get_object(build, "canvas"));
  gtk_window_set_application(win, app_class);
  g_object_unref(build);

  for (i = 0; i < 3; i++) {
    src = gtk_drag_source_new();
    content = gdk_content_provider_new_typed(
        G_TYPE_STRING, gtk_widget_get_name(GTK_WIDGET(src_labels[i])));
    gtk_drag_source_set_content(src, content);
    g_object_unref(content);
    gtk_widget_add_controller(GTK_WIDGET(src_labels[i]),
                              GTK_EVENT_CONTROLLER(src));
  }

  tgt = gtk_drop_target_new(G_TYPE_STRING, GDK_ACTION_COPY);
  g_signal_connect(tgt, "drop", G_CALLBACK(drop_cb), NULL);
  gtk_widget_add_controller(GTK_WIDGET(canvas), GTK_EVENT_CONTROLLER(tgt));

  provider = gtk_css_provider_new();
  s = g_strdup_printf(format, "black");
  gtk_css_provider_load_from_data(provider, s, -1);
  g_free(s);

  display = gdk_display_get_default();
  gtk_style_context_add_provider_for_display(
      display, GTK_STYLE_PROVIDER(provider),
      GTK_STYLE_PROVIDER_PRIORITY_APPLICATION);
  g_object_unref(provider);

  win = gtk_application_get_active_window(app_class);
  gtk_window_present(win);
}

static void manul_app_open(GApplication *app, GFile **files, gint n_files,
                           const char *hint) {}

static void manul_app_startup(GApplication *app) {

  g_action_map_add_action_entries(G_ACTION_MAP(app), _manul_app_entries, G_N_ELEMENTS(_manul_app_entries), app);

}

static void manul_app_shutdown(GApplication *app) {}

static void manul_app_dispose(GObject *object) {}

static void manul_app_class_init(ManulAppClass *class) {

  GObjectClass *object_class = G_OBJECT_CLASS(class);
  GApplicationClass *app_class = G_APPLICATION_CLASS(class);

  object_class->dispose = manul_app_dispose;

  app_class->activate = manul_app_activate;
  //  app_class->startup = manul_app_startup;
  app_class->open = manul_app_open;
  //  app_class->shutdown = manul_app_shutdown;
}

static void manul_app_init(ManulApp *manul_app) {}

ManulApp *manul_app_new(void) {
  return g_object_new(MANUL_APP_TYPE, "application-id", "org.gtk.manulapp",
                      "flags", G_APPLICATION_HANDLES_OPEN, NULL);
}
