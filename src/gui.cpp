#include "gui.h"

void GUI::Draw(Rectangle& rect)
{

    ImGui::Begin("Window Title");
    ImGui::Text("Press B to invert movement");

    ImGui::ColorEdit3("Color", rect.GetColors());
    ImGui::SameLine();
    ImGui::Checkbox("Draw Logo", &rect.GetShouldDraw());

    
    float speedX = rect.GetSpeedX();
    bool negative_flag = CheckNegative(speedX);
    if (negative_flag)
        speedX *= -1.0f;
    if (ImGui::SliderFloat("Speed X", &speedX, 0.0f, 20.0f, "%.2f")) {
        if (negative_flag)
            rect.SetSpeedX(speedX * -1.0f);
        else
            rect.SetSpeedX(speedX);
    }

    float speedY = rect.GetSpeedY();
    negative_flag = CheckNegative(speedY);
    if (negative_flag)
        speedY *= -1.0f;
    if (ImGui::SliderFloat("Speed X", &speedY, 0.0f, 20.0f, "%.2f")) {
        if (negative_flag)
            rect.SetSpeedY(speedY * -1.0f);
        else
            rect.SetSpeedY(speedY);
    }

    //ImGui::SliderFloat("Speed X", &rect.GetSpeedX(), 0.0f, 20.0f, "%.2f");
    //ImGui::SliderFloat("Speed Y", &rect.GetSpeedY(), 0.0f, 20.0f, "%.2f");

    if (ImGui::Button("Reset Logo"))
        rect.SetPosition({ 0.0f, 0.0f });

    ImGui::End();
}

bool GUI::CheckNegative(float speed) 
{
    if (speed < 0)
        return true;
    else
        return false;
}