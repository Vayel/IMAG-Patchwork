#include <stdlib.h>
#include <stdio.h>
#include "ast.h"

/*---------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------*/

/* fonctions de "confort" pour alleger (?) la syntaxe de creation d'un noeud */
static struct noeud_ast *valeur(const enum nature_primitif nat_prim)
{
	/*** TODO: A COMPLETER (facultatif) ***/
}

static struct noeud_ast *rotation(struct noeud_ast *opde)
{
	/*** TODO: A COMPLETER (facultatif) ***/
}

static struct noeud_ast *juxtaposition(struct noeud_ast *opde_gauche,
				       struct noeud_ast *opde_droit)
{
	/*** TODO: A COMPLETER (facultatif) ***/
}

static struct noeud_ast *superposition(struct noeud_ast *opde_gauche,
				       struct noeud_ast *opde_droit)
{
	/*** TODO: A COMPLETER (facultatif) ***/
}


/*---------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------*/

int main(int argc, char **argv)
{
  struct patchwork *pw_carre = creer_primitif(CARRE);
  struct patchwork *pw_triangle = creer_primitif(TRIANGLE);
  struct patchwork *pw_rot = creer_rotation(pw_carre);
  struct patchwork *pw_jux = creer_juxtaposition(pw_carre, pw_triangle);
  struct patchwork *pw_sup = creer_superposition(pw_carre, pw_triangle);

  liberer_patchwork(pw_carre);
  liberer_patchwork(pw_triangle);
  liberer_patchwork(pw_rot);
  liberer_patchwork(pw_jux);
  liberer_patchwork(pw_sup);

  return EXIT_SUCCESS;
}
