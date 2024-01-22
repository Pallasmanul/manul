
#include "manul-base-editor.h"

struct _ManulBaseEditor {
  GtkWidget parent;
  GtkText *text_input;
  GtkTextBuffer *text_edit_buffer;
};

G_DEFINE_TYPE(ManulBaseEditor, manul_base_editor, GTK_TYPE_TEXT_BUFFER)

static void manul_base_editor_init(ManulBaseEditor *edi) {
  edi->text_input = GTK_TEXT(gtk_text_new());
  edi->text_edit_buffer = GTK_TEXT_BUFFER(gtk_text_buffer_new(NULL));
}

static void manul_base_editor_dispose(ManulBaseEditor *edi) {
  g_object_unref(edi->text_input);
  g_object_unref(edi->text_edit_buffer);
}

static void manul_base_editor_class_init(ManulBaseEditorClass *edi_class) {}

GtkWidget *manul_base_editor_new(ManulBaseEditor *edi) {

  return GTK_WIDGET(g_object_new(MANUL_TYPE_BASE_EDITOR,"wrap-mode",GTK_WRAP_WORD_CHAR,NULL));
}

GtkWidget *manul_base_editor_new_with_file(GFile *file) {

}

