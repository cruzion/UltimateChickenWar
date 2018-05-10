#include "Popup.h"

Popup::Popup(std::string str,int h, int w) {
	text = str;
	src.x = 0;// 559;
	src.y = 0;// 345;
	src.h = 210;
	src.w = 610;

	dest.h = 210;
	dest.w = 610;
	dest.x = 500;//1169;
	dest.y = 225;//555;
	
	height = h;
	width = w;
};
Popup::~Popup(){
	SDL_DestroyTexture(box);
	gTextTexture.free(); };
void Popup::draw() {
	box = TextureManager::LoadTexture("assets/button/box.png");
	TextureManager::Draw(box, src, dest);
	//Open the font
	UCW::gFont = TTF_OpenFont("pixelFJ8pt1__.ttf", 60);
	//Render text
	SDL_Color textColor = { 0, 0, 0 };
	gTextTexture.loadFromRenderedText(text, textColor);
	gTextTexture.render((width - gTextTexture.getWidth()) / 2, (height- gTextTexture.getHeight()) / 2);
};
void Popup::clean() {
	gTextTexture.free();
}