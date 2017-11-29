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
	mEnemy = new Enemy[10];
	mPellet = new Item[1280 * 720];
	mPowerPellet = new Item[10];
	
	
	//Enemeis
	mEnemy[0].SetPosition(400, 400, Vector2(1, 0), 30);
	mEnemy[1].SetPosition(300, 300, Vector2(-1, 0), 10);
	mEnemy[2].SetPosition(400, 400, Vector2(0, 1), 1);

	//Pellets
	mPellet[0].SetPosition(1000, 650);
	mPellet[1].SetPosition(300, 300);
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
	
	//Vertical Walls
	mVerticalWall[0].SetPosition(110, 105);
	mVerticalWall[1].SetPosition(150, 105);
	mVerticalWall[2].SetPosition(400, 300);
	mVerticalWall[3].SetPosition(1100, 400);


	//Horizontal Walls
	mHorizontalWall[0].SetPosition(65, 500);
	mHorizontalWall[1].SetPosition(500, 500);

	//Enemy movement
	for (int iter = 0; iter < 3; iter++)
	{
		mEnemy[iter].Move();
	}
	
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			if ((mEnemy[i].GetX() + 25) >= mVerticalWall[j].GetX() &&
				(mEnemy[i].GetX() - 25) <= mVerticalWall[j].GetX())
			{
				if ((mEnemy[i].GetY() + 20) >= (mVerticalWall[j].GetY() - 50) &&
					(mEnemy[i].GetY() - 20) <= (mVerticalWall[j].GetY() + 50))
				{
					mEnemy[i].ChangeVelocity(mEnemy[i].GetVelocity() * -1);
				}
			}
		}
	}

	//Check if enemy hits player
	int playerLeftSide = mPlayer->GetX() - 15;
	int playerRightSide = mPlayer->GetX() + 15;
	int playerTop = mPlayer->GetY() + 15;
	int playerBottom = mPlayer->GetY() - 15;
	
	for (int i = 0; i < 3; i++)
	{
		if ((mEnemy[i].GetX() + 10) >= playerLeftSide &&
			(mEnemy[i].GetX() - 10) <= playerRightSide)
		{
			if ((mEnemy[i].GetY() - 10) <= playerTop &&
				(mEnemy[i].GetY() + 10) >= playerBottom)
			{
				mPlayer->LoseALife();
				mPlayer->ChangeX(0);
				mPlayer->ChangeY(0);
			}
		}
	}

	//Lose Condition
	if (mPlayer->CheckLives() == false)
	{
		quit();
	}

	//Check if player hits a pellet
	for (int i = 0; i < 2; i++)
	{
		if ((mPellet[i].GetX() + 5) >= playerLeftSide &&
			(mPellet[i].GetX() - 5) <= playerRightSide)
		{
			if ((mPellet[i].GetY() - 5) <= playerTop &&
				(mPellet[i].GetY() + 5) >= playerBottom)
			{
				if (mPellet[i].Status() == false)
				{
					mPlayer->PickUpPellet();
					mPellet[i].HasBeenPickedUp();
				}
				else
				{
					break;
				}
			}
		}
	}

	//Win Condition
	if (mPlayer->NumPellets() == 2)
	{
		quit();
	}


		//Checking if player hit a wall
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
				mPlayer->ChangePos(Vector2(-1, 0));
			}
			else if (mPlayer->GetX() >= mVerticalWall[vertWall].GetX())
			{
				facingVertWall = 2;		//Can't move LEFT
				mPlayer->ChangePos(Vector2(1, 0));
			}
			if ((mPlayer->GetY() + 15) == (mVerticalWall[vertWall].GetY() + 50))
			{
				facingVertWallCorner = 3;		//Can't move UP
				mPlayer->ChangePos(Vector2(0, -1));
			}
			else if ((mPlayer->GetY() + 15) == (mVerticalWall[vertWall].GetY() - 50))
			{
				facingVertWallCorner = 4;		//Can't move DOWN
				mPlayer->ChangePos(Vector2(0, 1));
			}
		}

		if (hitHorzWall == true)
		{
			if (mPlayer->GetY() <= mHorizontalWall[horzWall].GetY())
			{
				facingHorzWall = 3;		//Can't move UP
				mPlayer->ChangePos(Vector2(0, -1));
			}
			else if (mPlayer->GetY() >= mHorizontalWall[horzWall].GetY())
			{
				facingHorzWall = 4;		//Can't move DOWN
				mPlayer->ChangePos(Vector2(0, 1));
			}
			if ((mPlayer->GetX() + 15) == (mHorizontalWall[horzWall].GetX() - 50))
			{
				facingHorzWallCorner = 1;		//Can't move RIGHT
				mPlayer->ChangePos(Vector2(-1, 0));
			}
			else if ((mPlayer->GetX() - 15) == (mHorizontalWall[horzWall].GetX() + 50))
			{
				facingHorzWallCorner = 2;		//Can't move LEFT
				mPlayer->ChangePos(Vector2(1, 0));
			}
		}


		aie::Input* input = aie::Input::getInstance();

		if (input->isKeyDown(aie::INPUT_KEY_W) && facingHorzWall != 3 &&
			facingVertWallCorner != 3)
			mPlayer->ChangePos(Vector2(0, (200 * deltaTime)));

		if (input->isKeyDown(aie::INPUT_KEY_S) && facingHorzWall != 4 &&
			facingVertWallCorner != 4)
			mPlayer->ChangePos(Vector2(0, (-200 * deltaTime)));

		if (input->isKeyDown(aie::INPUT_KEY_A) && facingVertWall != 2 &&
			facingHorzWallCorner != 2)
			mPlayer->ChangePos(Vector2((-200 * deltaTime), 0));

		if (input->isKeyDown(aie::INPUT_KEY_D) && facingVertWall != 1 &&
			facingHorzWallCorner != 1)
			mPlayer->ChangePos(Vector2((200 * deltaTime), 0));

		//if (input->isKeyDown(aie::INPUT_KEY_SPACE)
		//	//SHOOT PROJECTILE

		// exit the application
		if (input->isKeyDown(aie::INPUT_KEY_ESCAPE))
			quit();


		// Walls that prevent the player and enemies from moving off screen
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
		for (int i = 0; i < 10; i++)
		{
			if (mEnemy[i].GetX() > 1280 - 25 || (mEnemy[i].GetX() - 25) < 0 ||
				mEnemy[i].GetY() > 720 - 25 || (mEnemy[i].GetY() - 25) < 0)
			{
				mEnemy[i].ChangeVelocity(mEnemy[i].GetVelocity() * -1.0f);
			}
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
	for (int i = 0; i < 3; i++)
	{
		m_2dRenderer->setRenderColour(1, 0, 0, 1);
		m_2dRenderer->drawCircle(mEnemy[i].GetX(), mEnemy[i].GetY(), 10);
	}
	
	//Pellets
	m_2dRenderer->setRenderColour(0, 1, 0, 1);
	for (int i = 0; i < 2; i++)
	{
		if (mPellet[i].Status() != true)
		{
			m_2dRenderer->drawCircle(mPellet[i].GetX(), mPellet[i].GetY(), 5);
		}
	}
	
	//Boundary Walls		width: 10  ,  height: 100
		m_2dRenderer->setRenderColour(0, 0, 1, 1);
		m_2dRenderer->drawBox(640, 0, 1280, 30);
		m_2dRenderer->drawBox(0, 360, 30, 720);
		m_2dRenderer->drawBox(640, 720, 1280, 30);
		m_2dRenderer->drawBox(1280, 360, 30, 720);
	
	//Vertical Walls		width: 20  ,  height: 100
		for (int i = 0; i < 10; i++)
		{
			m_2dRenderer->drawBox(mVerticalWall[i].GetX(), mVerticalWall[i].GetY(), 20, 100);
		}

	//Horizontal Walls		width: 100  , height: 20
		for (int i = 0; i < 10; i++)
		{
			m_2dRenderer->drawBox(mHorizontalWall[i].GetX(), mHorizontalWall[i].GetY(), 100, 20);
		}
	
	// //output some text, uses the last used colour
	m_2dRenderer->setRenderColour(1, 1, 1, 1);
	char lives[32];
	int livesLeft = (mPlayer->NumLives() - 1);
	sprintf_s(lives, 20, "Lives Left: %i", livesLeft);
	m_2dRenderer->drawText(m_font, lives, 1000, 5);

	// done drawing sprites
	m_2dRenderer->end();
}