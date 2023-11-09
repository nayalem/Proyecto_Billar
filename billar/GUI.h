#ifndef GUI_H
#define GUI_H

#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/Font.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/RenderStates.hpp>
#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/Graphics/Text.hpp>
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Window/Event.hpp>

#include "Menu.h"

class GUI : public sf::Drawable
{
public:
	GUI();
	~GUI();

	struct Jugador
	{
		sf::Text textoNumero;
		sf::Text textoPuntos;
		int puntos;
		int numero;
	};
	void setJugadorActual(Jugador);
	void setJugadorActual(int);
	Jugador getJugadorActual();
	void sumarPuntos(Jugador);

	bool juegoEnPausa;

	void reiniciar();
	void actualizar(sf::RenderWindow* ventana, bool& enPausa, bool& reiniciar, sf::Vector2f raton, sf::Event evento);
private:
	sf::Font fuente;

	Menu menu;
	Jugador jugador1;
	Jugador jugador2;
	Jugador jugadorActual;


	virtual void draw(sf::RenderTarget& objetivo, sf::RenderStates estados) const;

};

#endif
