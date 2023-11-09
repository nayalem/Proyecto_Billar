#pragma once
#ifndef TABLERO_H
#define TABLERO_H

#include <SFML/Graphics/ConvexShape.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/VertexArray.hpp>
#include <iostream>

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <vector>

#include "Linea.h"

class Tablero
{
public:
	Tablero();
	~Tablero();

	std::vector<Linea> obtenerLineasDeBorde();
	std::vector<Linea> obtenerAgujeros();

	void actualizar();
	void renderizar(sf::RenderTarget* objetivo);

private:
	sf::Sprite sprite;
	sf::Texture textura;
	std::vector<Linea> lineasDeBorde;
	std::vector<Linea> agujeros;

	void inicializarLineasDeBorde();
	void inicializarAgujeros();
};

#endif
