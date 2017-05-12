#include <stdio.h>
#include <gtk/gtk.h>

static void onDelete(GtkWidget *widget, GdkEvent *event, gpointer data){
	printf("Delete called\n");
	gtk_main_quit();
}

static void onDestroy(GtkWidget *widget, GdkEvent *event){
	printf("Destroy called\n");
	gtk_main_quit();
}

static void onButtonClick(GtkWidget *widget, gpointer data){
	static clicks=0;
	char label[]="         ";
	snprintf(label, 9, "%d", ++clicks);
	gtk_button_set_label(widget, label);
}

int main(int argc, char **argv){
	GtkWidget *window;
	GtkWidget *button;
	
	gtk_init (&argc, &argv);/* Dunno */
	
	window=gtk_window_new(GTK_WINDOW_TOPLEVEL);
	gtk_window_set_decorated(window, 0);
	g_signal_connect(window, "delete-event", G_CALLBACK(onDelete), NULL);/* close */
	g_signal_connect(window, "destroy", G_CALLBACK(onDestroy), NULL);/* Destroy? idk */
	
	button=gtk_button_new_with_label("Clicky button");
	g_signal_connect(button, "clicked", G_CALLBACK(onButtonClick), NULL);
	
	gtk_container_add(GTK_CONTAINER(window), button);
	gtk_widget_show(button);
	gtk_widget_show(window);
	gtk_main();
	
	return 0;
}
