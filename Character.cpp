#include "Character.h"
#include <SFML/Graphics.hpp>

using namespace sf;

Character::Character(sf::Vector2f size, Color color, float velocity, sf::Vector2f position, sf::Texture t)
	:m_velocity{ velocity }
{
	m_sprite = new sf::RectangleShape(size);
	m_sprite->setFillColor(color);
	m_sprite->setPosition(position);
	m_sprite->setTexture(&t);
}

Character::~Character()
{
	delete m_sprite;
}

void Character::update(float time)
{
	m_sprite->setPosition(m_position);
}

void World::init(float x, float y, sf::Texture t)
{
	Vector2f dimension(100, 100);
	character = new Character(dimension, Color::Green, 1, { x, y }, t);
}

void World::update(float time)
{
	character->update(time);
}

void World::form(RenderWindow& window)
{
	Drawable& shape = *character->getSprite();
	window.draw(shape);
}

void World::onkey(KeyEvent key)
{
	if (key.control && key.code == Keyboard::Key::Escape)
	{

	}
	else
	{
		character->onImput(key);
	}
}

sf::RectangleShape* Character::getSprite() const
{
	return m_sprite;
}

void Character::onImput(sf::Event::KeyEvent event) 
{
	Vector2f dir;

	if (event.code == Keyboard::Key::Right)
	{
		dir.x = m_velocity;
	}
	if (event.code == Keyboard::Key::Left)
	{
		dir.x = -m_velocity;
	}
	if (event.code == Keyboard::Key::Up)
	{
		dir.y = m_velocity;
	}
	if (event.code == Keyboard::Key::Down)
	{
		dir.y = -m_velocity;
	}
	m_position += dir;
}

/*void World::textures()
{
	Texture t;
	*character->loadFromFile("textures/hello.jpg");
	Texture t2;
	t2.loadFromFile("textures/hello.jpg");
	Texture t3;
	t3.loadFromFile("textures/hello.jpg");
	Texture t4;
	t4.loadFromFile("textures/hello.jpg");
}*/