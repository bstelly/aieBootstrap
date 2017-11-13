#include "Application2D.h"
#include "Texture.h"
#include "Font.h"
#include "Input.h"
#include "PacGuy.h"
#include "Wall.h"	
#include <Vector2.h>
#include <iostream>
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
	mPlayer = new PacGuy();
	mVerticalWall = new Wall[1280 * 720];
	mHorizontalWall = new Wall[1280 * 720];
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
	Vector2 moveUp(0, (1000 * deltaTime));
	Vector2 moveDown(0, (-1000 * deltaTime));
	Vector2 moveLeft((-1000 * deltaTime), 0);
	Vector2 moveRight((1000 * deltaTime), 0);
	Vector2 hitVerticalWall(-5, 0);

	mVerticalWall[0].SetPosition(640, 360);
	mVerticalWall[1].SetPosition(500, 500);

	// input example
	aie::Input* input = aie::Input::getInstance();

	// use arrow keys to move camera
	if (input->isKeyDown(aie::INPUT_KEY_W))
		mPlayer->ChangePos(moveUp);

	if (input->isKeyDown(aie::INPUT_KEY_S))
		mPlayer->ChangePos(moveDown);

	if (input->isKeyDown(aie::INPUT_KEY_A))
		mPlayer->ChangePos(moveLeft);

	if (input->isKeyDown(aie::INPUT_KEY_D))
		mPlayer->ChangePos(moveRight);

	//if (input->isKeyDown(aie::INPUT_KEY_SPACE)
	//	//SHOOT PROJECTILE

	// exit the application
	if (input->isKeyDown(aie::INPUT_KEY_ESCAPE))
		quit();

	// Walls that prevent the player from moving
	if (mPlayer->GetX() > 1280 - 30)
	{
		mPlayer->ChangeX(1280 - 30);
	}
	if ((mPlayer->GetX() - 30) < 0)
	{
		mPlayer->ChangeX(30);
	}
	if (mPlayer->GetY() > 720 - 30)
	{
		mPlayer->ChangeY(720 - 30);
	}
	if ((mPlayer->GetY() - 30) < 0)
	{
		mPlayer->ChangeY(30);
	}

	//Check to see if player is trying to pass over Vertical Wall
	
	//for (int i = 0; i < 3; i++)
	//{
	//	if (mPlayer->GetPos() == mVerticalWall[i].GetPosition());
	//	{
	//		std::cout << "Hit a wall" << std::endl;
	//		/*mPlayer->ChangePos(hitVerticalWall);*/
	//	}
	//	
	//}
	bool ans;
	if (mPlayer->GetPos() == mVerticalWall[0].GetPosition())
	{
		ans = true;
	}
	else
	{
	ans = false;
	}
}

void Application2D::draw() {
	
	// wipe the screen to the background colour
	clearScreen();

	// set the camera position before we begin rendering
	m_2dRenderer->setCameraPos(m_cameraX, m_cameraY);

	// begin drawing sprites
	m_2dRenderer->begin();
	


	m_2dRenderer->setRenderColour(1, 1, 0, 1);
	m_2dRenderer->drawCircle(mPlayer->GetX(), mPlayer->GetY(), 15);

	m_2dRenderer->setRenderColour(0, 0, 1, 1);
	m_2dRenderer->drawBox(640, 0, 1280, 30);
	m_2dRenderer->drawBox(0, 360, 30, 720);
	m_2dRenderer->drawBox(640, 720, 1280, 30);
	m_2dRenderer->drawBox(1280, 360, 30, 720);
	m_2dRenderer->drawBox(640, 360, 10, 100);
	m_2dRenderer->drawBox(500, 500, 10, 100);



	// //output some text, uses the last used colour
	//char fps[32];
	//sprintf_s(fps, 32, "FPS: %i", getFPS());
	//m_2dRenderer->drawText(m_font, fps, 0, 720 - 32);
	//m_2dRenderer->drawText(m_font, "Press ESC to quit!", 0, 720 - 64);

	// done drawing sprites
	m_2dRenderer->end();
}

