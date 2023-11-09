#include <SFML/Graphics.hpp>
#include "Bola.h"
#include <SFML/Graphics/Color.hpp>
#include <SFML/Graphics/PrimitiveType.hpp>
#include <SFML/Graphics/Sprite.hpp>

void Bola::inicializarVariables()
{
	MAX_PUNTOS = 20;
	VISCOSIDAD = 1.f;
	COLOR_FORMA = sf::Color::Red;

	m_radio = 10.f;
	m_angulo = 0.f;
	m_centro = sf::Vector2f(100.f, 100.f);
	m_velocidad = sf::Vector2f(0.f, 0.f);
	m_aceleracion = sf::Vector2f(0.f, 0.f);
	m_vertices.setPrimitiveType(sf::TrianglesFan);
	m_vertices.clear();
	m_vertices.resize(MAX_PUNTOS);
	m_color = COLOR_FORMA;
	m_masa = m_radio;
}

void Bola::inicializarForma()
{
	float x = 0.f;
	float y = 0.f;

	for (unsigned long i = 0; i != MAX_PUNTOS - 1; i++)
	{
		x = m_centro.x + m_radio * cos(((360.f) / (static_cast<float>(MAX_PUNTOS - 2)) * i + m_angulo) * M_PI / 180.f);
		y = m_centro.y + m_radio * sin(((360.f) / (static_cast<float>(MAX_PUNTOS - 2)) * i + m_angulo) * M_PI / 180.f);
		m_vertices[i] = sf::Vertex(sf::Vector2f(x, y), m_color);
	}
}

Bola::Bola()
{
	inicializarVariables();
	inicializarForma();
}

Bola::Bola(sf::Vector2f centro, float radio, sf::Color color)
{
	inicializarVariables();
	m_centro = centro;
	m_radio = radio;
	COLOR_FORMA = color;
	m_color = COLOR_FORMA;
	m_masa = m_radio;
	inicializarForma();
}

Bola::Bola(const Bola& other)
{
	inicializarVariables();
	m_centro = other.m_centro;
	m_radio = other.m_radio;
	COLOR_FORMA = other.m_color;
	m_color = COLOR_FORMA;
}

Bola& Bola::operator=(const Bola& other)
{
	m_vertices.clear();
	m_vertices = other.m_vertices;
	m_centro = other.m_centro;
	m_radio = other.m_radio;
	COLOR_FORMA = other.m_color;
	m_color = COLOR_FORMA;
	return *this;
}

Bola::~Bola()
{
	m_vertices.clear();
}

void Bola::setPosicion(float x, float y)
{
	m_centro.x = x;
	m_centro.y = y;
	inicializarForma();
}

void Bola::setAceleracion(sf::Vector2f aceleracion)
{
	m_aceleracion.x = aceleracion.x;
	m_aceleracion.y = aceleracion.y;
}

void Bola::setVelocidad(sf::Vector2f velocidad)
{
	m_velocidad = velocidad;
}

const sf::Vector2f Bola::getVelocidad() const
{
	return m_velocidad;
}

void Bola::actualizarVelocidad(float deltaTime)
{
	m_aceleracion = -m_velocidad * VISCOSIDAD;
	m_velocidad += m_aceleracion * deltaTime;
	setPosicion(m_centro.x + m_velocidad.x * deltaTime, m_centro.y + m_velocidad.y * deltaTime);
	setAngulo(atan2f(m_velocidad.y, m_velocidad.x) * 180.f / M_PI);
	if (std::abs(m_velocidad.x) < 0.1f || std::abs(m_velocidad.y) < 0.1f)
	{
		m_velocidad = sf::Vector2f(0.f, 0.f);
	}
}

sf::Vector2f Bola::getPosicion()
{
	return m_centro;
}

float Bola::getRadio()
{
	return m_radio;
}

float Bola::getMasa()
{
	return m_masa;
}

void Bola::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(m_vertices);
}

void Bola::mover(sf::Vector2f velocidad)
{
	setPosicion(m_centro.x + velocidad.x, m_centro.y + velocidad.y);
}

void Bola::setAngulo(float angulo)
{
	m_angulo = angulo;
}

void Bola::rota(float angulo)
{
	setAngulo(m_angulo + angulo);
}

void Bola::actualizarColisionBorde(const sf::RenderWindow& ventana)
{
	if ((m_centro.x + m_radio) > ventana.getSize().x)
	{
		setPosicion(ventana.getSize().x - m_radio, m_centro.y);
		m_velocidad.x = -m_velocidad.x;
	}
	if ((m_centro.x - m_radio) < 0.f)
	{
		setPosicion(m_radio, m_centro.y);
		m_velocidad.x = -m_velocidad.x;
	}
	if ((m_centro.y + m_radio) > ventana.getSize().y)
	{
		setPosicion(m_centro.x, ventana.getSize().y - m_radio);
		m_velocidad.y = -m_velocidad.y;
	}
	if ((m_centro.y - m_radio) < 0.f)
	{
		setPosicion(m_centro.x, m_radio);
		m_velocidad.y = -m_velocidad.y;
	}
}

bool Bola::verificarColisionPunto(const sf::Vector2f& mouse)
{
	float x_mouse = mouse.x;
	float y_mouse = mouse.y;
	if (((x_mouse - m_centro.x) * (x_mouse - m_centro.x) +
		(y_mouse - m_centro.y) * (y_mouse - m_centro.y)) <= m_radio * m_radio)
	{
		return true;
	}
	m_color = COLOR_FORMA;
	return false;
}

void Bola::actualizar(const sf::RenderWindow& ventana, float deltaTime)
{
	actualizarColisionBorde(ventana);
	actualizarVelocidad(deltaTime);
}
