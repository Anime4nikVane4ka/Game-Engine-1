#include "gui.h"

void GUI::Draw(Rectangle& rect)
{

    ImGui::Begin("Window Title");
    ImGui::Text("Press B to invert movement");

    const auto& logoNames = rect.GetLogoNames();
    
    //if (ImGui::BeginCombo("Current logo", logoNames[currentIndex].c_str()))
    //{
    //        for (int i = 0; i < logoNames.size(); ++i)
    //        {
    //            const bool isSelected = (i == currentIndex);

    //            if (ImGui::Selectable(logoNames[i].c_str(), isSelected))
    //                rect.SetCurrentLogoIndex(i);

    //            if (isSelected)
    //                ImGui::SetItemDefaultFocus();
    //        }

    //        ImGui::EndCombo();
    //}
    for (int i = 0; i < logoNames.size(); ++i)
    {
        if (ImGui::Button(logoNames[i].c_str()))
            rect.SetCurrentLogoIndex(i);
        ImGui::SameLine();
    }
    ImGui::NewLine();
    ImGui::ColorEdit3("Color", rect.GetColors());
    
    float speedX = rect.GetSpeedX();
    float negative_flag = CheckNegative(speedX);
    speedX *= negative_flag;
    if (ImGui::SliderFloat("Speed X", &speedX, 0.0f, 20.0f, "%.2f"))       
        rect.SetSpeedX(speedX * negative_flag);

    float speedY = rect.GetSpeedY();
    negative_flag = CheckNegative(speedY);
    speedY *= negative_flag;
    if (ImGui::SliderFloat("Speed Y", &speedY, 0.0f, 20.0f, "%.2f"))
        rect.SetSpeedY(speedY * negative_flag);

    float scale = rect.GetScaleFactor();
    if (ImGui::SliderFloat("Scale", &scale, 0.0f, 2.0f, "%.3f"))
        rect.SetScaleFactor(scale);

    //ImGui::SliderFloat("Speed X", &rect.GetSpeedX(), 0.0f, 20.0f, "%.2f");
    //ImGui::SliderFloat("Speed Y", &rect.GetSpeedY(), 0.0f, 20.0f, "%.2f");

    ImGui::Checkbox("Draw Logo", &rect.GetShouldDraw());
    ImGui::SameLine();
    if (ImGui::Button("Reset Logo"))
        rect.SetPosition({ 0.0f, 0.0f });

    ImGui::End();
}

float GUI::CheckNegative(float speed) 
{
    if (speed < 0)
        return -1.0f;
    else
        return 1.0f;
}