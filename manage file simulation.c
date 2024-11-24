#include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef struct fichier{
char nomf[20];
int id;
char emplacement[20];
char etat[8] ;
}fichier;

int i=0;
fichier T[100];

int recherche(char nomf[],int id){
int j=0;
for (j=0;j<=i;j++){
if (strcmp(T[j].nomf,nomf)==0 && T[j].id==id)
return 1;
}
return 0;
}

fichier ajout(char nomf[],int id ,char etat[]){
int search;
search=recherche(nomf,id);
if(search==1){
printf("le fichier deja existe\n");
}
else{
char *str1="@";
char buffer[100];
strcpy(T[i].nomf,nomf);
strcpy(T[i].etat,etat);
strcpy(T[i].emplacement,strcat(strcpy(buffer,str1),T[i].nomf));
T[i].id=id;
i++;
}
}

void changement(int id ,char nomf[],char nvnom[]){
int j=0;
for (j=0;j<=i;j++){
if(strcmp(T[j].nomf,nomf)==0 && T[j].id==id){
strcpy(T[j].nomf,nvnom);
return;
}
}
}

int partage(char nomf[],int id){
int j=0;
for (j=0;j<=i;j++){
if(strcmp(T[j].nomf,nomf)==0 && T[j].id==id){
if(strcmp(T[j].etat,"public")==0)
return 0;
else
strcpy(T[j].etat,"public");
return 1;
}
}
}

int retraitpartage(char nomf[],int id){
int j=0;
for (j=0;j<=i;j++){
if(strcmp(T[j].nomf,nomf)==0 && T[j].id==id){
if(strcmp(T[j].etat,"prive")==0)
return 0;
else
strcpy(T[j].etat,"prive");
return 1;
}
}
}

void afficher(fichier T[],int id){
int j=0;
for (j=0;j<=i;j++){
if(T[j].id==id){
printf("\nle nom de fichier : %s\n",T[j].nomf);
printf("\n\n");
}
}
}

int suppression(int id, char nomf[]){
int j;
for (j=0;j<=i;j++){
if(strcmp(T[j].nomf,nomf)==0 && T[j].id==id){
for (j=j;j<=i;j++){
T[j].id=T[j+1].id;
strcpy(T[j].emplacement,T[j+1].emplacement);
strcpy(T[j].etat,T[j+1].etat);
strcpy(T[j].nomf,T[j+1].nomf);
}
i=i-1;
return 1;
}
}
}

main(){
int choix=0;
int id,test;
char nomf[20];
char nvnom[20];
char etat[8];
       

while(1){
system("cls");
printf(" 1-la recherche d'un fichier\n");
        printf(" 2-l'ajout d'un fichier\n");
        printf(" 3-changement de nom d'un fichier\n");
        printf(" 4-la supression d'un fichier\n");
        printf(" 5-le partage d'un fichier\n");
        printf(" 6-le retrait de partage d'un fichier\n");
        printf(" 7-l'affichage de la liste des fichier\n");
        printf(" 8-quitter\n");
printf("\nenter votre choix : ");
scanf("%d",&choix);
switch (choix){
case 1:
   printf("donner le id d'utilisateur : ");
   scanf("%d",&id);
   printf("donner le nom de fichier : ");
   scanf("%s",nomf);
   test=recherche(nomf,id);
   if(test==1)
                    printf("fichier trouve\n");
                else
printf("fichier non existe\n");
break;
case 2:
printf("donner le id : ");
scanf("%d",&id);
printf("donner le nom de fichier : ");
scanf("%s",nomf);
printf("donner l'etat de partage (public/prive) : ");
scanf("%s",etat);
ajout(nomf,id,etat);
break;
            case 3:
            printf("donner le id d'utilisateur : ");
   scanf("%d",&id);
   printf("donner le nom de fichier : ");
   scanf("%s",nomf);
   printf("donner le nouveau nom de fichier : ");
   scanf("%s",nvnom);
            changement(id,nomf,nvnom);
            break;
case 4:
printf("donner le id d'utilisateur : ");
   scanf("%d",&id);
   printf("donner le nom de fichier a supprime : ");
   scanf("%s",nomf);
test=suppression(id,nomf);
if(test==1)
printf("le fichier est supprime");
else
printf("le fichier n'existe pas");
break;          
case 5:
printf("donner le id d'utilisateur : ");
   scanf("%d",&id);
   printf("donner le nom de fichier a partage : ");
   scanf("%s",nomf);
test=partage(nomf,id);
if(test==1)
printf("le fichier est partage");
if(test==0)
printf("le fichier est deja public");
break;
case 6:
printf("donner le id d'utilisateur : ");
   scanf("%d",&id);
   printf("donner le nom de fichier a retrait le partage : ");
   scanf("%s",nomf);
   test=retraitpartage(nomf,id);
   if(test==1)
printf("le partage est retre");
if(test==0)
printf("le fichier est deja prive");
   break;
case 7:
printf("donner le id d'utilisateur : ");
   scanf("%d",&id);
   afficher(T,id);
   break;
case 8:
exit(1);
break;
}
}while(1);
}
