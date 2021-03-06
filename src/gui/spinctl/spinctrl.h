/////////////////////////////////////////////////////////////////////////////
// Name:        spinctrl.h
// Purpose:     wxSpinCtrlBase class
// Author:      Vadim Zeitlin
// Modified by:
// Created:     22.07.99
// RCS-ID:      $Id: spinctrl.h 58757 2009-02-08 11:45:59Z VZ $
// Copyright:   (c) Vadim Zeitlin
// Licence:     wxWindows licence
/////////////////////////////////////////////////////////////////////////////

#ifndef SL_WX_SPINCTRL_H_
#define SL_WX_SPINCTRL_H_



#include "wx/defs.h"
#include <wx/spinctrl.h>



#if 0
//HAVE_WX29

#else

#if wxUSE_SPINCTRL

#include "wx/spinbutt.h"        // should make wxSpinEvent visible to the app

// Events
class  SlSpinDoubleEvent;

static const wxEventType SLEVT_COMMAND_SPINCTRLDOUBLE_UPDATED  = wxNewEventType();
//const wxEventType SLEVT_COMMAND_SPINCTRL_UPDATED  = wxNewEventType();

// ----------------------------------------------------------------------------
// A spin ctrl is a text control with a spin button which is usually used to
// prompt the user for a numeric input.
// There are two kinds for number types T=integer or T=double.
// ----------------------------------------------------------------------------

class  SlSpinCtrlBase : public wxControl
{
public:
    SlSpinCtrlBase() {}

    // accessor functions that derived classes are expected to have
    // T GetValue() const
    // T GetMin() const
    // T GetMax() const
    // T GetIncrement() const
    virtual bool GetSnapToTicks() const = 0;
    // unsigned GetDigits() const                   - SlSpinCtrlDouble only

    // operation functions that derived classes are expected to have
    virtual void SetValue(const wxString& value) = 0;
    // void SetValue(T val)
    // void SetRange(T minVal, T maxVal)
    // void SetIncrement(T inc)
    virtual void SetSnapToTicks(bool snap_to_ticks) = 0;
    // void SetDigits(unsigned digits)              - SlSpinCtrlDouble only

    // Select text in the textctrl
    virtual void SetSelection(long from, long to) = 0;

private:
	DECLARE_NO_COPY_CLASS(SlSpinCtrlBase)
};

// ----------------------------------------------------------------------------
// wxSpinDoubleEvent - a wxSpinEvent for double valued controls
// ----------------------------------------------------------------------------

class  SlSpinDoubleEvent : public wxNotifyEvent
{
public:
    SlSpinDoubleEvent(wxEventType commandType = wxEVT_NULL, int winid = 0,
                      double value = 0)
        : wxNotifyEvent(commandType, winid), m_value(value)
    {
    }

    SlSpinDoubleEvent(const SlSpinDoubleEvent& event)
        : wxNotifyEvent(event), m_value(event.GetValue())
    {
    }

    double GetValue() const       { return m_value; }
    void   SetValue(double value) { m_value = value; }

    virtual wxEvent *Clone() const { return new SlSpinDoubleEvent(*this); }

protected:
    double m_value;

private:
    DECLARE_DYNAMIC_CLASS_NO_ASSIGN(SlSpinDoubleEvent)
};

// ----------------------------------------------------------------------------
// wxSpinDoubleEvent event type, see also wxSpinEvent in wx/spinbutt.h
// ----------------------------------------------------------------------------

typedef void (wxEvtHandler::*SlSpinDoubleEventFunction)(SlSpinDoubleEvent&);

#define SlSpinDoubleEventHandler(func) \
    (wxObjectEventFunction)(wxEventFunction)wxStaticCastEvent(SlSpinDoubleEventFunction, &func)

//#define wxCommandEventHandler(func)
//    (wxObjectEventFunction)(wxEventFunction)wxStaticCastEvent(wxCommandEventFunction, &func)
// macros for handling spinctrl events

//#define EVT_SLSPINCTRL(id, fn)
//    wx__DECLARE_EVT1(SLEVT_COMMAND_SPINCTRL_UPDATED, id, SlSpinEventHandler(fn))

#define EVT_SLSPINCTRLDOUBLE(id, fn) \
    wx__DECLARE_EVT1(SLEVT_COMMAND_SPINCTRLDOUBLE_UPDATED, id, SlSpinDoubleEventHandler(fn))

//the common stuff
#include "generic/spinctlg.h"
//the actual tempalte class, seperated to avoid multiple definition conflicts
#include "generic/spinctrldouble.h"

#endif // wxUSE_SPINCTRL

#endif // _WX_SPINCTRL_H_



#endif //#ifdef HAVE_WX29
