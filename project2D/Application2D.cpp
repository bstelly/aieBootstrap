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
	m_texture = new aie::Texture("./textures/maze.png");
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

	StartUpObjects();
	return true;
}

void Application2D::shutdown() {

	delete m_font;
	delete m_texture;
	delete m_2dRenderer;
}

void Application2D::update(float deltaTime) {
	m_timer += deltaTime;



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
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 100; j++)
		{
			if ((mEnemy[i].GetX() + 60) >= mHorzWall[j].GetX() &&
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


	//Check if projectile hits wall
	for (int i = 0; i < 1; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			if ((mProjectile[i].GetX() + 4) >= (mVertWall[j].GetX() - 10) &&
				(mProjectile[i].GetX() - 4) <= (mVertWall[j].GetX() + 10))
			{
				if ((mProjectile[i].GetY() + 4) >= (mVertWall[j].GetY() - 50) &&
					(mProjectile[i].GetY() - 4) <= (mVertWall[j].GetY() + 50))
				{
						mProjectile[i].Deactivate();
				}
			}
		}


		//Update Projectile starting position
		for (int i = 0; i < 7; i++)
		{
			if (mProjectile[i].IsActive() == false)
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
		//if (mPlayer->NumPellets() == 2)
		//{
		//	quit();
		//}


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
				if ((mPlayer->GetY() + 20) >= (mVertWall[i].GetY() - 49) &&
					(mPlayer->GetY() - 20) <= (mVertWall[i].GetY() + 49))
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
				if ((mPlayer->GetX() + 15) >= (mHorzWall[i].GetX() - 49) &&
					(mPlayer->GetX() - 15) <= (mHorzWall[i].GetX() + 49))
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
			if (mPlayer->CheckProjectiles() == true)
			{
				for (int i = 0; i < 7; i++)
				{
					if (mProjectile[i].IsPickedUp() == true &&
						mPowerPellet[i].FiredStatus() == false)
					{
						mProjectile[i].Activate();
						mPowerPellet[i].HasBeenFired();
						mPlayer->SubtractProjectile();
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
	for (int i = 0; i < 1; i++)
	{
		if (mEnemy[i].Status() != true)
		{
			m_2dRenderer->setRenderColour(1, 0, 0, 1);
			m_2dRenderer->drawCircle(mEnemy[i].GetX(), mEnemy[i].GetY(), 10);
		}
	}

	//Pellets
	m_2dRenderer->setRenderColour(0, 1, 0, 1);
	for (int i = 0; i < 200; i++)
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


	//m_2dRenderer->drawSprite(m_texture, 639, 360.5);

	//Boundary Walls		width: 10  ,  height: 100
		m_2dRenderer->setRenderColour(0, 0, 1, 1);
		m_2dRenderer->drawBox(640, 0, 1280, 60);
		m_2dRenderer->drawBox(0, 360, 30, 720);
		m_2dRenderer->drawBox(640, 720, 1280, 30);
		m_2dRenderer->drawBox(1280, 360, 30, 720);

	//Vertical Walls		width: 20  ,  height: 100
		for (int i = 0; i < 100; i++)
		{
			m_2dRenderer->drawBox(mVertWall[i].GetX(), mVertWall[i].GetY(), 20, 100);
		}

	//Horizontal Walls		width: 100  , height: 20
		for (int i = 0; i < 100; i++)
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

void Application2D::StartUpObjects()
{
	////Vertical Walls
	mVertWall[0].SetPosition(150, 120);
	mVertWall[1].SetPosition(210, 120);
	mVertWall[2].SetPosition(390, 120);
	mVertWall[3].SetPosition(490, 120);
	mVertWall[4].SetPosition(650, 80);
	mVertWall[5].SetPosition(650, 130);
	mVertWall[6].SetPosition(710, 130);
	mVertWall[7].SetPosition(889, 188);
	mVertWall[8].SetPosition(1009, 168);
	mVertWall[9].SetPosition(1070, 220);
	mVertWall[10].SetPosition(1070, 120);
	mVertWall[11].SetPosition(1160, 80);
	mVertWall[12].SetPosition(1160, 180);
	mVertWall[13].SetPosition(1160, 220);
	mVertWall[14].SetPosition(150, 220);
	mVertWall[16].SetPosition(265, 260);
	mVertWall[17].SetPosition(710, 230);
	mVertWall[18].SetPosition(710, 250);
	mVertWall[19].SetPosition(779, 250);
	mVertWall[20].SetPosition(948, 257);
	mVertWall[21].SetPosition(948, 231);
	mVertWall[22].SetPosition(1009, 220);
	mVertWall[23].SetPosition(150, 320);
	mVertWall[24].SetPosition(150, 420);
	mVertWall[23].SetPosition(93, 352);
	mVertWall[24].SetPosition(93, 419);
	mVertWall[25].SetPosition(150, 320);
	mVertWall[26].SetPosition(150, 419);
	mVertWall[27].SetPosition(94, 558);
	mVertWall[28].SetPosition(211, 478);
	mVertWall[29].SetPosition(281, 599);
	mVertWall[30].SetPosition(321, 321);
	mVertWall[31].SetPosition(350, 421);
	mVertWall[32].SetPosition(350, 524);
	mVertWall[33].SetPosition(475, 475);
	mVertWall[34].SetPosition(540, 539);
	mVertWall[35].SetPosition(530, 328);
	mVertWall[36].SetPosition(603, 599);
	mVertWall[37].SetPosition(603, 499);
	mVertWall[38].SetPosition(603, 400);
	mVertWall[39].SetPosition(664, 449);
	mVertWall[40].SetPosition(664, 410);
	mVertWall[41].SetPosition(863, 410);
	mVertWall[42].SetPosition(863, 449);
	mVertWall[43].SetPosition(763, 459);
	mVertWall[44].SetPosition(763, 559);
	mVertWall[45].SetPosition(923, 520);
	mVertWall[46].SetPosition(993, 560);
	mVertWall[47].SetPosition(993, 460);
	mVertWall[48].SetPosition(993, 419);
	mVertWall[49].SetPosition(1093, 482);
	mVertWall[50].SetPosition(1093, 599);
	mVertWall[51].SetPosition(1213, 599);
	mVertWall[52].SetPosition(1213, 499);
	mVertWall[53].SetPosition(1213, 439);
	mVertWall[54].SetPosition(1153, 441);
	mVertWall[55].SetPosition(1153, 377);

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
	mHorzWall[10].SetPosition(99, 122);
	mHorzWall[11].SetPosition(770, 128);
	mHorzWall[12].SetPosition(870, 128);
	mHorzWall[13].SetPosition(950, 128);
	mHorzWall[14].SetPosition(53, 179);
	mHorzWall[15].SetPosition(270, 160);
	mHorzWall[16].SetPosition(768, 191);
	mHorzWall[17].SetPosition(99, 233);
	mHorzWall[18].SetPosition(270, 220);
	mHorzWall[19].SetPosition(350, 220);
	mHorzWall[20].SetPosition(530, 220);
	mHorzWall[21].SetPosition(53, 292);
	mHorzWall[22].SetPosition(380, 281);
	mHorzWall[23].SetPosition(480, 281);
	mHorzWall[24].SetPosition(573, 281);
	mHorzWall[25].SetPosition(952, 317);
	mHorzWall[26].SetPosition(1052, 317);
	mHorzWall[27].SetPosition(1152, 317);
	mHorzWall[28].SetPosition(1252, 317);
	mHorzWall[29].SetPosition(210, 362);
	mHorzWall[30].SetPosition(310, 362);
	mHorzWall[31].SetPosition(381, 344);
	mHorzWall[32].SetPosition(1052, 379);
	mHorzWall[33].SetPosition(1093, 379);
	mHorzWall[34].SetPosition(1253, 379);
	mHorzWall[35].SetPosition(350, 479);
	mHorzWall[36].SetPosition(724, 489);
	mHorzWall[37].SetPosition(804, 489);
	mHorzWall[38].SetPosition(153, 518);
	mHorzWall[39].SetPosition(480, 535);
	mHorzWall[40].SetPosition(543, 598);
	mHorzWall[41].SetPosition(663, 560);
	mHorzWall[42].SetPosition(763, 560);
	mHorzWall[43].SetPosition(863, 560);
	mHorzWall[44].SetPosition(1093, 542);
	mHorzWall[45].SetPosition(53, 659);
	mHorzWall[46].SetPosition(153, 659);
	mHorzWall[47].SetPosition(253, 659);
	mHorzWall[48].SetPosition(353, 659);
	mHorzWall[49].SetPosition(453, 659);
	mHorzWall[50].SetPosition(553, 659);
	mHorzWall[51].SetPosition(563, 659);
	mHorzWall[52].SetPosition(716, 659);
	mHorzWall[53].SetPosition(816, 659);
	mHorzWall[54].SetPosition(916, 659);
	mHorzWall[55].SetPosition(1016, 659);
	mHorzWall[56].SetPosition(1116, 659);
	mHorzWall[57].SetPosition(1155, 659);
	mHorzWall[58].SetPosition(1173, 659);

	////Enemies
	//mEnemy[0].SetPosition(400, 400, Vector2(1, 0), 15);
	//mEnemy[1].SetPosition(300, 300, Vector2(-1, 0), 10);
	//mEnemy[2].SetPosition(400, 400, Vector2(0, 1), 5)

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
	mPellet[26].SetPosition(1200, 45);
	mPellet[27].SetPosition(1240, 45);
	mPellet[28].SetPosition(1240, 85);
	mPellet[29].SetPosition(1200, 85);
	mPellet[30].SetPosition(1240, 85);
	mPellet[31].SetPosition(1200, 85);
	mPellet[32].SetPosition(1240, 165);
	mPellet[33].SetPosition(1200, 165);
	mPellet[34].SetPosition(1240, 205);
	mPellet[35].SetPosition(1200, 205);
	mPellet[36].SetPosition(1240, 245);
	mPellet[37].SetPosition(1200, 245);
	mPellet[38].SetPosition(1240, 285);
	mPellet[39].SetPosition(1200, 285);
	mPellet[40].SetPosition(1200, 285);
	mPellet[41].SetPosition(1160, 285);
	mPellet[42].SetPosition(1120, 285);
	mPellet[43].SetPosition(1080, 285);
	mPellet[44].SetPosition(1040, 285);
	mPellet[45].SetPosition(1000, 285);
	mPellet[46].SetPosition(1120, 85);
	mPellet[47].SetPosition(1120, 125);
	mPellet[48].SetPosition(1120, 165);
	mPellet[49].SetPosition(1120, 205);
	mPellet[50].SetPosition(1120, 245);
	mPellet[51].SetPosition(1040, 95);
	mPellet[52].SetPosition(1040, 135);
	mPellet[53].SetPosition(1040, 175);
	mPellet[54].SetPosition(1040, 215);
	mPellet[55].SetPosition(1040, 255);
	mPellet[56].SetPosition(980, 255);
	mPellet[57].SetPosition(980, 215);
	mPellet[58].SetPosition(980, 175);
	mPellet[59].SetPosition(950, 155);
	mPellet[60].SetPosition(920, 175);
	mPellet[61].SetPosition(920, 215);
	mPellet[62].SetPosition(920, 255);
	mPellet[63].SetPosition(920, 295);
	mPellet[64].SetPosition(880, 255);
	mPellet[65].SetPosition(880, 295);
	mPellet[66].SetPosition(840, 255);
	mPellet[67].SetPosition(840, 295);
	mPellet[68].SetPosition(800, 255);
	mPellet[69].SetPosition(800, 295);
	mPellet[70].SetPosition(800, 215);
	mPellet[71].SetPosition(840, 215);
	mPellet[72].SetPosition(850, 175);
	mPellet[73].SetPosition(800, 160);
	mPellet[74].SetPosition(760, 160);
	mPellet[75].SetPosition(180, 85);
	mPellet[76].SetPosition(180, 125);
	mPellet[77].SetPosition(180, 165);
	mPellet[78].SetPosition(180, 205);
	mPellet[79].SetPosition(180, 245);
	mPellet[80].SetPosition(180, 285);
	mPellet[81].SetPosition(180, 325);
	mPellet[82].SetPosition(220, 325);
	mPellet[83].SetPosition(260, 325);
	mPellet[84].SetPosition(300, 325);
	mPellet[85].SetPosition(220, 245);
	mPellet[86].SetPosition(220, 285);
	mPellet[87].SetPosition(300, 285);
	mPellet[88].SetPosition(300, 245);
	mPellet[89].SetPosition(340, 245);
	mPellet[90].SetPosition(380, 245);
	mPellet[91].SetPosition(420, 245);
	mPellet[92].SetPosition(460, 245);
	mPellet[93].SetPosition(500, 245);
	mPellet[94].SetPosition(540, 245);
	mPellet[95].SetPosition(580, 245);
	mPellet[96].SetPosition(620, 245);
	mPellet[97].SetPosition(660, 245);
	mPellet[98].SetPosition(420, 85);
	mPellet[99].SetPosition(460, 85);
	mPellet[100].SetPosition(420, 125);
	mPellet[101].SetPosition(460, 125);
	mPellet[102].SetPosition(420, 165);
	mPellet[103].SetPosition(460, 165);
	mPellet[104].SetPosition(420, 205);
	mPellet[105].SetPosition(460, 205);
	mPellet[106].SetPosition(260, 93);
	mPellet[107].SetPosition(260, 137);
	mPellet[108].SetPosition(300, 93);
	mPellet[109].SetPosition(300, 137);
	mPellet[110].SetPosition(340, 93);
	mPellet[111].SetPosition(340, 137);
	mPellet[112].SetPosition(220, 190);
	mPellet[113].SetPosition(260, 190);
	mPellet[114].SetPosition(300, 190);
	mPellet[115].SetPosition(340, 190);
	mPellet[116].SetPosition(380, 190);
	mPellet[117].SetPosition(500, 190);
	mPellet[118].SetPosition(540, 190);
	mPellet[119].SetPosition(580, 190);

	mPellet[120].SetPosition(500, 100);


	////Power Pellets
	mPowerPellet[0].SetPosition(620, 45);
	mPowerPellet[1].SetPosition(1220, 125);
	mPowerPellet[2].SetPosition(240, 113);
	//mPowerPellet[3].SetPosition(600, 450);
	//mPowerPellet[4].SetPosition(620, 450);
	//mPowerPellet[5].SetPosition(635, 450);
	//mPowerPellet[6].SetPosition(650, 450);

	////Projectiles
	mProjectile[0].SetPosition(mPlayer->GetX(), mPlayer->GetY());
	mProjectile[1].SetPosition(mPlayer->GetX(), mPlayer->GetY());
	mProjectile[2].SetPosition(mPlayer->GetX(), mPlayer->GetY());

}