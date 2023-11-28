#include "tfetextview.h"

struct _TfeTextView {
  GtkTextView parent;
  GFile *file;
};

// personal signal
enum { CHANGE_FILE, OPEN_RESPONSE, NUMBER_OF_SIGNALS };

G_DEFINE_FINAL_TYPE(TfeTextView, tfe_text_view, GTK_TYPE_TEXT_VIEW);

static guint tfe_text_view_signals[NUMBER_OF_SIGNALS];

static void tfe_text_view_dispose(GObject *gobject) {
  TfeTextView *tv = TFE_TEXT_VIEW(gobject);

  if (G_IS_FILE(tv->file))
    g_clear_object(&tv->file);

  G_OBJECT_CLASS(tfe_text_view_parent_class)->dispose(gobject);
}

static void tfe_text_view_init(TfeTextView *tv) { tv->file = NULL; }
static void tfe_text_view_class_init(TfeTextViewClass *class) {
  GObjectClass *object_class = G_OBJECT_CLASS(class);

  object_class->dispose = tfe_text_view_dispose;

  tfe_text_view_signals[CHANGE_FILE] =
      g_signal_new("change-file", G_TYPE_FROM_CLASS(class),
                   G_SIGNAL_RUN_LAST | G_SIGNAL_NO_RECURSE | G_SIGNAL_NO_HOOKS,
                   0, NULL, NULL, NULL, G_TYPE_NONE, 0);

  tfe_text_view_signals[OPEN_RESPONSE] =
      g_signal_new("open-response", G_TYPE_FROM_CLASS(class),
                   G_SIGNAL_RUN_LAST | G_SIGNAL_NO_RECURSE | G_SIGNAL_NO_HOOKS,
                   0, NULL, NULL, NULL, G_TYPE_NONE, 1, G_TYPE_INT);
}

GFile *tfe_text_view_get_file(TfeTextView *tv) {
  g_return_val_if_fail(TFE_IS_TEXT_VIEW(tv), NULL);

  if (G_IS_FILE(tv->file))
    return g_file_dup (tv->file);
  else
    return NULL;
}

static gboolean save_file(GFile *file, GtkTextBuffer *tb, GtkWindow *win) {
  GtkTextIter start_iter;
  GtkTextIter end_iter;
  char *contents;

  gboolean stat;

  return stat;
}

void tfe_text_view_open(TfeTextView *tv, GtkWindow *win) {
  g_return_if_fail(TFE_IS_TEXT_VIEW(tv));
}


GtkWidget *tfe_text_view_new(void) {
  return GTK_WIDGET(
      g_object_new(TFE_TYPE_TEXT_VIEW, "wrap-mode", GTK_WRAP_WORD_CHAR, NULL));
}
