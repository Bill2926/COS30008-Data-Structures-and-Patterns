#include <iostream>

#include "Particle2D.h"

#include <cmath>

using namespace std;

// constructor
Particle2D::Particle2D(
	float aMass,
	float aRadius,
	const Vector2D& aPosition,
	const Vector2D& aVelocity,
	const Vector2D& aAcceleration) :
	fMass(aMass),
	fRadius(aRadius),
	fPosition(aPosition),
	fVelocity(aVelocity),
	fAcceleration(aAcceleration)
{ }

// getters
const float Particle2D::getMass() const
{
	return fMass;
}

const float Particle2D::getRadius() const
{
	return fRadius;
}

const Vector2D& Particle2D::getPosition() const
{
	return fPosition;
}

const Vector2D& Particle2D::getVelocity() const
{
	return fVelocity;
}

const Vector2D& Particle2D::getAcceleration() const
{
	return fAcceleration;
}

// apply Acceleration
void Particle2D::applyAcceleration(const Vector2D& aAcceleration)
{
	fAcceleration = fAcceleration + aAcceleration;
}

// get vector direction
float Particle2D::direction() const
{
	return fVelocity.direction();
}

// align vector
void Particle2D::align(float aAngleInDegrees)
{
	fVelocity = fVelocity.align(aAngleInDegrees);
}

// get velocity vector's length
float Particle2D::speed() const
{
	return fVelocity.length();
}

// update particle
void Particle2D::update()
{
	fVelocity = fVelocity + fAcceleration;
	fPosition = fPosition + fVelocity;
}

// iostream
ostream& operator<< (ostream& aOStream, const Particle2D& aParticle)
{
	return aOStream << "Speed:" << round(aParticle.speed() * 100.0f) / 100.0f << "\n"
		<< "Direction:" << round(aParticle.direction() * 100.0f) / 100.0f << "\n"
		<< "Position:" << aParticle.getPosition() << "\n";
}