#include <gtk/gtk.h>

int main(int argc, char *argv[])
{
    GtkWidget *window;
    GtkWidget *sidebar;
    GtkWidget *stack;
    GtkWidget *box;
    GtkWidget *widget;
    GtkWidget *header;

    const gchar *pages[] = {
        "Child 1",
        "Child 2",
        "Child 3",
        "Child 4",
        "Child 5",
        "Child 6",
        "Child 7",
        "Child 8",
        "Child 9",
        "Child 10",
        NULL};

    const gchar *c = NULL;

    gtk_init(&argc, &argv);

    window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(window), "GTK+ 3 Sidebar");
    gtk_window_set_position(GTK_WINDOW(window), GTK_WIN_POS_CENTER);

    gtk_window_set_default_size(GTK_WINDOW(window), 500, 250);
    g_signal_connect(window, "destroy", G_CALLBACK(gtk_main_quit), NULL);

    box = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 0);
    sidebar = gtk_stack_sidebar_new();
    gtk_box_pack_start(GTK_BOX(box), sidebar, FALSE, FALSE, 0);

    stack = gtk_stack_new();
    gtk_stack_set_transition_type(GTK_STACK(stack), GTK_STACK_TRANSITION_TYPE_SLIDE_UP_DOWN);
    gtk_stack_sidebar_set_stack(GTK_STACK_SIDEBAR(sidebar), GTK_STACK(stack));

    widget = gtk_separator_new(GTK_ORIENTATION_VERTICAL);
    gtk_box_pack_start(GTK_BOX(box), widget, FALSE, FALSE, 0);

    gtk_box_pack_start(GTK_BOX(box), stack, TRUE, TRUE, 0);

    for (guint i = 0; (c = *(pages + i)) != NULL; i++)
    {
        widget = gtk_label_new(c);
        gtk_stack_add_named(GTK_STACK(stack), widget, c);
        gtk_container_child_set(GTK_CONTAINER(stack), widget, "title", c, NULL);
    }

    gtk_container_add(GTK_CONTAINER(window), box);

    gtk_widget_show_all(window);

    gtk_main();

    return 0;
}
