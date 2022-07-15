#include <raylib.h>
#include <string.h>
#include <vector>
#include <string>

struct BlankItem { float width; };
struct TextItem { Font font; char * str; int height; int spacing; };
struct ImageItem { Texture texture; Rectangle quad; int height; };

union ItemData {
	BlankItem blank;
	TextItem text;
	ImageItem img;
};

enum ItemType {
	BLANKITEM,
	TEXTITEM,
	IMAGEITEM
};

struct Item {
	ItemData data;
	ItemType type;

	bool hide;

	Item(const char * text, int height, int spacing);
};

struct bar {
	std::vector<Item*> items;
	int height;

	bar(int h);

	void add(Item * item);
};

void render_bar(const bar& b, int x, int y);


Item::Item(const char * t, int h, int s)
{
	type = TEXTITEM;

	data.text.str = new char[150];
	strcpy(data.text.str, t);

	data.text.font = GetFontDefault();
	data.text.height = h;
	data.text.spacing = s;
}

bar::bar(int h) : items(), height(h) {}
void bar::add(Item * item)
{
	items.push_back(item);
}

void render_bar(const bar& b, int x, int y) 
{

	int sx = x;
	for (Item* item : b.items) 
	{
		if (item->type == TEXTITEM) 
		{
			TextItem& text_it = (TextItem&)item->data;
			DrawTextEx(text_it.font, text_it.str, (Vector2){sx, y}, text_it.height, text_it.spacing, WHITE);
			sx += MeasureTextEx(text_it.font, text_it.str, text_it.height, text_it.spacing).x;
			break;
		}
	}
}