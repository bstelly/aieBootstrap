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
	mEnemy = new Enemy[1280 * 720];
	mPellet = new Item[1280 * 720];
	mPowerPellet = new Item[1280 * 720];
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
	int iter = 0;
	Vector2 moveUp(0, (400 * deltaTime));
	Vector2 moveDown(0, (-400 * deltaTime));
	Vector2 moveLeft((-400 * deltaTime), 0);
	Vector2 moveRight((400 * deltaTime), 0);

	//Enemies

	//Vertical Walls
	mVerticalWall[0].SetPosition(110, 105);
	mVerticalWall[1].SetPosition(150, 105);


	//Horizontal Walls
	mHorizontalWall[0].SetPosition(65, 500);
	mHorizontalWall[1].SetPosition(500, 500);
	mHorizontalWall[2].SetPosition(450, 500);
	mHorizontalWall[3].SetPosition(400, 500);
	mHorizontalWall[4].SetPosition(350, 500);


	//Enemy movement
	for (int i = 0; i < 10; i++)
	{
		if ((mEnemy->GetX() + 25) >= mVerticalWall[i].GetX() &&
			(mEnemy->GetX() - 25) <= mVerticalWall[i].GetX())
		{
			if ((mEnemy->GetY() + 20) >= (mVerticalWall[i].GetY() - 50) &&
				(mEnemy->GetY() - 20) <= (mVerticalWall[i].GetY() + 50))
			{
				
				break;
			}
	}



	int facingVertWall = 0;
	int facingHorzWall = 0;
	int facingVertWallCorner = 0;
	int facingHorzWallCorner = 0;
	int horzWall;
	int vertWall;
	bool hitVertWall;
	bool hitHorzWall;
	//Check for vertical wall for player
	for (int i = 0; i < 10; i++)
	{
		if ((mPlayer->GetX() + 25) >= mVerticalWall[i].GetX() &&
			(mPlayer->GetX() - 25) <= mVerticalWall[i].GetX())
		{
			if ((mPlayer->GetY() + 20) >= (mVerticalWall[i].GetY() - 50) &&
				(mPlayer->GetY() - 20) <= (mVerticalWall[i].GetY() + 50))
			{
				std::cout << "You hit a vertical wall" << std::endl;
				hitVertWall = true;
				vertWall = i;
				break;
			}
		}
		else
		{
			hitVertWall = false;
		}
	}

	//Checks for Horizontal Wall for player
	for (int i = 0; i < 10; i++)
	{
		if ((mPlayer->GetY() + 15) >= (mHorizontalWall[i].GetY() - 10) &&
			(mPlayer->GetY() - 15) <= (mHorizontalWall[i].GetY() + 10))
			{
				if ((mPlayer->GetX() + 15) >= (mHorizontalWall[i].GetX() - 50) &&
					(mPlayer->GetX() - 15) <= (mHorizontalWall[i].GetX() + 50))
				{
					std::cout << "you hit a horizontal wall" << std::endl;
					hitHorzWall = true;
					horzWall = i;
					break;
				}
			}
		else
		{
				hitHorzWall = false;
		}
	}
	if (hitVertWall == true)
	{
		if (mPlayer->GetX() <= mVerticalWall[vertWall].GetX())
		{
			facingVertWall = 1;		//Can't move RIGHT
		}
		else if (mPlayer->GetX() >= mVerticalWall[vertWall].GetX())
		{
			facingVertWall = 2;		//Can't move LEFT
		}
		if (mPlayer->GetY() <= mVerticalWall[vertWall].GetY())
		{
			facingVertWallCorner = 3;		//Can't move UP
		}
		else if (mPlayer->GetY() >= mVerticalWall[vertWall].GetY())
		{
			facingVertWallCorner = 4;		//Can't move DOWN
		}
	}

	if (hitHorzWall == true)
	{
		if (mPlayer->GetY() <= mHorizontalWall[horzWall].GetY())
		{
			facingHorzWall = 3;		//Can't move UP
		}
		else if (mPlayer->GetY() >= mHorizontalWall[horzWall].GetY())
		{
			facingHorzWall = 4;		//Can't move DOWN
		}
		if ((mPlayer->GetX() + 15) == (mHorizontalWall[horzWall].GetX() - 50))
		{
			facingHorzWallCorner = 1;		//Can't move RIGHT
		}
		else if ((mPlayer->GetX() -15) == (mHorizontalWall[horzWall].GetX() + 50))
		{
			facingHorzWallCorner = 2;		//Can't move LEFT
		}
	}
	
		
		aie::Input* input = aie::Input::getInstance();

	if (input->isKeyDown(aie::INPUT_KEY_W) && facingHorzWall != 3 &&
		facingVertWallCorner != 3)
		mPlayer->ChangePos(moveUp);

	if (input->isKeyDown(aie::INPUT_KEY_S) && facingHorzWall != 4 &&
		facingVertWallCorner != 4)
		mPlayer->ChangePos(moveDown);

	if (input->isKeyDown(aie::INPUT_KEY_A) && facingVertWall != 2 &&
		facingHorzWallCorner != 2)
		mPlayer->ChangePos(moveLeft);

	if (input->isKeyDown(aie::INPUT_KEY_D) && facingVertWall != 1 &&
		facingHorzWallCorner != 1)
		mPlayer->ChangePos(moveRight);

	//if (input->isKeyDown(aie::INPUT_KEY_SPACE)
	//	//SHOOT PROJECTILE

	// exit the application
	if (input->isKeyDown(aie::INPUT_KEY_ESCAPE))
		quit();
	

	// Walls that prevent the player from moving off screen
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


}

void Application2D::draw() {
	
	// wipe the screen to the background colour
	clearScreen();

	// set the camera position before we begin rendering
	m_2dRenderer->setCameraPos(m_cameraX, m_cameraY);

	// begin drawing sprites
	m_2dRenderer->begin();
	

	//Player
	m_2dRenderer->setRenderColour(1, 1, 0, 1);
	m_2dRenderer->drawCircle(mPlayer->GetX(), mPlayer->GetY(), 15);

	//Enemies
	m_2dRenderer->setRenderColour(0, 1, 0, 1);
	m_2dRenderer->drawCircle(mEnemy->GetX(), mEnemy->GetY(), 10);
	
	
	//Boundary Walls		width: 10  ,  height: 100
	m_2dRenderer->setRenderColour(0, 0, 1, 1);
	m_2dRenderer->drawBox(640, 0, 1280, 30);
	m_2dRenderer->drawBox(0, 360, 30, 720);
	m_2dRenderer->drawBox(640, 720, 1280, 30);
	m_2dRenderer->drawBox(1280, 360, 30, 720);
	
	//Vertical Walls		width: 10  ,  height: 100
	m_2dRenderer->drawBox(110, 105, 10, 100);
	m_2dRenderer->drawBox(150, 105, 10, 100);
	
	
	
	//Horizontal Walls		width: 100  , height: 10
	m_2dRenderer->drawBox(65, 500, 100, 10);
	m_2dRenderer->drawBox(500, 500, 100, 10);
	m_2dRenderer->drawBox(450, 500, 100, 10);
	m_2dRenderer->drawBox(400, 500, 100, 10);
	m_2dRenderer->drawBox(350, 500, 100, 10);





	// //output some text, uses the last used colour
	//char fps[32];
	//sprintf_s(fps, 32, "FPS: %i", getFPS());
	//m_2dRenderer->drawText(m_font, fps, 0, 720 - 32);
	//m_2dRenderer->drawText(m_font, "Press ESC to quit!", 0, 720 - 64);

	// done drawing sprites
	m_2dRenderer->end();
}