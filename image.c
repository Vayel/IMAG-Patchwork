#include <stdint.h>
#include "image.h"

uint16_t largeur_ppm(FILE *fichier)
{
}

void creer_image(const struct patchwork *patch, const char *fichier_ppm_carre,
                 const char *fichier_ppm_triangle, FILE *fichier_sortie)
{
  FILE *f_prim;
  f_prim = fopen(fichier_ppm_carre, 'r');
  uint16_t largeur_prim = largeur_ppm(f_prim);
  fclose(f_prim);

  // En-tete, en ASCII
  fprintf(fichier_sortie, "P6\n");
  fprintf(fichier_sortie, "%d", patch->largeur * largeur_prim);
  fprintf(fichier_sortie, " ");
  fprintf(fichier_sortie, "%d", patch->hauteur * largeur_prim);
  fprintf(fichier_sortie, "\n255\n");

  // Pixels, en binaire
  /*
  uint64_t area = size_x * size_y;
  uint32_t px;
  uint8_t r, g, b;

  for (uint64_t i = 0; i < area; i++) {
      px = pic[i];
      r = get_r(px);
      g = get_g(px);
      b = get_b(px);
      
      fwrite(&r, sizeof(uint8_t), 1, f);
      fwrite(&g, sizeof(uint8_t), 1, f);
      fwrite(&b, sizeof(uint8_t), 1, f);
  }
  */
}
