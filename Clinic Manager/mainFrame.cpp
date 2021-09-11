#include "mainFrame.h"
#include "cApp.h"
mainFrame::mainFrame() :wxFrame(NULL,wxID_ANY,"TEST FRAME")
{
	wxMenu* menuFile = new wxMenu();
	menuFile->Append(ID_Hello, "&Hello...\tCtrl-H",
		"Help string shown in status bar for this menu item");
	menuFile->AppendSeparator();
	menuFile->Append(wxID_EXIT);
	wxMenu* help = new wxMenu();
	help->Append(wxID_ABOUT);
	wxMenuBar* menuBar = new wxMenuBar();
	menuBar->Append(menuFile, "&File");
	menuBar->Append(help, "&Help");
	SetMenuBar(menuBar);
	CreateStatusBar();
	SetStatusText("Welcome to wxWidgets");
	Bind(wxEVT_MENU, &mainFrame::onHello, this, ID_Hello);
	Bind(wxEVT_MENU, &mainFrame::onAbout, this, wxID_ABOUT);
	Bind(wxEVT_MENU, &mainFrame::onExit, this, wxID_EXIT);
}
void mainFrame::onExit(wxCommandEvent& event) {
	Close(true);
}
void mainFrame::onAbout(wxCommandEvent& event) {
	wxMessageBox("This is a wxWidgets Hello World example",
		"About Hello World", wxOK | wxICON_INFORMATION);
}
void mainFrame::onHello(wxCommandEvent& event)
{
	wxLogMessage("Hello world from wxWidgets!");
}
mainFrame::~mainFrame() {

}