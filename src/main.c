#include <stdio.h>
#include <gtk/gtk.h>
#include "manulapp.h"
#include <adwaita.h>

int main(int argc , char* argv[]) {

  // init adwaita
  adw_init();

  return g_application_run(G_APPLICATION(manul_app_new()), argc, argv);
}

