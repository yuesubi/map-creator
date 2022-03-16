
struct Tile {
	unsigned int x, y;
	short img;
	int id;
};


struct Tile *Tile_new(unsigned int x, unsigned int y, short imageId);
void Tile_del(struct Tile *tile);
