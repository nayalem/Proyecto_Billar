#pragma once
#ifndef BOLA_H
#define BOLA_H

#include <SFML/Graphics.hpp>
#include <SFML/Graphics/CircleShape.hpp>
#include <SFML/Graphics/Color.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>

#include <cmath>

class Bola : public sf::Drawable
{
public:

	Bola();
	Bola(sf::Vector2f centro, float radio, sf::Color color);
	~Bola();

	Bola(const Bola&);
	Bola& operator=(const Bola&);
	void setPosicion(float x, float y);
	void setAngulo(float angulo);
	void setAceleracion(sf::Vector2f aceleracion);
	void setVelocidad(sf::Vector2f velocidad);

	sf::Vector2f getPosicion();
	const sf::Vector2f getVelocidad() const;
	sf::Vector2f getAceleracion();
	float getRadio();
	float getMasa();

	void mover(sf::Vector2f velocidad);
	void rota(float angulo);

	void actualizarVelocidad(float deltaTime);
	bool verificarColisionPunto(const sf::Vector2f& mouse);
	void actualizarColisionBorde(const sf::RenderWindow& ventana);

	void actualizar(const sf::RenderWindow& ventana, float deltaTime);
	void renderizar();

private:
	unsigned int MAX_PUNTOS;
	float VISCOSIDAD;
	sf::VertexArray m_vertices;
	sf::Color COLOR_FORMA;
	sf::Color m_color;
	sf::Vector2f viscosidad;
	sf::Vector2f m_centro;
	sf::Vector2f m_velocidad;
	sf::Vector2f m_aceleracion;
	float m_radio;
	float m_angulo;
	float m_masa;
	void inicializarVariables();
	void inicializarForma();
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
};

#endif
