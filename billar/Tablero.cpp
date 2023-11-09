#include "Tablero.h"
#include <SFML/Graphics/Color.hpp>
#include <SFML/Graphics/ConvexShape.hpp>
#include <SFML/Graphics/PrimitiveType.hpp>
#include <SFML/Graphics/Rect.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/Graphics/Vertex.hpp>
#include <SFML/Graphics/VertexArray.hpp>
#include <SFML/System/Vector2.hpp>
#include <SFML/Window/Mouse.hpp>
#include <vector>

Tablero::Tablero()
{
	//texture.loadFromFile("/home/user/C++/SFML/billiard/images/textureBoard.png", sf::IntRect(1,1,454,848));
	textura.loadFromFile("./Imagen/Texturatablero.png", sf::IntRect(1, 1, 454, 848));
	sprite.setTexture(textura);
	sprite.setPosition(572.5f, 25.f);
	inicializarLineasDeBorde();
	inicializarAgujeros();
}

Tablero::~Tablero()
{
	lineasDeBorde.clear();
	agujeros.clear();
}

void Tablero::inicializarLineasDeBorde()
{
	Linea lineaArribaIzq(602.5f, 40.f, 617.f, 55.f);
	Linea lineaArriba(617.f, 55.f, 983.5, 55.f);
	Linea lineaArribaDer(983.5f, 55.f, 998.5f, 40.f);
	lineasDeBorde.push_back(lineaArribaIzq);
	lineasDeBorde.push_back(lineaArriba);
	lineasDeBorde.push_back(lineaArribaDer);

	Linea lineaArribaDerIzq(1012.5f, 54.f, 997.5f, 69.5f);
	Linea lineaArribaDer(997.5f, 69.5f, 997.5f, 433.5f);
	Linea lineaArribaDerDer(997.5f, 433.5f, 1012.5f, 442.f);
	lineasDeBorde.push_back(lineaArribaDerIzq);
	lineasDeBorde.push_back(lineaArribaDer);
	lineasDeBorde.push_back(lineaArribaDerDer);

	Linea lineaAbajoDerIzq(1012.5f, 458.5f, 997.5f, 466.5f);
	Linea lineaAbajoDer(997.5f, 466.5f, 997.5f, 830.5f);
	Linea lineaAbajoDerDer(997.5f, 830.5f, 1012.5f, 846.f);
	lineasDeBorde.push_back(lineaAbajoDerIzq);
	lineasDeBorde.push_back(lineaAbajoDer);
	lineasDeBorde.push_back(lineaAbajoDerDer);

	Linea lineaAbajoIzq(998.5f, 860.f, 983.5f, 845.f);
	Linea lineaAbajo(983.5f, 845.f, 616.5f, 845.f);
	Linea lineaAbajoDer(616.5f, 845.f, 602.5f, 860.5f);
	lineasDeBorde.push_back(lineaAbajoIzq);
	lineasDeBorde.push_back(lineaAbajo);
	lineasDeBorde.push_back(lineaAbajoDer);

	Linea lineaAbajoIzqIzq(587.5f, 846.f, 602.5f, 830.5f);
	Linea lineaAbajoIzq(602.5f, 830.5f, 602.5f, 466.5f);
	Linea lineaAbajoIzqDer(602.5f, 466.5f, 587.5f, 458.5f);
	lineasDeBorde.push_back(lineaAbajoIzqIzq);
	lineasDeBorde.push_back(lineaAbajoIzq);
	lineasDeBorde.push_back(lineaAbajoIzqDer);

	Linea lineaArribaIzqIzq(587.5f, 442.5f, 602.5f, 433.5f);
	Linea lineaArribaIzq(602.5f, 433.5f, 602.5f, 69.5f);
	Linea lineaArribaIzqDer(602.5f, 69.5f, 587.5f, 54.f);
	lineasDeBorde.push_back(lineaArribaIzqIzq);
	lineasDeBorde.push_back(lineaArribaIzq);
	lineasDeBorde.push_back(lineaArribaIzqDer);
}

void Tablero::inicializarAgujeros()
{
	Linea agujeroArribaIzq(582.5f, 49.f, 596.5f, 35.f);
	agujeros.push_back(agujeroArribaIzq);

	Linea agujeroArribaDer(1003.5f, 35.f, 1017.5f, 49.f);
	agujeros.push_back(agujeroArribaDer);

	Linea agujeroDerecha(1012.5f, 442.f, 1012.5f, 458.5f);
	agujeros.push_back(agujeroDerecha);

	Linea agujeroAbajoDerecha(1017.5f, 851.f, 1003.5f, 865.f);
	agujeros.push_back(agujeroAbajoDerecha);

	Linea agujeroAbajoIzq(596.5f, 865.5f, 582.5f, 851.f);
	agujeros.push_back(agujeroAbajoIzq);

	Linea agujeroIzquierda(587.5f, 458.5f, 587.5f, 442.5f);
	agujeros.push_back(agujeroIzquierda);
}

std::vector<Linea> Tablero::obtenerLineasDeBorde()
{
	return lineasDeBorde;
}

std::vector<Linea> Tablero::obtenerAgujeros()
{
	return agujeros;
}

void Tablero::actualizar()
{

}

void Tablero::renderizar(sf::RenderTarget* objetivo)
{
	objetivo->draw(sprite);
	// Dibujar líneas del tablero y agujeros
	/*for (auto i : agujeros)
	{
		objetivo->draw(i);
	}
	for (auto i : lineasDeBorde)
	{
		objetivo->draw(i);
	}*/
}
