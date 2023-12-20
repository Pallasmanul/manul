project('Manul', 'c',
          license: 'GPL3+',
          version: '42.1',
    meson_version: '>= 0.59.1',
)

release_args = []

config_h = configuration_data()
config_h.set_quoted('PACKAGE_NAME', 'Manul')
config_h.set_quoted('PACKAGE_VERSION', meson.project_version())


pkgdocdir_abs = join_paths(get_option('prefix'), get_option('datadir'), 'doc', 'gnome-builder')
pkglibdir_abs = join_paths(get_option('prefix'), get_option('libdir'), 'gnome-builder')
pkglibdir = join_paths(get_option('libdir'), 'gnome-builder')
pkgincludedir = join_paths(get_option('includedir'), 'gnome-builder')
pkggirdir = join_paths(get_option('datadir'),'gnome-builder', 'gir-1.0')
pkgtypelibdir = join_paths(get_option('libdir'), 'gnome-builder', 'girepository-1.0')

glib_req_version = '2.72'
gtk_req_version = '4.10'
gtksourceview_req_version = '5.4'
libadwaita_req_version = '1.1'
gobject_introspection_req_version = '1.72'

glib_req = '>= @0@'.format(glib_req_version)
gtk_req = '>= @0@'.format(gtk_req_version)
gtksourceview_req = '>= @0@'.format(gtksourceview_req_version)
libadwaita_req = '>= @0@'.format(libadwaita_req_version)
gobject_introspection_req = '>= @0@'.format(gobject_introspection_req_version)

glib_major = glib_req_version.split('.')[0].to_int()
glib_minor = glib_req_version.split('.')[1].to_int()
gtk_major = gtk_req_version.split('.')[0].to_int()
gtk_minor = gtk_req_version.split('.')[1].to_int()
adw_major = libadwaita_req_version.split('.')[0].to_int()
adw_minor = libadwaita_req_version.split('.')[1].to_int()
gtksourceview_major = gtksourceview_req_version.split('.')[0].to_int()
gtksourceview_minor = gtksourceview_req_version.split('.')[1].to_int()

if glib_minor % 2 == 1
  glib_minor = glib_minor + 1
endif
if gtk_minor % 2 == 1
  gtk_minor = gtk_minor + 1
endif
if gtksourceview_minor % 2 == 1
  gtksourceview_minor = gtksourceview_minor + 1
endif

# These default values are obtained by running /bin/sh without setting PATH
safe_path = get_option('with_safe_path')
if safe_path == ''
  if host_machine.system() == 'freebsd'
    safe_path = '/bin:/usr/bin:/usr/local/bin'
  elif host_machine.system() == 'dragonfly'
    safe_path = '/bin:/usr/bin:/usr/local/bin:/usr/pkg/bin'
  elif host_machine.system() == 'netbsd'
    safe_path = '/usr/bin:/bin:/usr/pkg/bin:/usr/local/bin'
  elif host_machine.system() == 'openbsd'
    safe_path = '/usr/bin:/bin:/usr/X11R6/bin:/usr/local/bin'
  else
    safe_path = '/usr/bin:/bin'
  endif
endif

status = [
]


status += [
  'Version ............... : @0@'.format(meson.project_version()),
  'Build Type ............ : @0@'.format(get_option('buildtype')),
  '',
  'Prefix ................ : @0@'.format(get_option('prefix')),
  'Libdir ................ : @0@'.format(join_paths(get_option('prefix'), get_option('libdir'))),
  'Safe PATH ............. : @0@'.format(safe_path),
  '',
  '',
  'Help Docs ............. : @0@'.format(get_option('help')),
  'API Docs .............. : @0@'.format(get_option('docs')),
  '',
]

config_h.set_quoted('PACKAGE_STRING', 'gnome-builder-' + meson.project_version())
config_h.set_quoted('PACKAGE_DATADIR', join_paths(get_option('prefix'), get_option('datadir')))
config_h.set_quoted('PACKAGE_ICONDIR', join_paths(get_option('prefix'), get_option('datadir'), 'gnome-builder/icons'))
config_h.set_quoted('PACKAGE_DOCDIR', join_paths(get_option('prefix'), get_option('datadir'), 'doc/gnome-builder'))
config_h.set_quoted('PACKAGE_LIBDIR', join_paths(get_option('prefix'), get_option('libdir')))
config_h.set_quoted('PACKAGE_LOCALE_DIR', join_paths(get_option('prefix'), get_option('datadir'), 'locale'))
config_h.set_quoted('PACKAGE_LIBEXECDIR', join_paths(get_option('prefix'), get_option('libexecdir')))
config_h.set_quoted('SAFE_PATH', safe_path)
config_h.set('GETTEXT_PACKAGE', 'PACKAGE_NAME')
config_h.set('LOCALEDIR', 'PACKAGE_LOCALE_DIR')
config_h.set10('ENABLE_NLS', true) # Always enabled

# We should probably avoid using these
config_h.set_quoted('SRCDIR', meson.project_source_root())
config_h.set_quoted('BUILDDIR', meson.project_build_root())

add_global_arguments([
  '-DHAVE_CONFIG_H',
  '-I' + meson.project_build_root(), # config.h
  '-D_GNU_SOURCE',
  '-DIDE_COMPILATION',
], language: 'c')

libide_args = []

cc = meson.get_compiler('c')
global_c_args = [
  '-DGLIB_VERSION_MIN_REQUIRED=GLIB_VERSION_@0@_@1@'.format(glib_major, glib_minor),
  '-DGLIB_VERSION_MAX_ALLOWED=GLIB_VERSION_@0@_@1@'.format(glib_major, glib_minor),
  '-DGDK_VERSION_MIN_REQUIRED=GDK_VERSION_@0@_@1@'.format(gtk_major, gtk_minor),
  '-DGDK_VERSION_MAX_ALLOWED=GDK_VERSION_@0@_@1@'.format(gtk_major, gtk_minor),
  '-DGDK_DISABLE_DEPRECATION_WARNINGS',
  '-DADW_VERSION_MIN_REQUIRED=ADW_VERSION_@0@_@1@'.format(adw_major, adw_minor),
  '-DADW_VERSION_MAX_ALLOWED=ADW_VERSION_@0@_@1@'.format(adw_major, adw_minor),
  '-DGTK_SOURCE_VERSION_MIN_REQUIRED=GTK_SOURCE_VERSION_@0@_@1@'.format(gtksourceview_major, gtksourceview_minor),
  '-DGTK_SOURCE_VERSION_MAX_ALLOWED=GTK_SOURCE_VERSION_@0@_@1@'.format(gtksourceview_major, gtksourceview_minor),
]

test_c_args = [
  '-Wcast-align',
  '-Wdeclaration-after-statement',
  '-Werror=address',
  '-Werror=array-bounds',
  '-Werror=empty-body',
  '-Werror=implicit',
  '-Werror=implicit-function-declaration',
  '-Werror=incompatible-pointer-types',
  '-Werror=init-self',
  '-Werror=int-conversion',
  '-Werror=int-to-pointer-cast',
  '-Werror=main',
  '-Werror=misleading-indentation',
  '-Werror=missing-braces',
  '-Werror=missing-include-dirs',
  '-Werror=nonnull',
  '-Werror=overflow',
  '-Werror=parenthesis',
  '-Werror=pointer-arith',
  '-Werror=pointer-to-int-cast',
  '-Werror=redundant-decls',
  '-Werror=return-type',
  '-Werror=sequence-point',
  '-Werror=shadow',
  '-Werror=trigraphs',
  '-Werror=undef',
  '-Werror=write-strings',
  '-Wformat-nonliteral',
  ['-Werror=format-security', '-Werror=format=2'],
  '-Wignored-qualifiers',
  '-Wimplicit-function-declaration',
  '-Wlogical-op',
  # '-Wmissing-declarations',
  '-Wmissing-format-attribute',
  '-Wmissing-include-dirs',
  '-Wmissing-noreturn',
  '-Wnested-externs',
  '-Wno-cast-function-type',
  '-Wno-dangling-pointer',
  '-Wno-missing-field-initializers',
  '-Wno-sign-compare',
  '-Wno-unused-parameter',
  '-Wold-style-definition',
  '-Wpointer-arith',
  '-Wredundant-decls',
  '-Wstrict-prototypes',
  '-Wswitch-default',
  '-Wswitch-enum',
  '-Wundef',
  '-Wuninitialized',
  '-Wunused',
  '-fno-strict-aliasing',
]

if get_option('buildtype') != 'plain'
  test_c_args += '-fstack-protector-strong'
endif
if get_option('profiling')
  test_c_args += '-pg'
endif

foreach arg: test_c_args
  if cc.has_multi_arguments(arg)
    global_c_args += arg
  endif
endforeach

if cc.has_multi_arguments('-Wmissing-declarations')
  libide_args += '-Wmissing-declarations'
endif

add_project_arguments(global_c_args, language: 'c')

release_args = []
global_link_args = []
test_link_args = [
  '-Wl,-z,relro',
  '-Wl,-z,now',
]
if not get_option('buildtype').startswith('debug')

  # TODO: Maybe reuse 'b_ndebug' option
  add_global_arguments(['-DG_DISABLE_CAST_CHECKS'], language: 'c')

  release_args += [ '-DG_DISABLE_ASSERT' ]

  test_link_args += [
    '-Wl,-Bsymbolic',
    '-fno-plt',
  ]

endif

foreach link_arg: test_link_args
  if cc.has_link_argument(link_arg)
    global_link_args += link_arg
  endif
endforeach
add_project_link_arguments(global_link_args, language: 'c')


if get_option('tcmalloc')
  tcmalloc_ldflags = [
    '-fno-builtin-malloc',
    '-fno-builtin-calloc',
    '-fno-builtin-realloc',
    '-fno-builtin-free',
    '-Wl,--push-state,--no-as-needed',
    '-ltcmalloc_minimal',
    '-Wl,--pop-state'
  ]
  add_project_link_arguments(tcmalloc_ldflags, language: 'c')
endif

# Commonly used deps
libglib_dep = dependency('glib-2.0', version: glib_req)
libgio_dep = dependency('gio-2.0', version: glib_req)
libgiounix_dep = dependency('gio-unix-2.0', version: glib_req)
libgtk_dep = dependency('gtk4', version: gtk_req)
libgir_dep = dependency('gobject-introspection-1.0', version: gobject_introspection_req)
libadwaita_dep = dependency('libadwaita-1', version: libadwaita_req)
libgtksource_dep = dependency('gtksourceview-5', version: gtksourceview_req)
libpeas_dep = dependency('libpeas-1.0', version: '>= 1.22.0')

configure_file(output: 'config.h', configuration: config_h)

gnome = import('gnome')
i18n = import('i18n')
pkgconfig = import('pkgconfig')
pymod = import('python')

status += ['']

subdir('src')

gnome.post_install(
  glib_compile_schemas: true,
  gtk_update_icon_cache: true,
  update_desktop_database: true,
)

message('\n  '.join(status))


