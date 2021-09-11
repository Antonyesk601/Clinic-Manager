#include "cApp.h"
#include "mainFrame.h"
cApp::cApp() {

}
cApp::~cApp() {

}
bool cApp::OnInit() 
{
	mainFrame* frame = new mainFrame();
	frame->Show(true);
	return true;
}
wxIMPLEMENT_APP(cApp);