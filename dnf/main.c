#include <dnf-context.h>

gint
main (G_GNUC_UNUSED gint   argc,
      G_GNUC_UNUSED gchar *argv[])
{
    g_autoptr(DnfContext) ctx = dnf_context_new ();

    g_print ("[ctx->run()]: START\n");
    gboolean ret = dnf_context_run (ctx);
    g_print ("[ctx->run()]: %s\n", ret ? "OK" : "FAIL");
    g_print ("[ctx->run()]: FINISH\n");

    return 0;
}
