#include <stdlib.h>


#define TILEPICKER_MARGIN_X 0
#define TILEPICKER_MARGIN_Y 34
#define TILEPICKER_WIDTH 46
#define TILEPICKER_HEIGHT 0

#define TILEPICKER_TILE_SIZE 32
#define TILEPICKER_TILE_MARGIN 10


struct TilePicker {
	struct Tilemap *tilemap;
	short picked;
};


struct TilePicker *TilePicker_new(struct Tilemap *tilemap);
void TilePicker_del(struct TilePicker *tilePicker);

void TilePicker_render(struct TilePicker *tilePicker);
