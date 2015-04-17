#pragma once

struct dialog_contactprops_params_s
{
    contact_key_s key;

    dialog_contactprops_params_s() {}
    dialog_contactprops_params_s(const contact_key_s &key) :key(key)  {}
};

class dialog_contact_props_c;
template<> struct MAKE_ROOT<dialog_contact_props_c> : public _PROOT(dialog_contact_props_c)
{
    dialog_contactprops_params_s prms;
    MAKE_ROOT(drawcollector &dch) :_PROOT(dialog_contact_props_c)(dch) { init(false); }
    MAKE_ROOT(drawcollector &dch, const dialog_contactprops_params_s &prms) :_PROOT(dialog_contact_props_c)(dch), prms(prms) { init(false); }
    ~MAKE_ROOT() {}
};

class dialog_contact_props_c : public gui_isodialog_c
{
    ts::shared_ptr<contact_c> contactue;

    ts::wstr_c customname;
    bool custom_name( const ts::wstr_c & );

    keep_contact_history_e keeph = KCH_DEFAULT;
    void history_settings( const ts::str_c& );
    menu_c gethistorymenu();

protected:
    /*virtual*/ int unique_tag() { return UD_CONTACTPROPS; }
    /*virtual*/ void created() override;
    /*virtual*/ void getbutton(bcreate_s &bcr) override;
    /*virtual*/ int additions(ts::irect & border) override;
    /*virtual*/ void on_confirm() override;


public:
    dialog_contact_props_c(MAKE_ROOT<dialog_contact_props_c> &data);
    ~dialog_contact_props_c();

    /*virtual*/ ts::wstr_c get_name() const override;
    /*virtual*/ ts::ivec2 get_min_size() const override;
    /*virtual*/ bool sq_evt(system_query_e qp, RID rid, evt_data_s &data) override;
};

