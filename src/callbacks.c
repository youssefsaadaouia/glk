#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <gtk/gtk.h>
#include <string.h>
#include "callbacks.h"
#include "interface.h"
#include "support.h"
#include "capteur.h"

enum 
{
EID,
ENOM,
ETYPE,
EJOUR,
EMOIS,
EANNEE,
EVALEUR,
COLUMNS,
};

void
on_button1_clicked                     (GtkWidget       *objet,
                                        gpointer         user_data)
{
capteur c;
GtkWidget *input1,*input2,*input5, *combobox1,*spinbutton1,*spinbutton2,*spinbutton3;
GtkWidget *fenetre_ajout,*fenetre_affiche;
int j,m,a;
char jour[20],mois[20],annee[20];
fenetre_ajout=lookup_widget(objet,"fenetre_ajout");
input1=lookup_widget(objet,"entry1");
input2=lookup_widget(objet,"entry2");
//input3=lookup_widget(objet,"entry3");
//input4=lookup_widget(objet,"entry4");
input5=lookup_widget(objet,"entry5");

spinbutton1=lookup_widget(objet,"spinbutton1");
spinbutton2=lookup_widget(objet,"spinbutton2");
spinbutton3=lookup_widget(objet,"spinbutton3");

combobox1=lookup_widget(objet,"combobox1");
strcpy(c.id,gtk_entry_get_text(GTK_ENTRY(input1)));
strcpy(c.nom,gtk_entry_get_text(GTK_ENTRY(input2)));
strcpy(c.type,gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox1)));
j=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON(spinbutton1));
m=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON(spinbutton2));
a=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON(spinbutton3));

sprintf(jour,"%d\0",j);
sprintf(mois,"%d\0",m);
sprintf(annee,"%d\0",a);


strcpy(c.da.jour,jour);
strcpy(c.da.mois,mois);
strcpy(c.da.annee,annee);

//strcpy(c.DateAjout,gtk_entry_get_text(GTK_ENTRY(input4)));
strcpy(c.valeur,gtk_entry_get_text(GTK_ENTRY(input5)));
printf("%s",combobox1);

ajoutercapteur(c);

//////////////////////////////////////////////////////

fenetre_ajout=lookup_widget(objet,"fenetre_ajout");
gtk_widget_destroy(fenetre_ajout);
fenetre_affiche=lookup_widget(objet,"fenetre_affiche");
fenetre_affiche=create_fenetre_affiche();
gtk_widget_show(fenetre_affiche);

/////////////////////////////////////////////////////
}


void
on_button2_clicked                     (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *fenetre_ajout;
GtkWidget *fenetre_affiche;
GtkWidget *treeview1;
fenetre_ajout=lookup_widget(objet,"fenetre_ajout");
gtk_widget_destroy(fenetre_ajout);
fenetre_affiche=lookup_widget(objet,"fenetre_affiche");
fenetre_affiche=create_fenetre_affiche();
gtk_widget_show(fenetre_affiche);
treeview1=lookup_widget(fenetre_affiche,"treeview1");
affichercapteur(treeview1);
}



void
on_treeview1_row_activated             (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{

GtkTreeIter iter;
gchar* id;
gchar* nom;
gchar* type;
gchar* jour;
gchar* mois;
gchar* annee;
gchar* valeur;
capteur c;
date da;
GtkTreeModel *model= gtk_tree_view_get_model(treeview);
if(gtk_tree_model_get_iter(model,&iter,path)){
gtk_tree_model_get(GTK_LIST_STORE(model),&iter,0,&id,1,&nom,2,&type,3,&jour,4,&mois,5,&annee,6,&valeur,-1);

strcpy(c.id,id);
strcpy(c.nom,nom);
strcpy(c.type,type);
strcpy(c.da.jour,jour);
strcpy(c.da.mois,mois);
strcpy(c.da.annee,annee);
strcpy(c.valeur,valeur);
supprimercapteur(c);
affichercapteur(treeview);
}

}


void
on_button3_clicked                     (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *fenetre_ajout;
GtkWidget *fenetre_affiche;
fenetre_affiche=lookup_widget(objet,"fenetre_affiche");
gtk_widget_destroy(fenetre_affiche);
fenetre_ajout=lookup_widget(objet,"fenetre_ajout");
fenetre_ajout=create_fenetre_ajout();
gtk_widget_show(fenetre_ajout);
}


void
on_Actualiser_clicked                  (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *fenetre_affiche,*w1;
GtkWidget *treeview1;

w1=lookup_widget(objet,"fenetre_affiche");
fenetre_affiche=create_fenetre_affiche();
gtk_widget_show(fenetre_affiche);
gtk_widget_hide(w1);
treeview1=lookup_widget(fenetre_affiche,"treeview1");
affichercapteur(treeview1);


}


void
on_modifier_clicked                    (GtkWidget       *objet,
                                        gpointer         user_data)

{



GtkWidget *fenetre_ajout,*fenetre_affiche;











//////////////////////////////////////////////////////
fenetre_ajout=lookup_widget(objet,"fenetre_affiche");
gtk_widget_destroy(fenetre_ajout);
fenetre_affiche=lookup_widget(objet,"fenetre_modif");
fenetre_affiche=create_fenetre_modif();
gtk_widget_show(fenetre_affiche);
















/*
strcpy(nom,gtk_entry_get_text(GTK_ENTRY(ag_entry_nom_hotel)));
strcpy(type,gtk_entry_get_text(GTK_ENTRY(ag_entry_localisation_hotel)));
strcpy(rrate,gtk_entry_get_text(GTK_ENTRY(ag_entry_rate_hotel)));
strcpy(rprice,gtk_entry_get_text(GTK_ENTRY(ag_entry_price_hotel)));
strcpy(rcode,gtk_entry_get_text(GTK_ENTRY(ag_entry_code_hotel)));
ag_modifier_hotel(rnom,rlocalisation,rrate,rprice,rcode);



windowBienvenueagent=lookup_widget(objet_graphique,"windowBienvenueagent");
gtk_widget_destroy(windowBienvenueagent);
windowBienvenueagent=lookup_widget(objet_graphique,"windowBienvenueagent");
windowBienvenueagent=create_windowBienvenueagent();
gtk_widget_show(windowBienvenueagent);

ag_catalogue_hotel=lookup_widget(windowBienvenueagent,"ag_catalogue_hotel");
  affiche_hotel(ag_catalogue_hotel);
ag_catalogue_voiture=lookup_widget(windowBienvenueagent,"ag_catalogue_voiture");
  affiche_voiture(ag_catalogue_voiture);
ag_catalogue_vol=lookup_widget(windowBienvenueagent,"ag_catalogue_vol");
  affiche_vol(ag_catalogue_vol);

*/
}


void
on_supprimer_clicked                   (GtkWidget       *objet,
                                        gpointer         user_data)
{
 GtkTreeSelection *selection;
  GtkTreeModel     *model;
  GtkTreeIter       iter;
  GtkWidget         *view;

  view = gtk_tree_view_new();

  /* This will only work in single or browse selection mode! */

  selection = gtk_tree_view_get_selection(GTK_TREE_VIEW(view));
  if (1==1)
  {
    gchar *name;

    gtk_tree_model_get (model, &iter,EID, &name, -1);

   g_print ("selected row is: %s\n", name);
g_print ("selected row is");
   g_free(name);
//gtk_tree_selection_get_selected(selection, &model, &iter)
  }
  else
  {
    g_print ("no row selected.\n");
  }

}


void
on_update_clicked                      (GtkWidget       *objet,
                                        gpointer         user_data)
{

/*
char id[20],setedid[20]="my value";
int val;
GtkWidget *fenetre_modif,*fenetre_affiche,*idselect,*editid;
idselect=lookup_widget(objet,"idselect");
editid=lookup_widget(objet,"editid");
strcpy(setedid,gtk_entry_get_text(GTK_ENTRY(idselect)));

gtk_entry_set_text(GTK_ENTRY(editid),"myvalue");
gtk_entry_set_text(GTK_ENTRY(editid),"value");

g_print("%s",id);

g_print("%s",setedid);
recherchecapteur(id);
supprimercapteurbyid( id);




fenetre_affiche=lookup_widget(objet,"fenetre_affiche");
gtk_widget_destroy(fenetre_affiche);
fenetre_affiche=lookup_widget(objet,"fenetre_modif");
fenetre_modif=create_fenetre_modif();
gtk_widget_show(fenetre_modif);

*/


GtkWidget *editid;
GtkWidget *editnom;
GtkWidget *editvaleur;
GtkWidget *combobox2;
GtkWidget *spinbutton4;
GtkWidget *spinbutton5;
GtkWidget *spinbutton6;





char nom[20];
char type[20];
date da;
char valeur[20];
capteur c;

GtkWidget *fenetre_ajout,*fenetre_affiche;
int j,m,a;
char jour[20],mois[20],annee[20];
fenetre_ajout=lookup_widget(objet,"fenetre_modif");
editid=lookup_widget(objet,"editid");
editnom=lookup_widget(objet,"editnom");
editvaleur=lookup_widget(objet,"editvaleur");

spinbutton4=lookup_widget(objet,"spinbutton4");
spinbutton5=lookup_widget(objet,"spinbutton5");
spinbutton6=lookup_widget(objet,"spinbutton6");

combobox2=lookup_widget(objet,"combobox2");

strcpy(c.id,gtk_entry_get_text(GTK_ENTRY(editid)));
strcpy(c.nom,gtk_entry_get_text(GTK_ENTRY(editnom)));
strcpy(c.type,gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox2)));
j=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON(spinbutton4));
m=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON(spinbutton5));
a=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON(spinbutton6));

sprintf(jour,"%d\0",j);
sprintf(mois,"%d\0",m);
sprintf(annee,"%d\0",a);


strcpy(c.da.jour,jour);
strcpy(c.da.mois,mois);
strcpy(c.da.annee,annee);

//strcpy(c.DateAjout,gtk_entry_get_text(GTK_ENTRY(input4)));
strcpy(c.valeur,gtk_entry_get_text(GTK_ENTRY(editvaleur)));
//printf("%s",combobox2);

modifiercapteur(gtk_entry_get_text(GTK_ENTRY(editid)),c);

//////////////////////////////////////////////////////

fenetre_ajout=lookup_widget(objet,"fenetre_modif");
gtk_widget_destroy(fenetre_ajout);
fenetre_affiche=lookup_widget(objet,"fenetre_affiche");
fenetre_affiche=create_fenetre_affiche();
gtk_widget_show(fenetre_affiche);

}


void
on_etage1_toggled                      (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{

}


void
on_etage2_toggled                      (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{

}


void
on_etage3_toggled                      (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{

}


void
on_accepter_toggled                    (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{

}


void
on_treeview3_row_activated             (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{

}

