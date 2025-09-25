#include "Player.h"

// sfml includes
#include "SFML/Graphics/RenderTarget.hpp"
#include "SFML/Window/Keyboard.hpp"

// engine includes
#include "../Engine Code/SpriteManager.h"
#include "../Engine Code/TimeManager.h"

// game includes
#include "Weapon.h"
#include "Shotgun.h"

Player::Player()
	: spriteCurrent(SpriteManager::GetSprite("playerDir2")),
	pos(0.0f, 0.0f),
	dir(0.0f, 1.0f),
	posDelta(0.0f, 0.0f),
	speed(100.0f),
	pWeapon(new Shotgun())
{
	spriteCurrent->setScale(10.0f, 10.0f);
	EnqueueForUpdateRegistration();
	EnqueueForDrawRegistration();
	//Fire();
}

Player::~Player()
{
	delete pWeapon;
}

void Player::Update()
{
	posDelta = sf::Vector2f(0.0f, 0.0f);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) MoveNorth();
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) MoveWest();
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) MoveSouth();
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) MoveEast();

	// normalize posDelta
	float mag = sqrtf(posDelta.x * posDelta.x + posDelta.y * posDelta.y);
	if (mag > 0.0f)
	{
		posDelta *= (1.0f / mag);

		// set speed
		posDelta *= TimeManager::GetFrameTime() * speed;

		// move player
		pos += posDelta;
		spriteCurrent->setPosition(pos);
	}
}

void Player::draw(sf::RenderTarget& rTarget, sf::RenderStates states) const
{
	rTarget.draw(*spriteCurrent);
}

void Player::MoveNorth()
{
	posDelta.y -= 1.0f;
}

void Player::MoveEast()
{
	posDelta.x += 1.0f;
}

void Player::MoveSouth()
{
	posDelta.y += 1.0f;
}

void Player::MoveWest()
{
	posDelta.x -= 1.0f;
}

void Player::Fire()
{
	pWeapon->Fire(pos, dir);
}

void Player::Reload()
{
	pWeapon->Reload();
}
