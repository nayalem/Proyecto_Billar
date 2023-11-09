#include "GUI.h"
#include <SFML/Graphics/Color.hpp>
#include <SFML/Graphics/RenderStates.hpp>
#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/Graphics/Text.hpp>
#include <SFML/Window/Event.hpp>
#include <string>

GUI::GUI()
{
    fuente.loadFromFile("/usr/share/fonts/truetype/freefont/FreeSerif.ttf");

    jugador1.puntos = 0;
    jugador1.numero = 0;

    jugador1.textoNumero.setFont(fuente);
    jugador1.textoPuntos.setFont(fuente);
    jugador1.textoNumero.setString("Jugador 1");
    jugador1.textoNumero.setPosition(200, 100);
    jugador1.textoNumero.setCharacterSize(40);

    jugador1.textoPuntos.setCharacterSize(35);
    jugador1.textoPuntos.setString(std::to_string(jugador1.puntos));
    jugador1.textoPuntos.setPosition(250, 170);

    jugador2.puntos = 0;
    jugador2.numero = 1;

    jugador2.textoNumero.setFont(fuente);
    jugador2.textoPuntos.setFont(fuente);
    jugador2.textoNumero.setString("Jugador 2\n");
    jugador2.textoNumero.setPosition(1250, 100);
    jugador2.textoNumero.setCharacterSize(40);

    jugador2.textoPuntos.setCharacterSize(35);
    jugador2.textoPuntos.setString(std::to_string(jugador2.puntos));
    jugador2.textoPuntos.setPosition(1300, 170);

    jugadorActual = jugador1;
    juegoEnPausa = false;
}

GUI::~GUI()
{

}

void GUI::setJugadorActual(Jugador jugador)
{
    jugadorActual = jugador;
}

void GUI::setJugadorActual(int numero)
{
    if (numero == 0)
    {
        jugadorActual = jugador1;
    }
    if (numero == 1)
    {
        jugadorActual = jugador2;
    }
}

GUI::Jugador GUI::getJugadorActual()
{
    return jugadorActual;
}

void GUI::sumarPuntos(Jugador jugador)
{
    if (jugador.numero == 0)
    {
        jugador1.puntos++;
    }
    if (jugador.numero == 1)
    {
        jugador2.puntos++;
    }
}

void GUI::reiniciar()
{
    juegoEnPausa = false;
    jugador1.puntos = 0;
    jugador2.puntos = 0;
    jugadorActual = jugador1;
}

void GUI::actualizar(sf::RenderWindow* ventana, bool& enPausa, bool& reiniciar, sf::Vector2f raton, sf::Event evento)
{
    jugador1.textoNumero.setString("Jugador 1");
    jugador1.textoPuntos.setString(std::to_string(jugador1.puntos));
    jugador2.textoNumero.setString("Jugador 2");
    jugador2.textoPuntos.setString(std::to_string(jugador2.puntos));
    jugador1.textoNumero.setOutlineThickness(0.f);
    jugador2.textoNumero.setOutlineThickness(0.f);
    if (jugadorActual.numero == 0)
    {
        jugador1.textoNumero.setOutlineThickness(3.f);
        jugador1.textoNumero.setOutlineColor(sf::Color(0, 0, 0, 100));
    }
    if (jugadorActual.numero == 1)
    {
        jugador2.textoNumero.setOutlineThickness(3.f);
        jugador2.textoNumero.setOutlineColor(sf::Color(0, 0, 0, 100));
    }

    menu.actualizar(ventana, enPausa, reiniciar, raton, evento);
}

void GUI::draw(sf::RenderTarget& objetivo, sf::RenderStates estados) const
{
    if (juegoEnPausa)
    {
        objetivo.draw(menu);
    }

    objetivo.draw(jugador1.textoNumero);
    objetivo.draw(jugador1.textoPuntos);
    objetivo.draw(jugador2.textoNumero);
    objetivo.draw(jugador2.textoPuntos);
}
