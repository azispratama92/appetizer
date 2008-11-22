// -*- C++ -*- generated by wxGlade 0.6.3

#include <wx/wx.h>
#include <wx/image.h>
// begin wxGlade: ::dependencies
#include <wx/notebook.h>
// end wxGlade


#ifndef CONFIGDIALOGBASE_H
#define CONFIGDIALOGBASE_H


// begin wxGlade: ::extracode
enum {
ID_CDLG_MainNotebook,
ID_CDLG_BUTTON_Save,
ID_CDLG_BUTTON_Cancel,
ID_CDLG_BUTTON_CheckForUpdate,
ID_CDLG_BUTTON_InstallAutorunButton
};
// end wxGlade


class ConfigDialogBase: public wxDialog {
public:
    // begin wxGlade: ConfigDialogBase::ids
    // end wxGlade

    ConfigDialogBase(wxWindow* parent, int id, const wxString& title, const wxPoint& pos=wxDefaultPosition, const wxSize& size=wxDefaultSize, long style=wxDEFAULT_DIALOG_STYLE);

private:
    // begin wxGlade: ConfigDialogBase::methods
    void set_properties();
    void do_layout();
    // end wxGlade

protected:
    // begin wxGlade: ConfigDialogBase::attributes
    wxStaticBox* importExclusionSizer_staticbox;
    wxStaticBox* hotKeyGroupSizer_staticbox;
    wxStaticText* languageLabel;
    wxComboBox* languageComboBox;
    wxStaticText* label_1;
    wxCheckBox* alwaysOnTopCheckBox;
    wxStaticText* label_2;
    wxCheckBox* oneInstanceCheckBox;
    wxStaticText* label_5;
    wxButton* installAutorunButton;
    wxStaticText* label_3;
    wxButton* checkForUpdateButton;
    wxPanel* notebook_1_pane_1;
    wxStaticText* iconSizeLabel;
    wxComboBox* iconSizeComboBox;
    wxStaticText* orientationLabel;
    wxComboBox* orientationComboBox;
    wxStaticText* skinLabel;
    wxComboBox* skinComboBox;
    wxPanel* notebook_pane_2;
    wxCheckBox* autohideCheckBox;
    wxCheckBox* multiLaunchAutoRunCheckBox;
    wxCheckBox* hotKeyCtrlCheckBox;
    wxCheckBox* hotKeyAltCheckBox;
    wxCheckBox* hotKeyShiftCheckBox;
    wxComboBox* hotKeyComboBox;
    wxPanel* notebook_pane_3;
    wxTextCtrl* importExclusionTextBox;
    wxPanel* notebook_pane_4;
    wxNotebook* notebook;
    wxButton* saveButton;
    wxButton* cancelButton;
    // end wxGlade
}; // wxGlade: end class


#endif // CONFIGDIALOGBASE_H
