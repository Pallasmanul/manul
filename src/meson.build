exe_link_args = []
exe_c_args = []

manul_builder_pkg_requires = [
  'gio-2.0',
  'gio-unix-2.0',
  'gtk4',
  'gtksourceview-5',
  'libgtksource_dep',
]

manul_builder_gir_includes = [
  'Adw-1',
   'Gio-2.0',
  'Gtk-4.0',
  'GtkSource-5',
]

manul_builder_deps = [
  libgio_dep,
  libgiounix_dep,
  libgtk_dep,
  libpeas_dep,
  libadwaita_dep,
  libgtksource_dep,
]

manul_builder_static = [
]

resources = gnome.compile_resources('resources','dnd.gresource.xml',
)

gnome_builder = executable('Manul', 'main.c', 'manulapp.c', resources,
           install: true,
            c_args: exe_c_args + release_args,
         link_args: exe_link_args,
               pie: true,
        link_whole: manul_builder_static,
     install_rpath: pkglibdir_abs,
      dependencies: manul_builder_deps,
    export_dynamic: true,
)