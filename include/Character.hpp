#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include <string>

#include "Util/GameObject.hpp"
#include "Util/Logger.hpp"

class Character : public Util::GameObject {
public:
    explicit Character(const std::string& ImagePath);

    Character(const Character&) = delete;

    Character(Character&&) = delete;

    Character& operator=(const Character&) = delete;

    Character& operator=(Character&&) = delete;

    [[nodiscard]] const std::string& GetImagePath() const { return m_ImagePath; }

    [[nodiscard]] const glm::vec2& GetPosition() const { return m_Transform.translation; }

    [[nodiscard]] bool GetVisibility() const { return m_Visible; }

    void SetImage(const std::string& ImagePath);

    void SetPosition(const glm::vec2& Position) { m_Transform.translation = Position; }

    // TODO: Implement the collision detection
    [[nodiscard]] bool IfCollides(const std::shared_ptr<Character>& other) const {
        if(other == nullptr) return false;
        
        const glm::vec2& this_position = this->GetPosition();
        const glm::vec2& other_position = other->GetPosition();

        float dx = this_position.x - other_position.x;
        float dy = this_position.y - other_position.y;
        float d = dx * dx + dy * dy;
        // LOG_DEBUG("d = " + std::to_string(d));
        return d <= 3500;
    }

    // TODO: Add and implement more methods and properties as needed to finish Giraffe Adventure.
    // [[nodiscard]] const glm::vec2& GetPositionX() const { return m_Transform.translation; }



private:
    void ResetPosition() { m_Transform.translation = {0, 0}; }

    std::string m_ImagePath;
};


#endif //CHARACTER_HPP
