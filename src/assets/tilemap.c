#include "tilemap.h"

#include <stdio.h>
#include <stdlib.h>

#include "../macro.h"


struct Tilemap *Tilemap_new(const char *p_TextPath, int p_TileW, int p_TileH)
{
	struct Tilemap *newTilemap = (struct Tilemap *) malloc(
		sizeof(struct Tilemap));

	if (newTilemap) {
		newTilemap->text = LoadTexture(p_TextPath);;

		newTilemap->tileDim = (Vector2) { p_TileW, p_TileH };
		newTilemap->tilesInRow = newTilemap->text.width / p_TileW;

		newTilemap->tileAmount = (int) (newTilemap->text.width /
			p_TileW) * (int) (newTilemap->text.height / p_TileH);
	}

	return newTilemap;
}

void Tilemap_del(struct Tilemap *p_Tilemap)
{
	UnloadTexture(p_Tilemap->text);
	free(p_Tilemap);
}

void Tilemap_renderTile(struct Tilemap *p_Tilemap, short p_Img, Vector2 p_Pos,
	float p_Scale)
{
	Rectangle tileRec = {
		(int) (p_Img % p_Tilemap->tilesInRow) * p_Tilemap->tileDim.x,
		(int) (p_Img / p_Tilemap->tilesInRow) * p_Tilemap->tileDim.y,
		p_Tilemap->tileDim.x, p_Tilemap->tileDim.y};

	Rectangle dest = { p_Pos.x * p_Scale, p_Pos.y * p_Scale,
		p_Scale, p_Scale };
	Vector2 source = { p_Scale * .5f, p_Scale * .5f };

	DrawTexturePro(p_Tilemap->text, tileRec, dest, source, 0.f, WHITE);
}

void Tilemap_renderTileScreen(struct Tilemap *p_Tilemap, short p_Img,
	Vector2 p_Pos, float p_Scale)
{
	Rectangle tileRec = {
		(int) (p_Img % p_Tilemap->tilesInRow) * p_Tilemap->tileDim.x,
		(int) (p_Img / p_Tilemap->tilesInRow) * p_Tilemap->tileDim.y,
		p_Tilemap->tileDim.x, p_Tilemap->tileDim.y};

	Rectangle dest = { p_Pos.x, p_Pos.y, p_Scale, p_Scale };
	Vector2 source = { p_Scale * .5f, p_Scale * .5f };

	DrawTexturePro(p_Tilemap->text, tileRec, dest, source, 0.f, WHITE);
}
