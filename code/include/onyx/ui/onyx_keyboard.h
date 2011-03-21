#include <QtGui/QtGui>

#include "onyx/base/base.h"
#include "onyx/screen/screen_proxy.h"
#include "onyx/sys/sys_status.h"

#include "catalog_view.h"

#include "keyboard_data_factory.h"
#include "keyboard_data.h"

namespace ui
{

class OnyxKeyboard : public QWidget
{
    Q_OBJECT

public:
    enum KeyboardMenuType
    {
        KEYBOARD_MENU_SHIFT = 1,
        KEYBOARD_MENU_SYMBOL = 2,
        KEYBOARD_MENU_LANGUAGE = 3,
        KEYBOARD_MENU_WRITE = 4,
        KEYBOARD_MENU_OK = 5,
        KEYBOARD_MENU_CLEAR = 6,
    };

public:
    explicit OnyxKeyboard(QWidget *parent = 0);
    ~OnyxKeyboard();

    inline CatalogView * top() { return &top_; }
    inline CatalogView * menu() { return &menu_; }

protected:
    void init(const QLocale & locale);
    bool event(QEvent * event);

protected Q_SLOTS:
    void onItemActivated(CatalogView *catalog, ContentView *item, int user_data);

Q_SIGNALS:
    void okClicked(const QString text);

private:
    void createLayout();
    void connectWithChildren();
    void createLineEdit();
    void createSubMenu();
    void createTop();
    void createLeft();
    void createMiddle();
    void createRight();
    void createBottom();
    void createMenu();

    void menuItemActivated(ContentView *item, int user_data);
    void resetData(bool shift);
    void shiftClicked();
    void symbolClicked();
    void languageClicked();
    void clearClicked();
    ODatas & changeCase(ODatas & datas, bool is_caps_lock);
    void capsLockClicked();

private:
    QVBoxLayout big_layout_;
    QHBoxLayout line_edit_layout_;
    QHBoxLayout layout_;
    CatalogView line_edit_;
    // contains OK and Clear menu items
    CatalogView sub_menu_;
    CatalogView top_;
    CatalogView left_;
    CatalogView middle_;
    CatalogView right_;
    CatalogView bottom_;
    CatalogView menu_;

    KeyboardDataFactory keyboard_data_factory_;
    KeyboardData *keyboard_data_;

    bool shift_;
    bool symbol_;
    QLocale language_;               // current language
    bool is_handwriting_;            // is handwriting state

};

}   // namespace ui