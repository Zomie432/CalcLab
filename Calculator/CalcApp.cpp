#include "CalcApp.h"

wxIMPLEMENT_APP(CalcApp);

CalcApp::CalcApp() {

}

CalcApp::~CalcApp() {

}

bool CalcApp::OnInit() {
	calcWindow = new CalcWindow();
	calcWindow->Show();
	return true;
}