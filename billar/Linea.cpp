#include "Linea.h"
#include <SFML/Graphics/Color.hpp>
#include <SFML/Graphics/PrimitiveType.hpp>
#include <SFML/Graphics/RenderStates.hpp>
#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/Graphics/Vertex.hpp>
#include <SFML/Graphics/VertexArray.hpp>
#include <SFML/System/Vector2.hpp>

Linea::Linea()
{

}

Linea::Linea(float x1, float y1, float x2, float y2, sf::Color color)
{
	m_color = color;
	sf::Vertex inicio = sf::Vertex(sf::Vector2f(x1, y1), m_color);
	sf::Vertex fin = sf::Vertex(sf::Vector2f(x2, y2), m_color);
	m_puntos.setPrimitiveType(sf::LineStrip);
	m_puntos.append(inicio);
	m_puntos.append(fin);
}

Linea::~Linea()
{
	m_puntos.clear();
}

sf::VertexArray Linea::getPuntos()
{
	return m_puntos;
}

void Linea::dibujar(sf::RenderTarget& objetivo, sf::RenderStates estados) const
{
	objetivo.draw(m_puntos);
}
