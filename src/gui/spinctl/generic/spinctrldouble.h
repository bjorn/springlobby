#ifndef SPRINGLOBBY_HEADERGUARD_SPINCTRLDOUBLE_H
#define SPRINGLOBBY_HEADERGUARD_SPINCTRLDOUBLE_H

//-----------------------------------------------------------------------------
// SlSpinCtrlDouble
//-----------------------------------------------------------------------------

#include "../spinctrl.h"

class  SlSpinCtrlDouble : public SlSpinCtrlGenericBase
{
public:
    SlSpinCtrlDouble() : m_parent_instance(0), m_digits(0) { }
    SlSpinCtrlDouble(wxWindow *parent,
                     wxWindowID id = wxID_ANY,
                     const wxString& value = wxEmptyString,
                     const wxPoint& pos = wxDefaultPosition,
                     const wxSize& size = wxDefaultSize,
                     long style = wxSP_ARROW_KEYS | wxALIGN_RIGHT,
                     double min = 0, double max = 100, double initial = 0,
                     double inc = 1,
                     const wxString& name = wxT("SlSpinCtrlDouble"))
    {
        m_digits = 0;
        Create(parent, id, value, pos, size, style,
               min, max, initial, inc, name);
    }

    bool Create(wxWindow *parent,
                wxWindowID id = wxID_ANY,
                const wxString& value = wxEmptyString,
                const wxPoint& pos = wxDefaultPosition,
                const wxSize& size = wxDefaultSize,
                long style = wxSP_ARROW_KEYS | wxALIGN_RIGHT,
                double min = 0, double max = 100, double initial = 0,
                double inc = 1,
                const wxString& name = wxT("SlSpinCtrlDouble"))
    {
        m_parent_instance = parent;
        return SlSpinCtrlGenericBase::Create((wxWindow*)parent, id, value, pos, size,
                                             style, min, max, initial,
                                             inc, name);
    }

    // accessors
    double GetValue(wxSPINCTRL_GETVALUE_FIX) const { return DoGetValue(); }
    double GetMin() const { return m_min; }
    double GetMax() const { return m_max; }
    double GetIncrement() const { return m_increment; }
    unsigned GetDigits() const { return m_digits; }

    // operations
    void SetValue(const wxString& value)
        { SlSpinCtrlGenericBase::SetValue(value); }
    void SetValue(double value)                 { DoSetValue(value); }
    void SetRange(double minVal, double maxVal) { DoSetRange(minVal, maxVal); }
    void SetIncrement(double inc)               { DoSetIncrement(inc); }
    void SetDigits(unsigned digits);

protected:
    virtual void DoSendEvent();
    wxWindow* m_parent_instance;
    unsigned m_digits;

//    DECLARE_DYNAMIC_CLASS(SlSpinCtrlDouble)
};

#endif
