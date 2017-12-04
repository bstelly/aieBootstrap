#include "Application2D.h"
#include "Texture.h"
#include "Font.h"
#include "Input.h"
#include "PacGuy.h"
#include "Wall.h"
#include <Vector2.h>
#include <winerror.h>

Application2D::Application2D() {

}

Application2D::~Application2D() {

}

bool Application2D::startup() {

	m_2dRenderer = new aie::Renderer2D();
	m_texture = new aie::Texture("./textures/numbered_grid.tga");
	m_shipTexture = new aie::Texture("./textures/ship.png");
	m_font = new aie::Font("./font/consolas.ttf", 25);
	m_cameraX = 0;
	m_cameraY = 0;
	m_timer = 0;
	mPlayer = new PacGuy();
	mVertWall = new Wall[1280 * 720];
	mHorzWall = new Wall[1280 * 720];
	mEnemy = new Enemy[10];
	mPellet = new Item[1280 * 720];
	mPowerPellet = new Item[10];
	mProjectile = new Projectile[10];

	////Enemies
	//mEnemy[0].SetPosition(400, 400, Vector2(1, 0), 15);
	//mEnemy[1].SetPosition(300, 300, Vector2(-1, 0), 10);
	//mEnemy[2].SetPosition(400, 400, Vector2(0, 1), 5);

	//Pellets
	mPellet[0].SetPosition(60, 45);
	mPellet[1].SetPosition(100, 45);
	mPellet[2].SetPosition(140, 45);
	mPellet[3].SetPosition(180, 45);
	mPellet[4].SetPosition(220, 45);
	mPellet[5].SetPosition(260, 45);
	mPellet[6].SetPosition(300, 45);
	mPellet[7].SetPosition(340, 45);
	mPellet[8].SetPosition(380, 45);
	mPellet[9].SetPosition(420, 45);
	mPellet[10].SetPosition(460, 45);
	mPellet[11].SetPosition(500, 45);
	mPellet[12].SetPosition(540, 45);
	mPellet[13].SetPosition(580, 45);
	mPellet[14].SetPosition(680, 45);
	mPellet[15].SetPosition(720, 45);
	mPellet[16].SetPosition(760, 45);
	mPellet[17].SetPosition(800, 45);
	mPellet[18].SetPosition(840, 45);
	mPellet[19].SetPosition(880, 45);
	mPellet[20].SetPosition(920, 45);
	mPellet[21].SetPosition(960, 45);
	mPellet[22].SetPosition(1000, 45);
	mPellet[23].SetPosition(1040, 45);
	mPellet[24].SetPosition(1080, 45);
	mPellet[25].SetPosition(1120, 45);







	////Power Pellets
	mPowerPellet[0].SetPosition(620, 45);
	//mPowerPellet[1].SetPosition(550, 450);
	//mPowerPellet[2].SetPosition(580, 450);
	//mPowerPellet[3].SetPosition(600, 450);
	//mPowerPellet[4].SetPosition(620, 450);
	//mPowerPellet[5].SetPosition(635, 450);
	//mPowerPellet[6].SetPosition(650, 450);

	////Projectiles
	mProjectile[0].SetPosition(mPlayer->GetX(), mPlayer->GetY());
	mProjectile[1].SetPosition(mPlayer->GetX(), mPlayer->GetY());
	mProjectile[2].SetPosition(mPlayer->GetX(), mPlayer->GetY());


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

	////Vertical Walls
	mVertWall[0].SetPosition(150, 120);
	mVertWall[1].SetPosition(210, 120);
	mVertWall[2].SetPosition(650, 80);
	mVertWall[3].SetPosition(1070, 120);
	//mVertWall[3].SetPosition()

	//Horizontal Walls
	mHorzWall[0].SetPosition(65, 70);
	mHorzWall[1].SetPosition(110, 70);
	mHorzWall[2].SetPosition(250, 70);
	mHorzWall[3].SetPosition(350, 70);
	mHorzWall[4].SetPosition(530, 70);
	mHorzWall[5].SetPosition(550, 70);
	mHorzWall[6].SetPosition(650, 70);
	mHorzWall[7].SetPosition(750, 70);
	mHorzWall[8].SetPosition(930, 70);
	mHorzWall[9].SetPosition(1030, 70);






	//Enemy movement
	for (int iter = 0; iter < 3; iter++)
	{
		mEnemy[iter].Move();
	}

	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 100; j++)
		{
			if ((mEnemy[i].GetX() + 25) >= mVertWall[j].GetX() &&
				(mEnemy[i].GetX() - 25) <= mVertWall[j].GetX())
			{
				if ((mEnemy[i].GetY() + 20) >= (mVertWall[j].GetY() - 50) &&
					(mEnemy[i].GetY() - 20) <= (mVertWall[j].GetY() + 50))
				{
					mEnemy[i].ChangeVelocity(mEnemy[i].GetVelocity() * -1);
				}
			}
		}
	}
	for(int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 100; j++)
		{
			if((mEnemy[i].GetX() + 60) >= mHorzWall[j].GetX() &&
				(mEnemy[i].GetX() - 60) <= mHorzWall[j].GetX())
			{
				if ((mEnemy[i].GetY() + 10) >= (mHorzWall[j].GetY() - 10) &&
					(mEnemy[i].GetY() - 10) <= (mHorzWall[j].GetY() + 10))
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

	for (int i = 0; i < 1; i++)
	{
		if ((mEnemy[i].GetX() + 10) >= playerLeftSide &&
			(mEnemy[i].GetX() - 10) <= playerRightSide)
		{
			if ((mEnemy[i].GetY() - 10) <= playerTop &&
				(mEnemy[i].GetY() + 10) >= playerBottom)
			{
				if (mEnemy[i].Status() == false)
				{
					mPlayer->LoseALife();
					mPlayer->ChangeX(0);
					mPlayer->ChangeY(0);
				}
			}
		}
	}

	//Check if projectile hits enemy
	for (int i = 0; i < 1; i++)
	{
		for (int iter = 0; iter < 10; iter++)
		{
			if ((mProjectile[i].GetX() + 4) >= (mEnemy[iter].GetX() - 10) &&
				(mProjectile[i].GetX() - 4) <= (mEnemy[iter].GetX() + 10))
			{
				if ((mProjectile[i].GetY() - 4) <= (mEnemy[iter].GetY() + 10) &&
					(mProjectile[i].GetY() + 4) >= (mEnemy[iter].GetY() - 10))
				{
					if (mEnemy[i].Status() == false)
					{
						mEnemy[iter].EnemyHasDied();
						mProjectile[i].Deactivate();
					}
				}
			}
		}
	}

	//Update Projectile starting position
	for(int i = 0; i < 7; i++)
	{
		if(mProjectile[i].IsActive() == false)
		{
			mProjectile[i].SetPosition(mPlayer->GetX(), mPlayer->GetY());
		}
		if (mProjectile[i].IsActive() != false &&
			mProjectile[i].DirectionStatus() == false)
		{
			mProjectile[i].SetDirectionFacing(mPlayer->Facing());
			mProjectile[i].ChangeDirectionStatus();
		}
	}

	//Projectile Movement
	for (int i = 0; i < 7; i++)
	{
		if (mProjectile[i].DirectionStatus() == true)
		{
			mProjectile[i].Move();
		}
		else
		{
			break;
		}
	}

	//Lose Condition
	if (mPlayer->CheckLives() == false)
	{
		quit();
	}

	//Check if player hits a pellet
	for (int i = 0; i < 100; i++)
	{
		if ((mPellet[i].GetX() + 5) >= playerLeftSide &&
			(mPellet[i].GetX() - 5) <= playerRightSide)
		{
			if ((mPellet[i].GetY() - 5) <= playerTop &&
				(mPellet[i].GetY() + 5) >= playerBottom)
			{
				if (mPellet[i].PickedUpStatus() == false)
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

	//Check if player hits a Power Pellet
	for (int i = 0; i < 7; i++)
	{
		if ((mPowerPellet[i].GetX() + 8) >= playerLeftSide &&
			(mPowerPellet[i].GetX() - 8) <= playerRightSide)
		{
			if ((mPowerPellet[i].GetY() - 8) <= playerTop &&
				(mPowerPellet[i].GetY() + 8) >= playerBottom)
			{
				if (mPowerPellet[i].PickedUpStatus() == false)
				{
					mPlayer->AddProjectile();
					mPowerPellet[i].HasBeenPickedUp();
					mProjectile[i].HasBeenPickedUp();
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
		for (int i = 0; i < 100; i++)
		{
			if ((mPlayer->GetX() + 25) >= mVertWall[i].GetX() &&
				(mPlayer->GetX() - 25) <= mVertWall[i].GetX())
			{
				if ((mPlayer->GetY() + 20) >= (mVertWall[i].GetY() - 50) &&
					(mPlayer->GetY() - 20) <= (mVertWall[i].GetY() + 50))
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
		for (int i = 0; i < 100; i++)
		{
			if ((mPlayer->GetY() + 15) >= (mHorzWall[i].GetY() - 10) &&
				(mPlayer->GetY() - 15) <= (mHorzWall[i].GetY() + 10))
			{
				if ((mPlayer->GetX() + 15) >= (mHorzWall[i].GetX() - 50) &&
					(mPlayer->GetX() - 15) <= (mHorzWall[i].GetX() + 50))
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
			if (mPlayer->GetX() <= mVertWall[vertWall].GetX())
			{
				facingVertWall = 1;		//Can't move RIGHT
				mPlayer->ChangePos(Vector2(-1, 0));
			}
			else if (mPlayer->GetX() >= mVertWall[vertWall].GetX())
			{
				facingVertWall = 2;		//Can't move LEFT
				mPlayer->ChangePos(Vector2(1, 0));
			}
			if ((mPlayer->GetY() + 15) == (mVertWall[vertWall].GetY() + 50))
			{
				facingVertWallCorner = 3;		//Can't move UP
				mPlayer->ChangePos(Vector2(0, -1));
			}
			else if ((mPlayer->GetY() + 15) == (mVertWall[vertWall].GetY() - 50))
			{
				facingVertWallCorner = 4;		//Can't move DOWN
				mPlayer->ChangePos(Vector2(0, 1));
			}
		}

		if (hitHorzWall == true)
		{
			if (mPlayer->GetY() <= mHorzWall[horzWall].GetY())
			{
				facingHorzWall = 3;		//Can't move UP
				mPlayer->ChangePos(Vector2(0, -1));
			}
			else if (mPlayer->GetY() >= mHorzWall[horzWall].GetY())
			{
				facingHorzWall = 4;		//Can't move DOWN
				mPlayer->ChangePos(Vector2(0, 1));
			}
			if ((mPlayer->GetX() + 15) == (mHorzWall[horzWall].GetX() - 50))
			{
				facingHorzWallCorner = 1;		//Can't move RIGHT
				mPlayer->ChangePos(Vector2(-1, 0));
			}
			else if ((mPlayer->GetX() - 15) == (mHorzWall[horzWall].GetX() + 50))
			{
				facingHorzWallCorner = 2;		//Can't move LEFT
				mPlayer->ChangePos(Vector2(1, 0));
			}
		}


		aie::Input* input = aie::Input::getInstance();
		if (input->isKeyDown(aie::INPUT_KEY_W) && facingHorzWall != 3 &&
			facingVertWallCorner != 3)
		{
			mPlayer->ChangePos(Vector2(0, (250 * deltaTime)));
			mPlayer->ChangeDirection(3);
		}
		if (input->isKeyDown(aie::INPUT_KEY_S) && facingHorzWall != 4 &&
			facingVertWallCorner != 4)
		{
			mPlayer->ChangePos(Vector2(0, (-250 * deltaTime)));
			mPlayer->ChangeDirection(4);
		}
		if (input->isKeyDown(aie::INPUT_KEY_A) && facingVertWall != 2 &&
			facingHorzWallCorner != 2)
		{
			mPlayer->ChangePos(Vector2((-250 * deltaTime), 0));
			mPlayer->ChangeDirection(2);
		}
		if (input->isKeyDown(aie::INPUT_KEY_D) && facingVertWall != 1 &&
			facingHorzWallCorner != 1)
		{
			mPlayer->ChangePos(Vector2((250 * deltaTime), 0));
			mPlayer->ChangeDirection(1);
		}
		if (input->wasKeyPressed(aie::INPUT_KEY_SPACE))
		{
			if(mPlayer->CheckProjectiles() == true)
			{
				for (int i = 0; i < 7; i++)
				{
					if (mProjectile[i].IsPickedUp() == true &&
						mPowerPellet[i].FiredStatus() == false)
					{
						mProjectile[i].Activate();
						mPowerPellet[i].HasBeenFired();
						break;
					}
				}
			}
		}


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
		if ((mPlayer->GetY() - 45) < 0)
		{
			mPlayer->ChangeY(45);
		}
		for (int i = 0; i < 10; i++)
		{
			if (mEnemy[i].GetX() > 1280 - 25 || (mEnemy[i].GetX() - 25) < 0 ||
				mEnemy[i].GetY() > 720 - 25 || (mEnemy[i].GetY() - 35) < 0)
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
		if (mEnemy[i].Status() != true)
		{
			m_2dRenderer->setRenderColour(1, 0, 0, 1);
			m_2dRenderer->drawCircle(mEnemy[i].GetX(), mEnemy[i].GetY(), 10);
		}
	}

	//Pellets
	m_2dRenderer->setRenderColour(0, 1, 0, 1);
	for (int i = 0; i < 100; i++)
	{
		if (mPellet[i].PickedUpStatus() != true)
		{
			m_2dRenderer->drawCircle(mPellet[i].GetX(), mPellet[i].GetY(), 5);
		}
	}

	//Power Pellets
	for (int i = 0; i < 10; i++)
	{
		if (mPowerPellet[i].PickedUpStatus() != true)
		{
			m_2dRenderer->setRenderColour(1, 0, 1, 1);
			m_2dRenderer->drawCircle(mPowerPellet[i].GetX(), mPowerPellet[i].GetY(), 8);
		}
	}

	//Projectile
	for (int i = 0; i < 10; i++)
	{
		if (mProjectile[i].IsActive() != false)
		{
			m_2dRenderer->setRenderColour(1, 0, 1, 1);
			m_2dRenderer->drawCircle(mProjectile[i].GetX(), mProjectile[i].GetY(), 8);
		}
	}

	//Boundary Walls		width: 10  ,  height: 100
		m_2dRenderer->setRenderColour(0, 0, 1, 1);
		m_2dRenderer->drawBox(640, 0, 1280, 60);
		m_2dRenderer->drawBox(0, 360, 30, 720);
		m_2dRenderer->drawBox(640, 720, 1280, 30);
		m_2dRenderer->drawBox(1280, 360, 30, 720);

	//Vertical Walls		width: 20  ,  height: 100
		for (int i = 0; i < 10; i++)
		{
			m_2dRenderer->drawBox(mVertWall[i].GetX(), mVertWall[i].GetY(), 20, 100);
		}

	//Horizontal Walls		width: 100  , height: 20
		for (int i = 0; i < 10; i++)
		{
			m_2dRenderer->drawBox(mHorzWall[i].GetX(), mHorzWall[i].GetY(), 100, 20);
		}

	//output some text, uses the last used colour
	m_2dRenderer->setRenderColour(1, 1, 1, 1);
	char lives[32];
	char projectiles[32];
	int livesLeft = (mPlayer->NumLives() - 1);
	int projectilesLeft = (mPlayer->NumProjectiles());
	sprintf_s(lives, 20, "Lives Left: %i", livesLeft);
	m_2dRenderer->drawText(m_font, lives, 640, 6);
	sprintf_s(projectiles, 20, "Projectiles: %i", projectilesLeft);
	m_2dRenderer->drawText(m_font, projectiles, 1000, 6);


	//char fps[32];
	//sprintf_s(fps, 32, "FPS: %i", getFPS());
	//m_2dRenderer->drawText(m_font, fps, 0, 720 - 32);
	//m_2dRenderer->drawText(m_font, "Press ESC to quit!", 0, 720 - 64);

	// done drawing sprites
	m_2dRenderer->end();
}