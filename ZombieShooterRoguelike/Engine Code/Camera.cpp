#include "Camera.h"

#include "Variables.h"

Camera::Camera()
	: view(sf::Vector2f(Defaults::CamTargetX, Defaults::CamTargetY),
		sf::Vector2f(Defaults::ScreenWidth, Defaults::ScreenHeight))
{
	// do nothing
}

Camera::Camera(float worldX, float worldY, float worldWidth, float worldHeight)
	: view(sf::FloatRect(worldX, worldY, worldWidth, worldHeight))
{
	// do nothing
}

Camera::Camera(sf::Vector2f targetPos, sf::Vector2f worldSize)
	: view(targetPos, worldSize)
{
	// do nothing
}

Camera::Camera(const Camera& rCam)
	: view(rCam.view)
{
	// do nothing
}

Camera& Camera::operator=(const Camera& rCam)
{
	view = rCam.view;

	return *this;
}

Camera::~Camera()
{
	// do nothing
}

void Camera::Reset(float worldX, float worldY, float worldWidth, float worldHeight)
{
	view.reset(sf::FloatRect(worldX, worldY, worldWidth, worldHeight));
}

void Camera::SetSize(sf::Vector2f worldSize)
{
	view.setSize(worldSize);
}

void Camera::SetTarget(sf::Vector2f targetPos)
{
	view.setCenter(targetPos);
}

void Camera::MoveToTarget(sf::Vector2f newTargetPos)
{
	view.move(newTargetPos - view.getCenter());
}

void Camera::MoveByOffset(sf::Vector2f offset)
{
	view.move(offset);
}
