#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <gtk/gtk.h>
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

///////////////////////ajouter capteur//////////////////////////


void ajoutercapteur(capteur c){
FILE *f;
f=fopen("/home/youssef/Bureau/projet_edit_add/projetc/src/capteur.txt","a");
if (f!= NULL){

    fprintf(f,"%s %s %s %s %s %s %s\n",c.id,c.nom,c.type,c.da.jour,c.da.mois,c.da.annee,c.valeur);
}
fclose(f);
}



//////////////////afficher capteur ////////////////////////////

void affichercapteur(GtkWidget *liste)
{
   GtkCellRenderer *renderer; 

   GtkTreeViewColumn *column;

   GtkTreeIter iter;

   GtkListStore *store;
   capteur c;
   date da;
char id[20];
char nom[20];
char type[20];
char jour [20];
char mois [20];
char annee [20];
char valeur[20];
store=NULL;
FILE *f;
   store = gtk_tree_view_get_model(liste);

if(store==NULL)
{
renderer = gtk_cell_renderer_text_new ();  
column = gtk_tree_view_column_new_with_attributes("id", renderer, "text",EID, NULL); 
gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);
renderer = gtk_cell_renderer_text_new ();  
column = gtk_tree_view_column_new_with_attributes("nom", renderer, "text",ENOM, NULL); 
gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);
renderer = gtk_cell_renderer_text_new ();  
column = gtk_tree_view_column_new_with_attributes("type", renderer, "text",ETYPE, NULL); 
gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);
renderer = gtk_cell_renderer_text_new ();  
column = gtk_tree_view_column_new_with_attributes("jour", renderer, "text",EJOUR, NULL); 
gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

renderer = gtk_cell_renderer_text_new ();  
column = gtk_tree_view_column_new_with_attributes("mois", renderer, "text",EMOIS, NULL); 
gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);
renderer = gtk_cell_renderer_text_new ();  
column = gtk_tree_view_column_new_with_attributes("annee", renderer, "text",EANNEE, NULL); 
gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

renderer = gtk_cell_renderer_text_new ();  
column = gtk_tree_view_column_new_with_attributes("valeur", renderer, "text",EVALEUR, NULL); 
gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);
}
store=gtk_list_store_new (COLUMNS, G_TYPE_STRING, G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING);

f=fopen("/home/youssef/Bureau/projet_edit_add/projetc/src/capteur.txt", "r"); 

  if(f==NULL)
   {
  return;
   }
  else
  { 
f = fopen("/home/youssef/Bureau/projet_edit_add/projetc/src/capteur.txt", "a+");
       while(fscanf(f,"%s %s %s %s %s %s %s\n",id,nom,type,jour,mois,annee,valeur)!= EOF)
    {
 GtkTreeIter iter;
 gtk_list_store_append (store, &iter);

  gtk_list_store_set (store, &iter,EID,id,ENOM,nom,ETYPE,type,EJOUR,jour,EMOIS,mois,EANNEE,annee,EVALEUR,valeur,-1);
    }
    fclose(f);
  gtk_tree_view_set_model (GTK_TREE_VIEW (liste), GTK_TREE_MODEL (store)); 
  
g_object_unref (store);


}
}

//////////////////////supprimer capteur ///////////////////////////
void supprimercapteur(capteur c)
{ 
capteur c1;
date da ;
  FILE *f,*g;
 f=fopen("capteur.txt","r");
 g=fopen("new_capteur.txt","w");
if(f==NULL || g==NULL)
return;
else {
 
while (fscanf(f,"%s %s %s %s %s %s %s\n",c1.id,c1.nom,c1.type,c1.da.jour,c1.da.mois,c1.da.annee,c1.valeur)!=EOF)
   {
   if (strcmp(c.id,c1.id)!=0)

fprintf(g,"%s %s %s %s %s %s %s\n",c1.id,c1.nom,c1.type,c1.da.jour,c1.da.mois,c1.da.annee,c1.valeur); 
}
fclose(f);
fclose(g);
remove("capteur.txt");
rename("new_capteur.txt","capteur.txt");
}
}




////////////////// modifier capteur ////////////////////////

void modifiercapteur(char  id1[20],capteur c){
char id[20];
char nom[20];
char type[20];
char jour[20];
char mois[20];
char annee[20];
char valeur[20];
date da;
FILE *f;
FILE *f1;
f=fopen("/home/youssef/Bureau/projet_edit_add/projetc/src/capteur.txt","r");
f1=fopen("/home/youssef/Bureau/projet_edit_add/projetc/src/capteur1.txt","w");

fprintf(f1,"%s %s %s %s %s %s %s\n",c.id,c.nom,c.type,c.da.jour,c.da.mois,c.da.annee,c.valeur);


//if(!f1)exit(-1);

while (fscanf(f,"%s %s %s %s %s %s %s \n",id,nom,type,jour,mois,annee,valeur)!=EOF){

g_print(c.id);
g_print(id);
    if(!strcmp(id,c.id))
        {

printf("diff");
continue;}

    else{
        fprintf(f1,"%s %s %s %s %s %s %s \n",id,nom,type,jour,mois,annee,valeur);
    }
}
fclose(f);
fclose(f1);
remove("/home/youssef/Bureau/projet_edit_add/projetc/src/capteur.txt");
rename("/home/youssef/Bureau/projet_edit_add/projetc/src/capteur1.txt","/home/youssef/Bureau/projet_edit_add/projetc/src/capteur.txt");
}

////////////////////////////////////////////////////////////////
void recherchecapteur(char id[]){
/*capteur c;
date da;
FILE *f,*f1=NULL;
f=fopen("capteur.txt","r");
f1=fopen("capteurtempo.txt","w");
while(fscanf(f,"%s %s %s %s %s %s %s\n",c.id,c.nom,c.type,c.da.jour,c.da.mois,c.da.annee,c.valeur)!=EOF){
//g_print(strcmp(id,c.id));
if(strcmp(id,c.id)){
continue;
}
else{
g_print(f,"%s %s %s %s %s %s %s\n",c.id,c.nom,c.type,c.da.jour,c.da.mois,c.da.annee,c.valeur);
fprintf(f1,"%s %s %s %s %s %s %s\n",c.id,c.nom,c.type,c.da.jour,c.da.mois,c.da.annee,c.valeur);
break;
 
}
}
fclose(f);
fclose(f1);*/

}
///////////////////////////////////////////////////////////////////////////

void supprimercapteurbyid(char id[20])
{ 

capteur c;
  FILE *f,*f1;

f=fopen("capteur.txt","r");
f1=fopen("capteur1.txt","w");
  
while (fscanf(f,"%s %s %s %s %s %s %s\n",c.id,c.nom,c.type,c.da.jour,c.da.mois,c.da.annee,c.valeur)!=EOF)
   {
   if (!strcmp(id,c.id))
 {continue;}
else {fprintf(f1,"%s %s %s %s %s %s %s\n",c.id,c.nom,c.type,c.da.jour,c.da.mois,c.da.annee,c.valeur);
   
        }
        }
fclose(f);
fclose(f1);

remove("capteur.txt");
rename("capteur1.txt","capteur.txt");
}


/////////////////////////////////////////////////
/*
int ah_tab_capteur(capteur tab[200])
{int n=0;
FILE *g;
g=fopen("capteur.txt","r");
if (g!=NULL)
{while(fscanf(f,"%s %s %s %s %s %s %s\n",&tab[n].id,tab[n].nom,tab[n].type,tab[n].da.jour,tab[n].da.mois,tab[n].da.annee,tab[n].valeur)!=EOF)
{n++;}
fclose(g);}
return n;
}

*/

