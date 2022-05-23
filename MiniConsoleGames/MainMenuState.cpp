#include <sstream>
#include "MainMenuState.h"
#include "definicje.h" 
#include "StateGry.h"
#include "SnakeState.h"
#include "MahjongState.h"
#include <iostream>


namespace Engine
{
	MainMenuState::MainMenuState(DaneGryRef dane) : _dane(dane)
	{

	}

	void MainMenuState::Init()
	{
		this->_dane->assets.WczytajTexture("Tlo", MAIN_MENU_TLO_SCIEZKAPLIK);
		this->_dane->assets.WczytajTexture("Przycisk Play", MAIN_MENU_PLAY_PRZYCISK);
		this->_dane->assets.WczytajTexture("Przycisk Play Zewnetrzny", MAIN_MENU_PLAY_PRZYCISK_ZEW);
		this->_dane->assets.WczytajTexture("Tytul Gry", MAIN_MENU_TYTUL_SCIEZKAPLIK);
		
		this->_dane->assets.WczytajTexture("Drugi przycisk", DRUGI_PRZYCISK); //snake

		this->_tlo.setTexture(this->_dane->assets.WczytajTexture("Tlo"));
		this->_playPrzycisk.setTexture(this->_dane->assets.WczytajTexture("Przycisk Play"));
		this->_playPrzyciskZew.setTexture(this->_dane->assets.WczytajTexture("Przycisk Play Zewnetrzny"));
		this->_tytul.setTexture(this->_dane->assets.WczytajTexture("Tytul Gry"));

		this->_drugiPrzycisk.setTexture(this->_dane->assets.WczytajTexture("Drugi przycisk")); //snake

		this->_playPrzycisk.setPosition((SCREEN_WIDTH / 2) - (this->_playPrzycisk.getGlobalBounds().width / 2), (SCREEN_HEIGHT / 3) - (this->_playPrzycisk.getGlobalBounds().height / 3));
		this->_playPrzyciskZew.setPosition((SCREEN_WIDTH / 2) - (this->_playPrzyciskZew.getGlobalBounds().width / 2), (SCREEN_HEIGHT / 3) - (this->_playPrzyciskZew.getGlobalBounds().height / 3));
		this->_tytul.setPosition((SCREEN_WIDTH / 2) - (this->_tytul.getGlobalBounds().width / 2), (SCREEN_HEIGHT / 2) - (this->_tytul.getGlobalBounds().height * 1.8));

		this->_drugiPrzycisk.setPosition((SCREEN_WIDTH / 2) - (this->_drugiPrzycisk.getGlobalBounds().width / 2), (SCREEN_HEIGHT / 3) - (this->_drugiPrzycisk.getGlobalBounds().height * (-0.2))); //snake

	}

	void MainMenuState::HandleInput()
	{
		sf::Event event;

		while (this->_dane->window.pollEvent(event))
		{
			if (sf::Event::Closed == event.type)
			{
				this->_dane->window.close();
			}

			if (this->_dane->wczytywanie.CzySpriteKlikniety(this->_playPrzycisk, sf::Mouse::Left, this->_dane->window))
			{
				this->_dane->maszyna.DodajState(StateRef(new StateGry(_dane)), true);
			}

			else if (this->_dane->wczytywanie.CzySpriteKlikniety(this->_drugiPrzycisk, sf::Mouse::Left, this->_dane->window))
			{
				this->_dane->maszyna.DodajState(StateRef(new MahjongState(_dane)), true);
			}

		}
	}

	void MainMenuState::Update(float dt)
	{

	}

	void MainMenuState::Draw(float dt)
	{
		this->_dane->window.clear();
		this->_dane->window.draw( this->_tlo);
		this->_dane->window.draw( this->_playPrzycisk);
		this->_dane->window.draw( this->_playPrzyciskZew);
		this->_dane->window.draw(this->_drugiPrzycisk);
		this->_dane->window.draw( this->_tytul);

		this->_dane->window.display();

	}

}

//specyfikacja main menu i ustawienie przycisków