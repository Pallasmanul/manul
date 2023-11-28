
#include "manul-plugin.h"

struct _ManulPlugin
{
  GObject parent_object;
  PeasPluginInfo *info;
};

enum {
  PROP_0,
  PROP_AUTHORSS,
  PROP_DESCRIPTION,
  PROP_ID,
  PROP_INFO,
  PROP_NAME,
  PROP_SECTIN,
  PROP_VERION,
  PROP_WEBSITE,
  N_PROPS
};

G_DEFINE_FINAL_TYPE (ManulPlugin, manul_plugin, G_TYPE_OBJECT)

static GParamSpec *properties [N_PROPS];
static GHashTable *section;


static void manul_plugin_class_init(ManulPluginClass *object_class) {}
static void manul_plugin_init(ManulPlugin *mp) {}



