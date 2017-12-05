#pragma once

#include "Application.h"
#include "Renderer2D.h"
#include "PacGuy.h"
#include "Wall.h"
#include "Enemy.h"
#include "Item.h"
#include "Projectile.h"

class Application2D : public aie::Application {
public:

	Application2D();
	virtual ~Application2D();

	virtual bool startup();
	virtual void shutdown();

	virtual void update(float deltaTime);
	virtual void draw();
	void StartUpObjects();

protected:

	aie::Renderer2D*	m_2dRenderer;
	aie::Texture*		m_texture;
	aie::Texture*		m_shipTexture;
	aie::Font*			m_font;
	float m_cameraX, m_cameraY;
	float m_timer;
	float mPx;
	float mPy;
	PacGuy* mPlayer;
	Wall* mVertWall;
	Wall* mHorzWall;
	Enemy* mEnemy;
	Item* mPellet;
	Item* mPowerPellet;
	Projectile* mProjectile;
};