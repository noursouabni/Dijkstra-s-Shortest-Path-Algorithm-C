
#include <stdlib.h>
#include <stdio.h>
#include "LSTPRIM.H"
LISTE listeCreer(void) {
LISTE L;
L=(LISTE)malloc(sizeof(laStruct));
if (! L)
printf("\nProblème de mémoire");
else {
L->lg = 0;
L->tete = NULL;
}
return(L);
}
void listeDetruire(LISTE L){
int i;
Node p, q;
q= L->tete;
for(i = 1;i <= L->lg; i++)
{
p=q;
q=q->next;
noeudDetruire(p);
}
free(L);
}
void listeAfficher(LISTE L){
int i=1;
Node p;
p= L->tete;
for(i = 1;i <= L->lg; i++) {
elementAfficher(p->info);
p= p->next;
}}
LISTE listeCopier(LISTE L){
LISTE LR = listeCreer();
int i;
ELEMENT elt;
for(i = 1;i <= L->lg; i++) {
elt=elementCreer();
elementCopier(&elt, recuperer(L,i));
inserer(LR,elt, i);
}
return LR;
}
int listeComparer (LISTE L1,LISTE L2 )
{
int test= 1;
int i=1;
if (listeTaille(L1) != listeTaille(L2)) test= 0;
while ((i<=listeTaille(L1)) && (test)) {
if
(elementComparer(recuperer(L1,i),recuperer(L2,i))!=0)
test=0;
i++;
}
return test;}
int estVide(LISTE L) {
return (L->lg == 0);
}
int estSaturee(LISTE L) {
Node temp;
int saturee = 1;
temp = (NŒUD) malloc ( sizeof ( structNoeud ) );
if(temp != NULL) {
saturee = 0;
free(temp);
}
return saturee;
}
int listeTaille(LISTE L) {
return (L->lg);
}
int inserer (LISTE L, ELEMENT e, int pos){
int succee=1;
int i;
Node n, p, q;
if (estSaturee(L)){
printf ("\nListe saturée");
succee=0;}
else {
if ((pos < 1) || (pos > L->lg + 1)) {
printf ("\nPosition invalide");
succee=0;
}
else {
n=noeudCreer (e);
if (pos == 1)
{
n->next=L->tete;
L->tete = n;
}
else
{
q= L->tete;
for (i=1; i<pos; i++) {

p = q;
q = q->next;
}
p->next=n;
n->next=q;
}
(L->lg)++;
}
}
return succee;}
int supprimer (LISTE L, int pos ){
int i;
int succee=1;
Node p, q;
if (estVide(L)) {
printf ("\nListe vide");
succee=0;
}
else {
if ((pos < 1) || (pos > L->lg))
{
printf ("\nPosition invalide");
succee=0;
}
else
{
q = L->tete;
if (pos == 1)
L->tete=L->tete->next;
else {
for (i=1; i<pos; i++) {
p = q;
q = q->next;
}
p->next=q->next;
}
noeudDetruire(q);
(L->lg)--;
}}
return succee;
}
ELEMENT recuperer(LISTE L, int pos) {
ELEMENT elt= elementCreer();
int i;
Node p;
if (estVide(L))
printf ("\nListe vide");
else {
if ((pos < 1) || (pos > L->lg))
printf ("\nPosition invalide");
else {
p= L->tete;
for (i=1; i<pos; i++)
p = p->next;
elementAffecter(&elt,p->info);
}}
return(elt);
}
