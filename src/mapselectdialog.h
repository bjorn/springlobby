/* This file is part of the Springlobby (GPL v2 or later), see COPYING */

#ifndef MAPSELECTDIALOG_H
#define MAPSELECTDIALOG_H

#include <vector>
#include "gui/windowattributespickle.h"
#include "utils/globalevents.h"
//(*Headers(MapSelectDialog)
#include <wx/dialog.h>
class wxStdDialogButtonSizer;
class wxTextCtrl;
class MapGridCtrl;
class wxRadioButton;
class wxStaticText;
class wxListCtrl;
class wxBoxSizer;
class wxStaticBoxSizer;
class wxChoice;
//*)
class wxButton;

class Ui;
namespace LSL {
    struct UnitsyncMap;
}

// FIXME: WindowAttributesPickle calls SetSize which causes an wx-assertion
class MapSelectDialog: public wxDialog, public GlobalEvent /*,public WindowAttributesPickle, */
{
	public:

		MapSelectDialog( wxWindow* parent);
		virtual ~MapSelectDialog();

		LSL::UnitsyncMap* GetSelectedMap() const;

		void OnUnitsyncReloaded( wxCommandEvent& data );

	protected:

		//(*Declarations(MapSelectDialog)
		wxRadioButton* m_filter_recent;
		wxStaticText* m_map_name;
		wxRadioButton* m_filter_all;
		MapGridCtrl* m_mapgrid;
		wxChoice* m_vertical_choice;
		wxChoice* m_horizontal_choice;
		wxTextCtrl* m_filter_text;
		wxListCtrl* m_map_opts_list;
		wxRadioButton* m_filter_popular;
		wxStaticBoxSizer* m_map_details;
		//*)
		wxButton* m_vertical_direction_button;
		wxButton* m_horizontal_direction_button;

		//(*Identifiers(MapSelectDialog)
		static const long ID_STATICTEXT2;
		static const long ID_VERTICAL_CHOICE;
		static const long ID_STATICTEXT1;
		static const long ID_HORIZONTAL_CHOICE;
		static const long ID_FILTER_ALL;
		static const long ID_FILTER_POPULAR;
		static const long ID_FILTER_RECENT;
		static const long ID_FILTER_TEXT;
		static const long ID_MAP_NAME;
		static const long ID_MAP_OPTS_LIST;
		static const long ID_MAPGRID;
		//*)
		static const long ID_VERTICAL_DIRECTION;
		static const long ID_HORIZONTAL_DIRECTION;

		//(*Handlers(MapSelectDialog)
		void OnInit(wxInitDialogEvent& event);
		void OnSortKeySelect(wxCommandEvent& event);
		void OnMapGridLeftDClick(wxMouseEvent& event);
		void OnFilterAllSelect(wxCommandEvent& event);
		void OnFilterPopularSelect(wxCommandEvent& event);
		void OnFilterRecentSelect(wxCommandEvent& event);
		void OnFilterTextChanged(wxCommandEvent& event);
		//*)

		void OnMapSelected( wxCommandEvent& event );
		void OnMapLoadingCompleted( wxCommandEvent& event );
		void OnVerticalDirectionClicked( wxCommandEvent& event );
		void OnHorizontalDirectionClicked( wxCommandEvent& event );

		void AppendSortKeys( wxChoice* choice );
		void UpdateSortAndFilter();

		void LoadAll();
		void LoadPopular();
		void LoadRecent();

		bool m_horizontal_direction;
		bool m_vertical_direction;
		wxArrayString m_maps;
		wxArrayString m_replays;

		static const wxString m_dialog_name;
		enum {
			m_filter_all_sett = 0,
			m_filter_popular_sett = 1,
			m_filter_recent_sett = 2,
		};

		DECLARE_EVENT_TABLE()
};

wxString mapSelectDialog(bool hidden=false, wxWindow* parent=NULL);

#endif
