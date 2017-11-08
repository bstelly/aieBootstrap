#include "Application2D.h"
#include "Texture.h"
#include "Font.h"
#include "Input.h"
#include "PacGuy.h"

Application2D::Application2D() {

}

Application2D::~Application2D() {

}

bool Application2D::startup() {
	
	m_2dRenderer = new aie::Renderer2D();

	m_texture = new aie::Texture("./textures/numbered_grid.tga");
	m_shipTexture = new aie::Texture("./textures/ship.png");

	m_font = new aie::Font("./font/consolas.ttf", 32);
	
	m_cameraX = 0;
	m_cameraY = 0;
	m_timer = 0;
	mPx = 500;
	mPy = 500;
	return true;
}

void Application2D::shutdown() {
	
	delete m_font;
	delete m_texture;
	delete m_shipTexture;
	delete m_2dRenderer;
}

void Application2D::update(float deltaTime) {

	m_timer += deltaTime;

	// input example
	aie::Input* input = aie::Input::getInstance();

	// use arrow keys to move camera
	if (input->isKeyDown(aie::INPUT_KEY_W))
		mPy += 1550.0f * deltaTime;

	if (input->isKeyDown(aie::INPUT_KEY_S))
		mPy -= 1550.0f * deltaTime;

	if (input->isKeyDown(aie::INPUT_KEY_A))
		mPx -= 1550.0f * deltaTime;

	if (input->isKeyDown(aie::INPUT_KEY_D))
		mPx += 1550.0f * deltaTime;

	//if (input->isKeyDown(aie::INPUT_KEY_SPACE)
	//	//SHOOT PROJECTILE

	// exit the application
	if (input->isKeyDown(aie::INPUT_KEY_ESCAPE))
		quit();

	// stops player from going off of the screen
	if (mPx > 1280 - 15)
	{
		mPx = 1280 - 15;
	}
	if ((mPx - 15) < 0)
	{
		mPx = 15;
	}
	if (mPy > 720 - 15)
	{
		mPy = 720 - 15;
	}
	if ((mPy - 15) < 0)
	{
		mPy = 15;
	}

}

void Application2D::draw() {

	// wipe the screen to the background colour
	clearScreen();

	// set the camera position before we begin rendering
	m_2dRenderer->setCameraPos(m_cameraX, m_cameraY);

	// begin drawing sprites
	m_2dRenderer->begin();

	PacGuy pacGuy(mPx, mPy);
	if (pacGuy.GetX() == 500 && pacGuy.GetY() == 600)
	{
		quit();
	}
	m_2dRenderer->setRenderColour(1, 1, 0, 1);
	m_2dRenderer->drawCircle(mPx, mPy, 15);

	// output some text, uses the last used colour
	char fps[32];
	sprintf_s(fps, 32, "FPS: %i", getFPS());
	m_2dRenderer->drawText(m_font, fps, 0, 720 - 32);
	m_2dRenderer->drawText(m_font, "Press ESC to quit!", 0, 720 - 64);

	// done drawing sprites
	m_2dRenderer->end();
}