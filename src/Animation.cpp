#include "SFML_Animation/Animation.hpp"

Animation::Animation(sf::Texture* texture, sf::Vector2u imageCount, float switchTime)
    : m_imageCount{ imageCount },
    m_currentImage{ 0, 0 },  // i have set the .y = 0 on my own
    m_totalTime{ 0.f },
    m_switchTime{ switchTime }
{
    // size of the texture to be loaded
    m_uvRect.width = texture->getSize().x / imageCount.x;
    m_uvRect.height = texture->getSize().y / imageCount.y;
}

void Animation::update(int row, float deltaTime)
{
    m_currentImage.y = row;
    m_totalTime += deltaTime;

    if (m_totalTime > m_switchTime)
    {
        m_totalTime -= m_switchTime;   // not sure about its purpose
        m_currentImage.x = (m_currentImage.x + 1) % m_imageCount.x;
    }

    m_uvRect.left = m_currentImage.x * m_uvRect.width;
    m_uvRect.top = m_currentImage.y * m_uvRect.height;
}
