#include "tile.h"

#include <stdio.h>
#include <stdlib.h>


struct Tile *Tile_new(unsigned int p_X, unsigned int p_Y, short p_Img)
{
	struct Tile *newTile = (struct Tile *) malloc(sizeof(struct Tile));

	if (newTile) {
		newTile->x   = p_X;
		newTile->y   = p_Y;
		newTile->img = p_Img;
	}

	return newTile;
}

void Tile_del(struct Tile *p_Tile)
{
	free(p_Tile);
}
