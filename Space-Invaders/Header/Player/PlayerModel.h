#pragma once
#include<SFML/Graphics.hpp>

enum class PlayerState 
{
    ALIVE,
    DEAD,
    
};

class PlayerModel
{
private:

    const sf::Vector2f initial_player_position = sf::Vector2f(500.f, 500.f); 
    sf::Vector2f player_position; 
    PlayerState player_state; 
    int player_score;

public:

    const float player_movement_speed = 200.0f;

    PlayerModel();
    ~PlayerModel();

    void initialize();

    void reset(); 

    int getPlayerScore();
    void setPlayerScore(int value);

    sf::Vector2f getPlayerPosition();
    void setPlayerPosition(sf::Vector2f position);

    bool getPlayerAlive();
    void setPlayerAlive(bool alive);

};