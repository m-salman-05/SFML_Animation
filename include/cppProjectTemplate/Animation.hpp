#ifndef INCLUDE_ANIMATION_HPP
#define INCLUDE_ANIMATION_HPP

#include <SFML/Graphics.hpp>

class Animation
{
public:
    Animation(sf::Texture* texture, sf::Vector2u imageCount, float switchTime);
    ~Animation() = default;
    Animation(const Animation&) = delete;
    Animation& operator=(const Animation&) = delete;

    void update(int row, float deltaTime);

    sf::IntRect m_uvRect;   // srcrect??? for animation???

private:
    sf::Vector2u m_imageCount;  // i think this is the frames you want to animate
    sf::Vector2u m_currentImage;    // this is the current image location that we're accessing in the row???
    float m_totalTime;  // total time for all frames to animate???
    float m_switchTime; // time for which each frame lasts???
};

// i think the m_imageCount is a vector because we are interested in the number of images in each row, and the total number of rows.
// each row is an animation of a certain actions.

#endif // INCLUDE_ANIMATION_HPP