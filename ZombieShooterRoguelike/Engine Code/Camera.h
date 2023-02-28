#ifndef CAMERA_H
#define CAMERA_H

#include <SFML/Graphics/View.hpp>

class Camera
{
public:
	Camera();
	Camera(const Camera& rCam);
	Camera& operator=(const Camera& rCam);
	virtual ~Camera();

	// construct a camera from the top-left corner position in world space with a width and height
	Camera(float worldX, float worldY, float worldWidth, float worldHeight);

	// construct a camera with a target (center) position in world space with a width and height
	Camera(sf::Vector2f targetPos, sf::Vector2f worldSize);

	void Reset(float worldX, float worldY, float worldWidth, float worldHeight);
	void SetSize(sf::Vector2f worldSize);
	void SetTarget(sf::Vector2f targetPos);
	void MoveToTarget(sf::Vector2f newTargetPos);
	void MoveByOffset(sf::Vector2f offset);

private:
	sf::View view;
};

#endif