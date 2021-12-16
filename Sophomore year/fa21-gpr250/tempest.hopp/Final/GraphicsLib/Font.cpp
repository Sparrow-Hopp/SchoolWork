#include "Font.h"
#include "Font.h"
#include <cassert>

using namespace std;

Font::Font(const std::string& filename, int size)
	:mSize(size)
{
	mpSmallFont = al_load_font(filename.c_str(), size, 0);
	assert(mpSmallFont);
}

Font::~Font()
{
	al_destroy_font(mpSmallFont);
}
