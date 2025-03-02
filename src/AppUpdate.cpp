#include "App.hpp"

#include "Util/Input.hpp"
#include "Util/Keycode.hpp"

void App::Update() {

    // TODO: Add your own logics to finish the tasks in README.md
    if (Util::Input::IsKeyPressed(Util::Keycode::W)) {
        m_Giraffe->SetPosition({m_Giraffe->GetPosition().x, m_Giraffe->GetPosition().y + 5.0f});
    }
    if (Util::Input::IsKeyPressed(Util::Keycode::S)) {
        m_Giraffe->SetPosition({m_Giraffe->GetPosition().x, m_Giraffe->GetPosition().y - 5.0f});
    }
    if (Util::Input::IsKeyPressed(Util::Keycode::A)) {
        m_Giraffe->SetPosition({m_Giraffe->GetPosition().x - 5.0f, m_Giraffe->GetPosition().y});
    }
    if (Util::Input::IsKeyPressed(Util::Keycode::D)) {
        m_Giraffe->SetPosition({m_Giraffe->GetPosition().x + 5.0f, m_Giraffe->GetPosition().y});
    }

    if (m_Giraffe->IfCollides(m_Chest)){
        m_Chest->SetVisible(false);
    }

    for(int i = 0;i < 3;i++){
        if(m_Giraffe->IfCollides(m_Doors[i]) && m_Doors[i]->GetVisibility()){
            m_Doors[i]->SetImage(GA_RESOURCE_DIR"/Image/Character/door_open.png");            
        }
    }
    /*
     *  Do not touch the code below as they serve the purpose for validating the tasks,
     *  rendering the frame, and exiting the game.
    */

    if (Util::Input::IsKeyPressed(Util::Keycode::ESCAPE) || Util::Input::IfExit()) {
        m_CurrentState = State::END;
    }

    if (m_EnterDown) {
        if (!Util::Input::IsKeyPressed(Util::Keycode::RETURN)) {
            ValidTask();
        }
    }
    m_EnterDown = Util::Input::IsKeyPressed(Util::Keycode::RETURN);

    m_Root.Update();
}
