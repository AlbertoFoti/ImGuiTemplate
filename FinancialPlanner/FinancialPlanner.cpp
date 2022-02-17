#include "FinancialPlanner.h"

void FinancialPlanner::Init(GLFWwindow* window, const char* glsl_version)
{
	IMGUI_CHECKVERSION();
	ImGui::CreateContext();
	ImGuiIO &io = ImGui::GetIO();
	
	// Setup Platform/Renderer bindings
	ImGui_ImplGlfw_InitForOpenGL(window, true);
	ImGui_ImplOpenGL3_Init(glsl_version);
	ImGui::StyleColorsDark();
}

void FinancialPlanner::Update() 
{
    this->ShowCompoundInterestCalculator("Compound Interest Calculator");
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

