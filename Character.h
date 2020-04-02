#pragma once

#include <SFML/System/Vector2.hpp>
#include <SFML/Graphics/Color.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Window/Event.hpp>
#include <SFML/Graphics/Transformable.hpp>

namespace sf {
	class RenderWindow;
	struct sf::Event::KeyEvent;
}

typedef sf::Event::KeyEvent KeyEvent;

class Character
{
public:
	Character(sf::Vector2f size, sf::Color color, float velocity, sf::Vector2f position, sf::Texture t);
	~Character();

	void update(float time);
	void onImput(sf::Event::KeyEvent event);
	sf::RectangleShape* getSprite() const;

private:
	sf::RectangleShape* m_sprite;
	//sf::Texture* m_t;
	sf::Vector2f m_position;
	float m_velocity;
};

class World
{
public:
	void init(float x, float y, sf::Texture t);
	void update(float time);
	void form(sf::RenderWindow& window);
	void onkey(KeyEvent key);
	//void textures();

private:
	Character* character;
};