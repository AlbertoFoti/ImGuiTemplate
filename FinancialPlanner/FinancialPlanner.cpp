#include "FinancialPlanner.h"

void FinancialPlanner::Init(GLFWwindow* window, const char* glsl_version)
{
	IMGUI_CHECKVERSION();
	ImGui::CreateContext();
    ImGuiIO& io = ImGui::GetIO(); (void)io;
    io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;       // Enable Keyboard Controls
    //io.ConfigFlags |= ImGuiConfigFlags_NavEnableGamepad;      // Enable Gamepad Controls
    io.ConfigFlags |= ImGuiConfigFlags_DockingEnable;           // Enable Docking
    //io.ConfigFlags |= ImGuiConfigFlags_ViewportsEnable;         // Enable Multi-Viewport / Platform Windows
    //io.ConfigViewportsNoAutoMerge = true;
    //io.ConfigViewportsNoTaskBarIcon = true;
	
	// Setup Platform/Renderer bindings
	ImGui_ImplGlfw_InitForOpenGL(window, true);
	ImGui_ImplOpenGL3_Init(glsl_version);
	ImGui::StyleColorsDark();
}

void FinancialPlanner::Update() 
{
    static bool opt_fullscreen = true;
    static bool opt_padding = false;
    static ImGuiDockNodeFlags dockspace_flags = ImGuiDockNodeFlags_None;

    // We are using the ImGuiWindowFlags_NoDocking flag to make the parent window not dockable into,
    // because it would be confusing to have two docking targets within each others.
    ImGuiWindowFlags window_flags = ImGuiWindowFlags_MenuBar | ImGuiWindowFlags_NoDocking;
    if (opt_fullscreen)
    {
        const ImGuiViewport* viewport = ImGui::GetMainViewport();
        ImGui::SetNextWindowPos(viewport->WorkPos);
        ImGui::SetNextWindowSize(viewport->WorkSize);
        ImGui::SetNextWindowViewport(viewport->ID);
        ImGui::PushStyleVar(ImGuiStyleVar_WindowRounding, 0.0f);
        ImGui::PushStyleVar(ImGuiStyleVar_WindowBorderSize, 0.0f);
        window_flags |= ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoMove;
        window_flags |= ImGuiWindowFlags_NoBringToFrontOnFocus | ImGuiWindowFlags_NoNavFocus;
    }
    else
    {
        dockspace_flags &= ~ImGuiDockNodeFlags_PassthruCentralNode;
    }

    // When using ImGuiDockNodeFlags_PassthruCentralNode, DockSpace() will render our background
    // and handle the pass-thru hole, so we ask Begin() to not render a background.
    if (dockspace_flags & ImGuiDockNodeFlags_PassthruCentralNode)
        window_flags |= ImGuiWindowFlags_NoBackground;

    // Important: note that we proceed even if Begin() returns false (aka window is collapsed).
    // This is because we want to keep our DockSpace() active. If a DockSpace() is inactive,
    // all active windows docked into it will lose their parent and become undocked.
    // We cannot preserve the docking relationship between an active window and an inactive docking, otherwise
    // any change of dockspace/settings would lead to windows being stuck in limbo and never being visible.
    if (!opt_padding)
        ImGui::PushStyleVar(ImGuiStyleVar_WindowPadding, ImVec2(0.0f, 0.0f));
    ImGui::Begin("DockSpace Demo", nullptr, window_flags);
    if (!opt_padding)
        ImGui::PopStyleVar();

    if (opt_fullscreen)
        ImGui::PopStyleVar(2);

    // Submit the DockSpace
    ImGuiIO& io = ImGui::GetIO();
    if (io.ConfigFlags & ImGuiConfigFlags_DockingEnable)
    {
        ImGuiID dockspace_id = ImGui::GetID("MyDockSpace");
        ImGui::DockSpace(dockspace_id, ImVec2(0.0f, 0.0f), dockspace_flags);
    }

    if (ImGui::BeginMenuBar())
    {
        if (ImGui::BeginMenu("Options"))
        {
            // Disabling fullscreen would allow the window to be moved to the front of other windows,
            // which we can't undo at the moment without finer window depth/z control.
            ImGui::MenuItem("Fullscreen", NULL, &opt_fullscreen);
            ImGui::MenuItem("Padding", NULL, &opt_padding);
            ImGui::Separator();

            if (ImGui::MenuItem("Flag: NoSplit", "", (dockspace_flags & ImGuiDockNodeFlags_NoSplit) != 0)) { dockspace_flags ^= ImGuiDockNodeFlags_NoSplit; }
            if (ImGui::MenuItem("Flag: NoResize", "", (dockspace_flags & ImGuiDockNodeFlags_NoResize) != 0)) { dockspace_flags ^= ImGuiDockNodeFlags_NoResize; }
            if (ImGui::MenuItem("Flag: NoDockingInCentralNode", "", (dockspace_flags & ImGuiDockNodeFlags_NoDockingInCentralNode) != 0)) { dockspace_flags ^= ImGuiDockNodeFlags_NoDockingInCentralNode; }
            if (ImGui::MenuItem("Flag: AutoHideTabBar", "", (dockspace_flags & ImGuiDockNodeFlags_AutoHideTabBar) != 0)) { dockspace_flags ^= ImGuiDockNodeFlags_AutoHideTabBar; }
            if (ImGui::MenuItem("Flag: PassthruCentralNode", "", (dockspace_flags & ImGuiDockNodeFlags_PassthruCentralNode) != 0, opt_fullscreen)) { dockspace_flags ^= ImGuiDockNodeFlags_PassthruCentralNode; }
            ImGui::Separator();
            ImGui::EndMenu();
        }

        ImGui::EndMenuBar();
    }

    // Your GUIs go Here !
    this->ShowCompoundInterestCalculator("Compound Interest Calculator");
    this->ShowDemoWindow();

    ImGui::End();
}

void FinancialPlanner::Render() 
{
	// Render dear imgui into screen
	ImGui::Render();
	ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
}

void FinancialPlanner::Shutdown() 
{
	// Cleanup
	ImGui_ImplOpenGL3_Shutdown();
	ImGui_ImplGlfw_Shutdown();
	ImGui::DestroyContext();
}

void FinancialPlanner::NewFrame()
{
	// feed inputs to dear imgui, start new frame
	ImGui_ImplOpenGL3_NewFrame();
	ImGui_ImplGlfw_NewFrame();
	ImGui::NewFrame();
}

// Other helper Functions ================================================

void FinancialPlanner::ShowCompoundInterestCalculator(const char *nameGUI)
{
    // create your GUI
    ImGui::Begin(nameGUI);

    // Basics ================================================
    ImGui::BulletText("Initial NW");
    static char initialNW[50] = "10000.00";
    ImGui::InputText("NW", &initialNW[0], IM_ARRAYSIZE(initialNW));

    ImGui::BulletText("Expected interest rate (%%) [IR]");
    static char interestRate[50] = "10.00";
    ImGui::InputText("IR", &interestRate[0], IM_ARRAYSIZE(interestRate));

    ImGui::BulletText("Annual Deposits [AD]");
    static char annualDeposits[50] = "1000";
    ImGui::InputText("AD", &annualDeposits[0], IM_ARRAYSIZE(annualDeposits));

    ImGui::BulletText("Years of investment [IR]");
    static char investmentYears[50] = "10";
    ImGui::InputText("YI", &investmentYears[0], IM_ARRAYSIZE(investmentYears));

    ImGui::Spacing();

    static double initialNW_d = 0.00;
    static double interestRate_d = 0.00;
    static int investmentYears_d = 0;
    static double annualDeposits_d = 0.00;

    static double NWendPeriod_d = 0.00;
    static double totalDeposits_d = 0.00;
    static double totalInterests_d = 0.00;

    // Error Input Parameters
    static char OutputErrorString[50] = {};
    ImGui::Text("%s", OutputErrorString);

    if (ImGui::Button("Calculate")) {
        if (strcmp(initialNW, "") && strcmp(interestRate, "") && strcmp(annualDeposits, "") && strcmp(investmentYears, "")) {
            initialNW_d = std::stod(initialNW);
            interestRate_d = std::stod(interestRate);
            annualDeposits_d = std::stod(annualDeposits);
            investmentYears_d = std::stoi(investmentYears);
            NWendPeriod_d = this->core.CompoundInterestCalculate(initialNW_d, interestRate_d, annualDeposits_d, investmentYears_d);

            totalDeposits_d = initialNW_d + (annualDeposits_d * investmentYears_d);
            totalInterests_d = NWendPeriod_d - totalDeposits_d;

            sprintf(OutputErrorString, "%s", "");
        }
        else {
            NWendPeriod_d = 0.00;
            totalDeposits_d = 0.00;
            totalInterests_d = 0.00;
            sprintf(OutputErrorString, "%s", "Error! Complete All Input Fields!");
        }
    };

    // Calculation Result
    ImGui::BulletText("End of Period NW : ");
    static char NWendPeriod_s[50] = {};
    sprintf(NWendPeriod_s, "%.2f", NWendPeriod_d);
    ImGui::InputText("final NW", NWendPeriod_s, IM_ARRAYSIZE(NWendPeriod_s), ImGuiInputTextFlags_ReadOnly);

    ImGui::BulletText("Total Deposits   : ");
    static char totalDeposits[50] = {};
    sprintf(totalDeposits, "%.2f", totalDeposits_d);
    ImGui::InputText("total deposits", totalDeposits, IM_ARRAYSIZE(totalDeposits), ImGuiInputTextFlags_ReadOnly);

    ImGui::BulletText("Total Interests  : ");
    static char totalInterests[50] = {};
    sprintf(totalInterests, "%.2f", totalInterests_d);
    ImGui::InputText("total interests", totalInterests, IM_ARRAYSIZE(totalInterests), ImGuiInputTextFlags_ReadOnly);

    // Help Marker
    HelpMarker("Financial Planner - 2022 \n- initial NW : Net Worth (capital) at the beginning\n- interest Rate : return on investment in % (ex. 10%)\n- Years of investment: Years of compounding\n- Final NW: Net Worth (capital) after x years (deposits + interests)\n");

    ImGui::End();
}

void FinancialPlanner::ShowDemoWindow()
{
    ImGui::Begin("Testing");



    ImGui::End();
}

void FinancialPlanner::HelpMarker(const char* desc)
{
    ImGui::TextDisabled("(?)");
    if (ImGui::IsItemHovered())
    {
        ImGui::BeginTooltip();
        ImGui::PushTextWrapPos(ImGui::GetFontSize() * 35.0f);
        ImGui::TextUnformatted(desc);
        ImGui::PopTextWrapPos();
        ImGui::EndTooltip();
    }
}

