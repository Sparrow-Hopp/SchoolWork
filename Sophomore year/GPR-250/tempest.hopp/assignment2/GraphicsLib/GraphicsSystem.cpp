#include "GraphicsSystem.h"

GraphicsSystem::GraphicsSystem(int w, int h)
{
	Init(w, h);
}

GraphicsSystem::~GraphicsSystem()
{
	Cleanup();
}

void GraphicsSystem::Init(int w, int h)
{
	if (!al_init())
	{
		cout << "error initting Allegro\n";
	}
	if (!al_init_image_addon())
	{
		cout << "error - Image Add-on not initted\n";
	}
	if (!al_init_font_addon())
	{
		cout << "error - Font Add-on not initted\n";
	}
	if (!al_init_ttf_addon())
	{
		cout << "error - TTF Add-on not initted\n";
	}
	if (!al_init_primitives_addon())
	{
		cout << "error - primitives Add-on not initted\n";
	}
	if (!al_install_audio())
	{
		cout << "error - Audio Add-on not initted\n";
	}
	if (!al_init_acodec_addon())
	{
		cout << "error - Audio Codec Add-on not initted\n";
	}
	if (!al_reserve_samples(1))
	{
		cout << "error - samples not reserved\n";
	}
	mpDisplay = al_create_display(w, h);
	assert(mpDisplay);
	mpBuffer = new GraphicsBuffer(mpDisplay);
}

void GraphicsSystem::Cleanup()
{
	//delete mpBuffer;
	mpBuffer = NULL;

	al_uninstall_audio();
	al_shutdown_primitives_addon();
	al_shutdown_ttf_addon();
	al_shutdown_font_addon();
	al_shutdown_image_addon();
	al_destroy_display(mpDisplay);
	mpDisplay = NULL;
}

GraphicsBuffer* GraphicsSystem::getBuffer()
{
	return mpBuffer;
}

int GraphicsSystem::getWidth()
{
	return al_get_display_width(mpDisplay);
}

int GraphicsSystem::getHeight()
{
	return al_get_display_height(mpDisplay);
}

void GraphicsSystem::Flip()
{
	al_flip_display();
}

void GraphicsSystem::Draw(int locX, int locY, GraphicsBuffer* image, double scale)
{
	int sourceX = al_get_bitmap_x(image->mpBitmap);
	int sourceY = al_get_bitmap_y(image->mpBitmap);
	int width = image->getWidth();
	int height = image->getHeight();
	al_draw_scaled_bitmap(image->mpBitmap, sourceX, sourceY, width, height,
		locX, locY, width*scale, height*scale, 0);
}

void GraphicsSystem::Draw(GraphicsBuffer* targetbuffer, int locX, int locY, GraphicsBuffer* image, double scale)
{
	ALLEGRO_BITMAP* oldMap = al_get_target_bitmap();
	al_set_target_bitmap(targetbuffer->mpBitmap);
	int sourceX = al_get_bitmap_x(image->mpBitmap);
	int sourceY = al_get_bitmap_y(image->mpBitmap);
	int width = image->getWidth();
	int height = image->getHeight();
	al_draw_scaled_bitmap(image->mpBitmap, sourceX, sourceY, width, height,
		locX, locY, width * scale, height * scale, 0);
	al_set_target_bitmap(oldMap);
}

void GraphicsSystem::Draw(int locX, int locY, Sprite image, double scale)
{
	al_draw_bitmap_region(image.getBuffer()->mpBitmap, image.getSouceX(), image.getSourceY(), image.getWidth(), image.getHeight(), locX, locY, 0);
}

void GraphicsSystem::saveBuffer(GraphicsBuffer* savedBuffer, string fileName)
{
	al_save_bitmap(fileName.c_str(), savedBuffer->mpBitmap);
}

void GraphicsSystem::writeText(int locX, int locY, Font* font, Color color, string text)
{
	ALLEGRO_COLOR theColor = al_map_rgba(color.getRed(), color.getGreen(), color.getBlue(), color.getAlpha());
	al_draw_text(font->mFont, theColor, locX, locY, 0, text.c_str());
}

void GraphicsSystem::writeText(GraphicsBuffer* targetBuffer, int locX, int locY, Font* font, Color color, string text)
{
	ALLEGRO_BITMAP* oldMap = al_get_target_bitmap();
	ALLEGRO_COLOR theColor = al_map_rgba(color.getRed(), color.getGreen(), color.getBlue(), color.getAlpha());
	al_set_target_bitmap(targetBuffer->mpBitmap);
	al_draw_text(font->mFont, theColor, locX, locY, 0, text.c_str());
	al_set_target_bitmap(oldMap);
}
