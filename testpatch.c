#include <stdlib.h>
#include <stdio.h>
#include "ast.h"
#include "patchwork.h"
#include "image.h"

/*---------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------*/

/* fonctions de "confort" pour alleger (?) la syntaxe de creation d'un noeud */
static struct noeud_ast *valeur(const enum nature_primitif nat_prim)
{
  return creer_valeur(nat_prim);
}

static struct noeud_ast *rotation(struct noeud_ast *opde)
{
  return creer_unaire(ROTATION, opde);
}

static struct noeud_ast *juxtaposition(struct noeud_ast *opde_gauche,
				       struct noeud_ast *opde_droit)
{
  return creer_binaire(JUXTAPOSITION, opde_gauche, opde_droit);
}

static struct noeud_ast *superposition(struct noeud_ast *opde_gauche,
				       struct noeud_ast *opde_droit)
{
  return creer_binaire(SUPERPOSITION, opde_gauche, opde_droit);
}


/*---------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------*/

int main(int argc, char **argv)
{
  // AST
  struct noeud_ast *noeud_prim = creer_valeur(CARRE);
  struct noeud_ast *noeud_rot = creer_unaire(ROTATION, noeud_prim);
  
  struct noeud_ast *noeud_prim_carre = creer_valeur(CARRE);
  struct noeud_ast *noeud_prim_triangle = creer_valeur(TRIANGLE);
  struct noeud_ast *noeud_jux = creer_binaire(JUXTAPOSITION, noeud_prim_carre,
                                              noeud_prim_triangle);

  liberer_expression(noeud_rot);
  liberer_expression(noeud_jux);

  // Patchwork
  char *fichier_carre = "motifs/carre_64.ppm";
  char *fichier_triangle = "motifs/triangle_64.ppm";

  struct patchwork *pw_carre = creer_primitif(CARRE);
  struct patchwork *pw_triangle = creer_primitif(TRIANGLE);
  struct patchwork *pw_rot = creer_rotation(pw_carre);
  struct patchwork *pw_jux = creer_juxtaposition(pw_carre, pw_triangle);
  struct patchwork *pw_sup = creer_superposition(pw_carre, pw_triangle);

  FILE *fichier_sortie;
  fichier_sortie = fopen("test.ppm", "w");
  creer_image(pw_carre, fichier_carre, fichier_triangle, fichier_sortie); 
  fclose(fichier_sortie);

  liberer_patchwork(pw_carre);
  liberer_patchwork(pw_triangle);
  liberer_patchwork(pw_rot);
  liberer_patchwork(pw_jux);
  liberer_patchwork(pw_sup);

  return EXIT_SUCCESS;
}
