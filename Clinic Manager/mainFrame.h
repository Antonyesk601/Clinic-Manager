#pragma once
#include "cApp.h"
class mainFrame : public wxFrame
{
public:
	mainFrame();
	~mainFrame();
private:
	void onHello(wxCommandEvent& event);
	void onExit(wxCommandEvent& event);
	void onAbout(wxCommandEvent& event);
};
