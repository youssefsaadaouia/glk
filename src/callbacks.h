#include <gtk/gtk.h>


void
on_button1_clicked                     (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_button2_clicked                     (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_treeview1_row_activated             (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data);

void
on_button3_clicked                     (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_Actualiser_clicked                  (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_modifier_clicked                    (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_supprimer_clicked                   (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_update_clicked                      (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_etage1_toggled                      (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_etage2_toggled                      (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_etage3_toggled                      (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_accepter_toggled                    (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_treeview3_row_activated             (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data);
