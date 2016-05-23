#include <stdlib.h>
#include <stdint.h>
#include "patchwork.h"

struct primitif **init_primitifs(uint16_t h, uint16_t l)
{
  struct primitif **prims = calloc(h, sizeof(struct primitif *));

  for (uint16_t i = 0; i < h; i++) {
    prims[i] = calloc(l, sizeof(struct primitif));
  }

  return prims;
}

struct patchwork *init_patchwork(uint16_t h, uint16_t l)
{
  struct patchwork *pw = malloc(sizeof(struct patchwork));
  pw->hauteur = h;
  pw->largeur = l;

  struct primitif **prims = init_primitifs(h, l);
  pw->primitifs = prims;

  return pw;
}

// precond: nat ok, verifiee a la construction
struct patchwork *creer_primitif(const enum nature_primitif nat)
{
  struct patchwork *pw = init_patchwork(1, 1);

  struct primitif prim = {
    .nature = nat,
    .orientation = EST
  };
  pw->primitifs[0][0] = prim;

  return pw;
}


// precond: p valide
struct patchwork *creer_rotation(const struct patchwork *p)
{	
  // On inverse les dimensions car la rotation est de 90°
  struct patchwork *pw_rot = init_patchwork(p->largeur, p->hauteur);

  for (uint16_t i = 0; i < p->hauteur; i++) {
    for (uint16_t j = 0; j < p->largeur; j++) {
      pw_rot->primitifs[j][p->hauteur - i - 1] = p->primitifs[i][j];
    }
  }

  return pw_rot;
}


// precond: p_g et p_d valides
struct patchwork *creer_juxtaposition(const struct patchwork *p_g,
				      const struct patchwork *p_d)
{
  if (p_g->hauteur != p_d->hauteur) return NULL;
  
  struct patchwork *pw_jux = init_patchwork(p_g->hauteur, p_g->largeur + p_d->largeur);

  for (uint16_t i = 0; i < p_g->hauteur; i++) {
    for (uint16_t j = 0; j < p_g->largeur; j++) {
      pw_jux->primitifs[i][j] = p_g->primitifs[i][j];
    }
    for (uint16_t j = 0; j < p_d->largeur; j++) {
      pw_jux->primitifs[i][p_g->largeur + j] = p_g->primitifs[i][j];
    }
  }

  return pw_jux;
}


// precond: p_h et p_b valides
struct patchwork *creer_superposition(const struct patchwork *p_h,
                                      const struct patchwork *p_b)
{
	if (p_h->largeur != p_b->largeur) return NULL;
  
  struct patchwork *pw_sup = init_patchwork(p_h->hauteur + p_b->hauteur, p_h->largeur);

  for (uint16_t j = 0; j < p_h->largeur; j++) {
    for (uint16_t i = 0; i < p_h->hauteur; i++) {
      pw_sup->primitifs[i][j] = p_h->primitifs[i][j];
    }
    for (uint16_t i = 0; i < p_b->hauteur; i++) {
      pw_sup->primitifs[p_h->hauteur + i][j] = p_b->primitifs[i][j];
    }
  }

  return pw_sup;

}


void liberer_patchwork(struct patchwork *patch)
{
  for (uint16_t i = 0; i < patch->hauteur; i++) {
    free(patch->primitifs[i]);
  }
  
  free(patch->primitifs);
  free(patch);
}
