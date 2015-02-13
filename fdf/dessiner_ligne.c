void		dessiner_ligne(t_env *env, t_vecteur2 a, t_vecteur2 b, int couleur)
{
	int				deltaX;
	int				deltaY;
	unsigned int	nb_pixels;
	float			deltaX_pixel;
	float			deltaY_pixel;
	float			pixel_x;
	float			pixel_y;
	unsigned int	i;

	deltaX = b.x - a.x;
	deltaY = b.y - a.y;
	nb_pixels = (unsigned int)fmax(fabs(deltaX), fabs(deltaY));
	deltaX_pixel = (float)deltaX / nb_pixels;
	deltaY_pixel = (float)deltaY / nb_pixels;
	i = 1;
	pixel_x = a.x;
	pixel_y = a.y;
	while (i++ < nb_pixels)
	{
		dessiner_pixel(env, ceil(pixel_x), ceil(pixel_y), couleur);
		pixel_x = pixel_x + deltaX_pixel;
		pixel_y = pixel_y + deltaY_pixel;
	}
	dessiner_pixel(env, b.x, b.y, couleur);
}
