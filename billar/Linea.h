#pragma once
#ifndef LINEA_H
#define LINEA_H

#include <SFML/Graphics/Color.hpp>
#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/RenderStates.hpp>
#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/Graphics/Transformable.hpp>
#include <SFML/Graphics/VertexArray.hpp>
#include <iostream>

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <vector>

class Linea : public sf::Drawable, sf::Transformable
{
public:
	Linea();
	Linea(float x1, float y1, float x2, float y2, sf::Color color = sf::Color::White);
	~Linea();

	sf::VertexArray getPuntos();

	void actualizar();
	void renderizar(sf::RenderTarget& objetivo);

private:
	sf::VertexArray m_puntos;
	sf::Color m_color;
	virtual void dibujar(sf::RenderTarget& objetivo, sf::RenderStates estados) const;
};

#endif
