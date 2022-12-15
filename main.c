#include <stdio.h>
#include <glib.h>

#include "src/log.h"


gboolean timeout_callback(gpointer data) {
    log_info("timeout_callback called\n");
    return TRUE;
}


int main() {
    GMainLoop *loop = NULL;
    GMainContext *context = NULL;
    GSource *source = NULL;
    int id;

    log_info("Cogi start to run...");

    source = g_timeout_source_new_seconds(1);
    context = g_main_context_new();
    id = g_source_attach(source, context);
    loop = g_main_loop_new(context, FALSE);

    g_source_set_callback(source, timeout_callback, loop, NULL);

    g_main_loop_run(loop);
    g_main_loop_unref(loop);


    return 0;
}
